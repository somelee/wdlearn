#include <mysql/mysql.h>
#include <stdio.h>

int main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char* server="localhost";
	char* user="root";
	char* password="123456";
	char* database="test";
	char* query="select * from myclass";
	int t,r;
	conn=mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
	{
		printf("Error connecting to database:%s\n",mysql_error(conn));
	}else{
		printf("connected...\n");
	}
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
	}else{
		printf("Query made...\n");
		res=mysql_use_result(conn);
		if(res)
		{
			while((row=mysql_fetch_row(res))!=NULL)
			{
				for(t=0;t<mysql_num_fields(res);t++)
					printf("%s ",row[t]);
				printf("\n");
			}
		}
		mysql_free_result(res);
	}
	mysql_close(conn);
	return 0;
}

con_mysql:test.c delete.c insert.c
	gcc test.c -o query_mysql -I /usr/include/mysql/ -lmysqlclient
	gcc delete.c -o delete_mysql -I /usr/include/mysql/ -lmysqlclient
	gcc insert.c -o insert_mysql -I /usr/include/mysql/ -lmysqlclient
clean:
	rm query_mysql delete_mysql insert_mysql

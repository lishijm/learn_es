#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DB_FILE	"stu.db"

void menu()
{
	printf("\n****************************************\n");
	printf("insert:1 update:2 qury:3 delete:4 exit:5");
	printf("\n****************************************\n");
}

int do_insert(sqlite3 *db)
{
	// 输入id
	int id;
	printf("input id:");
	scanf("%d", &id);
	getchar();

	// 输入name
	char name[32] = {0};
	printf("input name:");
	scanf("%s", name);
	getchar();

	// 输入score
	int score;
	printf("input score:");
	scanf("%d", &score);
	getchar();

	char sql[128] = {0};
	sprintf(sql, "insert into stu values(%d, '%s', %d);", id, name, score);
	char *errMsg = NULL;
	int ret = sqlite3_exec(db, sql, NULL, NULL, &errMsg);
	if (ret != SQLITE_OK) {
		printf("sqlite3_exec error, %s\n", errMsg);
		sqlite3_free(errMsg);
		return -1;
	}

	printf("do_insert success\n");
	return 0;
}

int do_update(sqlite3 *db)
{
	// 输入id
	int id;
	printf("input id:");
	scanf("%d", &id);
	getchar();
	
	// 输入score
	int score;
	printf("input score:");
	scanf("%d", &score);
	getchar();

	char sql[128] = {0};
	sprintf(sql, "update stu set score=%d where id=%d;", score, id);
	char *errMsg = NULL;
	int ret = sqlite3_exec(db, sql, NULL, NULL, &errMsg);
	if (ret != SQLITE_OK) {
		printf("sqlite3_exec error, %s\n", errMsg);
		sqlite3_free(errMsg);
		return -1;
	}

	printf("do_update success\n");
	return 0;
}

int callback(void *para, int f_num, char **f_value, char **f_name)
{
	for (int i = 0; i < f_num; i++) {
		printf("%-10s", f_value[i]);
	}
	putchar(10);
	return 0;
}

int do_query(sqlite3 *db)
{
	char sql[] = "select * from stu;";
	char *errMsg = NULL;
	int ret = sqlite3_exec(db, sql, callback, NULL, &errMsg);
	if (ret != SQLITE_OK) {
		printf("sqlite3_exec error, %s\n", errMsg);
		sqlite3_free(errMsg);
		return -1;
	}

	printf("do_query success\n");
	return 0;
}

int do_query1(sqlite3 *db)
{
	char **result = NULL;
	int row, column;
	char *errMsg = NULL;
	char sql[] = "select * from stu;";
	int ret = sqlite3_get_table(db, sql, &result, &row, &column, &errMsg);
	if (ret != SQLITE_OK) {
		printf("sqlite3_get_table error, %s\n", errMsg);
		sqlite3_free(errMsg);
		return -1;
	}

	int index = (column-column);
	for (int i = 0; i <=row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%-10s", result[index++]);
		}
		putchar(10);
	}

	sqlite3_free_table(result);
	return 0;
}

int do_delete(sqlite3 *db)
{
	// 输入id
	int id;
	printf("input id:");
	scanf("%d", &id);
	getchar();

	char sql[128] = {0};
	sprintf(sql, "delete from stu where id=%d;", id);
	char *errMsg = NULL;
	int ret = sqlite3_exec(db, sql, NULL, NULL, &errMsg);
	if (ret != SQLITE_OK) {
		printf("sqlite3_exec error, %s\n", errMsg);
		sqlite3_free(errMsg);
		return -1;
	}

	printf("do_delete success\n");
	return 0;
}

int main()
{
	// 打开数据库
	sqlite3 *db = NULL;
	int ret = sqlite3_open(DB_FILE, &db);
	if (ret != SQLITE_OK) {
		printf("sqlite3_open error, %s\n", sqlite3_errmsg(db));
		return -1;
	}

	// 创建表
	char sql[] = "create table if not exists stu(id integer primary key not null, name text, score integer);";
	char *errMsg = NULL;
	ret = sqlite3_exec(db, sql, NULL, NULL, &errMsg);
	if (ret != SQLITE_OK) {
		printf("sqlite3_exec error, %s\n", errMsg);
		sqlite3_free(errMsg);
		return -1;
	}

	// 插入，更新，查询，删除表记录
	int op;
	while (1) {
		menu();
		printf("please input:");
		scanf("%d", &op);
		getchar();

		switch (op) {
			case 1:
				do_insert(db);
				break;
			case 2:
				do_update(db);
				break;
			case 3:
				do_query(db);
				break;
			case 4:
				do_delete(db);
				break;
			case 5:
				// 关闭数据库
				sqlite3_close(db);
				exit(0);
			default:
				printf("input %d error", op);
				break;
		}
	}

	return 0;
}

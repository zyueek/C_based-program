#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	char name[20];
	char grade[2];
	char math[3];
	char chinese[3];
};
struct Node
{
	struct student data;
	struct Node* next;
};
struct Node* createnode()
{
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	return head;
}
struct Node* createnode(struct student data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void insert(struct Node* head, struct student data)
{
	struct Node* newnode = createnode(data);
	newnode->next = head->next;
	head->next = newnode;
}
void deletenode(struct Node* head, char *name)
{
	struct Node* dnode = head->next; //dnode为删除节点,fnode为删除节点的前节点
	struct Node* fnode = head;
	if (dnode == NULL)
	{
		printf("数据为空\n");
		return;
	}
	while (strcmp(dnode->data.name, name))
	{
		fnode = dnode;
		dnode = fnode->next;
		if (dnode == NULL)
		{
			printf("未找到该数据\n");
			return;
		}
		fnode->next = dnode->next;
		free(dnode);
	}
}
struct Node* findnode(struct Node* head, char *name)
{
	struct Node* move = head->next;
	if (strcmp(move->data.name, name) != 0)
	{
		return NULL;
	}
	while (strcmp(move->data.name, name))
	{
		move = move->next;
	}
	return move;
}
void printlist(struct Node* head)
{
	struct Node* move = head->next;
	printf("姓名\t年级\t数学\t语文\n");
	while (move)
	{
		printf("%s\t%s\t%s\t%s\n", move->data.name,move->data.grade,move->data.math,move->data.chinese);
		move = move->next;
	}
}
void menu()
{
	printf("*****************学生信息管理系统******************\n");
	printf("                  1.录入信息\n");
	printf("                  2.信息显示\n");
	printf("                  3.信息修改\n");
	printf("                  4.信息删除\n");
	printf("                  5.信息搜寻\n");
	printf("                  6.退出系统\n");
	printf("***************************************************\n");

}
struct Node* list = createnode();
struct Node* move = NULL;
void search()
{
	int choice = 1;
	struct student data;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("----------------------录入信息---------------------\n");
		printf("请输入学生姓名,年级,数学成绩,语文成绩\n");
		fflush(stdin);
		scanf("%s%s%s%s", data.name, data.grade, data.math, data.chinese);
		insert(list, data);
		break;
	case 2:
		printf("----------------------信息显示---------------------\n");
		printlist(list);
		break;
	case 3:
		printf("----------------------信息修改---------------------\n");
		printf("请输入修改的学生姓名:");
		scanf("%s", data.name);
		move = findnode(list, data.name);
		if (move == NULL)
		{
			printf("无此姓名,请重新输入\n");
			system("pause");
		}
		else
		{
			printf("请输入修改后的信息\n");
			scanf("%s%s%s%s",move->data.name,move->data.grade,move->data.math,move->data.chinese);
		}
		break;
	case 4:
		printf("----------------------信息删除---------------------\n");
		printf("请输入删除的学生姓名:");
		scanf("%s", data.name);
		deletenode(list, data.name);
		break;
	case 5:
		printf("----------------------信息搜寻---------------------\n");
		printf("请输入搜寻的学生姓名:");
		scanf("%s", data.name);
		move = findnode(list, data.name);
		if (move == NULL)
		{
			printf("无此姓名,请重新输入\n");
			system("pause");
		}
		else
		{
			printf("姓名\t年级\t数学\t语文\n");
			printf("%s\t%s\t%s\t%s\n", move->data.name,move->data.grade,move->data.math,move->data.chinese);
		}
		break;
	case 6:
		printf("exit!\n");
		system("pause");
		exit(0);
		break;
	default:
		break;
	}
}
int main()
{
	while (1)
	{
		menu();
		search();
		system("pause");
		system("cls");
	}
	system("pause");

	return 0;
}
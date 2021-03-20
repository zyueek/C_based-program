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
	struct Node* dnode = head->next; //dnodeΪɾ���ڵ�,fnodeΪɾ���ڵ��ǰ�ڵ�
	struct Node* fnode = head;
	if (dnode == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	while (strcmp(dnode->data.name, name))
	{
		fnode = dnode;
		dnode = fnode->next;
		if (dnode == NULL)
		{
			printf("δ�ҵ�������\n");
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
	printf("����\t�꼶\t��ѧ\t����\n");
	while (move)
	{
		printf("%s\t%s\t%s\t%s\n", move->data.name,move->data.grade,move->data.math,move->data.chinese);
		move = move->next;
	}
}
void menu()
{
	printf("*****************ѧ����Ϣ����ϵͳ******************\n");
	printf("                  1.¼����Ϣ\n");
	printf("                  2.��Ϣ��ʾ\n");
	printf("                  3.��Ϣ�޸�\n");
	printf("                  4.��Ϣɾ��\n");
	printf("                  5.��Ϣ��Ѱ\n");
	printf("                  6.�˳�ϵͳ\n");
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
		printf("----------------------¼����Ϣ---------------------\n");
		printf("������ѧ������,�꼶,��ѧ�ɼ�,���ĳɼ�\n");
		fflush(stdin);
		scanf("%s%s%s%s", data.name, data.grade, data.math, data.chinese);
		insert(list, data);
		break;
	case 2:
		printf("----------------------��Ϣ��ʾ---------------------\n");
		printlist(list);
		break;
	case 3:
		printf("----------------------��Ϣ�޸�---------------------\n");
		printf("�������޸ĵ�ѧ������:");
		scanf("%s", data.name);
		move = findnode(list, data.name);
		if (move == NULL)
		{
			printf("�޴�����,����������\n");
			system("pause");
		}
		else
		{
			printf("�������޸ĺ����Ϣ\n");
			scanf("%s%s%s%s",move->data.name,move->data.grade,move->data.math,move->data.chinese);
		}
		break;
	case 4:
		printf("----------------------��Ϣɾ��---------------------\n");
		printf("������ɾ����ѧ������:");
		scanf("%s", data.name);
		deletenode(list, data.name);
		break;
	case 5:
		printf("----------------------��Ϣ��Ѱ---------------------\n");
		printf("��������Ѱ��ѧ������:");
		scanf("%s", data.name);
		move = findnode(list, data.name);
		if (move == NULL)
		{
			printf("�޴�����,����������\n");
			system("pause");
		}
		else
		{
			printf("����\t�꼶\t��ѧ\t����\n");
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
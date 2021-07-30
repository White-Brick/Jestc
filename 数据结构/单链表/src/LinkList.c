#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>

List *CreateList()
{
	List *ls = (List*)malloc(sizeof(List)/sizeof(char));
	if (NULL == ls)
		return NULL;
	
	// 创建头结点
	ls->head = (Node*)malloc(sizeof(Node)/sizeof(char));
	if(NULL == ls->head)
	{
		free(ls);
		return NULL;
	}
	
	ls->head->next = NULL;   // 空链表
	
	return ls;
}

BOOL Insert_Head(List *ls, Data data)
{
	if (NULL == ls)
		return ERROR;
	
	Node *node = (Node *)malloc(sizeof(Node)/sizeof(char));
	if (NULL == node)
		return ERROR;
	
	node->data = data;
	node->next = ls->head->next;
	ls->head->next = node;
	
	return TRUE;
}

BOOL Insert_Last(List *ls, Data data)
{
	if (NULL == ls)
		return ERROR;
	
	Node *node = (Node *)malloc(sizeof(Node)/sizeof(char));
	if (NULL == node)
		return ERROR;
	
	node->data = data;
	node->next = NULL;
	
	Node *tmp = ls->head;         // 头结点
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	
	tmp->next = node;
	
	return TRUE;
}

BOOL Insert_Pos(List *ls, int pos, Data data)
{
	if(NULL == ls|| pos<1)
		return ERROR;
	
	Node *tmp = ls->head;
	int i;
	for (i = 0; i<pos-1; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL)  // 越界
		{
			printf ("长度越界: %d\n", pos);
			return ERROR;
		}
	}
	
	Node *node = (Node *)malloc(sizeof(Node)/sizeof(char));
	if (NULL == node)
		return ERROR;
	
	node->data = data;
	node->next = tmp->next; 		
	tmp->next  = node;
	
				
	return TRUE;
}

BOOL Delete_Pos(List *ls, int pos)
{
	if(NULL == ls|| pos<1)
		return ERROR;
	
	Node *tmp = ls->head;
	int i;
	for (i = 0; i<pos-1; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL || tmp->next == NULL)  // 越界
		{
			printf ("长度越界: %d\n", pos);
			return ERROR;
		}
	}
	
	Node *p = tmp->next;
	tmp->next = p->next;
	free(p);
				
	return TRUE;
}

BOOL Delete_Data(List *ls, Data data)
{	
	if(NULL == ls)
		return ERROR;

	Node *tmp = ls->head;
	while (tmp->next)
	{
		if (tmp->next->data == data)
		{
			Node *p = tmp->next;
			tmp->next = p->next;
			free(p);
			return TRUE;
		}
		tmp = tmp->next;
	}
	
	return FALSE;
}

BOOL Reverse(List *ls)
{
	// NULL ==ls || NULL == ls->head    链表不存在
	// NULL == ls->head->next           空链表
	// NULL == ls->head->next->next     只有一个结点的链表
	if (NULL == ls || NULL == ls->head || NULL == ls->head->next || NULL == ls->head->next->next)
		return ERROR;
	
	Node *pre = ls->head->next;    // 第一个结点
	Node *cur = pre->next;         // 第二个结点
	Node *tmp;                     // 保存当前结点的下一个结点
	
	while (cur)
	{
		tmp = cur->next;
		cur->next = pre;
		
		pre = cur;
		cur = tmp;
	}
	
	ls->head->next->next = NULL;	//将原来第一个结点的指针域指向NULL
	ls->head->next = pre;			//将头结点的next指向最后一个元素
	
	return TRUE;
}

void Display(List *ls)
{
	if (NULL == ls)
		return;
	
	Node *tmp = ls->head->next;   // 第一个结点
	while (tmp)
	{
		printf ("%-4d", tmp->data);
		tmp = tmp->next;
	}
	
	printf ("\n");
	
}

void Destroy(List *ls)
{
	if (NULL == ls)
		return;
	
	Node *tmp = ls->head;
	while (tmp->next)
	{
		Node *p = tmp->next;
		tmp->next = p->next;
		free(p);
	}
	
	free(ls->head);
	free(ls);
}








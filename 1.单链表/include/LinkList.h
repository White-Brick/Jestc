#ifndef _LINKLIST_H_
#define _LINKLIST_H_


typedef enum {TRUE, FALSE, ERROR}  BOOL;

typedef int Data;
typedef struct _node
{
	Data data;          // 数据域
	struct _node *next; // 指针域，指向链表的下一个结点
}Node;

typedef struct _list
{
	Node *head;      // 头结点
}List;	

// 创建链表
List *CreateList();

// 插入：头插
BOOL Insert_Head(List *ls, Data data);

// 插入：尾插
BOOL Insert_Last(List *ls, Data data);

// 插入：在特定位置插入的数据
// pos：第 pos 个结点位置
BOOL Insert_Pos(List *ls, int pos, Data data);

// 删除特定位置的数据
// pos：第 pos 个结点位置
BOOL Delete_Pos(List *ls, int pos);

// 根据值删除数据
BOOL Delete_Data(List *ls, Data data);

// 链表逆序
BOOL Reverse(List *ls);

void Destory(List *ls);


void Display(List *ls);

#endif // _LINKLIST_H_






















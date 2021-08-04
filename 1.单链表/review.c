// 手撕链表

// 头文件
#include <stdio.h>
#include <stdlib.h>

// 自定义枚举类型
typedef enum {
    TRUE,
    FALSE,
    ERR
}BOOL;

// 自定义链表数据类型
typedef int Data;

// 链表节点
typedef struct _node {
    Data data;          // 数据域
    struct _node *next; // 指针域
}Node;

// 链表头
typedef struct _list {
    Node *head;
}List;

// = end of data struct =

// = start of func define =
List *CreateList();
BOOL Insert_Head(List *ls, Data data);
// BOOL Insert_Tail(List *ls, Data data);
// BOOL Insert_Pos(List *ls, int pos, Data data);
// BOOL Del_Pos(List *ls, int pos);
// BOOL Del_Data(List *ls, Data data);

// BOOL List_Reverse(List *ls);
// BOOL List_Destory(List *ls);
// BOOL List_Display(List *ls);
// = end of data struct =

List *CreateList() {
    // 栈上申请，函数返回不会被释放
    List *ls = (List *)malloc(sizeof(List) / sizeof(char));
    // Todo：数据清零memset
    // Todo：内存泄漏，通过链表计数避免
    if (NULL == ls) {
        // Todo:宏函数编写日志函数，湛剑
        printf("Create List fail.\n");
        return NULL;
    }

    // Todo:将链表头传给函数，实现链表创建
    ls->head = (Node *)malloc(sizeof(Node) / sizeof(char));
    if (NULL == ls->head) {
        free(ls); // !注意 第一次疏忽了内存泄漏
        return NULL;
    }

    ls->head->next = NULL;
    return ls;
}

BOOL Insert_Head(List *ls, Data data) {
    if (NULL == ls) {
        return ERR;
    }

    Node *node = (Node *)malloc(sizeof(Node) / sizeof(char));
    if (NULL == node) {
        return ERR;
    }
    node->data = data;
    node->next = ls->head->next;
    ls->head->next = node;

    return TRUE;
}


BOOL List_Display(List *ls) {
    if (NULL == ls) {
        return ERR;
    }
    int iLoop = 0;
    Node *tmp = ls->head->next;
    while (tmp) {
        printf("[%d]: %d\n", iLoop, tmp->data);
        tmp = tmp->next;
        iLoop++;
    }

    return TRUE;
}

int main(void) {
    List *ls = CreateList();
    if (NULL == ls) {
        return -1;
    }

    int ret = FALSE;
    ret = Insert_Head(ls, 1);
    ret = Insert_Head(ls, 2);
    ret = Insert_Head(ls, 3);
    ret = Insert_Head(ls, 4);
    ret = Insert_Head(ls, 5);

    ret = List_Display(ls);
    return 0;
}


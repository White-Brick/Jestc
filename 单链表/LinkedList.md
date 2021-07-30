# 链表
包括一个“头指针”变量，其中第0个结点称为整个链表的**头结点**，头结点中存放一个地址，该地址指向一个元素，头结点一般不存放具体数据，只是存放第一个结点的地址。  
链表中每一个元素称为“结点”，每个结点都由两部分组成：存放数据元素的数据域和存储直接后继存储位置的指针域。  
最后一个结点的指针域设置为空(NULL)，作为链表的结束标志
**单链表**: 当一个序列中只含有指向它的后继结点的链接




## 单链表的创建
### 1. 首先定义头结点和链表结点的结构体
```C
typedef enum {TRUE, FALSE, ERROR}  BOOL;
typedef int Data;

//链表结点
typedef struct _node
{
	Data data;          // 数据域
	struct _node *next; // 指针域，指向链表的下一个结点
}Node;


//头结点
typedef struct _list
{
	Node *head;      // 头结点
}List;	

```

### 2. 创建一个空链表
```
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
```

## 单链表的操作

### 数据插入

#### 头插
```C
/*	
	功能:在链表ls的头部插入一个链表结点
    参数:链表指针, 传入的数据
    返回值:成功TRUE 错误ERROR
*/
BOOL Insert_Head(List *ls, Data data)
{
	if (NULL == ls)
		return ERROR;

	//申请链表结点空间,返回给链表结点指针node
	Node *node = (Node *)malloc(sizeof(Node)/sizeof(char));
	if (NULL == node)
		return ERROR;
	//数据域
	node->data = data;

	node->next = ls->head->next;	//node指向原头结点的next
	ls->head->next = node;			//将头结点的next指向node
	
	return TRUE;
}
```


#### 尾插
```C
/*	
	功能:在链表ls的尾部插入一个链表结点
    参数:链表指针, 传入的数据
    返回值:成功TRUE 错误ERROR
*/
BOOL Insert_Head(List *ls, Data data)
{
	if (NULL == ls)
		return ERROR;
	//申请链表结点空间,返回给链表结点指针node
	Node *node = (Node *)malloc(sizeof(Node)/sizeof(char));
	if (NULL == node)
		return ERROR;
	//数据域
	node->data = data
	node->next = NULL;

	Node *tmp = ls->head;
	while(tmp->next)//找到链表的最后一个结点,其next为NULL
	{
		tmp = tmp->next;
	}


	tmp->next = node;
	return TRUE;

}
```

#### 任意位置插
```C
BOOL Insert_Pos(List *ls, int pos, Data data)
{
	if (NULL == ls || pos < 1)
		return ERROR;

	Node *tmp = ls->head;
	int i;
	for (i = 0; i < pos -1; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL)
		{
			printf("长度越界 %d\n", pos);
			return ERROR;
		}
	}

	Node *node = (Node *)malloc(sizeof(Node)/sizeof(char));

	node->data = data;
	node->next = tmp->next;
	tmp->next = node;

	return TRUE;
}
```

### 数据删除
#### 删除指定位置元素
```C
BOOL Delete_Pos(List *ls, int pos)
{
	if(NULL == ls|| pos<1)
		return ERROR;

	Node *tmp = ls->head;

	//找到指定位置的前一个结点
	int i;
	for (i = 0; i < pos -1; i++)
	{
		tmp = tmp->next;
		//如果当前位置为空,或者下一个位置为空(没东西删)
		if (tmp == NULL || tmp->next == NULL)
		{
			printf("长度越界: %d\n", pos);
			return ERROR;
		}
	}

	Node *p = tmp->next;
	tmp->next = p->next;
	free(p);

	return TRUE;

```

#### 删除指定内容
```C
BOOL Delete_Data(List *ls, Data data)
{
	if (NULL == ls)
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
```

### 链表逆序
```C
BOOL Reverse(List *ls)
{
	// NULL ==ls || NULL == ls->head    链表不存在
	// NULL == ls->head->next           空链表
	// NULL == ls->head->next->next     只有一个结点的链表
	if (NULL == ls || NULL == ls->head 
		|| NULL == ls->head->next 
		|| NULL == ls->head->next->next)
		return ERROR;

	Node *pre = ls->head->next;    // 第一个结点
	Node *cur = pre->next;         // 第二个结点
	Node *tmp;                     // 保存当前结点的下一个结点
}
```

### 打印链表
```C
Print(List *ls)
{
	if (NULL == ls)
		return ERROR;
	 Node *tmp = ls->head->next;
	 while(tmp)
	 {
	 	printf("%-4d\n", tmp->data);
	 	tmp = tmp->next;
	 }
	 printf("\n");
}
```

### 销毁链表
```C
void Destroy(List *ls)
{
	if (NULL == ls)
		return ERROR;
	Node *tmp = ls->head;
	while (tmp->next)
	{
		Node *p = tmp->next;
		tmp = p->next;
		
	}
}
```
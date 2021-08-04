#include <stdio.h>
#include "LinkList.h"

int main()
{
	List *ls = CreateList();
	if (NULL == ls)
	{
		printf ("创建失败\n");
	}
	printf ("创建成功\n");
	
	int i;
	for (i = 0; i < 10; i++)
	{
		// Insert_Head(ls, i);
		Insert_Last(ls, i);
	}

	Display(ls);

	Insert_Pos(ls, 2, 100);
	Display(ls);
	
	
/*	Insert_Pos(ls, 1, 123);
	Display(ls);
	
		
	Insert_Pos(ls, 12, 456);
	Display(ls);
	
	Insert_Pos(ls, 3, 100);
	Display(ls);
	
	Insert_Pos(ls, 30, 100);
	Display(ls);
	
	printf ("------------------\n");
	Delete_Pos(ls, 1);
	Display(ls);
	
	Delete_Pos(ls, 12);
	Display(ls);
	
	
	Delete_Pos(ls, 2);
	Display(ls);
	
	Delete_Pos(ls, 11);
	Display(ls);
	
		
	Delete_Data(ls, 6);
	Display(ls);
	
	
	Reverse(ls);
	Display(ls);
	*/
	return 0;
}


























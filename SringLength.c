
# if 0
#include<stdio.h>
#include<string.h>
#define LEN 100
#endif

#if 0 
int main(void)
{
	char str[LEN];
	int count = 0;
	printf("Please input a string!\n");
	scanf(%s, str);

	int i;
	for (i = 0; (str[i] <= 'z' && str[i] >= 'a') || (str[i] >= '0' && str[i] <= '9'); i++)
	{
		count++;
	}

	printf("%d\n", count);
    return 0;
}
#endif

#if 0
int main(void)
{
	char str[LEN];
	int count = 0;
	printf("Please input a string!\n");
	scanf("%s", str);

	char *p = str;
	
	while (*p != '\0' )
	{
		p++;
		count++;
	}

	printf("%d\n", count);
    return 0;
}
#endif


# if 0
int main(void)
{
    char str[LEN];
    int cnt = 0;
    char ch;
    printf("Please input a string!\n");

    while((ch = getchar()) != '\n')
    {
        if((ch <= 'z' && ch >= 'a') || (ch <= '9' && ch >= '0'))		cnt++;
    }

        
    printf("%d\n", cnt);
    return 0;
}
#endif


// 编写计算字符串长度的函数
// 函数：低耦合 高内聚
// 理清函数逻辑：
// 1. 获取字符串
// 2. 遍历字符串获取字符串长度（指针）


#include <stdio.h>
#define STR "12345"

int my_strlen(char *str)
{
	if (NULL == str)
		return -1;

	int cnt = 0;
	char *ptr = str;
	while (*ptr != '\0')
	{
		cnt++;
		ptr++;
	}

	return cnt;
}


int main(int argc, char const *argv[])
{

	printf("Str len: %d\n", my_strlen(STR));
	/* code */
	return 0;
}



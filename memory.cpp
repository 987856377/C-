#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//				指针参数是传递内存
/*
	char * GetMemory(char *str,int size)
	{
		str = (char*)malloc(size*sizeof(char));
		return str;
	}
*/

void GetMemory(char **str, int size)
{
	*str = (char*)malloc(size*sizeof(char));
}

int main()
{
	char * str = NULL;
//	str = GetMemory(str,12);
	GetMemory(&str,12);
	strcpy(str,"hello");
	printf("%s\n",str);
	free(str);
	return 0;
}

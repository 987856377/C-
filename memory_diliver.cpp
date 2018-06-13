#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//				指针参数是传递内存
/*			操作形参指针 , 隐式地操作实参指针 
	char * GetMemory(char *str,int size)
	{
		str = (char*)malloc(size*sizeof(char));
		return str;
	}
*/
/*			使用指针的指针 , 直接对原指针操作 
	void GetMemory(char **str, int size)
	{
		*str = (char*)malloc(size*sizeof(char));
	}
*/
/*			使用指针的指针 , 有返回地直接对原指针操作 
	char * GetMemory(char **str, int size)
	{
		*str = (char*)malloc(size*sizeof(char));
		return *str;
	}
*/

//			使用指针的引用,有返回地直接对原指针进行操作 
char * GetMemory(char *&str, int size)
{
	str = (char*)malloc(size*sizeof(char));
	return str;
}

int main()
{
	char * str = NULL;
//	str = GetMemory(str,12);
//	GetMemory(&str,12);
//	str = GetMemory(&str,12);
	str = GetMemory(str,12);
	strcpy(str,"hello");
	printf("%s\n",str);
	free(str);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define RUN 1


//�ַ����������:
//�궨���е� # ������Ѹ������Ĳ���ת����һ���ַ��� 
#define VERSION(n) "Copy Right , Version "#n

// ## ���ڰѲ������ӵ�һ�� 
#define NUM(x,y,z) x##y##z
#define STR(j,k,l) j##k##l

int main() {

#ifdef DEBUG	// ���DEBUG�ѱ�#define�����,����������е�����
	printf("DEBUG has been defined!\n");
#endif // DEBUG


#if DEBUG	// DEBUG Ϊ��0, ����������е�����
	printf("Debugging...\n");
#elif RUN	// RUN Ϊ��0, ����������е�����
	printf("Running...\n");
#else 
	printf("Program Error! Ensure your Code!!!\n");
#endif // DEBUG


#undef DEBUG	
#ifndef DEBUG
	printf("DEBUG has been undefined!\n");
#endif // !DEBUG


	printf("%s\n", VERSION(1.0));

	printf("%d\n", NUM(1, 2, 3));

	//printf("%s\n", STR("Hello", " world", " !!!"));

	return 0;
}


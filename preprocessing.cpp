#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define RUN 1


//字符串化运算符:
//宏定义中的 # 运算符把跟在其后的参数转化成一个字符串 
#define VERSION(n) "Copy Right , Version "#n

// ## 用于把参数连接到一起 
#define NUM(x,y,z) x##y##z
#define STR(j,k,l) j##k##l

int main() {

#ifdef DEBUG	// 如果DEBUG已被#define定义过,则编译代码块中的内容
	printf("DEBUG has been defined!\n");
#endif // DEBUG


#if DEBUG	// DEBUG 为非0, 则编译代码块中的内容
	printf("Debugging...\n");
#elif RUN	// RUN 为非0, 则编译代码块中的内容
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


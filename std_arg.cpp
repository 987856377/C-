#include <iostream>
#include <cstdarg>
using namespace std;

int  add_nums(int count, ...){
	int result = 0;
	va_list args;				// 保存可变参数数据 
	va_start(args,count);		// 首个可变参数前紧接的具名参数 
	for(int i=0; i<count;i++){
		result+=va_arg(args,int);// va_list 中下个参数类型的表达式 
	}
	va_end(args);
	return result;
}

int add(int *a,int *b){
	return *a+*b;
}

int add0(int *&a,int *&b){
	return *a+*b;
}

int main(){
	
	int result = add_nums(5,1,2,3,4,5);
	printf("%d\n",result);
	
	int a = 2, b = 3;
	printf("%d\n",add(&a,&b));	// pass int
	
	int *q1 = &a, *q2 = &b;
	printf("%d\n",add0(q1,q2));	// pass a pointer to int
	return 0;
}

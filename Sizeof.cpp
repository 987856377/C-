/*
           sizeof和strlen的区别：		   
		   sizeof  计算的是空间 
		   strlen  计算的是长度 
		   对齐规则

一般来说，结构体的对齐规则是先按数据类型自身进行对齐，然后再按整个结构体进行对齐，对齐值必须是2的幂，
比如1，2， 4， 8， 16。如果一个类型按n字节对齐，那么该类型的变量起始地址必须是n的倍数。
比如int按四字节对齐，那么int类型的变量起始地址一定是4的倍数，比如0x0012ff60，0x0012ff48等。


数据自身的对齐
数据自身的对齐值通常就是数据类型所占的空间大小，比如int类型占四个字节，那么它的对齐值就是4

整个结构体的对齐
整个结构体的对齐值一般是结构体中最大数据类型所占的空间，比如下面这个结构体的对齐值就是8，因为double类型占8个字节。
*/
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
typedef struct info{
	int data;
	struct info *next;
}info; 
int main()
{
	char a[88]="jfha";
	int *p = (int*)malloc(10*sizeof(int));
	int *q = new int;
	cout<<sizeof(q)<<endl;
	cout<<sizeof(p)<<endl; 
	cout<<"sizeof: "<<sizeof(a)<<endl;
	cout<<"strlen: "<<strlen(a)<<endl;
	cout<<sizeof(int)<<endl; 
	cout<<"info structure: "<<sizeof(info)<<endl;
	return 0;
}

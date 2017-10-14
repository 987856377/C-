/*
						const_cast转换
    该转换的作用是移除变量的const属性或者volatile属性
移除const限定：
    对于const变量我们不能修改它，但是如果我们非要修改它，那我们直接使用const_cast转换就可以了。
	但是需要注意的是const_cast转换符不该用在数据对象上，
		因为这样的转换得到的两个变量/对象没有相关性，只有用于指针或者引用，
		让变量指向同一个地址才是最终的解决方案。

这里改变的值不是 i 的值，只是将 i 的值去除const属性后获得的值，
在C++中，const就是const，不管怎么操作，它的值就是不变。

const_cast<type_id> (expression) 
该运算符用来修改类型的const或volatile属性。除了const 或volatile修饰之外， type_id和expression的类型是一样的。 
一、常量指针被转化成非常量指针，并且仍然指向原来的对象； 
二、常量引用被转换成非常量引用，并且仍然指向原来的对象； 
三、常量对象被转换成非常量对象。  
四、type_id 必须为指针或引用 

*/ 
#include<iostream>
using namespace std;
int main(){
	const int i=9;
	cout<<" i的值为:"<<i<<endl;
	
	//验证指针 
	const int *p=&i;
	cout<<"\n 指针p的地址为:"<<p<<"  指向的值为:"<<*p<<endl; 
	//验证指向指针的指针 
	const **P=&p;
	cout<<"\n P的地址为:"<<P<<"   *P的地址为:"<<*P<<"   **P的指向为:"<<**P<<endl;
	
	const int *const_p=&i;
	int *temp_p=const_cast<int*>(const_p);	//利用 const_cast 突破 const 限制 
	*temp_p=8;            // 修改内存地址上的值，绝对不是对const数据 i 进行重新赋值的操作，i 的值还是 9 
	cout<<"\n temp_p 的地址为:"<<temp_p<<"   *temp_p 的值为:"<<*temp_p<<endl;	
	cout<<"\n 突破const限制后，其地址所存的值为："<<*p<<endl; 
	cout<<"\n i 的地址为:"<<&i<<"   i 的值为:"<<i<<endl;
	
	return 0;
} 

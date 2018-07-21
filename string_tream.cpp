/*

	register 寄存器变量,decltype  推断传入类型,auto  自动判断变量类型
	volatile  “直接存取原始内存地址”,直接使用变量，不经过编译器优化, extern  声明变量或函数调用自外部文件 
	 
	
				全局变量、静态全局变量、静态局部变量和局部变量的区别
				
变量可以分为：
		全局变量、静态全局变量、静态局部变量和局部变量。
按存储区域分:
		全局变量、静态全局变量和静态局部变量都存放在内存的静态存储区域，局部变量存放在内存的栈区。
按作用域分:
		全局变量在整个工程文件内都有效；
		静态全局变量只在定义它的文件内有效；
		静态局部变量只在定义它的函数内有效，并且程序仅分配一次内存，函数返回后，该变量不会消失；
		局部变量在定义它的函数内有效，但是函数返回后失效。


		
全局变量和静态全局变量储方式上相同点：		
	全局变量(外部变量)的说明之前再冠以static 就构成了静态的全局变量。
	全局变量本身就是静态存储方式，静态全局变量当然也是静态存储方式。

这两者的区别:
	在于非静态全局变量的作用域是整个源程序，
		当一个源程序由多个源文件组成时，
		非静态的全局变量在各个源文件中都是有效的。
	而静态全局变量则限制了其作用域，
		即只在定义该变量的源文件内有效，在同一源程序的其它源文件中不能使用它。
		由于静态全局变量的作用域局限于一个源文件内，
		只能为该源文件内的函数公用，因此可以避免在其它源文件中引起错误。
		
从以上分析可以看出，把局部变量改变为静态变量后是改变了它的存储方式即改变了它的生存期。
把全局变量改变为静态变量后是改变了它的作用域，限制了它的使用范围。

static函数与普通函数作用域不同，只在定义该变量的源文件内有效。
	只在当前源文件中使用的函数应该说明为内部函数(static)，内部函数应该在当前源文件中说明和定义。
	对于可在当前源文件以外使用的函数，应该在一个头文件中说明，要使用这些函数的源文件要包含这个头文件。
static全局变量与普通的全局变量有什么区别：
	static全局变量只初使化一次，防止在其他文件单元中被引用;
static局部变量和普通局部变量有什么区别：
	static局部变量只被初始化一次，下一次依据上一次结果值；
static函数与普通函数有什么区别：
	static函数与普通函数作用域不同，只在定义该变量的源文件内有效；
全局变量和静态变量如果没有手工初始化，则由编译器初始化为0。局部变量的值不可知。
	
*/ 
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<sstream>
using namespace std;

//  构建模板 ， 将 T 类型的数据写入到串流中，转化为字符串返回 
template<class T>
string &toString(string &str,const T &num){         
	ostringstream os;
	os<<num;
	str=os.str();
	return str;
}

char *def(){
	char *p="hello world";
	return p;
	
}
int main(){	
	string s;
	s=toString(s,1351234245234);  //调用转化模板 
	cout<<s<<endl;
	
	//写入到字符串流中 
	string str,str4,str5;
	stringstream ios;
	ios<<"hello ";     
	ios<<"world";
	str = ios.str();
	//cout<<str.append("JSDHKJHFAJDHA")<<endl;
	cout<<"写入到字符串流中的数据为："<<str<<endl;
	
	//从字符串流中读取 (空格为读取每个字符串的结束标志) 
	ios.str(str);
	ios>>str4;        
	cout<<"从字符串流中读取的数据为："<<str4<<endl;
	ios>>str5;
	cout<<"从字符串流中读取的数据为："<<str5<<endl;
	
	istringstream is;
	string str1="jdhakjh 4646",str2,str3;
	is.str(str1);		//读取字符串 str1 
	
	is>>str2;
	cout<<str2<<endl;
	is>>str3;
	cout<<str3<<endl;
	
	//  测试字符串的返回类型 
	char *p;
	p=def();
	cout<<p<<endl;
	for(int i=0;*(p+i)!=NULL;i++){
		cout<<*(p+i)<<" ";
	}

	return 0;
}

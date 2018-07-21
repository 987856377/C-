/*
							static_cast转换							
    static_cast<type-id>(expression)
    该运算符把expression转换成type-id类型的，但是该转换是不安全的，因为没有进行类型安全检查
    staic_cast不仅可以作用于指针和引用，还可以作用于基本数据对象
用法如下：
    1 基类和子类之间指针或者引用的转换
    上行转换(子类的指针或者引用转换成基类的)是安全的
    下行转换(基类的指针或者引用转换成子类的)是不安全的
    
*/

#include<iostream>
using namespace std;
class Parents{
	public:
		virtual ~Parents(){
		}
	private:
};

class Children:public Parents{
	public:
		
	private:
};
int main(){
	//  <基类和派生类之间的转换>
	Children *son = new Children();
	Parents *father = static_cast<Parents*>(son);//安全的，派生类指针转化为基类指针
	Parents *mother = new Parents();
	Children *daughter = static_cast<Children*>(mother);//不安全的，基类指针转化为派生类指针 
	
	//  <基本数据类型之间的转换>  是不安全的 
	int i = 9;
	float j = 8;
	cout<<i<<"  "<<static_cast<float>(i)/4<<endl;
	cout<<j<<"  "<<static_cast<int>(j)/3<<endl;
	return 0;
} 

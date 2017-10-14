/*

通过基类的指针来删除派生类的对象时，基类的析构函数应该是虚的。否则其删除效果将无法实现。

原因： 
	在公有继承中，基类对派生类及其对象的操作，只能影响到那些从基类继承下来的成员。
	如果想要用基类对非继承成员进行操作，则要把基类的这个操作（函数）定义为虚函数。
	那么，析构函数自然也应该如此：如果它想析构子类中的重新定义或新的成员及对象，当然也应该声明为虚的。
注意： 
	如果不需要基类对派生类及对象进行操作，则不能定义虚函数（包括虚析构函数），因为这样会增加内存开销。

总结：只要一个类要作为其他类的基类, 那么它就一定有虚函数, 
	  只要一个类中有虚函数, 那么它的析构函数就一定也要是虚的,
	  否则可能造成内存泄露 
*/ 

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class Test{
	
	public:
		Test(string name,int age):name(name),age(age){
			cout<<"import test constructor."<<endl;
		}
		
		Test(const Test &t):name(t.name),age(t.age){
			cout<<"import test copy constructor."<<endl;
		}
		
		Test &operator=(const Test &t){
		
		}
		
		virtual ~Test(){     //将基类的析构函数声明为虚的（不加 virtual 则在主函数的语句则产生内存泄漏） 
			cout<<"import test destructor."<<endl;
		}
	
	private:
		string name;
		int age;
	
};

class Test1:public Test{
	public:
		Test1(string name,int age,char sex):Test(name,age),sex(sex){
			cout<<"import test1 constructor."<<endl;
		}
		
		~Test1(){
			cout<<"import test1 destructor."<<endl;
		}
		
	private:
		char sex;	
};

int main(){
	
	Test *p = new Test1("daqiang",18,'m');//基类Test构造函数和析构函数已调用，派生类Test1只调用了构造函数， 
	delete p;                             //没有调用析构函数 ，new出来的内存没有及时回收造成内存泄露 
	return 0;
}

/*

虚机制:
为每个含有虚函数的类或包含有虚函数的类派生类维护一个VTABLE,在VTABLE中,编译器放置特定类的虚函数的地址;
在每个带有虚函数(一个或多个)的类中,编译器秘密的放置一个指针VPTR(隐藏的类成员),指向这个VTABLE;
当多态调用时,编译器静态地获取VPTR,并在VTABLE中查找函数的地址并调用代码;
基类中声明了虚函数，派生类中无论是否说明，同原型函数都自动为虚函数。

基类指针可以指向派生类对象，
	但指向后基类指针只能使用基类的数据成员或函数，
	不能使用派生类继承下来的的数据成员或函数，
	（所以我们需要虚函数和纯虚函数，实现多态）

	带纯虚函数的类叫虚基类，这种基类不能直接生成对象，而只有被继承，并重写其虚函数后，才能使用。这样的类也叫抽象类。
	虚函数是为了继承接口和默认行为
	纯虚函数只是继承接口，行为必须重新定义
派生类指针不能指向基类对象	 

派生类在内存中包括两个部分：一部分是父类的部分，另一部分才是对象本身扩展的。
	首先把派生类地址付给基类指针是符合逻辑的，
	因为派生类包括基类的部分，派生类指针转换为基类指针后，基类指针指向派生类中基类的部分；
	另一方面设计为派生类对象地址可以付给基类指针这一特性是实现多态的基础。
	基类和派生类在指针和引用的问题上，这个是和虚函数（virtual）关联在一起实现运行时的多态。

静态绑定：绑定的是静态类型，所对应的函数或属性依赖于对象的静态类型，发生在编译期；
	静态类型转换：static_cast可以实现子类到基类的安全转换，但是不能实现基类到子类的安全转换
动态绑定：绑定的是动态类型，所对应的函数或属性依赖于对象的动态类型，发生在运行期；
	动态类型转换：dynamic_cast被用来执行从基类到子类的安全转换，
				  转换的类类型(基类)必须有虚函数，否则不能使用dynamic_cast
从上面的定义也可以看出，非虚函数一般都是静态绑定，而虚函数都是动态绑定（如此才可实现多态性）。	
*/ 

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
/*
class test{
	virtual void shout() = 0;
};
*/
class animal{// : public test{
	public:
	    animal(string ani):ani_name(ani) {
	    	cout<<"animal"<<endl;
		}
		animal(animal &anim){
			ani_name=anim.ani_name;
		}
		virtual void shout(){
			cout<<ani_name<<" is shouting..."<<endl;
		}
		void help(){
			cout<<"help............"<<endl; 
		}
		virtual ~animal(){
			cout<<"~animal"<<endl;
		}
		
	private:
	    string ani_name;	
};

class dog1:virtual public animal{
	public:
		dog1(string ani,string str1):animal(ani),dog1_name(str1){
			cout<<"dog1"<<endl;
		}
		virtual void shout(){
			cout<<dog1_name<<" is shouting..."<<endl;
		}
	    virtual ~dog1(){
	    	cout<<"~dog1"<<endl;
		}
	protected:
		string dog1_name;
};

class dog2:virtual public animal{
	public:
		dog2(string ani,string str2):animal(ani),dog2_name(str2){
			cout<<"dog2"<<endl;
		}
		virtual void shout(){
			cout<<dog2_name<<" is shouting..."<<endl;
		}
		virtual ~dog2(){
	    	cout<<"~dog2"<<endl;
		}
	protected:
		string dog2_name;
};

class baby:public dog1,public dog2{
	public:
		baby(string ani,string str1,string str2,string str3):animal(ani),dog1(ani,str1),dog2(ani,str2),str(str3){
			cout<<"baby"<<endl;
		}
		void shout(){
			cout<<dog2_name<<" & "<<str<<" is shouting..."<<endl;
		}
		static void shout1(){
			cout<<" is shouting..."<<endl;
		}
		~baby(){
	    	cout<<"~baby"<<endl;
		}
	private:
		string str;
};
/*
	函数模板 
*/ 
//template<class T>    // 利用模板函数进行类对象成员函数的调用 
void ani_shout(animal &t){    // 利用接口形式进行类对象成员函数调用 

	t.shout();				  // shout() 是声明 virtual 的函数 ，而 animal 是基类
							  //动态联编时会自动调用传入对象的成员函数 
}

int main(){
	baby b("animal","dog1","dog2","baby"),*b1;
	b.shout();
	b.shout1();
	b.help();					// 派生类调用基类函数 
	
	animal ani("ani"),*q;
	ani.shout();
	q=&b;
	q->shout();
	q->help();
	
	dog1 d1("animal","dog1");
	d1.shout(); 
		
	ani_shout(b);    			//使用函数模板 
	cout<<"address: "<<&ani<<endl;
	cout<<"address: "<<&b<<endl;
	cout<<"address: "<<&d1<<endl;

	return 0;
}

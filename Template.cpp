#include<iostream>
using namespace std;
/*template <class T> 
class Test  
{  
public:    
    Test(T val):a(val){} 
	~Test(){} 	
    T show(){return a;}  
  
private:  
    T a;  
  
};  
  
int main()  
{  
    Test<int> test(5);  
    cout<<test.show()<<endl;  
  
    Test<string> test1("abc");   
    cout<<test1.show()<<endl;  
    return 0;  
} */

template <typename T>
class myTemplate
{
	public:
		myTemplate(T a1,T b1):a(a1),b(b1){}
		~myTemplate(){}		
		T add()
		{
			return a+b;
		}
		T sub()
		{
			return a-b;
		}
		T mul()
		{
			return a*b;
		}
		T div()
		{
			return a/b;
		}
	private:
		T a;
		T b;
};
int main()
{
	cout<<"int type:"<<endl;
	myTemplate<int> temp(8,4);
	cout<<"两数之和："<<temp.add()<<endl;
	cout<<"两数之差："<<temp.sub()<<endl;
	cout<<"两数之积："<<temp.mul()<<endl;
	cout<<"两数之商："<<temp.div()<<endl;
	
	cout<<endl<<"double type:"<<endl;
	myTemplate<double> temp1(3.2,4.2);
	cout<<"两数之和："<<temp1.add()<<endl;
	cout<<"两数之差："<<temp1.sub()<<endl;
	cout<<"两数之积："<<temp1.mul()<<endl;
	cout<<"两数之商："<<temp1.div()<<endl;
	return 0;
} 


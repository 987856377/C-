/*
 *                                 关于析构函数  ~test();
 *             
 *
 *
*/


#include<iostream>
using namespace std;
class test{
	public:
		test(int a1,int b1):a(a1),b(b1){
			cout<<"调用含参的构造函数"<<endl; 
		}
		
		
		test(){
			cout<<"调用不含参数的构造函数"<<endl; 
			int a1;int b1;
			cin>>a1>>b1;
			a=a1;
			b=b1;
		}
		
		
		
		~test(){ 
		    cout<<"已调用析构函数"<<endl;//   析构函数如果在类中写为   ~test();   则会出现错误 
		}						    	//    原因：  这样写表示在类中就调用自身析构函数，函数返回出错 
		                               //     改进方法： 如果非要这样写，须在类外实现其函数体
		                              //      例：  test::~test()  {   ... body ...   } 
		void show(){
			cout<<"a = "<<a<<"  b = "<<b<<endl;
		}
	private:
		int a;
		char b;
};
int main(){
	
	test t1(1,'b');  //含参数的构造函数 
	t1.show();
	
	return 0;
}

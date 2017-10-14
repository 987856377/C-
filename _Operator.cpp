/*

	对于赋值运算符重载函数，一定要先检查是否是自赋值，如果是，直接return *this。

*/
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class Bitmap{
	
};

class Widget{
	public:
		Widget(){
			cout<<"Import constructor"<<endl;
		}
		
		//用引用: 可以避免在函数调用时对实参的一次拷贝,直接使用传进来的参数,提高效率。
		Widget &operator=(const Widget &rfc);
		
		~Widget(){
			cout<<"Import destractor"<<endl; 
		} 
		
	private:
		Bitmap *pb;
};

Widget &Widget::operator=(const Widget &rfc){
	if(this==&rfc)			//避免自赋值
		return *this;
		
	//如果忽略 if语句 ，就是不安全的 operator= 实现方式	
	delete pb;					//停止使用当前的bitmap	 
	pb = new Bitmap(*rfc.pb);	// 使用 rfc's bitmap 副本 
	/*
	这里的自我赋值的问题是，operator= 函数内的 *this(赋值的目的端)和 rfc 有可能是同一个对象。
	如果真是如此，delete 就不只是销毁当前对象的 bitmap ，它也销毁了 rfc 的 bitmap。
	在函数末尾，Widget----它原本不该被自我赋值动作改变的----发现自己持有一个指针只想一个已被删除的对象 
	*/ 
	return *this; 			//返回当前对象
	/*
	这个版本仍然存在异常方面的麻烦。
	如果 "new Bitmap" 导致异常(不论是分配内存不足或是因为 Bitmap 的 copy构造函数异常)，
	Widget最终会持有一个指针指向一块被删除的Bitmap，这样的指针有害。
	你无法安全的删除他们，甚至无法安全的读取他们。 
	*/
}

/*
		//  制作副本技术 
Widget &Widget::operator=(const Widget &rfc){
	Bitmap *pOrig = pb;		//记住原先的pb 
	pb = new Bitmap(*rfc.pb); //令 pb 指向 *pb 的一个副本 
	delete pOrig;			// 删除原先的 pb 
	return *this; 			//返回当前对象 
	
	现在，如果 "new Bitmap" 抛出异常，pb(及栖身的那个 Widget )，保持原状。
	即使没有自我赋值测试，这段代码还是能够处理自我赋值，
	因为我们对原 bitmap 做了一个副本，删除原 bitmap ，然后指向新制造的那个副本。 
}
*/

/*
		//  copy and swap 技术 
class Widget{
	public:
		. . . 
		void swap(Widget &rfc){			//交换 *this 和 rfc 的数据 
			. . .
		}
		
		Widget &operator=(const Widget &rfc);
		
		. . . 
	
	private:
		Bitmap *pb;
};

Widget &Widget::operator=(const Widget &rfc){
	Widget temp(rfc); 	 	//为 rfc 制作一个副本 
	swap(rfc); 				//将 *this 数据和上述副本的文件做交换  
	return *this; 			//返回当前对象 
	优点：伶俐巧妙
	缺点：牺牲了清晰性 
}
*/ 

int main(){
	Widget w;
	Widget v;
	w.operator=(w);
	
	// test
	string a="hello",b=" world";
	a.operator+=(b);
	cout<<a<<endl;
	a.operator=("bye bye");
	cout<<a<<endl;
	a.operator+=(b);
	cout<<a<<endl;
	return 0;
}

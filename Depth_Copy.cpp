/*

浅拷贝：也就是在对象复制时，只是对对象中的数据成员进行简单的赋值，
		如果对象中存在动态成员，即指针，拷贝后两个指针指向同一个内存空间; 
		进行对象析构时，会造成释放同一内存空间2次，导致内存泄露。
		
深拷贝：对于深拷贝，针对成员变量存在指针的情况，不仅仅是简单的指针赋值，而是重新分配内存空间;
		使指针成员所指内存不同
		
总结：浅拷贝只是对指针的拷贝，拷贝后两个指针指向同一个内存空间，
	深拷贝不但对指针进行拷贝，而且对指针指向的内容进行拷贝，经深拷贝后的指针是指向两个不同地址的指针。
*/
#include<iostream>
#include<cstring> 
#include<cstdlib>
using namespace std;
 
class test{
	
	public :
		test(char *str1):str(str1){
			
			cout<<str<<endl<<"import constructor..."<<endl;
		}
		test(test &t){		//	深拷贝 
			int len = strlen(t.str);
			//str = new char(sizeof(len));
			str = (char*)malloc(sizeof(char)*len);
			memcpy(str,t.str,len);
			cout<<str<<endl<<"import copy constructor..."<<endl;
		}
		void shout(){
			cout<<"0..0.."<<endl; 
		}
		~test(){
			cout<<"import  destructor..."<<endl;
		}
	private:
		char *str;
};
int main(){
	test t1("halkjsd");
	t1.~test();
	test t2(t1);
	t2.shout();
	
	// test
	int *a = new int[10];
	for(int i=0;i<10;i++){
		a[i]=i;
		cout<<a[i]<<"  ";
	}
	cout<<endl<<sizeof(a)<<endl;
	delete(a);
	
	int *b=(int*)malloc(sizeof(int)*10);
	for(int i=0;i<10;i++){
		b[i]=i;
		cout<<b[i]<<"  ";
	}
	cout<<endl<<sizeof(b)<<endl;
	free(b);
	return 0;
}

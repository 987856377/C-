#include<iostream>
using namespace std;

/*void swap(int &a,int &b){  //地址的交换 
	int temp=a;a=b;b=temp;
}*/

/*void swap(int *a,int *b){    //指针的地址交换 
	int *temp=a;a=b;b=temp;
}*/

void swap(int *&a,int *&b){    //指针指向的地址交换 
	int *temp=a;a=b;b=temp;
}

int main(){
	int a=1,b=2;
	cout<<a<<"   "<<b<<endl;
	swap(a,b);
	cout<<a<<"   "<<b;
	return 0;
}

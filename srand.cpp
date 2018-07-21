#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
	//srand(time(0));      //  设置随机种子  每次产生不同的随机数 
	//int x=x+rand()%101;
	//cout<<x<<endl;
	
	cout<<rand()<<endl;     // 每次只会产生同一个随机数 
	return 0;
} 

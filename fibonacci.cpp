#include<iostream>
using namespace std;

//               1!+2!+3!+...+n! 
     
/*          只有递归深度在一个可控的范围内，
	        那么整个递归过程都是可控的,
			如果递归深度超过了一定限度，
			会造成堆栈溢出， 
			数据数据是去真实性 	 
*/ 
int iterate(int n)
{
	if(n==1)
		return 1;
	else
		return n*iterate(n-1);
} 
int main()
{
	int m,counter=0;
	cin>>m;
	//cout<<iterate(m)<<endl;    求 m 的阶乘 
	for(int i = 1;i<=m;i++)
		counter+=iterate(i);
	cout<<counter<<endl;
	return 0;
}

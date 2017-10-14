#include"iostream"
#include"conio.h"
using namespace std;
int main()
{
	char password[20];
	int i=0;
	char ch;
	while((ch=getch())!='\r')
	{
		if(ch!='\b')
		{
			password[i]=ch;
			putch('*');
			i++;
		}
		else
		{
			i--;
			cout<<"\b \b";
			password[i]=0;
		}
		if(i>=20)break;
	}
	cout<<endl<<password;
	return 0;
} 
 

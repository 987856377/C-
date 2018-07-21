#include <iostream>
#include <cstdarg>
using namespace std;

int  add_nums(int count, ...){
	int result = 0;
	va_list args;				// ����ɱ�������� 
	va_start(args,count);		// �׸��ɱ����ǰ���ӵľ������� 
	for(int i=0; i<count;i++){
		result+=va_arg(args,int);// va_list ���¸��������͵ı��ʽ 
	}
	va_end(args);
	return result;
}
int main(){
	int result = add_nums(5,1,2,3,4,5);
	printf("%d\n",result);
	return 0;
}

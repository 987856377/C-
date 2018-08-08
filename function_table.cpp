#include <iostream>
#include <unistd.h>
using namespace std;

// 创建一些解释器或表处理程序时用到 
#define DF(N) void N() { cout << "Function " #N " Called..." << endl; }

DF(a);DF(b);DF(c);DF(d);DF(e);DF(f);DF(g);

void (*function_table[])() = { a, b, c, d, e, f, g };

void load_GUI(){
	cout << "loading...." << endl;
	sleep(3); 
	cout << "loading success"<<endl;
} 

int main(int argc, char **argv){
	
//	void (*pLoad)() = load_GUI; 声明并初始化函数指针
	void (*pLoad)(); 	// 声明函数指针 
	pLoad = load_GUI;	// 初始化函数指针 
	(*pLoad)();
	
	while(1){
		cout << "Press a key from 'a' to 'g' or 'q' to quit" << endl;
		char c, cr;
		cin.get(c);
		cin.get(cr);
		if(c=='q'){
			break;
		} 
		if(c<'a'||c>'g'){
			continue;
		}
		(*function_table[c-'a'])();
	}
	return 0;
}

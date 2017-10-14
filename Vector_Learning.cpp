#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<list>
#include<memory>
#include<cstdlib>
using namespace std;
int main(){
	vector<string> v1;
	string str = "hello world;";
	str.append(2,'J');
	cout<<str<<endl;
	str.assign("My first program.");    //字符串替换 
	cout<<str<<endl; 
	str.replace(3,5,"second");
	cout<<str<<endl; 
	
	v1.push_back("hello");
	v1.push_back("world");
	for(vector<string>::iterator it = v1.begin();it!=v1.end();++it){   //利用迭代器，遍历容器中的内容 
		cout<<*it<<endl;
	}
	//如果需求大小大于当前容量，reserve 至少分配与需求一样大的空间（可能更大） 
	cout<<v1.size()<<endl;		//显示已经保存元素的数目 
	cout<<v1.capacity()<<endl;	//容器在不扩张内存空间的情况下可以容纳多少元素 
	v1.push_back("odbc");		//容器中的数据超过容器的容量，容器会成倍增长容器的容量， 
	v1.reserve(3);			//允许通知容器它应该保存多少元素 
	cout<<v1.capacity()<<endl;
	
	for(int i=0;i<v1.size();i++){
		cout<<v1[i]<<" ";
	}
	
	int i=0;
	while(i<v1.size()){
		cout<<v1[i++]<<" ";
	}

	return 0;
}

#include<iostream>
#include<string.h>
using namespace std;
int kmpIndex(char S[],char T[]){
    int next[strlen(T)]; 
	int i=0,j=-1;
	next[0]=-1;
	while(i<strlen(T)){
		if(j==-1||T[i]==T[j]){
			i++;j++;
			if(T[i]!=T[j]){
				next[i]=j;
			}
			else{
				next[i]=next[j];
			}
		}
		else{
			j=next[j];
		}
	}
	
	int m=0,n=0;
	while(m<strlen(S)&&n<strlen(T)){
		if(n==-1||S[m]==T[n]){
			m++;
			n++;
		}
		else{
			n=next[n];
		}		    
	}
	if(n<strlen(T))
	    return -1;
	else 
	    return m-strlen(T);
}

int main(){
	char S[] ="bbcabcdababcdabcdabde";
	char T[] ="abcdabde";
	cout<<"匹配的起始点下标为："<<kmpIndex(S,T); 
	return 0; 
} 

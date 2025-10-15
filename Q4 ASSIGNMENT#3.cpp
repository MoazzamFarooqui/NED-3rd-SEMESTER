#include<bits/stdc++.h>
using namespace std;

void reverse_string(string &str,int start,int end){
	if(start>=end){
		return;
	}
    char temp=str[start];
    str[start]=str[end];
    str[end]=temp;
    reverse_string(str,start+1,end-1);
}

int main(void){
	string str;
	cout<<"ENTER A STRING:";
	cin>>str;
	reverse_string(str,0,str.length()-1);
	cout<<"REVERSED STRING:"<<str;
	return 0;
}




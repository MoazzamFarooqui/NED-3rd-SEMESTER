#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string&str,int start,int end){
	if(start>=end){
		return true;
	}
	if(str[start]!=str[end]){
		return false;
	}
	return is_palindrome(str,start+1,end-1);
}

int main(void){
	string str;
	cout<<"ENTER A STRING:";
	cin>>str;
	if(is_palindrome(str,0,str.length()-1)){
		cout<<"TRUE!"<<endl;
	}
	else{
		cout<<"FALSE!"<<endl;
	}
	return 0;
}




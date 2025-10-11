#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string m){
	stack<char>s;
	for(char ch:m){
		s.push(ch);
	}
	string reversed="";
	while(!s.empty()){
		reversed+=s.top();
		s.pop(); 
	}
	return m==reversed;
}

int main(void){
	string input;
	cout<<"ENTER STRING:"<<endl;
	cin>>input;
	if(ispalindrome(input))
	  cout<<"IT IS A PALINDROME!"<<endl;
	else
	  cout<<"IT IS NOT A PALINDROME!"<<endl;
	return 0;
}
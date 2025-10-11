#include<bits/stdc++.h>
using namespace std;

string f(string m){
	stack<char>s;
	for(char ch:m){
		if(ch=='#')
		  if(!s.empty())s.pop();
		else
		  s.push(ch);
	}
	
	string result="";
	while(!s.empty()){
	   result=s.top()+result;
	   s.pop();
   }
   return result;
}

bool compare(string s,string t){
	return f(s)==f(t);
}

int main(void){
	string s1="ab#c";
	string t1="ad#c";
	
	string s2="a#c";
	string t2="b";
	
	cout<<boolalpha;
	cout<<"EXAMPLE 1:"<<compare(s1,t1)<<endl;
	cout<<"EXAMPLE 2:"<<compare(s2,t2)<<endl;
	return 0;
}






#include<bits/stdc++.h>
using namespace std;

int sum_of_digits(int n){
	if(n==0){
		return 0;
	}
	else{
		return (n%10)+sum_of_digits(n/10);
	}
}

int main(void){
	int n;
	cout<<"ENTER A NUMBER:";
	cin>>n;
	cout<<"SUM OF DIGITS IS:"<<sum_of_digits(n)<<endl;
	return 0;
}



#include<bits/stdc++.h>
using namespace std;

int sum_of_natural_nums(int n,int total){
	if(n==0){
		return total;
	}
	return sum_of_natural_nums(n-1,total+n);//The recursive call is the last operation in the function no further computation
	//happens after this call
}

int main(void){
	int n;
	cout<<"ENTER A NUMBER:"; 
	cin>>n;
	cout<<"SUM IS:"<<sum_of_natural_nums(n,0);
	return 0;
}




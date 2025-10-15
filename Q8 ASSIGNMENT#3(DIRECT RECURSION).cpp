#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
	if(n==0 || n==1){
		return 1;
	}
    else{
    	return n*factorial(n-1);//Direct Recursion(Function calls itself directly)
	}
}

int main(void){
    int n;
    cout<<"ENTER A NUMBER:";
    cin>>n;
    cout<<"FACTORIAL OF "<<n<<" IS "<<factorial(n);
    return 0;
}




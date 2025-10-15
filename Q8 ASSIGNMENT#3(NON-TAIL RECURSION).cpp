#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
	if(n==0 || n==1){
		return 1;
	}
    else{
    	return n*factorial(n-1); //Recursive call is NOT the last operation because we multiply n after the call 
		//this makes it a non-tail recursion
	}
}

int main(void){
    int n;
    cout<<"ENTER A NUMBER:";
    cin>>n;
    cout<<"FACTORIAL OF "<<n<<" IS "<<factorial(n);
    return 0;
}



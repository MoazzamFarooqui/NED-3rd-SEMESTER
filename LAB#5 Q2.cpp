#include<bits/stdc++.h>
using namespace std;

int findthewinner(int n,int k){
	int winner=0;
	for(int i=2;i<=n;i++){
		winner=(winner+k)%i;
	}
	return winner+1;
}

int main(void){
	int n;
	int k;
	cout<<"ENTER NUMBER OF FRIENDS:"<<endl;
	cin>>n;
	cout<<"ENTER THE NUMBER THAT YOU COUNTED(K):"<<endl;
	cin>>k;
	int result;
	result=findthewinner(n,k);
	cout<<"THE WINNER IS FRIEND "<<result<<endl;
	return 0;
}
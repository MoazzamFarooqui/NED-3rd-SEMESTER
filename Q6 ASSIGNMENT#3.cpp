#include<bits/stdc++.h>
using namespace std;

void towerofhanoi(int n,char fromrod,char torod,char helperrod){
	if(n==1){
		cout<<"MOVE DISK "<<n<<" FROM "<<fromrod<<" TO "<<torod<<endl;
		return;
	}
	
	towerofhanoi(n-1,fromrod,helperrod,torod);
	
	cout<<"MOVE DISK "<<n<<" FROM "<<fromrod<<" TO "<<torod<<endl;
	
	towerofhanoi(n-1,helperrod,torod,fromrod);
}

int main(void){
	int n;
	cout<<"ENTER NUMBER OF DISKS:";
	cin>>n;
	
	towerofhanoi(n,'A','C','B');
	return 0;
}



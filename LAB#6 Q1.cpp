#include<iostream>
using namespace std;

void bubblesort(int arr[],int n){
	bool swapped;
	for(int i=0;i<n-1;i++){
		swapped=false;
	for(int j=0;j<n-1-i;j++){
		if(arr[j]>arr[j+1]){
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			swapped=true;
		}
	}
	if(swapped==false){
		break;
	}
	}
}

int maxtoys(int arr[],int n,int k){
	bubblesort(arr,n);
	int count=0;
	int sum=0;
	for(int i=0;i<n;i++){
		if(sum+arr[i]<=k){
			sum=sum+arr[i];
			count=count+1;
		}
		else{
			break;
		}
	}
		return count;
}

int main(void){
	int arr[]={1,12,5,111,200,1000,10};
	int n=7;
	int k=50;
	int result=maxtoys(arr,n,k);
	cout<<"YOU CAN BUY "<<result<<" TOYS"<<endl;
	return 0;
}
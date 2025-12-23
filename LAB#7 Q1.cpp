#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}

void quicksort(int arr[],int n){
	int stk[n];
	int top=-1;
	stk[++top]=0;
	stk[++top]=n-1;
	while(top>=0){
		int end=stk[top--];
		int start=stk[top--];
		int pivotindex=partition(arr,start,end);
		
		if(pivotindex-1>start){
			stk[++top]=start;
			stk[++top]=pivotindex-1;
		}
		if(pivotindex+1<end){
			stk[++top]=pivotindex+1;
			stk[++top]=end;
		}
	}
}

int main(void){
    int arr[]={10,7,8,9,1,5};
    int n=6;

    quicksort(arr,n);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
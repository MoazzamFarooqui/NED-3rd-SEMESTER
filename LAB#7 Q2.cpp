#include<iostream>
using namespace std;

void merge(int arr[],int left,int mid,int right){
	int n1=mid-left+1;
	int n2=right-mid;
	int leftarr[n1],rightarr[n2];
	
	for(int i=0;i<n1;i++){
		leftarr[i]=arr[left+i];
	}
	for(int j=0;j<n2;j++){    
		rightarr[j]=arr[mid+1+j];
	}
	
	int i=0,j=0,k=left;
	while(i<n1 && j<n2){ 
		if(leftarr[i]<=rightarr[j]){
			arr[k++]=leftarr[i++];
		}
		else{
			arr[k++]=rightarr[j++];
		}
	}
	while(i<n1){
		arr[k++]=leftarr[i++];
	}
	while(j<n2){
		arr[k++]=rightarr[j++];
	}
}

void mergesort(int arr[],int n){
	for(int size=1;size<n;size*=2){
		for(int start=0;start<n-1;start+=2*size){
			int mid=min(start+size-1,n-1);
			int end=min(start+2*size-1,n-1);
			merge(arr,start,mid,end);
		}
	}
}

int main(void){
    int arr[]={12,11,13,5,6,7};
    int n=6;
    
    mergesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}





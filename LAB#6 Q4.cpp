#include<iostream>
using namespace std;

void flip(int arr[],int k){
    int start=0;
    int end=k-1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

int findMaxIndex(int arr[],int n){
    int maxIndex=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[maxIndex]){
            maxIndex=i;
        }
    }
    return maxIndex;
}

void pancakeSort(int arr[],int n){
    for(int size=n;size>1;size--){
        int maxIndex=findMaxIndex(arr,size);
        if(maxIndex!=size-1){
            flip(arr,maxIndex+1);
            flip(arr,size);
        }
    }
}

int main(void){
    int arr[]={3,2,4,1};
    int n=4;
    pancakeSort(arr,n);
    cout<<"FINAL OUTPUT:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}




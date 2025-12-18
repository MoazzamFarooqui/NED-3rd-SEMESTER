#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    int n=7,k=50;
    vector<int> arr={1,12,5,111,200,1000,10};
    sort(arr.begin(),arr.end());
    int count=0,sum=0;
    for(int i=0;i<n;i++){
        if(sum+arr[i]<=k){
            sum+=arr[i];
            count++;
        }
    }
    cout<<count;
}





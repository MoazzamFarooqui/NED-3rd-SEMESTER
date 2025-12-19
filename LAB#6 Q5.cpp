#include<iostream>
using namespace std;

void sortcolors(int nums[], int n){
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(nums[mid]==0){
            int temp=nums[low];
            nums[low]=nums[mid];
            nums[mid]=temp;
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            int temp=nums[mid];
            nums[mid]=nums[high];
            nums[high]=temp;
            high--;
        }
    }
}

int main(void){
    int nums1[]={2,0,2,1,1,0};
    int nums2[]={2,0,1};
    int n1=6;
    int n2=3;
    
    sortcolors(nums1,n1);
    sortcolors(nums2,n2);
    
    
    cout<<"FIRST ARRAY:"<<endl;
    for(int i=0;i<n1;i++){
        cout<<nums1[i]<<" ";;
    }
    cout<<endl;
    cout<<"SECOND ARRAY:"<<endl;
    for(int j=0;j<n2;j++){
    	cout<<nums2[j]<<" ";
	}
    return 0;
}


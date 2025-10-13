#include<bits/stdc++.h>
using namespace std;

vector<int>sum_of_numbers(vector<int>&nums,int target){
	int n=nums.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(nums[i]+nums[j]==target){
				return{i,j};
			}
		}
	}
}

int main(void){
	vector<int>nums={10,20,30,40};
	int target=40;
	
	vector<int>m=sum_of_numbers(nums,target);
	cout<<m[0]<<" "<<m[1]<<" "<<endl;
	return 0;
}
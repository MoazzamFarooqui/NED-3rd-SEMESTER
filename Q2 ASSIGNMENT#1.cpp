#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>&nums){
    if(nums.empty()) return false;
    
    sort(nums.begin(),nums.end()); 
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            return true; 
        }
    }
    return false;
}

int main(void){
    vector<int>nums={10,13,15,12,13};
    if(containsDuplicate(nums)){
        cout<<"TRUE"<<endl;
    } else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}




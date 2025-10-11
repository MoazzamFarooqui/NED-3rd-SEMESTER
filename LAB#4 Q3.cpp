#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void backtrack(vector<vector<int>>&ans,vector<int>&nums,int index){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            backtrack(ans,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>>permute(vector<int>&nums){
        vector<vector<int>>ans;
        backtrack(ans,nums,0);
        return ans;
    }
};

int main(void){
    Solution s;
    vector<int>nums1={1,2,3};
    vector<int>nums2={0,1};
    
    vector<vector<int>>res1=s.permute(nums1);
    vector<vector<int>>res2=s.permute(nums2);
    
    for(auto v:res1){
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
    cout<<endl;
    
    for(auto v:res2){
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}

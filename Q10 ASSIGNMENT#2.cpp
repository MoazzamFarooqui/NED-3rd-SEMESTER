#include<bits/stdc++.h>
using namespace std;

vector<int>slidingwindowmax(vector<int>&arr,int k){
    deque<int>dq;
    vector<int>result;
    for(int i=0;i<arr.size();i++){
        while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();
        while(!dq.empty()&&arr[dq.back()]<=arr[i])dq.pop_back();
        dq.push_back(i);
        if(i>=k-1)result.push_back(arr[dq.front()]);
    }
    return result;
}

int main(void){
    vector<int>arr={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int>ans=slidingwindowmax(arr,k);
    cout<<"SLIDING WINDOW MAXIMUMS:";
    for(int i=0;i<ans.size();i++)cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>mergeintervals(vector<vector<int>>&intervals){
	if(intervals.empty()){
		return {};
	}
	sort(intervals.begin(),intervals.end());
	vector<vector<int>>merged; 
	vector<int>prev=intervals[0];
	
	for(int i=1;i<intervals.size();i++){
		vector<int>curr=intervals[i];
		
		if(curr[0]<=prev[1]){
			prev[1]=max(prev[1],curr[1]);
		}
		else{
			merged.push_back(prev);
			prev=curr;
		}
	}
	merged.push_back(prev);
	return merged;
}

int main(void){
	 vector<vector<int>>intervals={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>result=mergeintervals(intervals);

    for(auto interval:result){
        cout<<"["<<interval[0]<<","<<interval[1]<<"]";
    }
    return 0;
}
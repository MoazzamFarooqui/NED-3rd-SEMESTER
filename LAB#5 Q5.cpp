#include<bits/stdc++.h>
using namespace std;

class DataStream{
	private:
		vector<int>datastream;
		int value;
		int k;
	public:
		DataStream(int val,int kk){
			value=val;
			k=kk;
		}
		bool consec(int num){
			datastream.push_back(num);
		if(datastream.size()>k){
			datastream.erase(datastream.begin());
		}
		if(datastream.size()<k){
			return false;
		}
		for(int i=0;i<k;i++){
			if(datastream[i]!=value){
				return false;
			}
		}
		return true;
		}
};

int main(void){
	DataStream m(4,3);
	cout<<m.consec(4)<<endl;
	cout<<m.consec(4)<<endl;
	cout<<m.consec(4)<<endl;
	cout<<m.consec(3)<<endl;
	return 0;
}
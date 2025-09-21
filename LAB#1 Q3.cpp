#include<iostream>
using namespace std;

class MedianFinder{
	private:
		int arr[50000];
		int size;
	public:
		MedianFinder(){
			size=0;
		}
		
		void addnum(int num){
			int i=size-1;
			while(i>=0 && arr[i]>num){
				arr[i+1]=arr[i];
				i--;
			}
			arr[i+1]=num;
			size++;
		}
		
		double findmedian(){
			if(size%2==1){
				return arr[size/2];
			}
			else{
				int mid=size/2;
				return(arr[mid-1]+arr[mid])/2.0;
			}
		}
};

int main(void){
	MedianFinder mf;
	mf.addnum(1);
	mf.addnum(2);
	cout<<mf.findmedian()<<endl;
	mf.addnum(3);
	cout<<mf.findmedian()<<endl;
	return 0;
}
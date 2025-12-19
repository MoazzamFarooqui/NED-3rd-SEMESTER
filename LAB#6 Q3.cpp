#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Sort{
	private:
		int swaps;
		int comparisions;
	public:
		Sort(){
			swaps=0;
			comparisions=0;
		}
		int getswaps(){
			return swaps;
		}
		int getcomparisions(){
			return comparisions;
		}
		void bubblesort(int arr[],int n){
			comparisions=0;
			swaps=0;
			for(int i=0;i<n-1;i++){
				for(int j=0;j<n-1-i;j++){
					comparisions++;
					if(arr[j]>arr[j+1]){
						int temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
						swaps++;
					}
				}
			}
		}
		void insertionsort(int arr[],int n){
			comparisions=0;
			swaps=0;
			for(int i=1;i<n;i++){
				int key=arr[i];
				int j=i-1;
				while(j>=0 && arr[j]>key){
					comparisions++;
					arr[j+1]=arr[j];
					swaps++;
					j--;
				}
				comparisions++;
				arr[j+1]=key;
			}
		}
		void selectionsort(int arr[],int n){
			comparisions=0;
			swaps=0;
			for(int i=0;i<n-1;i++){
				int minindex=i;
				for(int j=i+1;j<n;j++){
					comparisions++;
					if(arr[j]<arr[minindex]){
						minindex=j;
					}
				}
				if(minindex!=i){
					int temp=arr[i];
					arr[i]=arr[minindex];
					arr[minindex]=temp;
					swaps++;
				}
			}
		}
};

void copyarray(int source[],int dest[],int n){
	for(int i=0;i<n;i++){
		dest[i]=source[i];
	}
}

int main(void){
	const int n=10;
	int original[n];
	int temp[n];
	Sort s;
	srand(time(0));
	for(int i=0;i<n;i++){
		original[i]=rand()%100;
	}
	cout<<"*****ORIGINAL ARRAY*****"<<endl;
	for(int i=0;i<n;i++){
		cout<<original[i]<<" ";
	}
	cout<<endl<<endl;

	cout<<"ENTER SORTING TECHNIQUE(BUBBLE/INSERTION/SELECTION/ALL):";
	string choice;
	cin>>choice;

	int minswaps=1000;
	int maxswaps=-1;
	string best;
	string worst;

	if(choice=="bubble"){
		copyarray(original,temp,n);
		s.bubblesort(temp,n);
		cout<<"BUBBLE SORT COMPARISIONS="<<s.getcomparisions()<<" ,SWAPS="<<s.getswaps()<<endl;
	}
	else if(choice=="insertion"){
		copyarray(original,temp,n);
		s.insertionsort(temp,n);
		cout<<"INSERTION SORT COMPARISIONS="<<s.getcomparisions()<<" ,SWAPS="<<s.getswaps()<<endl;
	}
	else if(choice=="selection"){
		copyarray(original,temp,n);
		s.selectionsort(temp,n);
		cout<<"SELECTION SORT COMPARISIONS="<<s.getcomparisions()<<" ,SWAPS="<<s.getswaps()<<endl;
	}
	else if(choice=="all"){
		copyarray(original,temp,n);
		s.bubblesort(temp,n);
		int bubblec=s.getcomparisions();
		int bubbles=s.getswaps();
		cout<<"BUBBLE SORT COMPARISIONS="<<bubblec<<" ,SWAPS="<<bubbles<<endl;
		if(bubbles<minswaps){minswaps=bubbles;best="BUBBLE SORT";}
		if(bubbles>maxswaps){maxswaps=bubbles;worst="BUBBLE SORT";}

		copyarray(original,temp,n);
		s.insertionsort(temp,n);
		int insertc=s.getcomparisions();
		int inserts=s.getswaps();
		cout<<"INSERTION SORT COMPARISIONS="<<insertc<<" ,SWAPS="<<inserts<<endl;
		if(inserts<minswaps){minswaps=inserts;best="INSERTION SORT";}
		if(inserts>maxswaps){maxswaps=inserts;worst="INSERTION SORT";}

		copyarray(original,temp,n);
		s.selectionsort(temp,n);
		int selectionc=s.getcomparisions();
		int selections=s.getswaps();
		cout<<"SELECTION SORT COMPARISIONS="<<selectionc<<" ,SWAPS="<<selections<<endl;
		if(selections<minswaps){minswaps=selections;best="SELECTION SORT";}
		if(selections>maxswaps){maxswaps=selections;worst="SELECTION SORT";}

		cout<<"BEST TECHNIQUE: "<<best<<endl;
		cout<<"WORST TECHNIQUE: "<<worst<<endl;
	}
	else{
		cout<<"INVALID CHOICE"<<endl;
	}
	return 0;
}

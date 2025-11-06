#include<iostream>
using namespace std;

int main(){
    int rows,cols;
    cout<<"Enter rows:";
    cin>>rows;
    cout<<"Enter columns:";
    cin>>cols;

    int arr[rows][cols];  
    int oned[rows];   
    int k=0;

    cout<<"Enter elements of 2D array:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }

    for(int j=0;j<cols;j++){       
        for(int i=0;i<rows;i++){   
            oned[k]=arr[i][j];
            k++;
        }
    }

    cout<<"1D array in Column Major Order:"<<endl;
    for(int i=0;i<rows*cols;i++){
        cout<<oned[i]<<" ";
    }

    return 0;
}
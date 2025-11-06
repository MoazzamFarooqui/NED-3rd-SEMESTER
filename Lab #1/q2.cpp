#include<iostream>
using namespace std;

int main(void){
	int credithour=3;
	string students[5]={"ALI","HIBA","ASMA","ZAIN","FAISAL"};
	float grades[5][5] = {
        {3.66, 3.33, 4.0, 3.0, 2.66},
        {3.33, 3.0, 3.66, 3.0, -1},
        {4.0, 3.66, 2.66, -1, -1},
        {2.66, 2.33, 4.0, -1, -1},
        {3.33, 3.66, 4.0, 3.0, 3.33}
    };
    
    for(int i=0;i<5;i++){
    	float gpa=0;
    	int totalcredithours=0;
    for(int j=0;j<5;j++){
    	float gpaofsubject=grades[i][j];
    	if(gpaofsubject!=-1){
    		totalcredithours+=credithour;
    		gpa+=gpaofsubject*credithour;
		}
	}
	float cgpa;
	cgpa=gpa/totalcredithours;
	cout<<students[i]<<"'s GPA:"<<cgpa<<endl;
	}
	return 0;
}
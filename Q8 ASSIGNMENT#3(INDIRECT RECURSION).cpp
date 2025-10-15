#include<bits/stdc++.h>
using namespace std;

void even(int n);
void odd(int n);

void even(int n){
    if(n>0){
        cout<<n<<" IS EVEN"<<endl;
        odd(n-1);//Function calls another function(Indirect recursion)
    }
}

void odd(int n){
    if(n>0){
        cout<<n<<" IS ODD"<<endl;
        even(n-1);//Function calls another function(Indirect recursion)
    }
}

int main(void){
    even(6);
    return 0;
}


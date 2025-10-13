#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

class Stack{
    Node*top;
public:
    Stack(){
        top=nullptr;
    }
    
    void push(int val){
        Node*newnode=new Node(val);
        newnode->next=top;
        top=newnode;
    }
    
    int pop(){
        if(top==nullptr){
            cout<<"STACK UNDERFLOW!"<<endl;
            return -1;
        }
        int val=top->data;
        Node*temp=top;
        top=top->next;
        delete temp;
        return val;
    }
    
    bool isempty(){
        return top==nullptr;
    }
};

int evaluatepostfix(string exp[],int n){
    Stack st;
    for(int i=0;i<n;i++){
        string token=exp[i];
        if(token=="+" || token=="-" || token=="*" || token=="/"){
            int b=st.pop();
            int a=st.pop();
            int result;
            if(token=="+")result=a+b;
            else if(token=="-")result=a-b;
            else if(token=="*")result=a*b;
            else result=a/b;
            st.push(result);
        }
        else{
            int num=stoi(token);
            st.push(num);
        }
    }
    return st.pop();
}

int main(void){
    string p[]={"5","6","2","+","*","12","4","/","-"};
    int size=sizeof(p)/sizeof(p[0]);
    cout<<"RESULT:"<<evaluatepostfix(p,size)<<endl;
    return 0;
}

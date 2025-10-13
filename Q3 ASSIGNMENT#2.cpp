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
private:
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
    
    void pop(){
        if(top==nullptr)return;
        Node*temp=top;
        top=top->next;
        delete temp;
    }
    
    int peek(){
        if(top==nullptr)return -1;
        return top->data;
    }
    
    bool empty(){
        return top==nullptr;
    }
};

int main(void){
    int num;
    cout<<"ENTER A DECIMAL NUMBER: ";
    cin>>num;
    
    Stack st;
    int n=num;
    while(n>0){
        int rem=n%2;
        st.push(rem);
        n=n/2;
    }
    cout<<"BINARY REPRESENTATION OF "<<num<<" IS: ";
    while(!st.empty()){
        cout<<st.peek();
        st.pop();
    }
    cout<<endl;
    return 0;
}

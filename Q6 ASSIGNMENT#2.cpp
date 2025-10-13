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
    Node*mintop;
public:
    Stack(){
        top=nullptr;
        mintop=nullptr;
    }
    
	void push(int val){
        Node*newnode=new Node(val);
        newnode->next=top;
        top=newnode;
        if(mintop==nullptr || val<=mintop->data){
            Node*newmin=new Node(val);
            newmin->next=mintop;
            mintop=newmin;
        }
    }
    
    int pop(){
        if(top==nullptr){
            cout<<"STACK UNDERFLOW!"<<endl;
            return -1;
        }
        int val=top->data;
        if(val==mintop->data){
            Node*tempmin=mintop;
            mintop=mintop->next;
            delete tempmin;
        }
        Node*temp=top;
        top=top->next;
        delete temp;
        return val;
    }
    
    int peek(){
        if(top==nullptr){
            cout<<"STACK IS EMPTY!"<<endl;
            return -1;
        }
        return top->data;
    }
    
    int getmin(){
        if(mintop==nullptr){
            cout<<"STACK IS EMPTY!"<<endl;
            return -1;
        }
        return mintop->data;
    }
    
    bool isempty(){
        return top==nullptr;
    }
};

int main(void){
    Stack st;
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);
    st.push(6);
    cout<<"CURRENT MIN:"<<st.getmin()<<endl;
    st.pop();
    st.pop();
    cout<<"CURRENT MIN:"<<st.getmin()<<endl;
    return 0;
}

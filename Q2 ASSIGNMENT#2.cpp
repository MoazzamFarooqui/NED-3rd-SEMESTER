#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    Node*next;
    Node(char val){
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
    void push(char val){
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
    
    char peek(){
        if(top==nullptr) return -1;
        return top->data;
    }
    
    bool empty(){
        return top==nullptr;
    }
};

int main(void){
    Stack st;
    string s;
    cout<<"ENTER STRING:";
    cin>>s;
    
    for(int i=0;i<s.length();i++)st.push(s[i]);
    string reversed="";
    while(!st.empty()){
        reversed+=st.peek();
        st.pop();
    }
    
    cout<<"REVERSED STRING:"<<reversed<<endl;
    return 0;
}

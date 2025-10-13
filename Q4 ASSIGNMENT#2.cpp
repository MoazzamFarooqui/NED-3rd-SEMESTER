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
    Node*top;
public:
    Stack(){
        top=nullptr;
    }
    
    void push(char c){
        Node*newnode=new Node(c);
        newnode->next=top;
        top=newnode;
    }
    
    char pop(){
        if(top==nullptr)return -1;
        Node*temp=top;
        char val=temp->data;
        top=top->next;
        delete temp;
        return val;
    }
    
    char peek(){
        if(top==nullptr)return -1;
        return top->data;
    }
    
    bool empty(){
        return top==nullptr;
    }
};

int precedence(char op){
    if(op=='^')return 3;
    if(op=='*'||op=='/')return 2;
    if(op=='+'||op=='-')return 1;
    return 0;
}

bool isoperand(char c){
    return c>='A'&&c<='Z';
}

string infixtopostfix(string infix){
    Stack st;
    string postfix="";
    for(int i=0;i<infix.size();i++){
        char c=infix[i];
        if(isoperand(c))postfix+=c;
        else if(c=='(')st.push(c);
        else if(c==')'){
            while(!st.empty()&&st.peek()!='(')postfix+=st.pop();
            st.pop();
        }
        else{
            while(!st.empty()&&precedence(st.peek())>=precedence(c))postfix+=st.pop();
            st.push(c);
        }
    }
    while(!st.empty())postfix+=st.pop();
    return postfix;
}

int main(void){
    string infix="(A+B)*C";
    cout<<"INFIX:"<<infix<<endl;
    cout<<"POSTFIX:"<<infixtopostfix(infix)<<endl;
    return 0;
}

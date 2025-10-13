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
        Node* newNode=new Node(val);
        newNode->next=top;
        top=newNode;
    }
    
    void pop(){
        if(top==NULL)return;
        Node* temp=top;
        top=top->next;
        delete temp;
    }
    
    char peek(){
        if(top==NULL)return -1;
        return top->data;
    }
    
    bool empty(){
        return top==NULL;
    }
    
    bool isValid(string s){
        Stack st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('||ch=='{'||ch=='[')st.push(ch);
            else{
                if(st.empty())return false;
                char top=st.peek();
                st.pop();
                if((ch==')'&&top!='(') || (ch=='}'&&top!='{') || (ch==']'&&top!='['))return false;
            }
        }
        return st.empty();
    }
};

int main(void){
    Stack st;
    string s;
    cout<<"ENTER STRING:";
    cin>>s;
    if(st.isValid(s))cout<<"VALID"<<endl;
    else cout<<"INVALID"<<endl;
    return 0;
}

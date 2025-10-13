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
        if(top==nullptr) return -1;
        Node*temp=top;
        int val=temp->data;
        top=top->next;
        delete temp;
        return val;
    }

    bool empty(){
        return top==nullptr;
    }

    int peek(){
        if(top==nullptr) return -1;
        return top->data;
    }
};

class Queue{
private:
    Stack s1,s2;
public:
    void enqueue(int x){
        s1.push(x);
        cout<<"ENQUEUED:"<<x<<endl;
    }

    int dequeue(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.pop());
            }
        }
        if(s2.empty()){
            cout<<"QUEUE IS EMPTY!"<<endl;
            return -1;
        }
        int val=s2.pop();
        cout<<"DEQUEUED:"<<val<<endl;
        return val;
    }
};

int main(void){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.dequeue();
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}

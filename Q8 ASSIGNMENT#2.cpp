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

class Queue{
    Node*front;
    Node*rear;
public:
    Queue(){
        front=nullptr;
        rear=nullptr;
    }

    void enqueue(int x){
        Node*newnode=new Node(x);
        if(rear==nullptr){
            front=rear=newnode;
            cout<<"ENQUEUED:"<<x<<endl;
            return;
        }
        rear->next=newnode;
        rear=newnode;
        cout<<"ENQUEUED:"<<x<<endl;
    }

    int dequeue(){
        if(isempty()){
            cout<<"QUEUE IS EMPTY!"<<endl;
            return -1;
        }
        Node*temp=front;
        int val=temp->data;
        front=front->next;
        if(front==nullptr)rear=nullptr;
        delete temp;
        cout<<"DEQUEUED:"<<val<<endl;
        return val;
    }

    int peek(){
        if(isempty()){
            cout<<"QUEUE IS EMPTY!"<<endl;
            return -1;
        }
        return front->data;
    }

    bool isempty(){
        return front==nullptr;
    }
};

int main(void){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"FRONT:"<<q.peek()<<endl;
    q.dequeue();
    cout<<"FRONT:"<<q.peek()<<endl;
    return 0;
}

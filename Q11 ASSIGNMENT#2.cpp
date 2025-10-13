#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node*prev;
    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};

class Deque{
    Node*front;
    Node*rear;
    int size;
public:
    Deque(){
        front=nullptr;
        rear=nullptr;
        size=0;
    }

    void enqueue(int val){
        Node*newnode=new Node(val);
        if(rear==nullptr){
            front=newnode;
            rear=newnode;
        }
        else{
        	rear->next=newnode;
            newnode->prev=rear;
            rear=newnode;
	    }
        size++;
    }
    
    void leftshift(){
        if(front==nullptr){
            cout<<"QUEUE UNDERFLOW(FRONT)"<<endl;
            return;
        }
        cout<<front->data<<" REMOVED FROM FRONT"<<endl;
        Node*temp=front;
        front=front->next;
        if(front)front->prev=nullptr;
        else rear=nullptr;
        delete temp;
        size--;
    }
    
    void rightshift(){
        if(rear==nullptr){
            cout<<"QUEUE UNDERFLOW(REAR)"<<endl;
            return;
        }
        cout<<rear->data<<" REMOVED FROM REAR"<<endl;
        Node*temp=rear;
        rear=rear->prev;
        if(rear)rear->next=nullptr;
        else front=nullptr;
        delete temp;
        size--;
    }

    int getsize(){
        return size;
    }

    void display(){
        Node*curr=front;
        cout<<"QUEUE:";
        while(curr){
            cout<<" "<<curr->data;
            curr=curr->next;
        }
        cout<<endl;
    }
};

int main(void){
    int n;
    cout<<"ENTER SIZE OF QUEUE:";
    cin>>n;
    
    Deque q;
    for(int i=1;i<=n;i++)q.enqueue(i);
    q.display();
    cout<<"MINIMUM OPERATIONS NEEDED="<<q.getsize()<<endl;
    cout<<"PERFORMING DELETIONS:"<<endl;
    while(q.getsize()>0){
        if(q.getsize()%2==0)q.leftshift();
        else q.rightshift();
    }
    return 0;
}

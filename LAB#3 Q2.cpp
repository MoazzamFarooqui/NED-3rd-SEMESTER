#include<iostream>
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

class DoubleEndedQueue{
	private:
		Node*front;
		Node*rear;
	public:
		DoubleEndedQueue(){
			front=nullptr;
			rear=nullptr;
		}
		
		void insert_at_front(int val){
			Node*newnode=new Node(val);
			if(front==nullptr){
				front=newnode;
				rear=newnode;
				return;
			}
			newnode->next=front;
			front->prev=newnode;
			front=newnode;
			return;
		}
		
		void insert_at_rear(int val){
			Node*newnode=new Node(val);
			if(front==nullptr){
				front=newnode;
				rear=newnode;
				return;
			}
			rear->next=newnode;
			newnode->prev=rear;
			rear=newnode;
			return;
		}
		
		void delete_at_front(){
			if(front==nullptr){
				cout<<"QUEUE IS EMPTY!"<<endl;
				return;
			}
			if(front==rear){
				delete front;
				front=nullptr;
				rear=nullptr;
				return;
			}
			front=front->next;
			delete front->prev;
			front->prev=nullptr;
			return;
		}
		
		void delete_at_rear(){
			if(front==nullptr){
				cout<<"QUEUE IS EMPTY!"<<endl;
				return;
			}
			if(front==rear){
				delete front;
				front=nullptr;
				rear=nullptr;
				return;
			}
		    rear=rear->prev;
		    delete rear->next;
		    rear->next=nullptr;
		    return;
		}
		
		void display(){
			Node*temp=front;
			while(temp!=nullptr){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}		
};

int main(void){
	DoubleEndedQueue ceq;
	ceq.insert_at_front(1);
	ceq.insert_at_front(2);
	ceq.insert_at_rear(3);
	ceq.delete_at_front();
	ceq.display();
	
	ceq.insert_at_rear(4);
	ceq.delete_at_rear();
	return 0;
}
#include<iostream>
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
			if(isEmpty()){
				cout<<"STACK EMPTY.CANNOT UNDERFLOW"<<endl;
				return;
			}
			Node*temp=top;
			top=top->next;
			delete temp;
		}
		
		int peek(){
			if(isEmpty()){
				cout<<"STACK IS EMPTY!"<<endl;
				return -1;
			}
			return top->data;
		}
		
		bool isEmpty(){
			return top==nullptr;
		}
		
		void display(){
			if(isEmpty()){
				cout<<"STACK IS EMPTY!"<<endl;
				return;
			}
			Node*temp=top;
			cout<<"STACK(TOP TO BOTTOM):"<<endl;
			while(temp!=nullptr){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};

int main(void){
	Stack s;
	s.push(1);
	s.push(2);
	
	cout<<"TOP ELEMENT:"<<s.peek()<<endl;
	
	s.pop();
	s.push(3);
	s.display();
	return 0;
}
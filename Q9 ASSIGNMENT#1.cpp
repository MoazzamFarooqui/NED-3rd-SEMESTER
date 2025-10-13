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

class DoublyLinkedList{
	private:
		Node*head;
	public:
		DoublyLinkedList(){
			head=nullptr;
		}
		
		void insert(int val){
			Node*newnode=new Node(val);
			if(head==nullptr){
				head=newnode;
				return;
			}
			Node*temp=head;
			while(temp->next!=nullptr){
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
		}
		
		void display(){
			Node*temp=head;
			while(temp!=nullptr){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
		void reverse(){
			Node*curr=head;
			Node*temp=nullptr;
			while(curr!=nullptr){
				temp=curr->prev;
				curr->prev=curr->next;
				curr->next=temp;
				curr=curr->prev;
			}
			if(temp!=nullptr){
				head=temp->prev;
			}
		}
};

int main(void){
	DoublyLinkedList dll;
	dll.insert(10);
	dll.insert(20);
	dll.insert(30);
	dll.insert(40);
	cout<<"BEFORE REVERSING:";
	dll.display();
	dll.reverse();
	cout<<"AFTER REVERSING:";
	dll.display();
	return 0;
}
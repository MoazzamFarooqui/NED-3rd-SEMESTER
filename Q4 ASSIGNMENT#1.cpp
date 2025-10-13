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

class SinglyLinkedList{
	private:
		Node*head;
	public:
		SinglyLinkedList(){
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
		}
		
		Node*reverse(){
	        Node*curr=head;
	        Node*prev=nullptr;
	    while(curr!=nullptr){
		    Node*next=curr->next;
		    curr->next=prev;
		    prev=curr;
		    curr=next;
	    }
	    head=prev;
    }

        void display(){
	        Node*temp=head;
	    while(temp!=nullptr){
		    cout<<temp->data<<" ";
		    temp=temp->next;
	    }
	    cout<<endl;
    }		
};

int main(void){
    SinglyLinkedList sll;
    sll.insert(10);
    sll.insert(20);
    sll.insert(30);
    sll.insert(40);
    sll.insert(50);

    cout<<"BEFORE REVERSING:";
    sll.display();

    sll.reverse();

    cout<<"AFTER REVERSING:";
    sll.display();
}
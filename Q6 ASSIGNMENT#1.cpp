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

class LinkedList{
	private:
		Node*head;
	public:
		LinkedList(){
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
        
        Node*delete_n_nodes(int n){
        	while(head!=nullptr && n>0){
        		Node*temp=head;
        		head=head->next;
        		temp->next=nullptr;
        		delete temp;
        		n--;
			}
			return head;
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
	LinkedList ll;
	cout<<"BEFORE DELETING N NODES:"<<endl;
	ll.insert(1);
	ll.insert(2);
	ll.insert(3);
	ll.insert(4);
	ll.display();
	
	cout<<"AFTER DELETING N NODES:"<<endl;
	ll.delete_n_nodes(2);
	ll.display();
	return 0;
}
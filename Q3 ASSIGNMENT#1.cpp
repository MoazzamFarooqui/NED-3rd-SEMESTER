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
		
		Node*find_middle_node(){
	       Node*slow=head;
	       Node*fast=head;
	
	       while(fast!=nullptr && fast->next!=nullptr){
		        slow=slow->next;
		        fast=fast->next->next;
	        }
	        return slow;
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
    cout<<"ORIGINAL LIST:";
	sll.display();

	cout<<"MIDDLE NODE IS:"<<sll.find_middle_node()->data<<" ";
	
	return 0;
}
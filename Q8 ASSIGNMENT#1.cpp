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
		Node*tail;
    public:
	    DoublyLinkedList(){
	    	head=nullptr;
	    	tail=nullptr;
		}	
		
		void insert_at_head(int val){
			Node*newnode=new Node(val);
			if(head==nullptr){
				head=newnode;
				tail=newnode;
				return;
			}
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
		}
		
		void insert_at_tail(int val){
			Node*newnode=new Node(val);
			if(head==nullptr){
				head=newnode;
				tail=newnode;
				return;
			}
			tail->next=newnode;
			newnode->prev=tail;
			tail=newnode;
		}
		
		void delete_at_head(){
			if(head==nullptr){
				cout<<"LIST IS EMPTY!"<<endl;
				return;
			}
			if(head==tail){
				delete head;
				head=nullptr;
				tail=nullptr;
				return;
			}
			head=head->next;
			delete head->prev;
			head->prev=nullptr;
		}
		
		void delete_at_tail(){
			if(head==nullptr){
				cout<<"LIST IS EMPTY!"<<endl;
				return;
			}
			if(head==tail){
				delete head;
				head=nullptr;
				tail=nullptr;
				return;
			}
			tail=tail->prev;
			delete tail->next;
			tail->next=nullptr;
		}
		
		void insert_after_node(Node*prevnode,int val){
			if(prevnode==nullptr){
				return;
			}
			Node*newnode=new Node(val);
			newnode->next=prevnode->next;
			newnode->prev=prevnode;
			if(prevnode->next!=nullptr){
				prevnode->next->prev=newnode;
			}
			else{
				tail=newnode;
			}
			prevnode->next=newnode;
		}
		
		void delete_node(Node*delnode){
			if(delnode==nullptr){
				return;
			}
			if(delnode==head){
				delete_at_head();
				return;
			}
			if(delnode==tail){
				delete_at_tail();
				return;
			}
			delnode->prev->next=delnode->next;
			delnode->next->prev=delnode->prev;
			
			delete delnode;
		}
		
		Node*search(int val){
			Node*temp=head;
			while(temp!=nullptr){
				if(temp->data==val){
					return temp;
				}
				temp=temp->next;
			}
			return nullptr;
	    }
	    
	    void display(){
	 	    Node*temp=head;
	 	    while(temp!=nullptr){
	 		   cout<<temp->data<<"<->";
	 		   temp=temp->next;
		    }
		cout<<"NULL";
	    }
};

int main(void){
    DoublyLinkedList dll;
    dll.insert_at_head(10);
    dll.insert_at_head(20);
    dll.insert_at_tail(5);
    dll.insert_at_tail(1);
    dll.display();
    cout<<endl;

    Node*found=dll.search(20);
    dll.insert_after_node(found, 15);
    dll.display();
    cout<<endl;

    found=dll.search(10);
    dll.delete_node(found);
    dll.display();
    cout<<endl;
    
    dll.delete_at_head();
    dll.delete_at_tail();
    dll.display();
    cout<<endl;
    return 0;
}

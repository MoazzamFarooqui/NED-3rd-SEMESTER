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

class CircularLinkedList{
	private:
		Node*head;
		Node*tail;
		
	public:
		CircularLinkedList(){
			head=nullptr;
			tail=nullptr;
		}
		
		void insert_at_head(int val){
			Node*newnode=new Node(val);
			if(head==nullptr){
				head=newnode;
				tail=newnode;
				tail->next=head;
				return;
			}
			newnode->next=head;
			head=newnode;
			tail->next=head;
		}
		
		void insert_at_tail(int val){
			Node*newnode=new Node(val);
			if(head==nullptr){
				head=newnode;
				tail=newnode;
				tail->next=head;
				return;
			}
			tail->next=newnode;
			tail=newnode;
			tail->next=head;
		}
		
		void insert_after_node(Node*prevnode,int val){
			if(prevnode==nullptr){
				return;
			}
			Node*newnode=new Node(val);
			newnode->next=prevnode->next;
			prevnode->next=newnode;
			
			if(prevnode==tail){
				tail=newnode;
			}
		}
		
		Node*search(int val){
			if(head==nullptr){
				return nullptr;
			}
			Node*temp=head;
			while(temp->next!=head){
				if(temp->data==val){
					return temp;
				}
				temp=temp->next;
			}
			
			if(temp->data==val){
				return temp;
			}
			return nullptr;
		}
		
		void display(){
			if(head==nullptr){
				cout<<"LIST IS EMPTY!"<<endl;
				return;
			}
			Node*temp=head;
			while(true){
				cout<<temp->data<<" ";
				temp=temp->next;
				if(temp==head){
					break;
				}
			}
			cout<<"(back to head)"<<endl;
		}
};

int main(void){
    CircularLinkedList cll;

    cll.insert_at_head(10);
    cll.insert_at_head(20);
    cll.insert_at_tail(5);
    cll.insert_at_tail(1);
    cll.display();

    Node*found=cll.search(10);
    cll.insert_after_node(found,15);
    cll.display();

    found=cll.search(1);
    cll.insert_after_node(found,25);
    cll.display();

    return 0;
}

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
		int size;
		
	public:
		CircularLinkedList(){
			head=nullptr;
			size=0;
		}
		
		void insert(int val){
			Node*newnode=new Node(val);
			if(head==nullptr){
				head=newnode;
				newnode->next=head;
			}
			else{
			   Node*temp=head;
			   while(temp->next!=head){
				temp=temp->next;
			   }
			   temp->next=newnode;
			   newnode->next=head;
			}
			size++;
		}
		
		void rotate(int k){
			if(head==nullptr || k==0) return;
			k=k%size;
			int steps=size-k;
			for(int i=0;i<steps;i++){
				head=head->next;
			}
		}
		
		void display(){
			if(head==nullptr) return;
			Node*temp=head;
			for(int i=0;i<size;i++){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};

int main(void){
	CircularLinkedList cll;
	for(int i=1;i<=7;i++){
		cll.insert(i);
	}
	
	cout<<"ORIGINAL LIST:";
	cll.display();
	
	cll.rotate(3);
	
	cout<<"ROTATED LIST:";
    cll.display();   
    return 0;
}
   
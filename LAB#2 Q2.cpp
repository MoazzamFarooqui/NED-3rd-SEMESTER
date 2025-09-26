#include<iostream>
using namespace std;

class Node{
	public:
		Node*next;
		int val;
		
		Node(int v){
			next=nullptr;
			val=v;
		}
};

Node*deleteduplicates(Node*head){
	if(head==nullptr){
		return nullptr;
	}
	
	Node*current=head;
	while(current!=nullptr && current->next!=nullptr){
		if(current->val==current->next->val){
			Node*duplicate=current->next;
			current->next=current->next->next;
			delete duplicate;	
		}
		else{
			current=current->next;
		}
	}
	return head;
}

void display(Node*head){
	while(head!=nullptr){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main(void){
    Node*head=new Node(1);
    head->next=new Node(1);
    head->next->next=new Node(2);
    head->next->next->next=new Node(3);
    head->next->next->next->next=new Node(3);
	
	cout<<"ORIGINAL LIST:";
	display(head);
	
	head=deleteduplicates(head);
	   
	cout<<"LIST AFTER REMOVING DUPLICATES:";
	display(head);
	
	return 0;
}
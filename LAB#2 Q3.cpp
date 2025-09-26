#include<iostream>
using namespace std;

class Node{
    public:
	   int val;
	   Node*next;
	   
	   Node(int v){
	   	   val=v;
	   	   next=nullptr;
	   }	
};


Node*findmiddlenode(Node*head){
	if(head==nullptr || head->next==nullptr){
		return head;
	}
	Node*slow=head;
	Node*fast=head;
	
	while(fast->next!=nullptr && fast->next->next!=nullptr){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

Node*mergetwolists(Node*list1,Node*list2){
	if(list1==nullptr){
		return list2;
	}
	
	if(list2==nullptr){
		return list1;
	}
	
	if(list1->val<=list2->val){
		list1->next=mergetwolists(list1->next,list2);
		return list1;
	}
	else{
		list2->next=mergetwolists(list1,list2->next);
		return list2;
	}
}

Node*mergesort(Node*head){
	if(head==nullptr || head->next==nullptr){
		return head;
	}
	
	Node*middle=findmiddlenode(head);
	Node*righthalf=middle->next;
	middle->next=nullptr;
	
	Node*left=mergesort(head);
	Node*right=mergesort(righthalf);
	
	return mergetwolists(left,right);
}

void display(Node*head){
	while(head!=nullptr){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main(void){
	Node*head=new Node(4);
	head->next=new Node(2);
	head->next->next=new Node(1);
	head->next->next->next=new Node(3);
	
	cout<<"ORIGINAL LIST:";
	display(head);
	
	head=mergesort(head);
	
	cout<<"SORTED LIST:";
	display(head);
	return 0;
}
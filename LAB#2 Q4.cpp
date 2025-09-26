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

Node*reverse(Node*head){
	Node*prev=nullptr;
	Node*curr=head;
	while(curr!=nullptr){
		Node*next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

bool is_palindrome(Node*head){
	if(head==nullptr || head->next==nullptr){
		return true;
	}
	Node*slow=head;
	Node*fast=head;
	
	while(fast->next!=nullptr && fast->next->next!=nullptr){
		slow=slow->next;
		fast=fast->next->next;
	}
	
	Node*secondhalf=reverse(slow->next);
	
	Node*firsthalf=head;
	Node*tempsecond=secondhalf;
	bool palindrome=true;
	
	while(tempsecond!=nullptr){
		if(firsthalf->val!=tempsecond->val){
			palindrome=false;
			break;
		}
		firsthalf=firsthalf->next;
	    tempsecond=tempsecond->next;
	}
    slow->next=reverse(secondhalf);
    return palindrome;
}

int main(void){
	Node*head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(2);
	head->next->next->next=new Node(1);
	
	if(is_palindrome(head)){
		cout<<"TRUE!"<<endl;
	}
	else{
		cout<<"FALSE!"<<endl;
	}
	return 0;
}
#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node*next;
    Node(int v){
        val=v;
        next=nullptr;
    }
};

Node* mergetwolists(Node*list1,Node*list2){
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

void display(Node*head){
	while(head!=nullptr){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main(void){
	Node*list1=new Node(1);
	list1->next=new Node(2);
	list1->next->next=new Node(4);
	
	Node*list2=new Node(1);
	list2->next=new Node(3);
	list2->next->next=new Node(4);
	
	Node*m=mergetwolists(list1,list2);
	cout<<"MERGED LIST:"<<endl;
	display(m);
	return 0;
}

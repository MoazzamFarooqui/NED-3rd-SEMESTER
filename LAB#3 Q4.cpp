#include<iostream>
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
		
		void insertrear(int val){
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
		
		void concatenate(DoublyLinkedList&other){
			if(other.head==nullptr)return;
			if(this->head==nullptr){
				head=other.head;
				tail=other.tail;
				return;
			}
			tail->next=other.head;
			other.head->prev=tail;
			tail=other.tail;
		}
		
		void sortdescending(){
			if(head==nullptr)return;
			
			for(Node*i=head;i!=nullptr;i=i->next){
				for(Node*j=i->next;j!=nullptr;j=j->next){
					if(i->data<j->data){
						int temp=i->data;
						i->data=j->data;
						j->data=temp;
					}
				}
			}
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
	DoublyLinkedList L;
	DoublyLinkedList M;
	DoublyLinkedList N;
	
	for(int i=2;i<=10;i+=2){
		L.insertrear(i);
	}
	
	for(int i=1;i<=9;i+=2){
		M.insertrear(i);
	}
	
	cout<<"LIST L(EVEN):"<<endl;
	L.display();
	
	cout<<"LIST M(ODD):"<<endl;
	M.display();
	
	N.concatenate(L);
	N.concatenate(M);
	cout<<"LIST N:"<<endl;
	N.display();
	cout<<"LIST N IN DESCENDING ORDER:"<<endl;
	N.sortdescending();
	N.display();
	return 0;
}
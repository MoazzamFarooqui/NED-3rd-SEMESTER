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
		
		Node*mergetwolists(Node*list1,Node*list2){
            if(list1==nullptr){
               return list2;
            }
            if(list2==nullptr){
               return list1;
            }
            if(list1->data<=list2->data){
               list1->next=mergetwolists(list1->next,list2);
               return list1;
            }
            else{
               list2->next=mergetwolists(list1,list2->next);
               return list2;
            }
        }
       
        void display(Node*n){
       	    while(n!=nullptr){
       	    	cout<<n->data<<" ";
       	   	    n=n->next;
			}
			cout<<endl;
	    }
	    
	    Node*getHead(){
	    	return head;
	    }
};

int main(void){
	SinglyLinkedList list1,list2,sll;

    list1.insert(10);
    list1.insert(30);
    list1.insert(50);

    list2.insert(20);
    list2.insert(40);
    list2.insert(60);

    cout<<"LIST 1:";
    list1.display(list1.getHead());

    cout<<"LIST 2:";
    list2.display(list2.getHead());

    Node*mergedhead=sll.mergetwolists(list1.getHead(),list2.getHead());
    cout<<"MERGED LIST:";
    sll.display(mergedhead);
    return 0;
}
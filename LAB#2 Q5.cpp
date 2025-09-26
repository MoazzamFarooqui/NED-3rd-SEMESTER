 #include<iostream>
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

class CircularQueue{
	private:
		Node*front;
		Node*rear;
	public:
		CircularQueue(){
			front=nullptr;
			rear=nullptr;
		}
		
		void enqueue(int val){
			Node*newnode=new Node(val);
			if(front==nullptr){
				front=newnode;
				rear=newnode;
				rear->next=front;
				return;
			}
			rear->next=newnode;
			rear=newnode;
			rear->next=front;
		}
		
		void dequeue(){
			if(isEmpty()){
				cout<<"QUEUE IS EMPTY!"<<endl;
				return;
			}
			if(front==rear){
				delete front;
				front=nullptr;
				rear=nullptr;
				return;
			}
			Node*temp=front;
			front=front->next;
			rear->next=front;
			delete temp;
		}
		
		int peek(){
			if(isEmpty()){
				cout<<"QUEUE IS EMPTY!"<<endl;
				return -1;
			}
			return front->data;
		}
		
		bool isEmpty(){
			return front==nullptr;
		}
		
		void display(){
			if(isEmpty()){
				cout<<"QUEUE IS EMPTY!"<<endl;
				return;
			}
			Node*temp=front;
			cout<<"QUEUE ELEMENTS:"<<endl;
			while(temp->next!=front){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<temp->data<<endl;
		}
};

int main(void){
	CircularQueue cq;
	cq.enqueue(1);
	cq.enqueue(2);
	cout<<"FRONT ELEMENT:"<<cq.peek()<<endl;
	cq.dequeue();
	cq.display();
	
	cq.enqueue(3);
	cq.display();
	return 0;
}
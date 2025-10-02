#include<iostream>
using namespace std;

class Node{
	public:
		string url;
		Node*next;
		Node*prev;
		
	    Node(string u){
	    	url=u;
	    	next=nullptr;
	    	prev=nullptr;
		}
};

class BrowserHistory{
	private:
		Node*curr;
	public:
		BrowserHistory(string homepage){
			curr=new Node(homepage);
		}
		
		void visit(string url){
			Node*newnode=new Node(url);
			curr->next=newnode;
			newnode->prev=curr;
			curr=newnode;
		}
		
		string back(int steps){
		   while(steps>0 && curr->prev!=nullptr){
		       curr=curr->prev;
		       steps--;
		   }	
		   return curr->url;
		}
		
		string forward(int steps){
			while(steps>0 && curr->next!=nullptr){
				curr=curr->next;
				steps--;
			}
			return curr->url;
		}
};

int main(void){
	BrowserHistory bh("leetcode.com");
	bh.visit("google.com");
	bh.visit("facebook.com");
	bh.visit("youtube.com");
	
	cout<<bh.back(1)<<endl;
	cout<<bh.back(1)<<endl;
	cout<<bh.forward(1)<<endl;
	
	bh.visit("instagram.com");
	cout<<bh.forward(1)<<endl;
	cout<<bh.back(2)<<endl;
	cout<<bh.back(7)<<endl;
    return 0;
}
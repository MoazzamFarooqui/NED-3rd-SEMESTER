#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque{
private:
	vector<int> dq;
    int front;
	int rear;
	int size;
	int capacity;
	
public:
    MyCircularDeque(int k){
        capacity=k;
        dq.resize(k);
        front=0;
        rear=0;
        size=0;
    }
    
    bool insertFront(int value){
        if(size==capacity) return false;
        front=(front-1+capacity)%capacity;
        dq[front]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value){
        if(size==capacity) return false;
        dq[rear]=value;
        rear=(rear+1)%capacity;
        size++;
        return true;
    }
    
    bool deleteFront(){
        if(size==0) return false;
        front=(front+1)%capacity;
        size--;
        return true;
    }
    
    bool deleteLast(){
        if(size==0) return false;
        rear=(rear-1+capacity)%capacity;
        size--;
        return true;
    }
    
    int getFront(){
        if(size==0) return -1;
        return dq[front];
    }
    
    int getRear(){
        if(size==0) return -1;
        return dq[(rear-1+capacity)%capacity];
    }
    
    bool isEmpty(){
        return size==0;
    }
    
    bool isFull(){
        return size==capacity;
    }
};

int main(void){
    MyCircularDeque myCircularDeque(3);
    cout<<myCircularDeque.insertLast(1)<<endl;
    cout<<myCircularDeque.insertLast(2)<<endl;
    cout<<myCircularDeque.insertFront(3)<<endl;
    cout<<myCircularDeque.insertFront(4)<<endl;
    cout<<myCircularDeque.getRear()<<endl;
    cout<<myCircularDeque.isFull()<<endl;
    cout<<myCircularDeque.deleteLast()<<endl;
    cout<<myCircularDeque.insertFront(4)<<endl;
    cout<<myCircularDeque.getFront()<<endl;
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int index;
    int height;
    Node*next;
    Node(int i,int h){
        index=i;
        height=h;
        next=nullptr;
    }
};

class Stack{
    Node*top;
public:
    Stack(){
        top=nullptr;
    }

    void push(int idx,int h){
        Node*newnode=new Node(idx,h);
        newnode->next=top;
        top=newnode;
    }

    void pop(){
        if(top==nullptr)return;
        Node*temp=top;
        top=top->next;
        delete temp;
    }

    bool empty(){
        return top==nullptr;
    }

    int peekindex(){
        if(top==nullptr)return -1;
        return top->index;
    }

    int peekheight(){
        if(top==nullptr)return -1;
        return top->height;
    }
};

int largestrectanglearea(int heights[],int n){
    Stack st;
    int maxarea=0;
    for(int i=0;i<=n;i++){
        int h;
        if(i==n)h=0;
        else h=heights[i];
        int lastindex=i;
        while(!st.empty()&&h<st.peekheight()){
            int height=st.peekheight();
            int index=st.peekindex();
            st.pop();
            lastindex=index;
            int width=i-index;
            int area=height*width;
            if(area>maxarea)maxarea=area;
        }
        st.push(lastindex,h);
    }
    return maxarea;
}

int main(void){
    int heights[]={2,1,5,6,2,3};
    int n=sizeof(heights)/sizeof(heights[0]);
    cout<<"LARGEST RECTANGLE AREA:"<<largestrectanglearea(heights,n)<<endl;
    return 0;
}

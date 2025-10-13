#include<bits/stdc++.h>
using namespace std;

class Call{
private:
    int callid,hour,minute;
    string customername;
public:
    Call(int ci,int h,int m,string cn){
        callid=ci;
        hour=h;
        minute=m;
        customername=cn;
    }
    int getid(){
	return callid;
	}
    int gethour(){return hour;}
    int getminute(){return minute;}
    string getname(){return customername;}
    int gettimeinminutes(){return hour*60+minute;}
};

class Callcenter{
private:
    queue<Call> callqueue;
    int numcsrs,currenttime;
    vector<bool> csravailable;
public:
    Callcenter(int csrs){
        numcsrs=csrs;
        csravailable.resize(csrs,true);
        currenttime=0;
    }
    void addcall(int id,int h,int m,string name){
        Call newcall(id,h,m,name);
        callqueue.push(newcall);
        cout<<"CALL ADDED-ID:"<<id<<" NAME:"<<name<<" ARRIVAL:";
        cout<<setw(2)<<setfill('0')<<h<<":";
        cout<<setw(2)<<setfill('0')<<m<<endl;
    }
    void processcall(){
        if(!callqueue.empty()) currenttime=callqueue.front().gettimeinminutes();
        while(!callqueue.empty()){
            for(int i=0;i<numcsrs;i++) csravailable[i]=true;
            int assigned=0;
            for(int i=0;i<numcsrs;i++){
                if(!callqueue.empty()){
                    Call currentcall=callqueue.front();
                    if(csravailable[i] && currentcall.gettimeinminutes()<=currenttime){
                        callqueue.pop();
                        csravailable[i]=false;
                        assigned++;
                        int h=currenttime/60;
                        int m=currenttime%60;
                        cout<<"CSR "<<i+1<<" is handling Call ID "<<currentcall.getid()
                            <<" from "<<currentcall.getname()<<" at time ";
                        cout<<setw(2)<<setfill('0')<<h<<":";
                        cout<<setw(2)<<setfill('0')<<m<<endl;
                    }
                }
            }
            if(assigned==0){
                if(!callqueue.empty()){
                    int nextCallTime=callqueue.front().gettimeinminutes();
                    if(nextCallTime>currenttime) currenttime=nextCallTime;
                    else currenttime++;
                }
            }else currenttime++;
        }
    }
};

int main(){
    Callcenter center(3);
    center.addcall(1,8,5,"Moazzam");
    center.addcall(2,8,41,"Ali");
    center.addcall(3,9,41,"Danyal");
    center.addcall(4,9,42,"Husn");
    center.addcall(5,10,43,"Saad");
    center.processcall();
    return 0;
}

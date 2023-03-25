#include<iostream>
using namespace std;
class Queue {
    public:
    int size;
    int* arr;
    Queue(int s){
        size=s;
        arr=new int[size];
        for(int i=0;i<size;i++){
            *(arr+i)=NULL;
        }
    }
    int b=-1;
    int f=-1;
    void dequeueF(){
        if(f!=b){
            arr[f+1]=NULL;
            f++;
        }
        else{
            cout<<"Empty"<<endl;
        }
        
    }
    void dequeueR(){
        if(f==b){
            cout<<"Empty"<<endl;
        }
        else{
            arr[b]=NULL;
            b--;
        }
        
    }
    void enqueueR(int a){
        if(b==size-1 && f==-1){
            cout<<"Full"<<endl;
        }
        else if(b==size-1 && f!=-1){
            Reset();
            arr[b+1]=a;
            b++;}
        else{
            arr[b+1]=a;
            b++;
        }
    }
    void enqueueF(int a){
        if(f==-1){
            cout<<"Full"<<endl;
        }
        else if(f!=-1){
            arr[f]=a;
            f--;
            }
    }
    bool isfull(){
        if(b==size-1 && f==-1){return true;}
        else{return false;}
    }
    bool isempty(){
        if(f==b){return true;}
        else{return false;}
    }
    int peek(int index){
        return arr[index+f+1];
    }
    int first(){return arr[f+1];}
    int last(){return arr[b];}
    void display(){
        for(int i=f+1; i<b+1;i++){
            cout<<arr[i]<<'\n';
        }
    }
    void Reset(){
        int* a= new int[b-f];
        for(int i=f+1; i<b+1;i++){
            a[i-f-1]= arr[i];
            arr[i]=NULL;
        }
        for(int i=0; i<b-f;i++){
            arr[i]= a[i];
        }
        b=b-f-1;
        f=-1;
    }
};
int main(){
    Queue q(5);
    q.enqueueR(0);
    q.enqueueR(1);
    q.enqueueR(2);
    q.enqueueR(3);
    q.enqueueR(4);
    q.dequeueR();
    // q.dequeue();
    // q.dequeue();
    // q.enqueue(3);
    q.display();


    
    // q.dequeue();
    // q.display();
    // cout<<q.f<<endl<<q.b<<endl;

    
return 0;
}
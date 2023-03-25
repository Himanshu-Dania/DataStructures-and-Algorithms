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
    void dequeue(){
        if(f!=b){
            arr[f+1]=NULL;
            f++;
        }
        else{
            cout<<"Empty"<<endl;
        }
        
    }
    void enqueue(int a){
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
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.dequeue();
    q.enqueue(3);
    q.display();


    
    // q.dequeue();
    // q.display();
    // cout<<q.f<<endl<<q.b<<endl;

    
return 0;
}
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
            arr[(f+1)%size]=NULL;
            f=(f+1)%size;
        }
        else{
            cout<<"Empty"<<endl;
            exit(1);
        }
        
    }
    void enqueue(int a){
        if((b+1)%size==f){
            cout<<"Full"<<endl;
            exit(2);
        }
        // else if(b==size-1 && f!=-1){
        //     // Reset();
        //     arr[(b+1)%size]=a;
        //     b++;}
        else{
            arr[(b+1)%size]=a;
            b=(b+1)%size;
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
};
int main(){
    Queue q(5);
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(1);
    cout<<q.f<<endl<<q.b<<endl;
    // q.enqueue(2);
    q.dequeue();
    cout<<q.f<<endl<<q.b<<endl;

    // q.dequeue();
    // q.enqueue(3);
    q.display();
    cout<<q.f<<endl<<q.b<<endl;


    
    // q.dequeue();
    // q.display();
    // cout<<q.f<<endl<<q.b<<endl;

    
return 0;
}
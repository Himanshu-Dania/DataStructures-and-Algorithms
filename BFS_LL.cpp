#include<iostream>
#include<list>
using namespace std;
class node{
    public:
    int data;
    list<node> head;
    node(){
        
    }
    node(int a){
        data=a;
        
    }
    node(int a, list<node> h){
        data=a;
        head=h;
    }
    bool operator==(node y){
        if(this->data==y.data){
            return true;
        }
        else return false;
    }
    void operator=(node y){
        this->data=y.data;
        this->head=y.head;
    }
};
node seek(list<node> l, int i){
    list<node>::iterator iter=l.begin();
    for(int j=0;j<i;j++){
        // cout<<iter->data<endl;
        iter++;
    }
    return *iter;
    // return iter->data;
}
// node null(-1);
class Queue {
    public:
    int size;
    node* arr;
    Queue(int s){
        size=s;
        arr=new node[size];
        // for(int i=0;i<size;i++){
        //     *(arr+i)=null;
        // }
    }
    int b=-1;
    int f=-1;
    void dequeue(){
        if(f!=b){
            f++;
        }
        else{
            cout<<"Empty"<<endl;
        }
        
    }
    void enqueue(node a){
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
    node peek(int index){
        return arr[index+f+1];
    }
    node first(){return arr[f+1];}
    node last(){return arr[b];}
    void Reset(){
        node* a= new node[b-f];
        for(int i=f+1; i<b+1;i++){
            a[i-f-1]= arr[i];
            
        }
        for(int i=0; i<b-f;i++){
            arr[i]= a[i];
        }
        b=b-f-1;
        f=-1;
    }
};

void BFS(node x, int size){

Queue explored(size);
int visited[size];

for(int i=0;i<size;i++){visited[i]=0;}
explored.enqueue(x);
visited[x.data]=1;
list<node>::iterator iter;
while(explored.isempty()==false){
    // cout<<iter->data<<endl;
    for(int i=0; i<explored.first().head.size();i++){
        if(visited[seek(explored.first().head, i).data]==0){
            // cout<<iter->data<<" s"<<endl;
            visited[seek(explored.first().head, i).data]=1;
            explored.enqueue(seek(explored.first().head, i));
    }
    }
    cout<<explored.first().data<<" ";
    explored.dequeue();

}

}
int main(){
node w(0);
node x(1);
node y(2);
node z(3);
x.head={w,y,z};
y.head={w,x};
z.head={x};
w.head={x,y};
BFS(z, 4);
return 0;
}

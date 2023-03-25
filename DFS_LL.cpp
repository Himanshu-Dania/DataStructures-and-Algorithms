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
class Stack {
    public:
    int size;
    Stack(int s){
        size=s;
        for(int i=0;i<s;i++){
            arr[i]=NULL;
        }
    }
    node* arr=new node[size];
    int top=-1;
    void pop(){
        top--;
    }
    void push(node a){
        arr[top+1]=a;
        top++;
    }
    bool isfull(){
        if(top==size-1){return true;}
        else{return false;}
    }
    bool isempty(){
        if(top==-1){return true;}
        else{return false;}
    }
    node peek(int index){
        return arr[index];
    }
    node stackTop(){return arr[top];}
    node stackBottom(){return arr[0];}
    void display(){
        for(int i=0; i<top+1;i++){
            cout<<arr[i].data<<'\n';
        }
    }
};
void BFS(node x, int size){

Stack explored(size);
int visited[size];

for(int i=0;i<size;i++){visited[i]=0;}
explored.push(x);
visited[x.data]=1;
list<node>::iterator iter;
while(explored.isempty()==false){
    // cout<<iter->data<<endl;
    cout<<explored.stackTop().data<<" ";
    node temp = explored.stackTop();
    explored.pop();
    for(int i=0; i<temp.head.size();i++){
        if(visited[seek(temp.head, i).data]==0){
            // cout<<iter->data<<" s"<<endl;
            visited[seek(temp.head, i).data]=1;
            explored.push(seek(temp.head, i));
        }
    }
    

}
cout<<endl;
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
BFS(w, 4);
BFS(x, 4);
BFS(y, 4);
BFS(z, 4);
return 0;
}

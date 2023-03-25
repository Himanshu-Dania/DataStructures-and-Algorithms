#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
class Stack {
    public:
    int size;
    Stack(int s){
        size=s;
        for(int i=0;i<s;i++){
            arr[i]=NULL;
        }
    }
    int* arr=new int[size];
    int top=-1;
    void pop(){
        arr[top]=NULL;
        top--;
    }
    void push(int a){
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
    int peek(int index){
        return arr[index];
    }
    int stackTop(){return arr[top];}
    int stackBottom(){return arr[0];}
    void display(){
        for(int i=0; i<top+1;i++){
            cout<<arr[i]<<'\n';
        }
    }

};

void DFS(int graph[4][4], int size, int in=0){
Stack explored(size);
int visited[size];
int index=in;

for(int i=0;i<size;i++){visited[i]=0;}
explored.push(index);
visited[index]=1;
while(explored.isempty()==false){
    cout<<explored.stackTop()<<" ";
    explored.pop();
    for(int i=0; i<size;i++){
        if(graph[index][i]==1 && visited[i]==0){
            explored.push(i);
            visited[i]=1;
        }
    }
    
    if(explored.isempty()==false){
        index=explored.stackTop();
    }
    else{
        break;
    }
}
cout<<endl;

}
int main(){

int graph[4][4]={
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {0,1,0,0}
};
DFS(graph,4,0);
DFS(graph,4,1);
DFS(graph,4,2);
DFS(graph,4,3);

return 0;
}
#include<iostream>
using namespace std;
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

void BFS(int graph[4][4], int size, int in=0){
Queue explored(size);
int visited[size];
int index=in;

for(int i=0;i<size;i++){visited[i]=0;}
explored.enqueue(index);
visited[index]=1;
while(explored.isempty()==false){
    for(int i=0; i<size;i++){
        if(graph[index][i]==1 && visited[i]==0){
            explored.enqueue(i);
            visited[i]=1;
        }
    }
    cout<<index<<" ";
    explored.dequeue();
    if(explored.isempty()==false){
        index=explored.first();
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
BFS(graph,4,0);
BFS(graph,4,1);
BFS(graph,4,2);
BFS(graph,4,3);

return 0;
}
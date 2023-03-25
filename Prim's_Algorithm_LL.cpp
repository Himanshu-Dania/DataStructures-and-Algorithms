#include<iostream>
#include<list>
using namespace std;
class node{
    public:
    int data;
    list<pair<node, int>> head;
    node(){
        
    }
    node(int a){
        data=a;
        
    }
    node(int a, list<pair<node, int>> h){
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
void createEdge(node *n, list<pair<node,int>> l){
    n->head= l;
}
pair<node, int> seek(list<pair<node, int>> l, int i){
    list<pair<node, int>>::iterator iter=l.begin();
    for(int j=0;j<i;j++){
        // cout<<iter->data<endl;
        iter++;
    }
    return *iter;
    // return iter->data;
}
void findMCST(node n[], int nodes){

int v[nodes];
for (int i = 0; i < nodes; i++)
{
    v[i]=0;
}
v[n[0].data]=1;
int cost=0;
int counter=nodes-1;

while(counter){
   node insert;
   int tmp=INT32_MAX;
   for(int i=0;i<nodes;i++){
    if(v[i]==1){
        for(int j=0; j<n[i].head.size();j++){
            
            if(v[seek(n[i].head, j).first.data]==0 && seek(n[i].head, j).second<tmp){
                
                tmp=seek(n[i].head, j).second;
                insert=seek(n[i].head, j).first;//gotta delete head for last node
            }
        }
    }
   }
   v[insert.data]=1;
   cout<<"("<<insert.data<<", "<<tmp<<"), ";

   counter--;
}
}
int main(){
node w(0);
node x(1);
node y(2);
node z(3);
w.head={{x,5}, {y,3}};
x.head={{w,5}, {y,9}, {z,4}};
y.head={{w,3}, {x,9}};
z.head={{x,4}};
node graph[]={w,x,y,z};

findMCST(graph, 4);

return 0;
}

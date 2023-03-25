#include<iostream>
#include<vector>
using namespace std;

void findMCST(vector<vector<int>> graph, int nodes, int in){
int g[nodes][nodes];
for (int i = 0; i < nodes; i++)
{
    for (int j = 0; j < nodes; j++)
    {
        g[i][j]=0;
    }
    
}
int v[nodes];
for (int i = 0; i < nodes; i++)
{
    v[i]=0;
}
v[in]=1;
int cost=0;
int counter=nodes-1;
while(counter){
    int tmp=INT32_MAX;
    int col;
    int row;
    for(int i=0;i<nodes;i++){
        if(v[i]==1){
            for (int j = 0; j < nodes; j++)
            {
                if(graph[i][j]<tmp&&v[j]==0&&graph[i][j]!=0){
                    tmp=graph[i][j];
                    col=j;
                    row=i;
                }

            }
              
        }

    }
    // cout<<row<<" "<<col<<endl;
    g[row][col]=tmp;
    g[col][row]=tmp;
    v[col]=1;
    cost+= tmp;
    counter--;
}
for (int i = 0; i < nodes; i++)
{
    for (int j = 0; j < nodes; j++)
    {
        cout<<g[i][j]<<" ";
    }
    cout<<endl;
}
cout<<"Cost of MCST is "<<cost<<endl;
// return g;
}
int main(){
 
vector<vector<int>> graph{
    {0,5,3,0},
    {5,0,9,4},
    {3,9,0,0},
    {0,4,0,0}
};
int nodes = 4;
int begin=2;
vector<vector<int>> MCST;
//MCS=12 2-0-1-3
findMCST(graph, nodes, begin);
return 0;
}
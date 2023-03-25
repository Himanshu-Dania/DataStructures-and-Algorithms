#include<iostream>
using namespace std;
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<endl;
    }
    
}
int main(){

int temp;
int arr[]={3,2,2,9,7};
int s =sizeof(arr)/4;
for(int i=0;i<s;i++){
    temp=i;
    for(int j=i;j<s;j++){
        if(arr[temp]>arr[j]){
            temp=j;
        }
    }
    swap(arr[temp], arr[i]);
}
printArray(arr,s);




return 0;
}
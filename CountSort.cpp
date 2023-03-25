#include<iostream>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<endl;
    }
    
}
void CountSort(int arr[], int n){
    int max=0;
    for(int i=0;i<n;i++){if(max<arr[i]){max=arr[i];}}
    int count[max+1];
    for(int i=0;i<max+1;i++){count[i]=0;}
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    int temp=0;
    int j=0;

    for(int i=0;i<max+1;i++){
        temp=count[i];
        while(temp!=0){
            arr[j]=i;
            j++;
            temp--;
        }
    }
}
int main(){
    int arr[]={0,2,1,2,9};
    CountSort(arr, 5);
    printArray(arr,5);
return 0;
}
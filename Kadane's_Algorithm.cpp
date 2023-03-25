#include<iostream>
using namespace std;
pair<int,pair<int,int>> MaxSumSubArray(int arr[], int n){
    int best=arr[0];
    int sum=arr[0];
    int a=0;
    int b=1;
    for(int i=1; i < n; i++){
        sum+=arr[i];
        if(sum>best){
            best=sum;
            b=i;
        }
        else if(sum<arr[0]){
            a=i+1;
            sum=arr[0];
        }
    }
    pair<int,pair<int,int>> x = {best, {a,b}};
    return x;
}
int main(){
int arr[]={0,5,2,5,-6,3};
pair<int,pair<int,int>> x = MaxSumSubArray(arr, 6);
cout<<x.first<<endl<<x.second.first<<endl<<x.second.second;
//SUM, START INDEX, END INDEX
return 0;
}
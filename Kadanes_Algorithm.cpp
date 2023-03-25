#include<iostream>
using namespace std;
pair<int,pair<int,int>> MaxSumSubArray(int arr[], int n){
    int best=0;
    int sum=0;
    int a=0;
    int b=0;
    int negsum=INT32_MIN;
    bool negarr;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
           negarr=false;
           break; 
        }
        else if(arr[i]>negsum){
            negarr=true;
            negsum=arr[i];
            a=i;
            b=i;
        }
    }
    if(negarr==true){
        return {negsum,{a,b}};
        }

    
    for(int i=0; i < n; i++){
        sum+=arr[i];
        if(sum>best){
            best=sum;
            b=i;
        }
        else if(sum<0){
            a=i+1;
            sum=0;
        }
    }
    pair<int,pair<int,int>> x = {best, {a,b}};
    return x;
}
int main(){
int arr[]={-5,-9,-4};
pair<int,pair<int,int>> x = MaxSumSubArray(arr, 3);
cout<<x.first<<endl<<x.second.first<<endl<<x.second.second;
//SUM, START INDEX, END INDEX
return 0;
}
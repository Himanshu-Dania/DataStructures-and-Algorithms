#include<iostream>
using namespace std;

int binarysearch(int arr[],int low, int high, int x){
 int mid=(low+high)/2;
 if(arr[low]==x){return low;}
 else if(arr[high]==x){return high;}
 else if(arr[mid]==x){return mid;}
 else if(arr[mid]>x){
return binarysearch(arr,low+1, mid-1, x);
 }
 else{
return binarysearch(arr,mid+1,high-1,x);
 } 
}
int main(){
int arr[]={1,2,3,4,5,6,9};
cout<<binarysearch(arr, 0, 6, 3+);
return 0;
}
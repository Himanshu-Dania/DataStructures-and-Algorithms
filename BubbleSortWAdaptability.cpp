#include<iostream>
using namespace std;

int main(){
int n;
cin>>n;
int arr[n];

int count=0;
int totalcalls=0;
for(int i=0; i<n;i++){
    cin>>arr[i];
}
for(int i=0; i<n-1;i++){
  for(int j=0; j<n-1-i; j++){
      if(arr[j]>arr[j+1]){
          swap(arr[j], arr[j+1]);
          count++; 
      } 
  }
  totalcalls++;
  if(count==0){
        break;
      }
  else{
        count=0;
        
      }
}
for(int i=0; i<n;i++){
    cout<<arr[i]<<endl;
}
return 0;
}
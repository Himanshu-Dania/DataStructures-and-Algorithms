#include<iostream>
using namespace std;

int main(){
int n;
int arr[n];
for(int i=0; i<sizeof(arr)/4;i++){
    cin>>arr[i];
}


for(int i=0; i<sizeof(arr)/4-1;i++){
  for(int j=0; j<sizeof(arr)/4-1-i; j++){
      if(arr[j]>arr[j+1]){
          swap(arr[j], arr[j+1]);
          
      }
      
  }
}
for(int i=0; i<sizeof(arr)/4;i++){
    cout<<arr[i]<<endl;
}
return 0;
}
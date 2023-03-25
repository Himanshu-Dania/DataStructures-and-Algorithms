#include<iostream>
using namespace std;
void Sieve(int x){
    int prime[x+1]={0};
    prime[0]=1;
    for(int k=2; k<=x;k++){
        if(prime[k]==0){
            // cout<<k<<" ";
            for(int j=k*k; j<=x;j+=k){
                
                prime[j]=1;
                
            }
        }
    }
    for(int l=0;l<x+1;l++){
        if(prime[l]==0){
            cout<<l<<" ";
        }
    }
    cout<<endl;
}
int main(){
Sieve(INT32_MAX);
return 0;
}
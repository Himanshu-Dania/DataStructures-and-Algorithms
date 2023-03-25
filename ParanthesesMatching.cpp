#include<iostream>
#include<String>
using namespace std;
class Stack {
    public:
    int size;
    
    int* arr=new int[size];
    Stack(int s){
        size=s;
        for(int i=0;i<s;i++){
            arr[i]=NULL;
        }
    }
    int top=-1;
    void pop(){
        if(top==-1){
            cout<<"Unbalanced Parantheses"<<'\n';
            exit(1);
        }
        arr[top]=NULL;
        top--;
    }
    void push(int a){
        arr[top+1]=a;
        top++;
    }
    bool isfull(){
        if(top==size-1){return true;}
        else{return false;}
    }
    bool isempty(){
        if(top==-1){return true;}
        else{return false;}
    }
    int peek(int index){
        return arr[index];
    }
    int stackTop(){return arr[top];}
    int stackBottom(){return arr[0];}
    void display(){
        for(int i=0; i<top+1;i++){
            cout<<arr[i]<<'\n';
        }
    }

};
int main(){
    string str;
    cin>>str;
    int n = str.length();
    Stack s(n);
    for(int i=0; i<n; i++){
        if(str[i]=='('){
            s.push(1);
        }
        else if(str[i]==')'){
            s.pop();
        }
    }
    if(s.isempty()==true){
        cout<<"Balanced Parantheses"<<'\n';
    }
    else{
        cout<<"Unbalanced Parantheses"<<'\n';
        exit(2);
    }
    
    return 0;
}
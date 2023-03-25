#include<iostream>
using namespace std;
class Stack {
    public:
    int size;
    Stack(int s){
        size=s;
        for(int i=0;i<s;i++){
            arr[i]=NULL;
        }
    }
    int* arr=new int[size];
    int top=-1;
    void pop(){
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
    Stack a(5);
    cout<<a.isempty()<<'\n';
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    a.push(5);
    a.display();
    cout<<a.isempty()<<'\n'<<a.isfull()<<'\n';
    a.push(4);
    a.pop();
    a.push(9);
    a.push(5);
    a.display();
    cout<<a.isempty()<<'\n'<<a.isfull()<<'\n';
    cout<<a.stackTop()<<'\n'<<a.stackBottom()<<'\n'<<a.peek(4);
return 0;
}
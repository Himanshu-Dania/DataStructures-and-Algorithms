#include<iostream>
#include<String>
using namespace std;
class Stack {
    public:
    int size;
    
    char* arr=new char[size];
    Stack(int s){
        size=s;
        for(int i=0;i<s;i++){
            arr[i]=NULL;
        }
    }
    int top=-1;
    void pop(){
        if(top==-1){
            cout<<"StackUnderflow"<<'\n';exit(1);
        }
        arr[top]=NULL;
        top--;
    }
    void push(char a){
        if(top==size-1){cout<<"StackOverflow"<<'\n';exit(2);}
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
    char peek(int index){
        return arr[index];
    }
    char stackTop(){return arr[top];}
    char stackBottom(){return arr[0];}
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
    string fstr;
    int x;
    for(int i=0; i<n; i++){
        x =s.top;
        
        cout<<str[i]<<endl;
        cout<<x<<endl;
        if(str[i]=='*' || str[i]=='/'){
            for(int j=0; j<x+1;j++){
                cout<<"Inside /* for"<<endl;
                if(s.stackTop()=='/' || s.stackTop()=='*'){
                    fstr.push_back(s.stackTop());
                    s.pop();
                    cout<<"Popped"<<endl;
                }
                else if(s.stackTop()=='+' || s.stackTop()=='-'){
                    cout<<"Break"<<endl;
                    break;
                }   
            }
            s.push(str[i]);
            }
        else if(str[i]=='+' || str[i]=='-'){
            for(int j=0; j<x+1;j++){
                cout<<"Inside +- for"<<endl;
                if(s.stackTop()=='/' || s.stackTop()=='*' || s.stackTop()=='+' || s.stackTop()=='-'){
                    fstr.push_back(s.stackTop());
                    s.pop();
                    cout<<"Popped"<<endl;
                }
            }
            s.push(str[i]);
        }
        else {
            cout<<"Pushed in formatted str"<<endl;
           fstr.push_back(str[i]); 
        }
    }
    x=s.top;
    for(int i=0;i<x+1;i++){
        cout<<"Emptying-Pushing in "<<s.stackTop()<<endl;
        fstr.push_back(s.stackTop());
        s.pop(); 
    }

    cout<<fstr<<endl;


    return 0;
}
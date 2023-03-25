#include<iostream>
using namespace std;
class Node{
 public:
 int data;
 Node* next;
 Node(int d){data=d;}
 
};
void Insert(Node*& h, Node& x, int index=0){
        x.next=h;
        h=&x;  
}
void Delete(Node*& h){
    
        h=h->next;
}
void Display(Node* head){
     for(Node *i=head;i!=NULL;i=i){
         cout<<i->data<<endl;
         i=i->next;
     }
 }
class Stack {
    Node* head;
    public:
    // int size;
    
    Stack(int headdata=NULL){
        // size=s;
        head=new Node(headdata);
        head->next=NULL;
    }
    int top=-1;
    void pop(){
        if(top==-1){
            cout<<"Fail";
        }
        else if(top==0){
            head->data=NULL;
        }
        else{
            head=head->next;
        }
    }
    void push(Node &n){
        cout<<top;
        if(top==-1){
            head->data=n.data;
            top=0;
        }
        else{
       n.next=head;
       head=&n;
       top++;
        }
    }
    bool isempty(){
        if(top==-1){return true;}
        else{return false;}
    }
    int peek(int index){
        Node* t=head;
        for(int i=0;i<index;i++){
         t=t->next;
        }
        return t->data;
    }
    int stackTop(){return head->data;}
    int stackBottom(){
        Node* temp;
        for(temp=head;temp->next!=NULL;temp=temp){
         temp=temp->next;
        }
         return temp->data;
     
    }
    void display(){
        for(Node *i=head;i!=NULL;i=i){
         cout<<i->data<<endl;
         i=i->next;
     }
    }

};
int main(){
    Stack s;
    Node a(5);
    Node b(6);
    Node c(7);
    s.push(a);
    s.push(b);
    s.push(c);
    s.display();
    s.pop();
    s.display();
    cout<<s.stackBottom()<<'\n';
    
    cout<<s.peek(0)<<'\n';
    cout<<s.peek(1)<<'\n';
    s.pop();
    // cout<<s.peek()<<'\n';
    s.display();

    
return 0;
}
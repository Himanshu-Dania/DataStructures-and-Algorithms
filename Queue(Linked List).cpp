#include<iostream>
using namespace std;
class Node{
 public:
 int data;
 Node* next;
 Node(int d){data=d;}
 
};
void Insert(Node*& h, Node& x, int index){
    if(index==0){
        x.next=h;
        h=&x;
    }
    else{
        Node* temp = h;
        for(int i=0;i<index-1; i++){
            temp=temp->next; 
        }

        x.next=temp->next;
        temp->next=&x;
    } 
}
void Delete(Node*& h,int index){
    if(index==0){
        h=h->next;
    }
    else{
        Node* temp = h;
        for(int i=0;i<index-1; i++){
            temp=temp->next; 
        }
        temp->next=(temp->next)->next;
    }
}
void Display(Node*& head){
     for(Node *i=head;i!=NULL;i=i){
         cout<<i->data<<endl;
         i=i->next;
     }
 }

 class Queue {
    public:
    Node* f;
    Node* r;
    Queue(){
        f= new Node(NULL);
        f->next=NULL;
        r=f; 
    }
    void dequeue(){
        if(r==f && f->data==NULL){
            cout<<"Underflow"<<endl;
        }
        else if(r==f && f->data!=NULL){
            f->data==NULL;
            r=f;
        }
        else{
            f=f->next;
            cout<<f->data<<endl<<r->data<<endl;
        }
 }
    void enqueue(Node &n){
        if(r==f && f->data==NULL){
            f->data=n.data;
            // cout<<f->data<<endl<<r->data<<endl;
        }
        else{
            r->next=&n;
            r=&n;
            n.next=NULL;
            // cout<<f->data<<endl<<r->data<<endl;
        }
    }
    bool isempty(){
        if(f==r&&f->data==NULL){return true;}
        else{return false;}
    }   
    int peek(int index){
        Node* temp = f;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
    int first(){return f->data;}
    int last(){return r->data;}
    
    void display(){
        for(Node* i = f; i!=NULL; i=i->next){
            cout<<i->data<<endl;
        }
    }  
};

int main(){
    Node node1(5);
    Node node2(7);
    Node node3(9);
    Node node4(2);
    Queue q;
    q.enqueue(node1);
    q.enqueue(node2);
    q.enqueue(node3);
    q.enqueue(node4);
    q.dequeue();
    q.display();
    q.peek(0);
    q.peek(1);
    q.peek(2);
return 0;
}
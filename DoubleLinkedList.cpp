#include<iostream>
using namespace std;
class Node{
 public:
 int data;
 Node* next;
 Node* prev;

 Node(int d){data=d;}
 
};
void Insert(Node*& h, Node& x, int index){
    if(index==0){
        x.next=h;
        x.prev=NULL;
        h->prev=&x;
        h=&x;
    }
    else{
        Node* temp = h;
        for(int i=0;i<index-1; i++){
            temp=temp->next; 
        }
        x.prev=temp;
        x.next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=&x;
            temp->next=&x;
        }
        else{
            temp->next=&x;
        }
    } 
}
void Delete(Node*& h,int index){
    if(index==0){
        h->next->prev=NULL;
        h=h->next;
        
    }
    else{
        Node* temp = h;
        for(int i=0;i<index-1; i++){
            temp=temp->next; 
        }
        if(temp->next->next!=NULL){
            temp->next->next->prev=temp;
            temp->next=temp->next->next;
        }
        else{
            temp->next=NULL;
        }
    }
}
void Display(Node*& head){
     for(Node *i=head;i!=NULL;i=i){
         cout<<i->data<<endl;
         i=i->next;
     }
 }
int main(){
    Node node1(5);
    Node node2(7);
    Node node3(9);
    Node node4(2);
    node1.next=&node2;
    node2.next=&node3;
    node3.next=&node4;
    node4.next=NULL;
    node1.prev=NULL;
    node2.prev=&node1;
    node3.prev=&node2;
    node4.prev=&node3;
    Node node(8);
    Node* head = &node1;
    // Insert(head,node, 0);
    // Delete(head, 3);
    // cout<<head->data<<endl;
    // cout<<head->next->data<<endl;
    // cout<<head->next->next->data<<endl;
    // // cout<<head->next->next->next->data<<endl;

    Display(head);
return 0;
}
#include<iostream>
using namespace std;
class Node{
 public:
 int data;
 Node* next;
 Node(int d){data=d;}
 
};
void Insert(Node*& l, Node& x, int index){
   
        Node* temp = l;
        for(int i=0;i<index; i++){
            temp=temp->next; 
        }

        if(temp!=l){
            x.next=temp->next;
            temp->next=&x;
        }
        else{
            l=&x;
            x.next=temp->next;
            temp->next=&x;
        }
    
}
void Delete(Node*& l,int index){
    
  
        Node* temp = l;
        for(int i=0;i<index; i++){
            temp=temp->next; 
        }
        if(temp!=l){
            temp->next=(temp->next)->next;
        }
        else{
            temp->next=(temp->next)->next;
            l=temp;
        }
}
void Display(Node* last){
     Node* i=last->next;
     do{
         cout<<i->data<<'\n';
         i=i->next;
     }
     while(i!=last->next);
 }
int main(){
    Node node1(5);
    Node node2(7);
    Node node3(9);
    Node node4(2);
    node1.next=&node2;
    node2.next=&node3;
    node3.next=&node4;
    node4.next=&node1;
    Node node(8);
    Node* last = &node4;
    Delete(last, 3);
    // Delete(head, 0);
    // cout<<head->data<<'\n';
    // cout<<head->next->data<<'\n';
    // cout<<head->next->next->data<<'\n';
    // cout<<head->next->next->next->data<<'\n';
    // cout<<head->next->next->next->data<<'\n';
    Display(last);
return 0;
}
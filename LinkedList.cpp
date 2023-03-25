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
int main(){
    Node node1(5);
    Node node2(7);
    Node node3(9);
    Node node4(2);
    node1.next=&node2;
    node2.next=&node3;
    node3.next=&node4;
    node4.next=NULL;
    Node node(8);
    Node* head = &node1;
    Insert(head,node, 0);
    Delete(head, 0);

    Display(head);
return 0;
}
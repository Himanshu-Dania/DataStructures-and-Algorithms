#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* l=NULL;
    Node* r=NULL;
    Node(int data){
        this->data=data;
    }
    Node(int data , Node* a, Node* b){
        this->data=data;
        l=a;
        r=b;
    }
};

void preorder(Node* n){
    if(n!=NULL){
        cout<<n->data<<endl;
        preorder(n->l);
        preorder(n->r);
    }
    else{
    }

}
void postorder(Node* n){
    if(n->l==NULL && n->r==NULL){
        if(n!=NULL){
            cout<<n->data<<endl;
        }
    }
    else if(n->l!=NULL && n->r!=NULL){
        postorder(n->l);
        postorder(n->r);
        cout<<n->data<<endl;
    }
    else if(n->l==NULL && n->r!=NULL){
        postorder(n->r);
        cout<<n->data<<endl;
    }
    else if(n->l!=NULL && n->r==NULL){
        postorder(n->l);
        cout<<n->data<<endl;
    }
}

void inorder(Node* n){
    if(n!=NULL){
        inorder(n->l);
        cout<<n->data<<" ";
        inorder(n->r);
    }
}
int main(){
Node* root = new Node(5, new Node(8, NULL, new Node(0)), new Node(1, new Node(4), NULL));/*
        5
    8      1
   10  0    4   9
*/
preorder(root);

// postorder(root);
// inorder(root);
return 0;
}
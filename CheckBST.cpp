#include<iostream>
#include<vector>
using namespace std;
int count=0;
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

bool CheckBST(Node* n, int min=INT32_MIN, int max=INT32_MAX){
    count++;
    if(n==NULL){return true;}
    else if(n->data>=min && n->data<=max && CheckBST(n->l, min, n->data) && CheckBST(n->r, n->data, max)){
        return 1;
    }
    else{return 0;}
}

void inorder(Node* n){
    if(n->l==NULL && n->r==NULL){
        if(n!=NULL){
            cout<<n->data<<" ";
        }
    }
    else if(n->l!=NULL && n->r!=NULL){
        inorder(n->l);
        cout<<n->data<<" ";
        inorder(n->r);
        
    }
    else if(n->l==NULL && n->r!=NULL){
        inorder(n->r);
        cout<<n->data<<" ";
    }
    else if(n->l!=NULL && n->r==NULL){
        inorder(n->l);
        cout<<n->data<<" ";
    }
}
int main(){
Node* root = new Node(5, new Node(1, new Node(0), new Node(2)), new Node(7, new Node(6), new Node(9)));/*
        5
    1      7
   0  2   6   9
*/
inorder(root);
cout<<endl;
cout<<CheckBST(root);
cout<<endl;
cout<<count;
return 0;
}
#include<iostream>
#include<vector>
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
vector<int> vinorder(Node* n){
    static vector<int> v;
    if(n->l==NULL && n->r==NULL){
        if(n!=NULL){
            v.push_back(n->data);
        }
    }
    else if(n->l!=NULL && n->r!=NULL){
        vinorder(n->l);
        v.push_back(n->data);
        vinorder(n->r);
        
    }
    else if(n->l==NULL && n->r!=NULL){
        vinorder(n->r);
        v.push_back(n->data);
    }
    else if(n->l!=NULL && n->r==NULL){
        vinorder(n->l);
        v.push_back(n->data);
    }
    return v;
}
void display(vector<int> a){
    vector<int>::iterator it ;
    for(it=a.begin(); it !=a.end(); it++){
        cout<<*it<<" ";
    }
    
}
void CheckBST(Node* n){
    vector<int> v;
    v =vinorder(n);
    v.shrink_to_fit();
    vector<int>::iterator it;
    int prev=*v.begin();
    
    
    // display(v);
    for(it=v.begin()+1; it !=v.end(); it++){
        if(prev<= *it){
            prev= *it;
            continue;
        }
        else{
            cout<<"False";
            break;
        }
    }
    cout<<"True";

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
CheckBST(root);
cout<<endl;
return 0;
}
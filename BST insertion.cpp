#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* NewNode(int data){
    Node* temp=new Node();
    temp->key=data;
    temp->left=temp->right=NULL;
    return temp;
}

Node* insert(Node* root, int data){
    if(root==NULL){
        return NewNode(data);
        
    }
    if(root->key>data){
        root->left=insert(root->left,data);
    }
    
    else if(root->key<data){
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
int main(){
    int n;
    cout<<"enter the array size";
    cin>>n;
    Node* root=NULL;
    
    for(int i=0;i<n;i++){
        int a;
        cout<<"enter the ith value"<<" "<<i;
        cin>>a;
        root=insert(root,a);
    }
    inorder(root);
}
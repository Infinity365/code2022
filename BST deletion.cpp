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

Node* minValue(Node* q){
    while(q&& q->left!=NULL){
        q=q->left;
    }
    return q;
}

Node* delete(Node* root,int val){
   if( root->key>val){
       root->left=delete(root->left,val);
   }
   
   else if(root->key<val){
       root->right=delete(root->right,val);
   }
   
   else{
       if(root->left==NULL && root->right==NULL){
           free(root);
           return NULL;
       }
       
       else if(root->left==NULL){
           Node* temp=root->right;
           
          free(root);
          return temp;
           
       }
       
       else if(root->right==NULL){
           Node* temp=root->left;
           free(root);
           return temp;
       }
       
       else{
           Node* temp=minValue(root->right);
           
           root->value=temp->value;
          root->right= delete(root->right,temp->value);
       }
       
     
   }
     return root;
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
    int val;
    cout<<" enter the value to be delete";
    
    cin>>val;
    
    root=delete(root,val);
   
    inorder(root);
    
    return 0;
}
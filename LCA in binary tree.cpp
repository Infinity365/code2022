{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    Node* findnode(Node* root,int n1,int n2){
        Node* left1;
        Node* right1;
        if(root==NULL)
        return NULL;
        
        if(root->data==n1 || root->data==n2)
        return root;
        
        left1=findnode(root->left,n1,n2);
        right1=findnode(root->right,n1,n2);
        
        if(left1 && right1)
        return root;
        
        return (left1!=NULL)? left1: right1;
        
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       Node * ans=findnode(root,n1,n2);
       
       return ans;
    }
};

https://www.youtube.com/watch?v=_-QHfMDde90
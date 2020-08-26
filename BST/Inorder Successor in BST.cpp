/ returns the inorder successor of the Node x in BST (rooted at 'root')
int cnt=0;
Node * inOrderSuccessor(Node *root, Node *x)
{
    stack<Node*>st; bool flag=0;
    Node* ans=NULL;
    while(root!=NULL || !st.empty())
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        Node* temp=st.top(); st.pop();
        if(temp==x){
            flag=1;
        }
        if(flag==1)
        {
          ans=temp;
          break;
        }
        root=root->right;
        
    }
    return ans;
    
}

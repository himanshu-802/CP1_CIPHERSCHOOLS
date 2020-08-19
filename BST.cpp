#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int val;
		Node* left;
		Node* right;
		Node(){
			this->left=this->right=NULL;
		}
		Node(int data){
			this->val=data;
			this->left=this->right=NULL;
		}
};

class BST{
	public:
		Node* root;
		Tree(){
			root=NULL;
		}
		bool searchHelper(Node* ptr,int val)
		{
			if(ptr==NULL)return false;
			if(ptr->val==val)return true;
			//return searchHelper(ptr->left,val)|| searchHelper(ptr->right,val);		
            if(ptr->val < val)
            {
            	return searchHelper(ptr->right,val);
			}
			else{
				return searchHelper(ptr->left,val);
			}
		}
		bool search(int val){
			Node* ptr=root;
			return searchHelper(ptr,val);
		}
		Node* insertHelper(Node* ptr,int val)
		{
			if(ptr==NULL){
				Node* newnode= new Node(val);
				return newnode;
			}
			if(ptr->val <= val){
				ptr->right= insertHelper(ptr->right);
				
			}
			else 
				ptr->left= insertHelper(ptr->left);
			}
			return ptr;
			
		}
		void insertNode(int val)
		{
			Node* ptr=root;
			root=insertHelper(ptr,val);
		}
		
		Node* deleteNodeHelper(Node* ptr, int val)
		{
			if(ptr==NULL)return NULL;
			if(ptr->val <val)
			{
				ptr->right= deleteNodeHelper(ptr->right,val);
				return ptr;
			}
			else if(ptr->val> val){
				ptr->left=deleteNodeHelper(ptr->left,val);
				return ptr;
			}
			else{
				if(ptr->left==NULL){
					Node* temp=ptr->right;
					delete ptr;
					return temp;
				}
				if(ptr->right==NULL)
				{
					Node* temp=ptr->left;
					delete ptr;
					return temp;
				}
				// BOTH ARE NOT NULL
				int maxVal=findMax(ptr->left);
				ptr->val=maxVal;
				ptr->left=deleteNodeHelper(ptr->left,maxVal);
				return ptr;
			}
		}
		void deleteNode(int val)
		{
			root= deleteNodeHelper(root,val);
		}
		
		void inOrderHelper(Node* ptr){
			if(ptr==NULL)return;
			inOrderHelper(ptr->left);
			cout<<ptr->val<<" ";
			inOrderHelper(ptr->right);
		}
		void inOrder(){
			inorderHelper(root);
			cout<<endl;
		}
		int height(Node* ptr)
		{
			if(ptr==NULL){
				return 0;
			}
			return 1+ max(height(ptr->left),height(ptr->right));
		}
		void printLevel(Node* ptr, int level)
		{
			if(ptr==NULL)return;
			if(level==1)cout<<ptr->val<<" ";
			else if(level>1){
				printLevel(ptr->left,level-1);
				printLevel(ptr->right,level-1);
			}
		}
		void LevelOrder(){
			if(root==NULL)return;
			int h= height();
			for(int i=1;i<=h;i++)
			{
				printLevel(root,i);
				cout<<"\n";

		}
		void inOrderIterative()
		{
			Node* ptr=root;
			if(root==NULL)return;
		   stack<Node*>st;
			while(!ptr || !st.empty()){
				while(!ptr){
					s.push(ptr);
					ptr->left;
				}
				ptr=st.top() ; st.pop();
				cout<<ptr->val<<" ";
				ptr=ptr->right;
			}
		
			
		}
};

int main()
{
	BST* root= new BST();
}

//===========================================================================
// Name    	: aditya_a6.cpp
// Author  	: Aditya Agre
// Version 	:
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* right;
	node* left;
    
	node(int k){
    	right=NULL;
    	left=NULL;
    	data=k;
	}
    
    
    
	void show(){
    	cout<<data<<endl;
	}
};

void inorder(node *head){
    
    
	//Left
	if(head->left!=NULL){
    	//recursively passing left subtree
    	inorder(head->left);
	}
    
	//root
	head->show();
    
	//right
	if(head->right!=NULL){
        	//recursively passing right subtree
        	inorder(head->right);
    	}}
   	 
void preorder(node *head){
    
	//root
	head->show();
    
	//left
	if(head->left!=NULL){
    	//recursively passing left subtree
    	preorder(head->left);
	}
    
	//right
	if(head->right!=NULL){
        	//recursively passing right subtree
        	preorder(head->right);
    	}
    
    
}

void postorder(node *head){
    
	//left
	if(head->left!=NULL){
    	//recursively passing left subtree
    	postorder(head->left);
	}
    
	//right
	if(head->right!=NULL){
        	//recursively passing right subtree
        	postorder(head->right);
    	}
   	 
   	 
	//root
	head->show();
    
}
   	 



node* insert(node *head, node *new_address, int val, node *new_node){
    
    
	//case where tree is empty
	if(head==NULL){
    	head=new_node;
   	 
	}
    
	//tree is not empty
	else{
    
	// if our number is smaller than current node
	// we go to left
	if(new_address->data>val){
    	if(new_address->left==NULL){    	//going to the end(leaf node)
        	new_address->left=new_node; 	//and then adding new node
    	}
   	 
    	else{
        	insert(head, new_address->left, val, new_node);
        	// if the cuurent node (root) isnt a leaf node
        	// pass the next left node recursively to insert
    	}
	}
    
	// if our number is greater than current node(root)
	// we go to right
	if(new_address->data<val){
    	if(new_address->right==NULL){   	//going to the end(leaf node)
        	new_address->right=new_node;	//and then adding new node
    	}
   	 
    	else{
        	insert(head, new_address->right, val, new_node);    
        	// if the cuurent node (root) isnt a leaf node
        	// pass the next right node recursively to insert
    	}
	}
    
    
}
	return head;
}

int main(){
    
    
	node *head=NULL;
	int n;
	cout<<"Enter number of nodes:"<<endl;
	cin>>n;
    
	for(int i=0; i<n;i++){
    	cout<<"Enter data"<<endl;
    	int kk;
    	cin>>kk;
   	 
    	node *newnode= new node(kk);
   	 
    	head=insert(head, head, kk, newnode);
   	 
	}
    
	cout<<endl<<"Binary tree Inorder:"<<endl;
	inorder(head);
	cout<<"Binary tree Preorder:"<<endl;
	preorder(head);
	cout<<"Binary tree Postorder:"<<endl;
	postorder(head);
}
   	 




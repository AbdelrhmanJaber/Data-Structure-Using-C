#include<stdio.h>
#include<stdlib.h>
#include"binaryTree.h"

tree* CreateTree(tree*root)
{
	root=NULL;
	return root;
}

tree* CreateNode(int data)
{
	tree* temp=(tree*)malloc(sizeof(tree));
	temp->value=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

tree* Inserttree(tree*root,int data)
{
	tree* current,*prev;
	current=root;
	if(!root)
		root=CreateNode(data);
	else
	{
		while(current)
		{
			prev=current;
			if(LessThan(data,current->value))
				current=current->left;
			else
				current=current->right;
		}
	if(LessThan(data,(prev->value)))
		prev->left=CreateNode(data);
	else
		prev->right=CreateNode(data);
	}
	return root;
}

int LessThan(int data,int parentData)
{
	return (data<parentData)? 1:0;
}

int Equal(int data,int parentData)
{
	return(data==parentData)?1:0;
}

void HelpDisplay(tree*root)
{
	   tree*parent=root;
	   if(!parent) return;
	   HelpDisplay(parent->left);
	   printf("%d ",parent->value);
	   HelpDisplay(parent->right);
}

void Display(tree*root)
{
	if(!root){
		printf("the tree is empty\n");
	return;}
	else
		HelpDisplay(root);
}

int TreeSize(tree*root)
{
	if(!root)
		return 0;
	return (1+TreeSize(root->right)+TreeSize(root->left));
}

int TreeDepth(tree*root)
{
   if(!root) 
	   return 0;
   int a=TreeDepth(root->left);
   int b=TreeDepth(root->right);
   return (a>b)?a+1:b+1;
}

void HelpClearTree(tree*root)
{
	if(root)
	{
		HelpClearTree(root->left);
		HelpClearTree(root->right);
		free(root);
	}
}

tree* ClearTree(tree*root)
{
	HelpClearTree(root);
	root=NULL;
	return root;
}

int FindElement(tree*root,int data)
{
	tree*temp=root;
	int found=0;
		while(temp)
		{
			if(Equal(data,temp->value))
			  found=1;
		  
			if(LessThan(data,temp->value))
				temp=temp->left;
			else
				temp=temp->right;	
		}
	return found;
}

int DeleteElement(tree*root,int data)
{
	tree*temp=root;
	tree*prev=NULL;
	int found=0;
	while(temp&&!(found=(Equal(data,temp->value))))
		{
			prev=temp;
			if(LessThan(data,temp->value))
				temp=temp->left;
			else
				temp=temp->right;				
		}
		
	if(found)
	{
		if(!prev)
			root=DeleteNode(root);
		else if(LessThan(data,prev->value))
			temp=DeleteNode(prev->left);
		else
			temp=DeleteNode(prev->right);
	}
	return found;
}

tree* DeleteNode(tree*root)
{
	tree*temp=root;
	tree*current,*prev;
	if(!(temp->left))
		temp=temp->right;
	else if(!(temp->right))
		temp=temp->left;
	else
	{
		current=temp->left;
		if(!(current->right))
		{
			temp->value=current->value;
			temp->left=current->left;	
		}
		else
		{
			do
			{
				prev=current;
				current=current->right;
			}while(current->right);
			temp->value=current->value;
			prev->right=current->left;
		}
	}
	free(current);
	return temp;
}
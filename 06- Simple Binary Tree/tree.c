#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

tree* CreateNode(char data)
{
	tree* temp=(tree*)malloc(sizeof(tree));
	temp->value=data;
    temp->right=NULL;
	temp->left=NULL;
	
	return temp;
}

tree* InsertLeft(tree* root,char data)
{
	root->left=CreateNode(data);
	return root->left;
}

tree* InsertRight(tree* root,char data)
{
	root->right=CreateNode(data);
	return root->left;
}

void InOrderTreaversal(tree*root)
{
	if(root==NULL)return;
	InOrderTreaversal(root->left);
	printf("%c ",root->value);
	InOrderTreaversal(root->right);
}

void PreOrderTreaversal(tree*root)
{
	if(root==NULL)return;
	printf("%c ",root->value);
	PreOrderTreaversal(root->left);
	PreOrderTreaversal(root->right);
}

void PostOrderTreaversal(tree*root)
{
	if(root==NULL)return;
	PostOrderTreaversal(root->left);
	PostOrderTreaversal(root->right);
	printf("%c ",root->value);
}
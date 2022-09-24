#ifndef TREE_H
#define TREE_H

typedef struct myStruct
{
	char value;
	struct myStruct *right,*left;
}tree;
tree* CreateNode(char data);
tree* InsertLeft(tree* root,char data);
tree* InsertRight(tree* root,char data);
void InOrderTreaversal(tree*root);
void PreOrderTreaversal(tree*root);
void PostOrderTreaversal(tree*root);
#endif
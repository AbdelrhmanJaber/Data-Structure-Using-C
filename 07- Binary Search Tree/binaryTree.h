#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct myStruct
{
	int value;
	struct myStruct* left,*right;
}tree;

tree* CreateTree(tree*root);
tree* Inserttree(tree*ptrToTree,int data);
tree* CreateNode(int data);
void HelpDisplay(tree*root);
void Display(tree*root);
int TreeSize(tree*root);
int TreeDepth(tree*root);
tree* ClearTree(tree*root);
void HelpClearTree(tree*root);
int LessThan(int data,int parentData);
int Equal(int data,int parentData);
int FindElement(tree*root,int data);
int DeleteElement(tree*root,int data);
tree* DeleteNode(tree*root);
#endif
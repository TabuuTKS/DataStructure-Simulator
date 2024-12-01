#ifndef BINARYTREE_H
#define BINARYTREE_H

struct CustomBinaryTreeNode
{
	int data;
	struct CustomBinaryTreeNode* LeftChild;
	struct CustomBinaryTreeNode* RightChild;
}typedef BinaryTreeNode;

struct CustomBinaryTree
{
	BinaryTreeNode* root;
}typedef BinaryTree;

BinaryTreeNode* CreateBinaryTreeNode(int data);
BinaryTree* CreateBinaryTree();
void DeleteBinaryTree(BinaryTree* binaryTree);

void InsertBinaryTreeNode(BinaryTree* tree, int element);
void DeleteBinaryTreeNode(BinaryTree* tree, int data);
void DisplayBinaryTree(BinaryTree* tree);


#endif // !BINARYTREE_H

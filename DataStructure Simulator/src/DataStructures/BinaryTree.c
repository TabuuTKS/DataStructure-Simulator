#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "../Menus/Colors.h"
#include "testDS.h"

BinaryTreeNode* CreateBinaryTreeNode(int data) {
	BinaryTreeNode* newNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	if (!newNode)
	{
		printf("Memory allocation error\n");
		exit(1);
	}
	newNode->data = data;
	newNode->LeftChild = NULL;
	newNode->RightChild = NULL;
	return newNode;
}

BinaryTree* CreateBinaryTree() {
	BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	if (!tree) {
		printf("Memory allocation error\n");
		exit(1);
	}
	tree->root = NULL;
	return tree;
}

void DeleteAllNodesHelper(BinaryTreeNode* node)
{
	if (node == NULL) return;
	DeleteAllNodesHelper(node->LeftChild); 
	DeleteAllNodesHelper(node->RightChild);  
	free(node); 
}
void DeleteBinaryTree(BinaryTree* tree) 
{
	if (tree == NULL || tree->root == NULL) 
	{  
		return;
	}
	DeleteAllNodesHelper(tree->root); 
	tree->root = NULL;  
}

void InsertBinaryTreeNode(BinaryTree* tree, int data)
{
	BinaryTreeNode* newNode = CreateBinaryTreeNode(data);
	if (tree->root == NULL)
	{
		tree->root = newNode;
		setGreenColor();
		printf("Inserted %d as root node\n", data);
		resetToBaseColor();
		return;
	}
	BinaryTreeNode* queue[100];
	int front = 0;
	int rear = 0;
	queue[rear++] = tree->root;
	while (front < rear)
	{
		BinaryTreeNode* temp = queue[front++];
		if (temp->LeftChild == NULL)
		{
			temp->LeftChild = newNode;
			setGreenColor();
			printf("Inserted %d as left child of %d\n", data, temp->data);
			resetToBaseColor();
			return;
		}
		else
		{
			queue[rear++] = temp->LeftChild;
		}
		if (temp->RightChild == NULL)
		{
			temp->RightChild = newNode;
			setGreenColor();
			printf("Inserted %d as right child of %d\n", data, temp->data);
			resetToBaseColor();
			return;
		}
		else
		{
			queue[rear++] = temp->RightChild;
		}
	}
}

void DeleteBinaryTreeNode(BinaryTree* tree, int data)
{
	if (tree->root == NULL)
	{
		printf("The tree is empty\n");
		return;
	}
	BinaryTreeNode* queue[100];
	int front = 0;
	int rear = 0;
	queue[rear++] = tree->root;
	BinaryTreeNode* nodeToDelete = NULL;
	BinaryTreeNode* lastNode = NULL;
	BinaryTreeNode* parentOfLastNode = NULL;
	while (front < rear)
	{
		BinaryTreeNode* temp = queue[front++];
		if (temp->data == data)
		{
			nodeToDelete = temp;
		}
		if (temp->LeftChild != NULL)
		{
			queue[rear++] = temp->LeftChild;
			parentOfLastNode = temp;
			lastNode = temp->LeftChild;
		}
		if (temp->RightChild != NULL)
		{
			queue[rear++] = temp->RightChild;
			parentOfLastNode = temp;
			lastNode = temp->RightChild;
		}
	}
	if (nodeToDelete != NULL)
	{
		printf("Node to delete found: %d\n", nodeToDelete->data);
		printf("Last node found: %d\n", lastNode->data);
		nodeToDelete->data = lastNode->data;
		if (parentOfLastNode->LeftChild == lastNode)
		{
			parentOfLastNode->LeftChild = NULL;
		}
		else if (parentOfLastNode->RightChild == lastNode)
		{
			parentOfLastNode->RightChild = NULL;
		}
		free(lastNode);
		printf("Deleted node with data %d\n", data);
	}
	else
	{
		printf("Node with data %d not found\n", data);
	}
}

void DisplayBinaryTree(BinaryTree* tree)
{
	if (tree->root == NULL)
	{
		printf("The tree is empty\n");
		return;
	}
	BinaryTreeNode* queue[100];
	int front = 0;
	int rear = 0;
	queue[rear++] = tree->root;
	while (front < rear)
	{
		int nodeCount = rear - front;
		for (int i = 0; i < nodeCount; i++)
		{
			BinaryTreeNode* temp = queue[front++];
			printf("(%d) ", temp->data);
			if (temp->LeftChild != NULL)
			{
				queue[rear++] = temp->LeftChild;
			}
			if (temp->RightChild != NULL)
			{
				queue[rear++] = temp->RightChild;
			}
		}
		printf("\n");
	}
}
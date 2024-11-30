#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

LinkedListNode* createNode(int data) {
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

LinkedList* createLinkedList() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->root = NULL;
}

void InsertNode(LinkedList* list, int data) {
	LinkedListNode* newNode = createNode(data);
	if (list->root == NULL)
	{
		list->root = newNode;
	}
	else {
		LinkedListNode* lastNode = list->root;
		while (lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
}

void Display(LinkedList* list) {
	LinkedListNode* newRoot = list->root;
	while (newRoot->next != NULL) {
		printf("%d -> ", newRoot->next);
		newRoot = newRoot->next;
	}
	printf("NULL\n");
}
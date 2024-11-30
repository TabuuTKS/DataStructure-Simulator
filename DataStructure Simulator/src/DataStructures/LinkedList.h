#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct CustomLinkedListNode
{
	int data;
	struct CustomLinkedListNode* next;
}typedef LinkedListNode;

struct CustomLinkedList
{
	LinkedListNode* root;
}typedef LinkedList;

LinkedListNode* createNode(int data);
LinkedList* createLinkedList();

void InsertNode(LinkedList* list, int data);
void Display(LinkedList* list);

#endif
#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "../Menus/Colors.h"
#include "testDS.h"


LinkedListNode* createNode(int data) {
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        printf("Memory allocation error\n");
        exit(1);
    }
    list->root = NULL;
    return list;
}


void deleteLinkedList(LinkedList* list) {
    LinkedListNode* temp = list->root;
    while (temp != NULL) {
        LinkedListNode* next = temp->next;
        printf("Freeing node with data: %d\n", temp->data); // Debug print
        free(temp);
        temp = next;
    }
    list->root = NULL;
}


void InsertNode(LinkedList* list, int data) {
    LinkedListNode* newNode = createNode(data);
    if (list->root == NULL) {
        list->root = newNode;
    }
    else {
        LinkedListNode* lastNode = list->root;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    setGreenColor();
    printf("\nInsertion Successful");
    printf("\n");
    DisplayList(&testList);
    resetToBaseColor();
}

void DisplayList(LinkedList* list) {
    if (list->root == NULL) {
        printf("List is Empty\n");
    }
    else {
        LinkedListNode* temp = list->root;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

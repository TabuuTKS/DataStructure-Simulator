#include <stdio.h>
#include <conio.h>

#include "Colors.h"
#include "MainMenu.h"
#include "../DataStructures/LinkedList.h"
#include "../DataStructures/testDS.h"

void checkListDeleted() {
	int option2 = 0;
	setYellowColor();
	printf("\nWant to Go Back, Do You Want to Store The Privious Data?: ");
	printf("\n1) Yes");
	printf("\n2) No");
	printf("\nEnter The Option Number: ");
	scanf_s("%d", &option2);
	if (option2 == 1)
	{
		setRedColor();
		printf("Linked List Memory Not Deleted");
		resetToBaseColor();
	}
	else {
		setGreenColor();
		deleteLinkedList(&testList);
		printf("Linked List Memory Deleted");
		isLinkedListCreated = false;
		resetToBaseColor();
	}
}

void LinkedListInsertMenu() {
	int element;
	printf("\nEnter The Element You Want to insert: ");
	scanf_s("%d", &element);
	InsertNode(&testList, element);
}

void LinkedListMenu() {
	if (isLinkedListCreated == false)
	{
		setYellowColor();
		printf("\nNo Linked List Exists..We Have To Create One");
		testList = *createLinkedList();
		setGreenColor();
		printf("\nLinked List Created");
		resetToBaseColor();
		isLinkedListCreated = true;
	}
	else
	{
		setGreenColor();
		printf("\nLinked List Already Exists");
		resetToBaseColor();
	}

	int option = -1;
	printf("\nSelect an Operation to be performed on Your Linked List:\n");
	printf("1) Insert\n");
	printf("2) Delete\n");
	printf("3) Display\n");
	printf("\n0) Go Back\n");

	printf("\nEnter The Option Number: ");
	scanf_s("%d", &option);

	switch (option)
	{
		case 0:
			checkListDeleted();
			MainMenu();
			break;
		case 1:
			LinkedListInsertMenu();
			_getch();
			LinkedListMenu();
			break;
		case 2:
			printf("\nWill Delete Later");
			_getch();
			break;
		case 3:
			DisplayList(&testList);
			_getch();
			LinkedListMenu();
			break;
		default:
			printf("\nError: Invalid Option\n");
			LinkedListMenu();
	}
}
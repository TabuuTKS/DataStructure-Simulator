#include <stdio.h>
#include <conio.h>

#include "Colors.h"
#include "MainMenu.h"
#include "../DataStructures/Stack.h"
#include "../DataStructures/testDS.h"

void checkStackDeleted() {
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
		printf("Stack Not Deleted");
		resetToBaseColor();
	}
	else {
		setGreenColor();
		DeleteStack(&testStack);
		printf("Stack Deleted");
		isStackCreated = false;
		resetToBaseColor();
	}
}

void StackPushMenu() {
	int element;
	printf("\nEnter The Element You Want to Push to Stack: ");
	scanf_s("%d", &element);
	Push(&testStack, element);
}

void StackMenu() {
	if (isStackCreated == false)
	{
		setYellowColor();
		printf("\nNo Stack Exists..We Have To Create One");
		CreateStack(&testStack);
		setGreenColor();
		printf("\nStack Created");
		resetToBaseColor();
		isStackCreated = true;
	}
	else {
		setGreenColor();
		printf("\nStack Already Exists");
		resetToBaseColor();
	}

	int option = -1;
	printf("\nSelect an Operation to be performed on Your Stack:\n");
	printf("1) Push\n");
	printf("2) Pop\n");
	printf("3) Display\n");
	printf("\n0) Go Back\n");

	printf("\nEnter The Option Number: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 0:
		checkStackDeleted();
		MainMenu();
		break;
	case 1:
		StackPushMenu();
		_getch();
		StackMenu();
		break;
	case 2:
		Pop(&testStack);
		_getch();
		StackMenu();
		break;
	case 3:
		DisplayStack(&testStack);
		_getch();
		StackMenu();
		break;
	default:
		printf("\nError: Invalid Option\n");
		StackMenu();
	}
}
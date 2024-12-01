#include <stdio.h>
#include <conio.h>

#include "Colors.h"
#include "MainMenu.h"
#include "../DataStructures/testDS.h"
#include "../DataStructures/Queue.h"

void checkQueueDeleted() {
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
		printf("Queue Not Deleted");
		resetToBaseColor();
	}
	else {
		setGreenColor();
		DeleteQueue(&testQueue);
		printf("Queue Deleted");
		isQueueCreated = false;
		resetToBaseColor();
	}
}

void EnqueueMenu() {
	int element;
	printf("\nEnter The Element You Want to Enqueue: ");
	scanf_s("%d", &element);
	Enqueue(&testQueue, element);
}

void QueueMenu() {
	if (isQueueCreated == false)
	{
		setYellowColor();
		printf("\nNo Queue Exists..We Have To Create One");
		CreateQueue(&testQueue);
		setGreenColor();
		printf("\nQueue Created");
		resetToBaseColor();
		isQueueCreated = true;
	}
	else {
		setGreenColor();
		printf("\nQueue Already Exists");
		resetToBaseColor();
	}

	int option = -1;
	printf("\nSelect an Operation to be performed on Your Queue:\n");
	printf("1) Enqueue\n");
	printf("2) Dequeue\n");
	printf("3) Display\n");
	printf("\n0) Go Back\n");

	printf("\nEnter The Option Number: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 0:
		checkQueueDeleted();
		MainMenu();
		break;
	case 1:
		EnqueueMenu();
		_getch();
		QueueMenu();
		break;
	case 2:
		Dequeue(&testQueue);
		_getch();
		QueueMenu();
		break;
	case 3:
		DisplayQueue(&testQueue);
		_getch();
		QueueMenu();
		break;
	default:
		printf("\nError: Invalid Option\n");
		QueueMenu();
	}
}
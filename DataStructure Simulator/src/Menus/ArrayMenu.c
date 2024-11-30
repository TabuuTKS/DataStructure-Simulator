#include <stdio.h>
#include <conio.h>

#include "../DataStructures/ArrayADT.h"
#include "../DataStructures/testDS.h"
#include "Colors.h"
#include "MainMenu.h"

void checkDeleted() {
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
		printf("Array Memory Not Deleted");
		resetToBaseColor();
	}
	else {
		setGreenColor();
		DeleteArray(&testArray);
		printf("Array Memory Deleted");
		isArrayCreated = false;
		resetToBaseColor();
	}
}

void insertMenu() {
	int element, index;
	printf("\nEnter The Element You Want to insert: ");
	scanf_s("%d", &element);
	printf("Enter The Index at Which You Want to insert: ");
	scanf_s("%d", &index);
	Insert(&testArray, element, index);
}

void deleteMenu() {
	int index;
	printf("\nEnter The Index At Which You Want to Perform Deletion: ");
	scanf_s("%d", &index);
	DeleteElement(&testArray, index);
}

void LinearSearchMenu() {
	int element;
	printf("Enter The Element You Want to Search For: ");
	scanf_s("%d", &element);
	LinearSearch(&testArray, element);
}

void BinarySearchMenu() {
	int element, option2 = 0;
	printf("\nBefore Binary Search, First We Need to Confirm Something.");
	printf("\nIs your Array Sorted?: ");
	printf("\n1) Yes");
	printf("\n2) No");
	printf("\nChose an Option: ");
	scanf_s("%d", &option2);
	if (option2 == 1) {
		printf("Let's Continue With Binary Search");
		printf("\nEnter The Element You Want to Search For: ");
		scanf_s("%d", &element);
		BinarySearch(&testArray, element);
	}
	else {
		printf("Then Sort The Array First");
	}
}

void ArrayMenu() {
	if (isArrayCreated == false)
	{
		setYellowColor();
		printf("\nNo Array Exists..We Have To Create One");
		resetToBaseColor();
		int TotalSize, UsedSize;
		printf("\nEnter The Total Size of Array: ");
		scanf_s("%d", &TotalSize);
		printf("\nEnter The Size you Want to use: ");
		scanf_s("%d", &UsedSize);
		CreateArray(&testArray, TotalSize, UsedSize);
		Set(&testArray);
		setGreenColor();
		printf("\nArray Created");
		resetToBaseColor();
		isArrayCreated = true;
	}
	else if (isArrayCreated == true)
	{
		setGreenColor();
		printf("\nArray Already Exists");
		resetToBaseColor();
	}
	int option = -1;
	printf("\nSelect an Operation to be performed on Your Array:\n");
	printf("1) Insert\n");
	printf("2) Delete\n");
	printf("3) Display\n");
	printf("4) Linear Search\n");
	printf("5) Binary Search\n");
	printf("6) Bubble Sort\n");
	printf("\n0) Go Back\n");

	printf("\nEnter The Option Number: ");
	scanf_s("%d", &option);

	switch (option)
	{
		case 0:
			checkDeleted();
			MainMenu();
			break;
		case 1:
			insertMenu();
			_getch();
			ArrayMenu();
			break;
		case 2:
			deleteMenu();
			_getch();
			ArrayMenu();
			break;
		case 3:
			Display(&testArray);
			_getch();
			ArrayMenu();
			break;
		case 4:
			LinearSearchMenu();
			_getch();
			ArrayMenu();
		case 5:
			BinarySearchMenu();
			_getch();
			ArrayMenu();
		case 6:
			BubbleSort(&testArray);
			_getch();
			ArrayMenu();
		default:
			setRedColor();
			printf("\nError: Invalid Option\n");
			ArrayMenu();
			resetToBaseColor();
	}
}
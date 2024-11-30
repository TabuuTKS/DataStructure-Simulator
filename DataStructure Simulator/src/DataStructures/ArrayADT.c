#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

#include "ArrayADT.h"
#include "testDS.h"
#include "../Menus/Colors.h"

void CreateArray(Array* a, int Tsize, int Usize) {
	a->Total_Size = Tsize;
	a->Used_Size = Usize;
	a->ptr = (int*)malloc(Tsize * sizeof(int));
}
void Set(Array* a) {
	int n;
	for (int i = 0; i < a->Used_Size; i++)
	{
		printf("Enter Element at arr[%d]: ", i);
		scanf_s("%d", &n);
		(a->ptr)[i] = n;
	}
}

void DeleteArray(Array* a) {
	free(a->ptr);
}

//operations
void Display(Array* a) {
	printf("[");
	for (int i = 0; i < a->Used_Size; i++)
	{
		printf("%d", (a->ptr)[i]);
		if (!(i == a->Used_Size-1))
		{
			printf(", ");
		}
	}
	printf("]");
}

void Insert(Array *a, int element, int index) {
	if (a->Used_Size>=a->Total_Size)
	{
		setRedColor();
		printf("\nError: Out of Memory Reserved for This Array, Insertion failed");
		resetToBaseColor();
	}
	else if (index > a->Used_Size)
	{
		setRedColor();
		printf("\nError: Index Out of Bounds, Insertion failed");
		resetToBaseColor();
	}
	else {
		for (int i = (a->Used_Size)-1; i > index-1; i--)
		{
			(a->ptr)[i + 1] = (a->ptr)[i];
		}
		(a->ptr)[index] = element;
		a->Used_Size++;
		setGreenColor();
		printf("\nInsertion Successful");
		printf("\n");
		Display(&testArray);
		resetToBaseColor();
	}
}

void DeleteElement(Array* a, int index) {
	for (int i = index; i < (a->Used_Size)-1; i++)
	{
		(a->ptr)[i] = (a->ptr)[i + 1];
	}
	(a->Used_Size)--;
	setGreenColor();
	printf("\nDeletion Successful");
	printf("\n");
	Display(&testArray);
	resetToBaseColor();
}

void LinearSearch(Array* a, int element) {
	bool found = false;
	for (int i = 0; i < a->Used_Size; i++)
	{
		if ((a->ptr)[i] == element)
		{
			setGreenColor();
			printf("\nElement %d found at index %d", element, i);
			resetToBaseColor();
			found = true;
			break;
		}
		else
		{
			setYellowColor();
			printf("\nNot Found at Index %d", i);
			resetToBaseColor();
		}
		Sleep(2000);
	}
	if (!found)
	{
		setRedColor();
		printf("\nElement %d not found in Array", element);
		resetToBaseColor();
	}
}

void BinarySearch(Array* a, int element) {
	int left = 0, right = (a->Used_Size)-1;
	int step = 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		setYellowColor();
		printf("Step %d: left = %d, right = %d, mid = %d\n", step, left, right, mid);
		printf("Comparing element %d with arr[%d] = %d\n", element, mid, (a->ptr)[mid]);
		resetToBaseColor();

		if ((a->ptr)[mid] == element) {
			setGreenColor();
			printf("Element found at index %d\n", mid);
			resetToBaseColor();
			return;
		}

		if ((a->ptr)[mid] < element) { left = mid + 1; }
		else { right = mid - 1; }
		step++;
	}
	setRedColor();
	printf("Element is not present in array\n");
	resetToBaseColor();
	return;
}

void BubbleSort(Array* a) {
	Display(a);
	Sleep(2000);
	for (int n = 0; n < (a->Used_Size)-1; n++)
	{
		for (int i = 0; i < (a->Used_Size)-n-1; i++)
		{
			if ((a->ptr)[i] > (a->ptr)[i + 1]) {
				int temp = (a->ptr)[i];
				(a->ptr)[i] = (a->ptr)[i + 1];
				(a->ptr)[i + 1] = temp;
				setYellowColor();
				printf("\n");
				Display(a);
				resetToBaseColor();
				Sleep(2000);
			}
		}
	}
	setGreenColor();
	printf("\nArray Sorted");
	resetToBaseColor();
}
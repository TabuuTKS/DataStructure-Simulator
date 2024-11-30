#include <stdio.h>
#include <stdlib.h>
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
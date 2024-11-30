#include <stdio.h>
#include <stdbool.h>

#include "Stack.h"
#include "testDS.h"
#include "../Menus/Colors.h"

void CreateStack(Stack* stack) {
	stack->top = -1;
}

bool isFull(Stack* stack) {
	if (stack->top >= MAX - 1) {
		return true;
	}
	else
	{
		return false;
	}
}

bool isEmpty(Stack* stack) {
	if (stack->top == (-1)) {
		return true;
	}
	else
	{
		return false;
	}
}

void Push(Stack* stack, int element) {
	if (isFull(stack))
	{
		setRedColor();
		printf("\nError: Stack Overflow");
		resetToBaseColor();
	}
	else {
		stack->arr[++(stack->top)] = element;
		setGreenColor();
		printf("\nElement %d Pushed in Stack", element);
		resetToBaseColor();
	}
}

void Pop(Stack* stack) {
	if (isEmpty(stack))
	{
		setRedColor();
		printf("\nError: Stack Underflow");
		resetToBaseColor();
	}
	else {
		stack->top--;
		setGreenColor();
		printf("\nTop Element Deleted in Stack");
		resetToBaseColor();
	}
}

void DisplayStack(Stack* stack) {
	if (isEmpty(stack))
	{
		setYellowColor();
		printf("\nEmpty Stack");
		resetToBaseColor();
	}
	else
	{
		for (int i = stack->top; i >=0; i--)
		{
			printf("\n|%d|", stack->arr[i]);
		}
		printf("\n******");
	}
}

void DeleteStack(Stack* stack) {
	while (!(isEmpty(stack))) {
		stack->top--;
	}
}
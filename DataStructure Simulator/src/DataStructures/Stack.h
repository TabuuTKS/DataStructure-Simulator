#ifndef STACK_H
#define STACK_H
#define MAX 100

struct CustomStack
{
	int arr[MAX];
	int top;
}typedef Stack;

void CreateStack(Stack* stack);
void Push(Stack* stack, int element);
void Pop(Stack* stack);
void DisplayStack(Stack* stack);
void DeleteStack(Stack* stack);

#endif // !STACK_H
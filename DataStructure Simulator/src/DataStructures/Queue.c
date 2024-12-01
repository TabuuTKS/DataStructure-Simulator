#include <stdio.h>
#include <stdbool.h>

#include "Queue.h"
#include "testDS.h"
#include "../Menus/Colors.h"

void CreateQueue(Queue* queue) {
	queue->front = -1;
	queue->rear = 0;
}

bool isQueueFull(Queue* queue) {
	if (queue->rear == MAX - 1) { return true; }
	else { return false; }
}

bool isQueueEmpty(Queue* queue) 
{
	return queue->front == -1 || queue->front > queue->rear;
}

void Enqueue(Queue* queue, int element) {
	if (isQueueFull(queue))
	{
		setRedColor();
		printf("\nError: Queue Overflow");
		resetToBaseColor();
	}
	else {
		if (queue->front == (-1)) { queue->front = 0; }
		if (queue->rear == 0) { queue->arr[0] = element; queue->rear++; }
		else { queue->arr[queue->rear] = element; queue->rear++; }
		setGreenColor();
		printf("\nElement %d Enqueued in Queue", element);
		resetToBaseColor();
	}
}

void Dequeue(Queue* queue) {
	if (isQueueEmpty(queue))
	{
		setRedColor();
		printf("\nError: Queue Underflow");
		resetToBaseColor();
	}
	else {
		int element = queue->arr[queue->front++];
		setGreenColor();
		printf("\nElement %d Dequeued from Queue", element);
		resetToBaseColor();
		if (queue->front > queue->rear)
		{
			queue->front = queue->rear = -1;
		}
	}
}

void DisplayQueue(Queue* queue) {
	if (isQueueEmpty(queue)) {
		setYellowColor();
		printf("\nQueue is empty");
		resetToBaseColor();
		return;
	}
	else {
		printf("[");
		for (int i = queue->front; i <= (queue->rear-1); i++) {
			printf("%d", queue->arr[i]);
			if (i != (queue->rear-1))
			{
				printf(", ");
			}
		}
		printf("]\n");
	}
}

void DeleteQueue(Queue* queue) {
	while (!(isQueueEmpty(queue))) {
		queue->front--;
		queue->rear--;
	}
}
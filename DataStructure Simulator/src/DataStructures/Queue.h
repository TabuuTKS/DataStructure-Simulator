#ifndef QUEUE_H
#define QUEUE_H
#define MAX 100

struct CustomQueue
{
	int arr[MAX];
	int front;
	int rear;
}typedef Queue;

void CreateQueue(Queue* queue);
void Enqueue(Queue* queue, int element);
void Dequeue(Queue* queue);
void DisplayQueue(Queue* queue);
void DeleteQueue(Queue* queue);

#endif // !QUEUE_H

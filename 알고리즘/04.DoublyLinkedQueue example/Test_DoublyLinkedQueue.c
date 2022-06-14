#include "DoublyLinkedQueue.h"

int main(void)
{
	Node* Popped;
	LinkedQueue* Queue;

	DLQ_CreateQueue(&Queue);

	DLQ_Enqueue(Queue, DLQ_CreateNode("abc", 1));
	DLQ_Enqueue(Queue, DLQ_CreateNode("def", 3));
	DLQ_Enqueue(Queue, DLQ_CreateNode("efg", 2));
	DLQ_Enqueue(Queue, DLQ_CreateNode("hij", 4));
	DLQ_Enqueue(Queue, DLQ_CreateNode("kft", 0));

	printf("Queue Size : %d\n", Queue->Count);

	while (DLQ_IsEmpty(Queue) == 0)
	{
		Popped = DLQ_Dequeue(Queue);

		printf("Dequeue : %s \n", Popped->Data);

		DLQ_DestroyNode(Popped);
	}

	DLQ_DestroyQueue(Queue);

	return 0;
}
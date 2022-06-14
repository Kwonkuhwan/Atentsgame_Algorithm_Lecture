#include "LinkedQueue.h"

int main(void)
{
	Node* Popped;
	LinkedQueue* Queue;

	LQ_CreateQueue(&Queue);

	LQ_Enqueue(Queue, LQ_CreateNode("abc", 1));
	LQ_Enqueue(Queue, LQ_CreateNode("def", 3));
	LQ_Enqueue(Queue, LQ_CreateNode("efg", 2));
	LQ_Enqueue(Queue, LQ_CreateNode("hij", 4));
	LQ_Enqueue(Queue, LQ_CreateNode("kft", 0));

	printf("Queue Size : %d\n", Queue->Count);

	while (LQ_IsEmpty(Queue) == 0)
	{
		Popped = LQ_Dequeue(Queue);

		printf("Dequeue : %s \n", Popped->Data);

		LQ_DestroyNode(Popped);
	}

	LQ_DestroyQueue(Queue);

	return 0;
}
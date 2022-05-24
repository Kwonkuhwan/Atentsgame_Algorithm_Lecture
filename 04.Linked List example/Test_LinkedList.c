#include "LinkedList.h"

int main() 
{
	// �迭�� ������ ���ų�, fix�Ǿ��ִٸ� ����ϸ� ����.
	// ��ũ�� ����Ʈ�� ������ �������� �ʾ����� ����ϸ� ����.
	int Count			= 0;
	Node* List			= NULL;		// Head ���(�� ���� ���) �ּҰ� �����
	Node* Current		= NULL;		// ���� ��� �ּҰ� ����
	Node* NewNode	= NULL;		// ���ο� ��� �ּҰ� ����

	// ��� 5�� �߰�
	for (int i = 0; i < 5; i++) 
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);

	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);

	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (int i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// ����Ʈ�� 3��° ��� �ڿ� �� ��� ����
	printf("\nInserting 3000 After [2]...\n\n");

	// GetNodeAt�� ����ؼ� 2��° ��带 �����´�.
	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (int i = 0; i < Count; i++) 
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// ��� ��� �޸� ����
	printf("\nDestorying List...\n");

	for (int i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}

	return 0;
}
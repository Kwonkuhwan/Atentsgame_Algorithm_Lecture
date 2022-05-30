#include "DisjointSet.h"

void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2)
{
	Set2 = DS_FinSet(Set2);
	Set2->Parent = Set1;
}

DisjointSet* DS_FinSet(DisjointSet* Set)
{
	while (Set->Parent != NULL)
		Set = Set->Parent;

	return Set;
}

DisjointSet* DS_MakeSet(void* NewData)
{
	DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet));
	NewNode->Parent = NULL;

	return NewNode;
}

void DS_DestroySet(DisjointSet* Set)
{
	free(Set);
}

#include "Graph.h"
#include "TopologicalSort.h"

int main(void)
{
	Node* SortedList = NULL;
	Node* Currentnode = NULL;

	Graph* graph = CreateGraph();

	Vertex* Vertex1 = CreateVertex("C¾ð¾î");
	Vertex* Vertex2 = CreateVertex("C++");
	Vertex* Vertex3 = CreateVertex("C#");
	Vertex* Vertex4 = CreateVertex("Python");
	Vertex* Vertex5 = CreateVertex("JAVA");
	Vertex* Vertex6 = CreateVertex("OpenCV");
	Vertex* Vertex7 = CreateVertex("Unity");
	Vertex* Vertex8 = CreateVertex("Tenserflow");
	Vertex* Vertex9 = CreateVertex("Pytorch");
	Vertex* Vertex10 = CreateVertex("JS");


	AddVertex(graph, Vertex1);
	AddVertex(graph, Vertex2);
	AddVertex(graph, Vertex3);
	AddVertex(graph, Vertex4);
	AddVertex(graph, Vertex5);
	AddVertex(graph, Vertex6);
	AddVertex(graph, Vertex7);
	AddVertex(graph, Vertex8);
	AddVertex(graph, Vertex9);
	AddVertex(graph, Vertex10);

	AddEdge(Vertex1, CreateEdge(Vertex1, Vertex2, 0));
	AddEdge(Vertex1, CreateEdge(Vertex1, Vertex3, 0));
	AddEdge(Vertex1, CreateEdge(Vertex1, Vertex4, 0));
	AddEdge(Vertex1, CreateEdge(Vertex1, Vertex5, 0));

	AddEdge(Vertex2, CreateEdge(Vertex2, Vertex6, 0));

	AddEdge(Vertex3, CreateEdge(Vertex3, Vertex7, 0));

	AddEdge(Vertex4, CreateEdge(Vertex4, Vertex8, 0));
	AddEdge(Vertex4, CreateEdge(Vertex4, Vertex9, 0));

	AddEdge(Vertex5, CreateEdge(Vertex5, Vertex10, 0));

	TopologicalSort(graph->Vertices, &SortedList);

	printf("TopologicalSort Result : ");

	Currentnode = SortedList;

	while (Currentnode != NULL)
	{
		printf("%s ", Currentnode->Data->Data);
		Currentnode = Currentnode->NextNode;
	}

	printf("\n");

	DestroyGraph(graph);

	return 0;
}
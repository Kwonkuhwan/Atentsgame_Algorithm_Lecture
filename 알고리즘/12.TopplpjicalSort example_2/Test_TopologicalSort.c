#include "Graph.h"
#include "TopologicalSort.h"

int main(void)
{
	Node* SortedList = NULL;
	Node* Currentnode = NULL;

	Graph* graph = CreateGraph();

	Vertex* C = CreateVertex("C언어");
	Vertex* CPP = CreateVertex("C++");
	Vertex*	CS = CreateVertex("C#");
	Vertex* P = CreateVertex("Python");
	Vertex* J = CreateVertex("JAVA");
	Vertex* OCV = CreateVertex("OpenCV");
	Vertex* TD = CreateVertex("3D 그래픽");
	Vertex* Uni = CreateVertex("Unity");
	Vertex* Unreal = CreateVertex("언리얼엔진");
	Vertex* Tensor = CreateVertex("Tensorflow");
	Vertex* Pytorch = CreateVertex("Pytorch");
	Vertex* Js = CreateVertex("JS");


	AddVertex(graph, C);
	AddVertex(graph, CPP);
	AddVertex(graph, CS);
	AddVertex(graph, P);
	AddVertex(graph, J);
	AddVertex(graph, OCV);
	AddVertex(graph, TD);
	AddVertex(graph, Uni);
	AddVertex(graph, Unreal);
	AddVertex(graph, Tensor);
	AddVertex(graph, Pytorch);
	AddVertex(graph, Js);

	AddEdge(C, CreateEdge(C, J, 0));
	AddEdge(C, CreateEdge(C, P, 0));
	AddEdge(C, CreateEdge(C, CS, 0));
	AddEdge(C, CreateEdge(C, CPP, 0));

	AddEdge(CPP, CreateEdge(CPP, OCV, 0));

	AddEdge(CS, CreateEdge(CS, TD, 0));

	AddEdge(TD, CreateEdge(TD, Uni, 0));
	AddEdge(TD, CreateEdge(TD, Unreal, 0));

	AddEdge(P, CreateEdge(P, Tensor, 0));
	AddEdge(P, CreateEdge(P, Pytorch, 0));

	AddEdge(J, CreateEdge(J, Js, 0));

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
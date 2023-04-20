#include "functions.h"

#define YES 'y'
#define NO 'n'
#define EMPTY 0

void error()
{
	cout << "invalid input" << endl;
	exit(1);
}

void checkDirectedInput(char directed, bool& isDirected)
{
	if (directed == YES)
	{
		isDirected = true;
	}
	else if (directed == NO)
	{
		isDirected = false;
	}
	else
	{
		error();
	}
}

void checkNumOfVertices(int& numOfVertices)
{
	if (numOfVertices <= EMPTY)
	{
		error();
	}
}

void checkNumOfArcs(int numOfArcs, int numOfVertices, bool isDirected)
{
	if (numOfArcs < EMPTY)
	{
		error();
	}
	if (isDirected && numOfArcs > numOfVertices * (numOfVertices - 1))
	{
		error();
	}
	if (!isDirected && numOfArcs > (numOfVertices * (numOfVertices - 1))/2)
	{
		error();
	}
}

void checkArc(int firstVertex, int secondVertex, int numOfVertices, Graph* graph)
{
	if (firstVertex <= EMPTY || firstVertex > numOfVertices
		|| secondVertex <= EMPTY || secondVertex > numOfVertices)
	{
		delete graph;
		error();
	}
}

Graph* getInput()
{
	bool isDirected;
	int numOfVertices, numOfArcs, firstVertex, secondVertex;
	char directed;
	cout << "Is the graph directed: y/n" << endl;
	cin >> directed;
	checkDirectedInput(directed, isDirected);
	cin >> numOfVertices;
	checkNumOfVertices(numOfVertices);
	cin >> numOfArcs;
	checkNumOfArcs(numOfArcs, numOfVertices, isDirected);
	Graph* graph = new Graph(numOfVertices, isDirected, numOfArcs);
	for (int i = 0; i < numOfArcs; ++i)
	{
		cin >> firstVertex >> secondVertex;
		checkArc(firstVertex, secondVertex, numOfVertices, graph);
		graph->addArc(firstVertex, secondVertex);
	}
	return graph;
}

bool checkConditionsForAulerianCircle(Graph& graph)
// The function checks the necessary and sufficient conditions for the aulerian circle in the graph 
{
	bool isConnected = false;
	bool degrees = graph.checkDegrees();
	if (degrees)
	{
		isConnected = graph.checkConnected();
	}
	return (degrees && isConnected); 
}
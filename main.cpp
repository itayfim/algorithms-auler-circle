#include "header.h"

/*
This program creates graph and finds Aulerian circle in it if exists.
The program works for directed & undirected graphs.
First the user decides if the graph is directed/undirected,
then the user inputs how much vertices and arcs in the graph,
finally the user inputs the arcs (for the arc {a,b}, the user needs to input a b)
*/

int main()
{
	Graph* graph = getInput();
	bool conditions = checkConditionsForAulerianCircle(*graph);
	if (conditions) 
	{
		cout << "The graph is aulerian" << endl;
		graph->findAulerianCircle();
	}
	else
	{
		cout << "The graph is not aulerian" << endl;
	}
	delete graph;
	return 0;
}
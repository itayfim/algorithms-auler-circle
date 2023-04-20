#ifndef __GRAPH_H
#define __GRAPH_H

#include "header.h"

class Vertex;

class Graph
{
private:
	vector<Vertex> neighborsList;
	bool isDirected;
	int numOfArcs;

public:
	Graph(const int& numOfVertices, bool isDirected, int numOfArcs);
	void addArc(int firstVertex, int secondVertex);
	bool checkDegrees();
	bool checkConnected();
	void visit(int vertex, vector<bool>& visited);
	Graph buildGraphTranspose();
	void findAulerianCircle();
	list<int> findCircuit(int vertexName);
	void printAulerianCircle(list<int> L);
};

#endif // !__GRAPH_H
#include "Graph.h"

Graph::Graph(const int& numOfVertices, bool isDirected, int numOfArcs)
{
	for (int i = 0; i < numOfVertices; ++i)
	{
		neighborsList.push_back(Vertex());
	}
	this->isDirected = isDirected;
	this->numOfArcs = numOfArcs;
}

void Graph::addArc(int firstVertex, int secondVertex)
{
	neighborsList[firstVertex - 1].addArcToList(Node(secondVertex));
	if (isDirected)
	{
		neighborsList[secondVertex - 1].setInDegree();
	}
	else
	{
		neighborsList[secondVertex - 1].addArcToList(Node(firstVertex)); // for undirected - adding the mutual arc
		neighborsList[firstVertex - 1].lst.back().setMutualPointer(&neighborsList[secondVertex - 1].lst.back()); // setting mutual ptr
	}
}

bool Graph::checkDegrees()
{
	bool desgreesIsOK = true;
	if (isDirected)
	{
		for (Vertex& v : neighborsList)
		{
			if (v.inDegree != v.lst.size()) // lst.size = v.outDegree
			{
				return !desgreesIsOK;
			}
		}
	}
	else
	{
		for (Vertex& v : neighborsList)
		{
			if (v.lst.size() % 2 != 0)
			{
				return !desgreesIsOK;
			}
		}
	}
	return desgreesIsOK;
}

bool Graph::checkConnected() {
	bool isConnected = true;
	// this code (till the end of for loop) is for undirected and directed graph
	vector<bool> visited(neighborsList.size(), false);
	int firstVertex = 0;
	visit(firstVertex, visited);
	for (bool v : visited) 
	{
		if (!v) // if not visited in vertex v
		{ 
			return !isConnected;
		}
	}
	if (isDirected)
	{
		Graph gTranspose = buildGraphTranspose();
		visited.assign(neighborsList.size(), false);
		gTranspose.visit(firstVertex, visited); // note that 'firstVertex' is the same as for the original graph!
		for (bool v : visited) 
		{
			if (!v) // if not visited in vertex v
			{ 
				return !isConnected;
			}
		}
	}
	return isConnected;
}

void Graph::visit(int vertex, vector<bool>& visited) // sane as 'visit' that learned in the class
{
	visited[vertex] = true;
	for (Node& node : neighborsList[vertex].lst) 
	{
		int neighbor = node.getName();
		if (!visited[neighbor - 1]) 
		{
			visit(neighbor - 1, visited);
		}
	}
}

Graph Graph::buildGraphTranspose()
{
	Graph gTranspose(this->neighborsList.size(), true, this->numOfArcs);
	for (Vertex& v : neighborsList) // for each arc {a,b} in the original graph -> add {b,a} for the graph transpose
	{
		for (Node& n : v.lst)
		{
			gTranspose.addArc(n.getName(), v.name);
		}
	}
	return gTranspose;
}

void Graph::findAulerianCircle()
{
	list<int> L = findCircuit(neighborsList[0].getName());
	list<int>::iterator it, itEnd = L.end();
	for (it = L.begin(); it != itEnd; ++it)
	{
		if (neighborsList[*it - 1].currPosition != neighborsList[*it - 1].lst.end()) // if there are arcs that didn't mark
		{
			list<int> L1 = findCircuit(neighborsList[*it - 1].getName());
			auto temp = it;
			temp = find(L.begin(), L.end(), L1.front()); // finding the right position to paste the list
			L1.pop_front();
			L.splice(++temp, L1); // pasting the list in the right position
		}
	}
	printAulerianCircle(L);
}

list<int> Graph::findCircuit(int vertexName)
{
	list<int> L;
	bool getOut = false;
	L.push_back(vertexName);
	while (neighborsList[vertexName - 1].currPosition != neighborsList[vertexName - 1].lst.end()) // while there are still arcs in the list
	{
		while (!getOut && neighborsList[vertexName - 1].currPosition->isVisited()) // there are still not visited arcs in the list
		{
			neighborsList[vertexName - 1].currPosition++;
			if (neighborsList[vertexName - 1].currPosition == neighborsList[vertexName - 1].lst.end())
				getOut = true;
		}
		if (getOut)
			break;
		neighborsList[vertexName - 1].currPosition->setVisit();
		Vertex& u = neighborsList[neighborsList[vertexName - 1].currPosition->getName() - 1];
		if (!isDirected)
		{
			neighborsList[vertexName - 1].currPosition->getMutualPointer()->setVisit();
		}
		neighborsList[vertexName - 1].currPosition++;
		L.push_back(u.getName());
		vertexName = u.getName();
	}
	return L;
}

void Graph::printAulerianCircle(list<int> L)
{
	int counter = 0;
	cout << "(";
	for (int& v : L)
	{
		cout << v;
		if (counter++ != L.size() - 1)
			cout << ",";
	}
	cout << ")" << endl;
}

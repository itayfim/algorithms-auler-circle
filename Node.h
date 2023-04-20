#ifndef __NODE_H
#define __NODE_H

#include "header.h"

class Node
{
private:
	int name;
	bool allreadyVisited;
	Node* mutualPointer; // just for undirected graph

public:
	Node(const int& name);
	void setMutualPointer(Node* ptr);
	int getName() { return name; }
	void setVisit() { allreadyVisited = true; }
	bool isVisited() const { return allreadyVisited; }
	Node* getMutualPointer() { return mutualPointer; }
};

#endif // !__NODE_H



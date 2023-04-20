#ifndef __VERTEX_H
#define __VERTEX_H

#include "header.h"

class Node;

class Vertex
{
friend class Graph;
private:
	static int counter;
	int name;
	list<Node> lst;
	list<Node>::iterator currPosition; // like a pointer to the first unmarked arc
	int inDegree;

public:
	Vertex();
	void addArcToList(const Node& newArc);
	void setInDegree() { inDegree++; }
	int getName() { return name; }
};

#endif // !__VERTEX_H



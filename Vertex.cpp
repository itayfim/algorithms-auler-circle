#include "Vertex.h"
#define ONE_ELEMENT 1
#define INITIAL_IN_DEGREE 0

int Vertex::counter;

Vertex::Vertex()
{
	name = ++counter;
	inDegree = INITIAL_IN_DEGREE;
}

void Vertex::addArcToList(const Node& newArc)
{
	lst.push_back(newArc);
	if (lst.size() == ONE_ELEMENT)
	{
		currPosition = lst.begin();
	}
}

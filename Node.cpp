#include "Node.h"

Node::Node(const int& name)
{
	this->name = name;
	allreadyVisited = false;
	mutualPointer = nullptr;
}

void Node::setMutualPointer(Node* ptr)
{
	if (mutualPointer == nullptr)
	{
		mutualPointer = ptr;
		ptr->setMutualPointer(this);
	}
}

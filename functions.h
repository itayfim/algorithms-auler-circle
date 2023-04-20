#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "header.h"

class Graph;

Graph* getInput();
void error();
void checkDirectedInput(char directed, bool& isDirected);
void checkNumOfVertices(int& numOfVertices);
void checkNumOfArcs(int numOfArcs, int numOfVertices, bool isDirected);
void checkArc(int firstVertex, int secondVertex, int numOfVertices, Graph* graph);
bool checkConditionsForAulerianCircle(Graph& graph);

#endif // !__FUNCTIONS_H

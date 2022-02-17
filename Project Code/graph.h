#pragma once
#include <iostream>
#include "vertex.h"
#include "edge.h"
using namespace std;

class Graph {
public:
	Graph() {};
	virtual ~Graph() {};
	virtual bool addVertex(Vertex& v) = 0;
	virtual bool addVertices(Vertex* vArray, int size) = 0;
	virtual bool addEdge(Edge& e) = 0;
	virtual bool searchEdge(Edge& e) = 0;
	virtual void displayGraph() = 0;
	virtual bool clean() = 0;
};
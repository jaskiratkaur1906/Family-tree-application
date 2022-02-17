#pragma once
#include <iostream>
#include <string>
#include "vertex.h"

using namespace std;

class Edge {
public:
	Edge();
	Edge(Vertex&, Vertex&);
	Edge(const Edge&); 
	~Edge();

	Vertex* getSource() const;
	Vertex* getDestination() const;

	void setSource(Vertex*);
	void setDestination(Vertex*);

	virtual void print();

	bool operator==(const Edge& e) const;


private:
	Vertex* source;
	Vertex* destination;

};
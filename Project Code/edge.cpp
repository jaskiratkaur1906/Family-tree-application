#include "edge.h"

Edge::Edge()
{
	source = nullptr;
	destination = nullptr;
}

Edge::Edge(Vertex& s, Vertex& d)
{
	source = &s;
	destination = &d;
}

Edge::Edge(const Edge& e)
{
	source = e.source; 
	destination = e.destination;
}

Edge::~Edge()
{
	//delete source;
	//delete destination;
}

Vertex* Edge::getSource() const
{
	return source;
}

Vertex* Edge::getDestination() const
{
	return destination;
}

void Edge::setSource(Vertex* s)
{
	source = s;
	delete s;				// so theres no extra pointer 
}

void Edge::setDestination(Vertex* d)
{
	destination = d;
	delete d;		// so theres no extra pointer 
}

void Edge::print()
{
	cout << " (" << &source << "," << &destination << ") ";
}

bool Edge::operator==(const Edge& e) const
{
	if ((e.source == source) && (e.destination == destination))
		return true;
	else
		return false; 
}
#include "vertex.h"

Vertex::Vertex()
{
	vertexName = ""; //start point is vertex 1 
	//vertices = {};
	//vertex = new Vertex; 
}

Vertex::Vertex(string vertexName_)
{
	vertexName = vertexName_;
}

Vertex::Vertex(const Vertex& v)
{
	vertexName = v.vertexName; 
}

Vertex::~Vertex()
{
}

void Vertex::setVertexName(string n)
{
	vertexName = n;
}

string Vertex::getVertexName() const
{
	return vertexName;
}

void Vertex::print()
{
	cout << vertexName;
}
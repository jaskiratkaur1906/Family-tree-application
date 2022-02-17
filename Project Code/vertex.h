#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include "edge.h"

using namespace std;

class Vertex {
public:
	Vertex();
	Vertex(string);
	Vertex(const Vertex&);
	~Vertex();

	void setVertexName(string);
	string getVertexName() const;

	virtual void print();

private:
	string vertexName;

};
#include "directedGraph.h"

DirectedGraph::DirectedGraph()
{
	edges = new Edge[MAX];
	vertices = new Vertex[MAX];
	numEdges = 0;				//amount of edges in graph 
	numVertex = 0;
}
DirectedGraph::DirectedGraph(Vertex& v1, Vertex& v2):DirectedGraph()
{
	this->addVertex(v1);
	this->addVertex(v2);
	Edge constructorEdge(v1, v2);
	this->addEdge(constructorEdge);
}
DirectedGraph::DirectedGraph(const DirectedGraph& d)
{
	//copies attributes 
	numEdges = d.numEdges;
	numVertex = d.numVertex;
	MAX = d.MAX; 

	//copied edges
	for (int i = 0; i < d.numEdges; i++) {
		edges = new Edge(d.edges[i]);
	}
	//copies vertices
	for (int i = 0; i < d.numVertex; i++) {
		vertices = new Vertex(d.vertices[i]); 
	}

	//the rest (vectors + map) is done automatically when display function is called 
}

DirectedGraph::~DirectedGraph()
{
	//delete edges;
	//delete vertices;
}

bool DirectedGraph::addVertex(Vertex& v)
{
	// adds a vertex to the array of vertices returns true if successful. 
	try {
		vertices[numVertex] = v;
		numVertex++;
	}
	catch (...) { return false; }

	return true;
}

bool DirectedGraph::addVertices(Vertex* vArray, int size)
{
	// if addVertex doesnt add the vertex, it will return false 
	for (int i = 0; i < size; i++) {
		if (!addVertex(vArray[i]))
			return false;
	}
	return true;
}

bool DirectedGraph::isEmpty()
{
	//if no edges or vertices 
	if ((edges[0].getSource() == nullptr) && (vertices[0].getVertexName() == "") && (edges[0].getDestination() == nullptr))
		return true;
	return false;
}

bool DirectedGraph::isDirectional()
{
	int undirected = 0;
	//goes through all the edges, checks if source = destination
	for (int i = 0; i < numEdges; i++) {
		for (int j = 0; j < numEdges; j++) {
			if (edges[i].getSource() == edges[j].getDestination()
				&& edges[i].getDestination() == edges[j].getSource()) {
				undirected++;
			}
		}
	}
	//if all the edges have 2 edges with the same source and destination, the graph is undirectional 
	if ((undirected) == numEdges)
		return false;
	return true;
}

bool DirectedGraph::addEdge(Edge& e)
{
	// adds a edge to the array of edges returns true if successful. 
	try {
		edges[numEdges] = e;
		numEdges++;
	}
	catch (...) { return false; }

	return true;
}

bool DirectedGraph::searchEdge(Edge& e)
{
	for (int i = 0; i < numEdges; i++) {
		if (edges[i] == e)
			return true;
	}
	return false;
}

void DirectedGraph::displayGraph()
{
	//if vertex not linked to the graph display just the vertex 
	paths.clear(); 
	//put all edges/vertices in the map 
	fillMap(); 
	vector<Vertex>temp = getFirstVertices(); 
	//for every first vertice, fill the list of paths 
	for (Vertex v : temp) fillListPaths("", v); 
	printPaths(); 
}

void DirectedGraph::fillListPaths(string str, Vertex v)
{	
	//string that holds one path at a time 
	string tempStr = str; 
	tempStr += " " + v.getVertexName();

	//Recursion to get all the paths 
	//if the vertice has no next vertice, push string of paths into list of paths 
	if (nextMap[v.getVertexName()].empty()) {
		paths.push_back(tempStr);	
		return; 
	}
	else {
		//if theres a next vertice, recursion to find paths 
		int size = nextMap[v.getVertexName()].size(); 
		for (int i = 0; i < size; i++) {
			fillListPaths(tempStr, nextMap[v.getVertexName()][i]);
		}
	}
}

void DirectedGraph::printPaths()
{
	//print every string in the vector paths 
	for(string p : paths)
	{
		cout << p << endl;
	}
}

void DirectedGraph::printFromVertex(Vertex v)
{
	//clear to not print the same paths over and over again
	paths.clear(); 
	//fill the list of paths and print them starting from vertex V
	fillListPaths("", v);
	printPaths();
}

vector<Vertex> DirectedGraph::getFirstVertices()
{
	//get the top of the graph, the vertices that no other vertice has this vertice as a next, and puts it in a vector
	vector<Vertex> tempVertexList; 
	for (int i = 0; i < numVertex; i++) {
		int counterOfInstances = 0;
		for (int j = 0; j < numEdges; j++) {
			if (edges[j].getDestination()->getVertexName() == vertices[i].getVertexName()) {
				counterOfInstances++; 
			}
		}
		if (counterOfInstances == 0) {
			tempVertexList.push_back(vertices[i]);
		}
	}

	return tempVertexList;
}

bool DirectedGraph::clean()
{
	try {
		this->~DirectedGraph();
		edges = new Edge[MAX];
		vertices = new Vertex[MAX];
		numEdges = 0;				//amount of edges in graph 
		numVertex = 0;
	}
	catch (...) { return false; }

	return true; 
}

bool DirectedGraph::searchByVertexValue(string value)
{
	for (int i = 0; i < numVertex; i++) {
		if (vertices[i].getVertexName() == value)
			return true;
	}

	return false;
}

void DirectedGraph::fillMap()
{
	//puts vertices in map so that the next vertices can be found 
	//vertice linked to a list of the next vertices 
	for (int i = 0; i < numVertex; i++) {
		//gets list of next(adjacent) vertices and puts it in a temporary variable
		vector<Vertex> tempVect = nextVertex(vertices[i]);
		//create a pair which links a vertice to the vertices that are next to it 
		pair<string, vector<Vertex>>tempPair(vertices[i].getVertexName(), tempVect);
		//insert pair into map (order does not matter)
		nextMap.insert(tempPair);
	}
}

vector<Vertex> DirectedGraph::nextVertex(Vertex v)
{
	//Create temporary list of Vertex 
	vector<Vertex> tempList; 

	//puts the next vertices in the list 
	for (int i = 0; i < numEdges; i++) {
		//if source of edge is equal to the vertex in parameter 
		if (edges[i].getSource()->getVertexName() == v.getVertexName()) {
			//add destination into list of next Vertices 
			tempList.push_back(*edges[i].getDestination());
		}
	}

	return tempList;
}

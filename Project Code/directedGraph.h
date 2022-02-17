#pragma once
#include "graph.h"
#include <vector>
#include <list>
#include <string>
#include <map> 
#include <unordered_map>


class DirectedGraph : public Graph {

public:
	DirectedGraph();
	//Makes a graph with two connected vertices v1 to v2 
	DirectedGraph(Vertex& v1, Vertex& v2);
	DirectedGraph(const DirectedGraph&); 
	~DirectedGraph();

	//add in one vertex; bool returns if it is added successfully.
	virtual bool addVertex(Vertex& v);
	virtual bool addVertices(Vertex* vArray, int size);									//3 part 1 
	//remove a edge;  as a result, some node may remain as orphan.
	virtual bool addEdge(Edge& e);														//3 part 2 
	// return bool if a Edge exists in a graph;
	virtual bool searchEdge(Edge& e);													//7 
	 

	//Erases graph
	virtual bool clean();																
	//true is graph is empty
	bool isEmpty();																		//1
	//true is graph is directional 
	bool isDirectional();																//2
	//returns true is vertex exists 
	bool searchByVertexValue(string value);											    //8


	//functions for display
	virtual void displayGraph();														//5 and 6 
	//Fills vector of strings of paths 
	void fillListPaths(string str, Vertex v);
	//prints all the paths in the table f paths
	void printPaths();
	//prints paths from a specific vertice
	void printFromVertex(Vertex v);
	//find the first vertices in a graph and puts them in a vector
	vector<Vertex> getFirstVertices();

	//list of vertices and edges 
	Vertex* vertices; 
	Edge* edges;

private:
	int numEdges;
	int numVertex;
	int MAX = 100;

	//list of all the paths 
	vector<string> paths; 
	//map of all the next vertices 
	unordered_map<string, vector<Vertex>> nextMap; 

	//function to get the list of vertices that are after (next) the input V
	vector<Vertex> nextVertex(Vertex v); 
	//private function for map 
	void fillMap();

};
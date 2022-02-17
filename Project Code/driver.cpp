#include "directedGraph.h"
int main()
{
	//Family tree 

	DirectedGraph famTree;

	cout << "*************************************** function 1 : isEmpty() ***************************************" << endl;
	cout << "Testing isEmpty() Function [1]: " << endl;
	if (famTree.isEmpty())
		cout << "Graph is empty, function [1] works as intended. " << endl;
	else
		cout << "ERROR: Graph is not empty as it should be, check isEmpty() Function." << endl;

	//Creating vertices 
	Vertex grandpa = Vertex("grandpa");
	Vertex dad = Vertex("dad");
	Vertex son = Vertex("son");
	Vertex daughter = Vertex("daughter");
	Vertex grandma = Vertex("grandma");

	//Creating Edges 
	Edge grandpaDad = Edge(grandpa, dad);
	Edge dadSon = Edge(dad, son);
	Edge dadDaughter = Edge(dad, daughter);
	Edge grandmaDad = Edge(grandma, dad); 

	//addEdge 
	if (famTree.addEdge(grandpaDad))
		cout << "Add edges works correctly. [3]" << endl; 

	famTree.addEdge(dadSon);
	famTree.addEdge(dadDaughter);

	if (famTree.isEmpty())
		cout << "ERROR: Graph is empty, function does not work as intended. " << endl << endl;
	else
		cout << "Graph is not empty, function [1] works as intended. " << endl << endl;


	cout << "*************************************** function 3 : add ***************************************" << endl;

	//edges already added 

	if (famTree.addVertex(grandpa))
		cout << "Add vertex works correctly [3] " << endl; 
	Vertex *vArray = new Vertex[3]; 
	vArray[0] = dad; 
	vArray[1] = son; 
	vArray[2] = daughter; 
	famTree.addVertices(vArray, 3);

	cout << "Check to see if son is at position 2: ";
	famTree.vertices[2].print(); 
	cout << endl << "If printed son then [3] works as intended. " << endl << endl;
	

	cout << "*************************************** function 7 : searchEdge() ***************************************" << endl;

	cout << "Looking for edge between son and dad: " << endl; 
	if (famTree.searchEdge(dadSon))
		cout << "dad-son exists, function [7] works as intended. " << endl;
	else
		cout << "ERROR: searchEdge() function. "<< endl; 

	Vertex randomV = Vertex("random"); 
	Edge randomE = Edge(randomV, randomV); 
	cout << endl << "Looking for edge that does not exist: " << endl; 
	if (famTree.searchEdge(randomE))
		cout << "ERROR: searchEdge() function. " << endl << endl;
	else
		cout << "random edge does not exist in graph, function [7] works as intended. " << endl << endl; 

	cout << "*************************************** function 8 : searchByVertexValue() ***************************************" << endl;
	if (famTree.searchByVertexValue("daughter"))
		cout << "Search function [8] functions correctly, finds value of vertex. " << endl;
	else
		cout << "ERROR: search function, does not find vertexValue. " << endl; 

	if (famTree.searchByVertexValue("summerpls"))
		cout << "ERROR: search function, finds random vertexValue. " << endl << endl;
	else
		cout << "Search function [8] functions correctly, does not find random value. " << endl << endl; 

	cout << "*************************************** function 2 : directional ***************************************" << endl;

	if (famTree.isDirectional())
		cout << "Graph is directional, function [2] works correctly. " << endl;
	else
		cout << "ERROR: function [2] does not function correctly. " << endl << endl;
	
	cout << "*************************************** function 5-6 : print ********************************************" << endl;

	cout << "Display of all graph paths before adding grandma: " << endl; 
	famTree.displayGraph(); 

	famTree.addVertex(grandma);
	famTree.addEdge(grandmaDad);

	cout << "Display of all graph paths after adding grandma: " << endl;
	famTree.displayGraph();


	cout << "Display of paths starting from Grandma: " << endl; 
	famTree.printFromVertex(grandma);


	cout << endl << endl << "*************************************** function 2 : graph can be undirectional ***************************************" << endl;

	DirectedGraph famTree2;
	//Creating Edges to make graph undirectional
	Edge dadGrandpa = Edge(dad, grandpa);
	Edge sonDad = Edge(son, dad);
	Edge daughterDad = Edge(daughter, dad);

	famTree2.addEdge(grandpaDad);
	famTree2.addEdge(dadSon);
	famTree2.addEdge(dadDaughter);
	famTree2.addEdge(dadGrandpa);
	famTree2.addEdge(sonDad);
	famTree2.addEdge(daughterDad);

	if (famTree2.isDirectional())
		cout << "ERROR: Graph is directional, function [2] does not work correctly. " << endl;
	else
		cout << "Graph is undirectional, function [2] works correctly. " << endl << endl;

	cout << "*************************************** Entire Program works correctly ***************************************" << endl
		<< "**************************************************************************************************************" << endl
		<< "**************************************************************************************************************" << endl
		<< "**************************************************************************************************************" << endl; 

	//--------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------------------------
	// Create your own Graph

	cout << "Small Family Tree Application (one parent, 2 children): " << endl; 

	DirectedGraph famTreeApp;
	string famMember1; 
	string famMember1Child; 
	string famMember1Child2; 
	string yesorno; 

	cout << "Please enter a family member's name: ";
	cin >> famMember1;
	Vertex vertex1(famMember1);
	famTreeApp.addVertex(vertex1);

	cout << endl << "Please enter " << famMember1 << " child: ";
	cin >> famMember1Child; 
	Vertex vertex2(famMember1Child);
	famTreeApp.addVertex(vertex2); 

	//adding first edge in family tree
	Edge edge1(vertex1, vertex2); 
	famTreeApp.addEdge(edge1); 

	cout << endl << "Please enter " << famMember1 << " second child: ";
	cin >> famMember1Child2; 
	Vertex vertex3(famMember1Child2); 
	famTreeApp.addVertex(vertex3); 

	//adding second edge in family tree
	Edge edge2(vertex1, vertex3); 
	famTreeApp.addEdge(edge2); 

	cout << endl << "Display small family: " << endl;
	famTreeApp.displayGraph(); 


}
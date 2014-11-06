#include "dag.h"

Dag::Dag(int vertices)
{
	numberOfVertices = vertices;
	
	// Add nodes/vertices
	IntBoolGraph::iterator node;
	for (int i=0;i<numberOfVertices;i++)
		{
		IntBoolGraph::iterator node = graph.insert(i);
		nodes.push_back(node);
		}
	numberOfEdges	 = 0;
	
	// adjList = new list<int>[numberOfVertices];
	colorList = new char[numberOfVertices];
}

Dag::~Dag()
{
	// delete adjList;
	delete colorList;
}

bool Dag::addEdge(int src, int dst)
{
	bool ret = false;
	if( src < numberOfVertices && dst < numberOfVertices)
		{
		IntBoolGraph::arc_iterator edge = graph.arc_insert(nodes[src],nodes[dst],true);
		arcs.push_back(edge);
		numberOfEdges++;
		ret = true;
		}
	return ret;
}

bool Dag::deleteEdge(int src, int dst)
{
	bool ret = false;
	if( src < numberOfVertices && dst < numberOfVertices)
		{
		//locate and remove the edge
		IntBoolGraph::arc_iterator edge;
		IntBoolGraph::iterator from;
		IntBoolGraph::iterator to;
		for (int i=0;i<numberOfEdges; i++)
			{
				from = graph.arc_from(arcs[i]);
				to = graph.arc_to(arcs[i]);
				if (*from == src && *to == dst)
				{
					graph.arc_erase(arcs[i]);
					numberOfEdges--;
					ret = true;
					break;
				}		
			}
		}
	return ret;
}

void Dag::print(ostream &out)
{
	out << "DAG: " << numberOfVertices << " Vertices and " << numberOfEdges << " Edges " << endl;

	for (int index = 0; index < numberOfVertices; index++)
		{
		out << "["<< index << "] => " ;
		
			for(int j = 0; j< graph.fanout(nodes[index]); j++)
			{
				IntBoolGraph::arc_iterator edge = graph.output(nodes[index],j);
				IntBoolGraph::iterator toNode = graph.arc_to(edge);
				out << *toNode << " " ;
			}
		cout << endl;
		}
}

void Dag::addEdges()
{
	
	int src, dst;
	cout << "Enter the edges (E.g. 4 3 means a directed edge from 4 to 3). -1 -1 as input stops the process" << endl;
	do
		{
			cin >> src >> dst;
			
			if(src!=-1 && !addEdge(src,dst))
				cout <<"Failed to add this edge, (Try again with vertex numbers between range (0,TotalVertices -1))"  << endl;
				
		}while(src!=-1);
}


void Dag::deleteEdges()
{
	
	int src, dst;
	cout << "Enter the edges (E.g. 4 3 means a directed edge from 4 to 3). -1 -1 as input stops the process" << endl;
	do
		{
			cin >> src >> dst;
			
			if(src!=-1 && !deleteEdge(src,dst))
				cout <<"Failed to add this edge, (Try again with vertex numbers between range (0,TotalVertices -1))"  << endl;
				
		}while(src!=-1);
}

vector<int>& Dag::performDfsFromGivenSource()
{
	int src;
	cout << "Enter the source node for DFS...";
	cin >> src;
	
	dfsOutputList.clear();
	for(int i=0;i<numberOfVertices;i++)
	{
		colorList[i] = WHITE;
	}
	dfs(src);
	cout << "DFS from "	<< src << " : ";
	
	for(int i=0;i<dfsOutputList.size();i++)
		cout << dfsOutputList[i] << ", ";
	
	cout << endl;
	return dfsOutputList;
}

void Dag::dfs(int sourceVertex)
{
	colorList[sourceVertex] = BLACK;
	dfsOutputList.push_back(sourceVertex);
	
	for(int j = 0; j< graph.fanout(nodes[sourceVertex]); j++)
		{
		IntBoolGraph::arc_iterator edge = graph.output(nodes[sourceVertex],j);
		IntBoolGraph::iterator toNode = graph.arc_to(edge);
		if ( colorList[*toNode] != BLACK )
			dfs(*toNode);
		}
	cout << endl;
}

bool Dag::doesCycleExist()
{
	NodeVector topo = graph.dag_sort();
	return topo.empty();
}

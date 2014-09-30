#include "dag.h"

Dag::Dag(int vertices)
{
	numberOfVertices = vertices;
	numberOfEdges	 = 0;
	
	adjList = new list<int>[numberOfVertices];
	colorList = new char[numberOfVertices];
}

Dag::~Dag()
{
	delete adjList;
	delete colorList;
}

bool Dag::addEdge(int src, int dst)
{
	bool ret = false;
	if( src < numberOfVertices && dst < numberOfVertices)
		{
		adjList[src].push_back(dst);
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
		adjList[src].remove(dst);
		numberOfEdges--;
		ret = true;
		}
	return ret;
}

ostream &operator << (ostream &out, const Dag &dag)
{
	out << "DAG: " << dag.numberOfVertices << " Vertices and " << dag.numberOfEdges << " Edges " << endl;
	
	for (int index = 0; index < dag.numberOfVertices; index++)
		{
		out << "["<< index << "] => " ;
	 	for (list<int>::iterator it=dag.adjList[index].begin(); it != dag.adjList[index].end(); ++it)
			{
				out << *it << " " ;
			}
		cout << endl;
		}
  
	return out;
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

void Dag::dfs(int sourceVertex, list<int> & outputList)
{
	for(int i=0;i<numberOfVertices;i++)
	{
		colorList[i] = WHITE;
	}
	colorList[sourceVertex] = BLACK;
	outputList.push_back(sourceVertex);
	for(list<int>::iterator it = adjList[sourceVertex].begin(); it != adjList[sourceVertex].end(); ++it)
		{
			if ( colorList[*it] != BLACK )
				dfs(*it,outputList);
		}
}

bool Dag::doesCycleExist()
{
	for(int i=0;i<numberOfVertices;i++)
	{
		colorList[i] = WHITE;
	}
	
	for(int i=0;i<numberOfVertices;i++)
	{
		if( colorList[i] == WHITE )
			{
				if ( visit(i) )
					return true;
			}
	}
	return false;	
}

bool Dag::visit(int v)
{
	int u;
	colorList[v] = GREY;
	
	for (list<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); ++it)
		{
			u = *it;
			
			if ( colorList[u] == GREY)
				{
				cout << " Edge " << v << "," << u << " is involved in cycle" << endl;
				return true;
				}
			else if (colorList[u] == WHITE)
				{
					if ( visit(u) )
						return true;
				}
		}
	
	colorList[v] = BLACK;
	return false;
}


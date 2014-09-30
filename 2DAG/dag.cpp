#include "dag.h"

Dag::Dag(int vertices)
{
	numberOfVertices = vertices;
	numberOfEdges	 = 0;
	
	adjList = new list<int>[numberOfVertices];
}

Dag::~Dag()
{

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


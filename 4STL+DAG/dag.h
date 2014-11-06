#include <iostream>
#include <list>
#include <vector>
#include "digraph.hpp"
using namespace std;

enum Color { WHITE, GREY, BLACK };

typedef stlplus::digraph<int,bool> IntBoolGraph; // int Node Type & bool arc type
typedef std::vector<IntBoolGraph::iterator> NodeVector ;
typedef std::vector<IntBoolGraph::arc_iterator> ArcVector ;


class Dag
{
	public:
		Dag(int vertices);
		~Dag();
		
		int vertices() { return numberOfVertices; }
		int edges() { return numberOfEdges; }

		bool addEdge(int src, int dst);
		void addEdges();
		
		bool deleteEdge(int src, int dst);
		void deleteEdges();
		
		vector<int>& performDfsFromGivenSource();
		void dfs(int sourceVertex);
		
		bool doesCycleExist();
		bool visit(int vertex);
		
		void print(ostream &out);

	private:
		int numberOfEdges;
		int numberOfVertices;
		list<int>* adjList;
		char* colorList;
		vector<int> dfsOutputList;
		
		IntBoolGraph graph;
		NodeVector nodes;
		ArcVector arcs;
		
};

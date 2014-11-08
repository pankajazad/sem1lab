#include <iostream>
#include <list>
#include <vector>
using namespace std;

enum Color { WHITE, GREY, BLACK };

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
		
		friend ostream &operator << (ostream &out, const Dag &dag);

	private:
		int numberOfEdges;
		int numberOfVertices;
		list<int>* adjList;
		char* colorList;
		vector<int> dfsOutputList;
};

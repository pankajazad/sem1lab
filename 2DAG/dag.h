#include <iostream>
#include <list>
using namespace std;



class Dag
{
	public:
		Dag(int vertices);
		~Dag();
		
		int vertices();
		int edges();

		bool addEdge(int src, int dst);
		void addEdges();
		
		bool deleteEdge(int src, int dst);
		void deleteEdges();
		friend ostream &operator << (ostream &out, const Dag &dag);

	private:
		int numberOfEdges;
		int numberOfVertices;
		list<int>* adjList;
};

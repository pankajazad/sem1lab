#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "dag.h"

#ifdef __linux__
	#define CLEAR_SCREEN system("clear")
#elif _WIN32
	#define CLEAR_SCREEN system("cls")
#endif

using namespace std;

int main()
{
	int input=0,vertices=0;

	CLEAR_SCREEN;

	cout << "\nComputational Lab - Assignment 2: Directed Acyclic Graph (DAG)";
	cout << "\nBy: Pankaj Azad, Roll Number - 14M517, M.Tech Ist Sem\n\n\n" << endl;
	
	cout << "Enter number of vertices...";
	cin >> vertices;

	Dag dag(vertices);


	dag.addEdges();
	
	do
	{
		cout << "Enter any of the following available choices" << endl;
		cout << "1 - Add Edge(s)" << endl;
		cout << "2 - Delete Edge(s)" << endl;
		cout << "3 - Print Adjacency list" << endl;
		cout << "4 - Depth First Search (DFS)" << endl;
		cout << "5 - Detect existence of cycle" << endl;
		cout << "9 - Exit" << endl;
		
		cin >> input;
		switch(input)
		{
			case 1: 
				dag.addEdges();
				break;

			case 2: 
				dag.deleteEdges();
				break;
		
			case 3: 
				cout << dag << endl;
				break;

			case 4: 
			{
				int src;
				cout << "Enter the source node for DFS...";
				cin >> src;
				list<int> outputList(dag.vertices()*dag.vertices());
				dag.dfs(src,outputList);
				cout << "DFS from "	<< src << " : ";
				for(list<int>::iterator it = outputList.begin(); it != outputList.end(); it++)
					cout << *it << " , " ;
				cout << endl;
				break;
			}
				
			case 5: cout << ( dag.doesCycleExist()? "Cycle Exits": "No Cycle found") << endl;
				break;		
						
			case 9: exit(0);
				break;
		}
		
	}while(input!=9);
	
	return 0;
}

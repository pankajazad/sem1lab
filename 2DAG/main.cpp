#include <iostream>
#include <cstdlib>
#include "dag.h"

using namespace std;

int main()
{
	int input=0,vertices=0;

	#ifdef __linux__
		system("clear");
	#elif _WIN32
		system("cls");
	#endif

	cout << "\n----------- Computational Lab - Assignment 2: Directed Acyclic Graph (DAG) ----------------";
	cout << "\n---------------- By: Pankaj Azad, Roll Number - 14M517, M.Tech Ist Sem --------------------\n\n\n" << endl;
	
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
		cout << "4 - " << endl;
		
		cin >> input;
		switch(input)
		{
			case 1: dag.addEdges();
				break;

			case 2: dag.deleteEdges();
				break;
		
			case 3: cout << dag << endl;
				break;

			case 4: 
				break;
		}
	}while(input!=9);
	
	return 0;
}

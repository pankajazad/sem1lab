#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void bubblesort(void *list,size_t numOfElements, size_t sizeOfEachElement, int (*compar)(const void*,const void*));

int intComparator(const void *s1, const void *s2);

int main()
{

	int numOfElements;

	#ifdef __linux__
		system("clear");
	#elif _WIN32
		system("cls");
	#endif

	cout << "\n---------------------- Computational Lab - Assignment 1: Bubble Sort ---------------------------";
	cout << "\n------------------- By: Pankaj Azad, Roll Number - 14M517, M.Tech Ist Sem ----------------------\n\n\n" ;
	

	cout << "Enter the number of elements..." << endl;
	cin >> numOfElements;

	int *list = new int[numOfElements];

	cout << "Enter " << numOfElements << " integer elements delimited by a space or newline" << endl;
	for(int i=0;i<numOfElements;i++)
		cin >> list[i];

	bubblesort(list,numOfElements,sizeof(int),intComparator);
	
	cout << "Sorted list is " << endl;
	
	for (int i=0;i<numOfElements;i++)
		cout << list[i] << "   ";

	cout << endl;

	delete list;
	return 0;
}

void bubblesort(void *list,size_t numOfElements, size_t sizeOfEachElement, int (*compare)(const void*,const void*))
{
	char *temp = new char[sizeOfEachElement];
	void *s1, *s2;

	bool swapped = false;
	do
		{
		swapped = false;
		for (int i = 0; i<numOfElements-1; i++)
			{
			s1 =list + i*sizeOfEachElement;
			s2 = list + (i+1)*sizeOfEachElement;

			if( compare (s1 ,s2 ) > 0)
				{
				memcpy(temp, s1, sizeOfEachElement);
				memcpy(s1, s2, sizeOfEachElement);
				memcpy(s2, temp, sizeOfEachElement);
				swapped = true;			
				}
			}
		}while(swapped);

	delete temp;
}


int intComparator(const void *s1, const void *s2)
{
	return ( *((int *)s1) - *((int*)s2) );
}


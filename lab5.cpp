/* Norris, Joel R.
 * filename		: lab5.cpp
 * class		: CSCI_3080
 * instructor	: Dr. Pettey
 * description	: read in the array-pointer representation of a graph, tell which nodes are isolated, and print out the adjacency matrix.
*/

#include <iostream>

using namespace std;


int main()
{
	const int MAX_ROWS = 30;
	const int MAX_COLS = 2;
	int A[MAX_ROWS][MAX_COLS] = { 0 };
	int numNodes = 0;
	int numRows = 0;
	
	// get the number of nodes from the user
	cout << endl;
	cout << "Please enter the umber of nodes: ";
		
	cin >> numNodes;

	// get the number of rows from the user
	cout << endl;
	cout << "How many rows are in the array-pointer representation? ";

	cin >> numRows;

	// get the array-pointer representation from the user
	cout << endl;
	cout << "Please input the array-pointer representation of the graph: " << endl;

	// determine the isolated nodes, 
	// those will be in the initial portion of the array, within numNodes,  w/ a -1.



    return 0;
}


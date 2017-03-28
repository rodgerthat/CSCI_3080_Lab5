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
	int isolatedNodesArray[MAX_ROWS] = { 0 };
	int numIsolatedNodes = 0;
	int i, j;
	
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
    for (i = 0; i < numRows; ++i) {
		for (j = 0; j < MAX_COLS; ++j) {
            cin >> A[i][j];
        }
    }

	// print out array-pointer representation
	cout << "numNodes: " << numNodes << endl;
	cout << "numRows: " << numRows << endl;
    for (i = 0; i < numRows; ++i) {
		for (j = 0; j < MAX_COLS; ++j) {
            cout << A[i][j] << " ";
        }
		cout << endl;
    }


	// determine the isolated nodes, 
	// those will be in the initial portion of the array, within numNodes,  w/ a -1.
	cout << "--------------" << endl;
	for (i = 0; i < numNodes; ++i) {
		// if this node is -1, it's isolated.
		cout << "A[i][1]: " << A[i][1] << endl;
		if (A[i][1] == -1) {
			// put it in the isolatedNodeArray
			isolatedNodesArray[numIsolatedNodes] = A[i][0];
			++numIsolatedNodes;
		}
	}

	// check if there's more than one node, the language pluralizes
	if (numIsolatedNodes > 1) {
		cout << "nodes ";
		for (i = 0; i < numIsolatedNodes - 1; ++i) {
			cout << isolatedNodesArray[i] << " ";
		}
		cout << "and " << isolatedNodesArray[numIsolatedNodes -1] <<  " are isolated" << endl;
	} else {
		cout << "node " << isolatedNodesArray[0] << " is isolated" << endl;
	}


    return 0;
}


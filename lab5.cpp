/* Norris, Joel R.
 * filename		: lab5.cpp
 * class		: CSCI_3080
 * instructor	: Dr. Pettey
 * description	: read in the array-pointer representation of a graph, 
 *				: tell which nodes are isolated, and print out the adjacency matrix.
*/

#include <iostream>

using namespace std;

int main()
{
	const int MAX_ROWS = 30;
	const int MAX_COLS = 2;
	int A[MAX_ROWS][MAX_COLS] = { 0 };		// array pointer representation
	int AM[MAX_ROWS][MAX_ROWS] = { 0 };		// adjacency matrix
	int numNodes = 0;
	int numRows = 0;
	int isolatedNodesArray[MAX_ROWS] = { 0 };
	int numIsolatedNodes = 0;
	int i, j;

	// get the number of nodes from the user
	cout << endl;
	cout << "Please input the number of nodes: ";

	cin >> numNodes;

	// get the number of rows from the user
	cout << "How many rows are in the array-pointer representation? ";

	cin >> numRows;

	// get the array-pointer representation from the user, assign the values into the array
	cout << "Please input the array-pointer representation of the graph: " << endl;
	for (i = 0; i < numRows; ++i) {
		for (j = 0; j < MAX_COLS; ++j) {
			cin >> A[i][j];
		}
	}

	// print out array-pointer representation
	// for debuggery
	/*
	cout << "numNodes: " << numNodes << endl;
	cout << "numRows: " << numRows << endl;
	cout << endl;
	for (i = 0; i < numRows; ++i) {
		for (j = 0; j < MAX_COLS; ++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/

	// build an adjacency matrix based on the array-pointer representation
	// loop through the rows in the matrix and assign 1's to the corresponding adjacency columns for each row.
	for (int i = 0; i < numNodes; ++i) {

		int nodeVal = A[i][0];
		int nodeNext = A[i][1];

		// if the first node contains a -1 for it's nodeNext value, it's isolated
		if (nodeNext == -1) {
			isolatedNodesArray[numIsolatedNodes] = A[i][0];
			++numIsolatedNodes;
		};

		// if the node is not isolated, we need to follow it's adjacency pointer~path
		if (nodeNext != -1) {

			do {

				// get the values from the next node in the tree, offset for numerical index
				nodeVal = A[nodeNext - 1][0];
				nodeNext = A[nodeNext - 1][1];

				// assign a 1 to the proper column in the row of the adjacency matrix
				// subtract one to counter for the mathematician entering the values
				// so it's an array index
				AM[i][nodeVal - 1] = 1;

			} while (nodeNext != -1);	// once we hit -1 we're at the end of the pointer~path

		}

	}

	// tell the benevolent mathamatician how many nodes are isolated
	// check if there's more than one node, the language pluralizes
	// is that a word? pluralizes? a language major, i am not.
	cout << endl;
	if (numIsolatedNodes == 0) {
		cout << "There are no isolated nodes.";
	} else if (numIsolatedNodes > 1) {
		cout << "nodes ";
		for (i = 0; i < numIsolatedNodes - 1; ++i) {
			cout << isolatedNodesArray[i] << " ";
		}
		cout << "and " << isolatedNodesArray[numIsolatedNodes -1] <<  " are isolated" << endl;
	} else {
		cout << "node " << isolatedNodesArray[0] << " is isolated" << endl;
	}
	cout << endl;

	// print out the adjacency matrix
	cout << endl << "The adjacency matrix is" << endl;
	for (i = 0; i < numNodes; ++i) {
		for (j = 0; j < numNodes; ++j) {
			cout << AM[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}

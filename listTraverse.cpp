// filename: listTraverse.cpp
// stub for moving through a wonky array-pointer representation.
//
// "apr" is short for "array-pointer representation"
// 

#include <iostream>

using namespace std;

const int ROWS=30;
const int COLS=2;
int apr1[ROWS][COLS]={{1,4},{2,5},{3,-1},{2,-1},{1,-1}};
const int apr1_numNodes = 3;
const int apr1_numRows = 5;
int apr2[ROWS][COLS]={{1,5},{2,8},{3,11},{4,14},{2,6},{3,7},{4,-1},{1,9},{3,10},{4,-1},{1,12},{2,13},{4,-1},{1,15},{2,16},{3,-1}};
const int apr2_numNodes = 4;
const int apr2_numRows = 16;

void traverseArray(int apr[][COLS], int numNodes);
void printArray(int apr[][COLS], int numRows);

int main() {

	printArray(apr1, apr1_numRows);
    cout << endl;
    //printArray(apr2);
    
    traverseArray(apr1, apr1_numRows);
    cout << endl;
    traverseArray(apr2, apr2_numNodes);

    return 0;

}

void traverseArray(int apr[][COLS], int numNodes) {

    // loop through the list nodes
    //
    // if the first node contains a -1 it's isolated, 
    //
    // otherwise follow the 

    // the initial node value is the row of the adjacency matrix

    for (int i=0; i<numNodes; ++i) {
        
        int nodeVal = apr[i][0];
        int nodeNext = apr[i][1];

        // if the first node contains a -1 for it's nodeNext value, it's isolated
        cout << "| " <<  nodeVal << " | " << nodeNext << " |";

        if ( nodeNext != -1 ) cout << "-->";

        if ( nodeNext != -1 ) {

            do {

                nodeVal = apr[nodeNext-1][0];
                nodeNext = apr[nodeNext-1][1];

                cout << "| " <<  nodeVal << " | " << nodeNext << " |";
                if ( nodeNext != -1 ) cout << "-->";


            } while ( nodeNext != -1 );

        }

        cout << endl;
        cout << endl;
    }

	// check if entry node as value of -1, if so, it's isolated, no need to path
	

	// otherwise follow the path
	

}
 
void printArray(int apr[][COLS], int numRows) {

    for (int i=0; i<numRows; ++i) {

        cout << i << " " << i+1 << " : ";

        for (int j=0; j<COLS; ++j) {
            
            cout << apr[i][j] << " ";

        }

        cout << endl;

    }
}


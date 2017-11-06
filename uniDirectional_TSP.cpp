/*
 *      Author: Patrick Smith
 *      Date: 2-9-17
 *      Class: CSCI 4950
 *      Assignment: Unidirectional TSP
 *      Description:
 *          Find the minimum weight path given a matrix where
 *          the TSP can only travel to adjacent nodes in the
 *          forward direction.
 */
#include <iostream>
#include <limits>

struct Info{
    int theCost;
    int trace[100]; // 100 is max # of number.
} myInfo;

int row, col;

void recur(int currTrace[100], int mySum, int currRow, int currCol, int theMatrix[][100]);
// Recursively track sum and path of 2d matrix.

void combineTrace(int currTrace[100]);
// Assign correct path for the lowest cost path.

int main() {
    int myMatrix[10][100]; // Matrix that stores all elements.

    while(std::cin >> row >> col) {
        myInfo.theCost = std::numeric_limits<int>::max(); // Assigns max int for initialization purposes.

        // Take input into array.
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                std::cin >> myMatrix[i][j];
        }

        for (int i = 0; i < row; i++){
            int myTrace[100]; // Create current path used for each starting index.
            recur(myTrace, myMatrix[i][0], i, 0, myMatrix); // Starting index that gets path.

        }

        // Print shortest path.
        for (int i = 0; i < col; i++){
            if (i + 1 == col)
                std::cout << myInfo.trace[i];
            else
                std::cout << myInfo.trace[i] << " ";
        }
        std::cout << std::endl << myInfo.theCost << std::endl; // Print shortest path cost.
    }

    return 0;
}

void recur(int currTrace[100], int mySum, int currRow, int currCol, int theMatrix[][100]){
    if (currCol == col){
        if (myInfo.theCost > mySum){
            myInfo.theCost = mySum; // Assigns new lowest sum.
            combineTrace(currTrace); // Corrects path to reflect new lowest sum.
        }
    }
    else{
        // Get the new indexes for our recursive function.
        int first = row + currRow - 1;
        int second = currRow;
        int third = currRow + 1;
        first = first % row;
        third = third % row;
        currTrace[currCol] = currRow + 1; // Assign row to current path.

        recur(currTrace, mySum + theMatrix[first][currCol + 1], first, currCol + 1, theMatrix); // Left
        recur(currTrace, mySum + theMatrix[second][currCol + 1], second, currCol + 1, theMatrix); // Center
        recur(currTrace, mySum + theMatrix[third][currCol + 1], third, currCol + 1, theMatrix); // Right
    }
}

void combineTrace(int currTrace[100]){
    for (int i = 0; i < col; i++){
        myInfo.trace[i] = currTrace[i];
    }
}

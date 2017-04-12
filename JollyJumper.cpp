/************************************************************
 *      Author: Patrick Smith
 *      Date: 1-26-17
 *      Class: CSCI 4950
 *      Assignment: Jolly Jumpers
 *      Description:
 *          Determines whether a set of integers of some
 *          sequence contains all absolute differences from
 *          (n-1) to 1.
 *          An absolute difference is |a-b|, where a and b
 *          are sequential.
 *
************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

bool findJolly(std::stringstream & theStream);
// Determines if a set of numbers has all possible values
// 1 through n - 1, which are absolute differences.

int main() {
    std::string myLine;
    bool check;

    // Gets the next line of input and stores it in
    // myLine. Which contains each set of numbers.
    while (std::getline(std::cin, myLine)){

        // Creates a new input from the string myLine.
        std::stringstream myStream(myLine);

        // Function call to determine if the current
        // set of numbers have all absolute differences.
        check = findJolly(myStream);
        if (check)
            std::cout << "Jolly" << std::endl;
        else
            std::cout << "Not jolly" << std::endl;

    }
    return 0;
}

bool findJolly(std::stringstream & theStream){
    int temp1, temp2;

    // This needs to be unsigned int because this
    // will be used as the size of vector<bool>.
    unsigned int mySize;

    theStream >> mySize >> temp1;

    std::vector<bool> theList(mySize - 1);

    // This sets each index of the vector to true
    // when it is reached by an absolute difference.
    for (int i = 0; i < mySize - 1; i++){
        theStream >> temp2;
        theList[std::abs(temp1 - temp2)] = true;
        temp1 = temp2;
    }

    // This checks whether all elements in the vector are true
    // or not. If an absolute difference was not reached then the
    // element will be undefined.
    for (int i = 1; i < mySize; i++){
        if (!theList[i])
            return false;
    }
    return true;
}

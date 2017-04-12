/*
 *      Author: Patrick Smith
 *      Date: 2-2-17
 *      Class: CSCI 4950
 *      Assignment: #3, Shoemaker's Problem
 *      Description:
 *          A shoemaker has N jobs and can only work on one a day.
 *          For each i-th job, the time in days to complete and the
 *          fine per day until start is given. Calculate the order
 *          of each job that would result in the least amount of fines.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int getMax(std::vector<float> & theList);
// Gets the max element within our vector and
// replaces the max element with a zero. The
// index+1 is returned.

int main() {
    int numCases;
    std::cin >> numCases;

    while(numCases--) {

        std::vector<float> myList;
        float first, second;
        int theSize;

        std::cin >> theSize;
        // Calculates the cost per day ratio and
        // inputs the results in a vector.
        for (int i = 0; i < theSize; i++) {
            std::cin >> first >> second;
            myList.push_back(second / first);
        }

        // Obtains the correct order for least amount of fines.
        for (int i = 0; i < myList.size(); i++) {
            // This makes sure that we have spaces in the correct places.
            if (i + 1 < myList.size())
                std::cout << getMax(myList) << " ";
            else
                std::cout << getMax(myList);
        }
        // We want two newlines for every case but the last one.
        if (numCases >= 1)
            std::cout << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

int getMax(std::vector<float> & theList){
    int key = 0;
    float max = 0;
    for (int i = 0; i < theList.size(); i++){

        // Finds the max inside the current list.
        // The key is set to index+1 because
        // of output formatting.
        if (theList[i] > max){
            key = i + 1;
            max = theList[i];
        }
    }

    // The max number is set to zero so we can correctly
    // find the next biggest number during the next
    // iteration.
    theList[key - 1] = 0;
    return key;
}

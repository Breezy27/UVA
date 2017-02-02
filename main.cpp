/*--------------------------------------------------
 *      Author: Patrick Smith
 *      Date: 1-9-2016
 *      Class: CSCI 4950
 *      Assignment: Problem 1
 *      Description: Finds the maximum cycle length
 *          between two integers (inclusive)
 *          using the 3n+1 approach.
--------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int findCycle(long int i);
// Finds the cycle length of a given integer.

int main() {
    int currentCycle, maxCycle = 0;
    std::string myLine;
    std::vector<long int> myArray;

    // The while loop reads until there are no
    // lines left in file to read.
    while (std::getline(std::cin, myLine)){
         long int temp1, temp2;

        // stringstream is created inside while loop
        // or else the new line would not be passed.
        std::stringstream myStream(myLine);

        // Input of data to variables which are then
        // inserted into vector.
        myStream >> temp1 >> temp2;
        myArray.push_back(temp1);
        myArray.push_back(temp2);
    }

    // Iterate by two since our vector contains the
    // integers we need to use in pairs.
    for (int i = 0; i < myArray.size(); i = i + 2){

        // Output of pair.
        std::cout << myArray[i] << " " << myArray[i + 1] << " ";

        // Finds max cycle for each pair and assigns to
        // variable for immediate output.
        // If and else; switches the order of which integer from pair leads.
        // This is needed or else all cycles will not be calculated.
        if (myArray[i] < myArray[i + 1]){
            for (long int j = myArray[i]; j <= myArray[i + 1]; j++){
                currentCycle = findCycle(j);
                if (currentCycle > maxCycle)
                    maxCycle = currentCycle;
            }
        }
        else{
            for (long int j = myArray[i + 1]; j <= myArray[i]; j++){
                currentCycle = findCycle(j);
                if (currentCycle > maxCycle)
                    maxCycle = currentCycle;
            }
        }


        std::cout << maxCycle << std::endl;

        // This is so the next pair with a lesser max
        // cycle don't run into issues.
        maxCycle = 0;
    }

    return 0;
}

int findCycle(long int i){

    // Current is the cycle length of i.
    // Current is initialized to 1 since we already
    // have our first number (i).
    int current = 1;

    // Terminates the loop if we reach 1.
    while (i != 1){

        // Decides whether i is even or odd.
        if ((i % 2) == 0){
            i /= 2;
            current++;
        }
        else{
            i = (3 * i) + 1;
            current++;
        }
    }

    return current;
}

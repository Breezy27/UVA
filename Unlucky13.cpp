/*
 *      Author: Patrick Smith
 *      Last Revised: 3-3-17
 *      Description:
 *          Finds the count of all n-digit numbers that do not contain 13.
 *          Memoization is used. We get all numbers with 13 from base case
 *          and build off of that to obtain results.
 *
 *				Note the program is very expensive and may take some
 *
 *				time to run.
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <sstream>

int UL(const int n);
// Returns the number of n-digit length integers
// that do not contain "13".

void creation(const int n);
// Creates new set of all n-digit length numbers
// that contain "13". Stores in global list.

std::string toString(const int num);
// Converts int to string.

bool inList(const std::string myString, const int n);
// Checks to see if string is in the current list.

void leftAppend(const std::string myString, const int n);
// Appends new left values for given string and puts
// any new elements into the global list.

void rightAppend(const std::string myString, const int n);
// Appends new right values for given string and puts
// any new elements into the global list.

// Global where all numbers with "13" are stored.
std::vector<std::vector<std::string> > list;

int main(){
    int n;
    std::cout << "Input n: ";
    std::cin >> n;

    // Initializes correct number of spaces for first vector
    // and puts -1 as sentinel value in each element.
    for (int i = 0; i <= n; i++){
        std::vector<std::string> tempVec;
        tempVec.push_back("-1");
        list.push_back(tempVec);
    }

    // Base case.
    if (n > 1)
        list[2][0] = "13";

    int result = UL(n); // Function call.

    /* UNCOMMENT TO SEE ALL VALUES FOR LIST[N].
    for (int i = 0; i < list[n].size(); i++){
        std::cout << i << ": " << list[n][i] << std::endl;
    }*/

    std::cout << "Number of " << n << "-digit lucky numbers: " << result << std::endl;
}

int UL(const int n){
    // Base case that needs to be included or else
    // program gets seg fault.
    if (n == 1)
        return 10;

    // Check global list to see if answer is known.
    // If not call creation.
    if (list[n][0] == "-1"){
        creation(n);
    }

    // Returns number of integers without "13" of n-digit length.
    return std::pow(10, n) - std::pow(10, n-1) - list[n].size();
}

void creation(const int n){
    // Check to see if previous n is known, if not previous n
    // is calculated until original n is calculated.
    if ((list[n][0] == "-1") && (n > 3)){
        creation(n-1);
    }

    // Function call to append all left and right values for each element
    // in the previous n.
    for(int i = 0; i < list[n-1].size(); i++){
        leftAppend(list[n-1][i], n);
        rightAppend(list[n-1][i], n);
    }
}

std::string toString(const int num){
    std::stringstream sIn;
    sIn << num;
    return sIn.str();
}

bool inList(const std::string myString, const int n){
    // For loop iterates through all known elements in list[n].
    for (int i = 0; i < list[n].size(); i++){
        if (list[n][i] == myString) // If matching string;
            return true;
    }
    return false;
}

void leftAppend(const std::string myString, const int n){
    // The left values will always be 1-9.
    for (int i = 1; i < 10; i++){
        std::string tempString = toString(i) + myString; // Places string in correct order.
        if (list[n][0] == "-1"){ // Check to see if list has any values. This is needed or we get extra.
            list[n][0] = tempString;
        }
        else{
            if (!inList(tempString, n)) // Checks to see if value does not exist in list.
                list[n].push_back(tempString);
        }
    }
}

void rightAppend(const std::string myString, const int n){
    // The right values will always be 0-9.
    for (int i = 0; i < 10; i++){
        std::string tempString =  myString + toString(i); // Places string in correct order.
        if (list[n][0] == "-1"){ // Check to see if list has any values. This is needed or we get extra.
            list[n][0] = tempString;
        }
        else{
            if (!inList(tempString, n)) // Checks to see if value does not exist in list.
                list[n].push_back(tempString);
        }
    }
}

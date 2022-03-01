#ifndef TESTLOCATIONLOCALFORCPP_CHAPTER7EXERCISES_H
#define TESTLOCATIONLOCALFORCPP_CHAPTER7EXERCISES_H

#include <cmath>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

class Chapter7Exercises {

    // Functions for Exercise 7.1
    void E7_1_greaterThanAverage(const double list[], const int &arraySize);
    double E7_1_findAverage(const double list[], const int &arraySize);

    // Functions for Exercise 7.2.
    /* All functions for this Exercise are copies from Listing 7.6
     * */
    void E7_2_reverse(const int list[], int newList[], int size);
    void E7_2_printArray(const int list[], int size);

    // Functions for Exercise 7.3
    void E7_3_countOccurrences(const int list[], int counts[], const int &arraySize, const int &upperLimit);
    void E7_3_displayCounts(const int counts[], const int &upperLimit);

    // Functions for Exercise 7.4
    void E7_4_compareToAverage(const double list[], const int &arraySize);
    double E7_4_findAverage(const double list[], const int &arraySize);

public:

    // Covers content from Sections 7.2 - 7.4
    int Exercise7_1();                              // (Analysing input)
    int Exercise7_2();                              // (Reversing the numbers entered)
    int Exercise7_3();                              // (Counting the occurrence of numbers)
    int Exercise7_4();                              // (Analysing scores)

};


#endif //TESTLOCATIONLOCALFORCPP_CHAPTER7EXERCISES_H

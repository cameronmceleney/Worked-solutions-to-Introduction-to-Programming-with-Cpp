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

    // Functions for Exercise 7.5
    void E7_5_printDistinctNumbers(int list[], const int &arraySize);
    bool E7_5_isInList(int list[], const int &arraySize, const int &testValue);
    void E7_5_printArray(const int list[], const int &arraySize);

    // Function for Exercise 7.6
    void E7_6_findPrimes(int listOfPrimes[], const int &numberOfPrimesToFind);
    void E7_6_printArray(const int list[], const int &arraySize);

    // Functions for Exercise 7.7
    void E7_7_countRandomNumbers(int counts[], const int &totalToGenerate, const int &maxValue);
    void E7_7_printArray(const int counts[], const int &maxValue);

    // Functions for Exercise 7.8
    int E7_8_indexOfSmallestElement(double array[], int size);

    // Functions for Exercise 7.9
    double E7_9_max(double array[], int size);

    // Functions for Exercise 7.10
    int E7_10_average(const int array[], int size);
    double E7_10_average(const double array[], int size);

    // Functions for Exercise 7.11
    double E7_11_mean(const double x[], int size);
    double E7_11_deviation(const double x[], int size);

    // Functions for Exercise 7.12
    void E7_12_assignGrades(const double grades[], const int &arraySize);
    double E7_12_findBestGrade(const double grades[], const int &arraySize);

    // Functions for Exercise 7.13
    double E7_13_binarySearch(const int list[], int key, int arraySize);

    // Functions for Exercise 7.14
    int E7_14_linearSearch(const int list[], int key, int arraySize);
    int E7_14_binarySearch(int list[], int key, int arraySize);
    void E7_14_selectionSort(int list[], int arraySize);

    // Functions for Exercise 7.15
    void E7_15_findOpenLockers(const int &numberOfLockers, const int &numberOfStudents);

    // Functions for Exercise 7.16
    void E7_16_bubbleSort(double array[], const int &arraySize);
    void E7_16_swap(double &n1, double &n2);
    void E7_16_printArray(const double array[], const int &arraySize);

    // Functions for Exercise 7.17
    void E7_17_galtonMachine(const int &numberOfBalls, const int &numberOfSlots);
    void E7_17_dropBall(const int &numberOfBalls, const int &numberOfSlots, int slotsArray[]);
    void E7_17_printHistogram(const int &numberOfSlots, const int slotsArray[]);
    int E7_17_findLargest(const int &numberOfSlots, const int slotsArray[]);

    // Functions for Exercise 7.18
    void E7_18_selectionSort(double array[], const int &arraySize);
    void E7_18_printArray(double const array[], const int &arraySize);


public:

    // Covers content from Sections 7.2 - 7.4
    int Exercise7_1();                              // (Analysing input)
    int Exercise7_2();                              // (Reversing the numbers entered)
    int Exercise7_3();                              // (Counting the occurrence of numbers)
    int Exercise7_4();                              // (Analysing scores)
    int Exercise7_5();                              // (Printing distinct numbers)
    int Exercise7_6();                              // (Revising Listing 4.14, PrimeNumber.cpp)
    int Exercise7_7();                              // (Counting single digits)

    // Covers content from Sections 7.5 - 7.7
    int Exercise7_8();                              // (Finding the index of the smallest element)
    int Exercise7_9();                              // (Find the largest element)
    int Exercise7_10();                             // (Averaging an array)
    int Exercise7_11();                             // (Computing deviation)
    int Exercise7_12();                             // (Assigning grades)

    // Covers content from Sections 7.8 - 7.9
    int Exercise7_13();                             // (Financial applications: finding the sales amount) Skipped this
    int Exercise7_14();                             // (Timing execution)
    int Exercise7_15();                             // (Game: locker puzzle)
    int Exercise7_16();                             // (Bubble sort)
    int Exercise7_17();                             // (Game: bean machine)
    int Exercise7_18();                             // (Revising selection sort)
    int Exercise7_19();                             // (Simulation: coupon collector's problem)

};

#endif //TESTLOCATIONLOCALFORCPP_CHAPTER7EXERCISES_H

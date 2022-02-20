#ifndef TESTLOCATIONLOCALFORCPP_CHAPTER5EXERCISES_H
#define TESTLOCATIONLOCALFORCPP_CHAPTER5EXERCISES_H

#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

class Chapter5Exercises {

private:

    // Functions for Exercise 5.1
    int E5_1_getPentagonalNumber(int);

    // Functions for Exercise 5.2
    int E5_2_sumDigits(long n);

    // Functions for Exercise 5.3
    int E5_3_sumDigits(int number);

    // Functions for Exercise 5.4
    int E5_4_reverse(int number);

    // Functions for Exercise 5.5
    bool E5_5_isPalindrome(int number);

    // Functions for Exercise 5.6
    void E5_6_displayPattern(int n);

    // Functions for Exercise 5.7
    double E5_7_computeCommission(double salesAmount);

    // Functions for Exercise 5.8. The implementations of these should be included in a header "UnitConversions.h"
    double E5_8_footToMeter(double foot);
    double E5_8_meterToFoot(double meter);

    // Functions for Exercise 5.9
    bool E5_9_isPrime(int number);

    // Functions for Exercise 5.10. The implementations of these should be saved in the header file "TempConversions.h"
    double E5_10_celsiusToFahrenheit(double celsius);
    double E5_10_fahrenheitToCelsius(double fahrenheit);

    // Functions for Exercise 5.11
    int E5_11_printChars(char ch1, char ch2, int numberPerLine);

    // Functions for Exercise 5.12
    double E5_12_sumSeries(int seriesLimit);

    // Functions for Exercise 5.13
    double E5_13_sumSeries(unsigned int);

    // Functions for Exercise 5.14
    double E5_14_computeTax(int status, double taxableIncome);

public:

    // Covers content from Sections 5.2 - 4.11
    int Exercise5_1();                  // (Math: pentagonal numbers)
    int Exercise5_2();                  // (Summing the digits in an integer)
    int Exercise5_3();                  // (Returning the sum of digits in a number)
    int Exercise5_4();                  // (Returning an integer reversed)
    int Exercise5_5();                  // (Palindrome number)
    int Exercise5_6();                  // (Displaying patterns)
    int Exercise5_7();                  // (Financial application: computing commissions)
    int Exercise5_8();                  // (Conversions between feet and meters)
    int Exercise5_9();                  // (Using the isPrime Function)
    int Exercise5_10();                 // (Conversions between Celsius and Fahrenheit)
    int Exercise5_11();                 // (Displaying a set of characters and the number of characters in the set)
    int Exercise5_12();                 // (Summing series)
    int Exercise5_13();                 // (Computing series)
    int Exercise5_14();                 // (Financial application: print a tax table)
};


#endif //TESTLOCATIONLOCALFORCPP_CHAPTER5EXERCISES_H

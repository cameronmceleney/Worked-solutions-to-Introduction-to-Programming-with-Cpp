//
// Created by Cameron Aidan McEleney on 17/02/2022.
//

#ifndef TESTLOCATIONLOCALFORCPP_CHAPTER5LISTINGS_H
#define TESTLOCATIONLOCALFORCPP_CHAPTER5LISTINGS_H

#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std; // All of the book's functions use this namespace, so will give class scope for ease
class Chapter5Listings {
private:
    // These functions are private to simplify the tooltip options in this software's main.cpp file. Moving them to
    // public would affect no change.

    // Functions for Listing 5.1
    int L5_1_max(int num1, int num2);               // Return max between two numbers for Listing 5.1

    // Functions for Listing 5.2
    void L5_2_printGrade(double score);             // Print grade for the score

    // Functions for Listing 5.3
    char L5_3_getGrade(double score);               // Return the grade for the score

    // Functions for Listing 5.4
    int L5_4_gcd(int n1, int n2);                   // Return the gcd of two integers

    // Functions for Listing 5.5
    bool L5_5_isPrime(int number);                  // Check whether number is prime
    void L5_5_printPrimeNumbers(int numberOfPrimes);// Test if a number is prime, and print list of primes to console

    // Functions for Listing 5.6
    int L5_6_max(int num1, int num2);               // Return the max between two int values
    double L5_6_max(double num1, double num2);      // Find the max between two double values
    double L5_6_max(double num1, double num2, double num3);     // Find the max among three double values

public:
    // The functions here are the main() functions shown in each of the Listings. If you wish to use one of these
    // elsewhere, ensure you also copy the corresponding private function(s).

    int TestMax();                                  // Listing 5.1
    int TestVoidFunction();                         // Listing 5.2
    int TestReturnGradeFunction();                  // Listing 5.3
    int GreatestCommonDivisorFunction();            // Listing 5.4
    int PrimeNumberFunction();                      // Listing 5.5
    int TestFunctionOverloading();                  // Listing 5.6
};


#endif //TESTLOCATIONLOCALFORCPP_CHAPTER5LISTINGS_H

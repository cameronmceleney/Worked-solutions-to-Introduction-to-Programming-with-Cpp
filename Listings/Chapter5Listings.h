#ifndef TESTLOCATIONLOCALFORCPP_CHAPTER5LISTINGS_H
#define TESTLOCATIONLOCALFORCPP_CHAPTER5LISTINGS_H

#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std; // All the book's functions use this namespace, so will give class scope for ease
class Chapter5Listings {
private:
    /* These functions are private to simplify the tooltip options in this software's main.cpp file. Moving them to
     * public would affect no change. */

    // Functions for Listing 5.1
    int L5_1_max(int num1, int num2);                           // Return max between two numbers for Listing 5.1

    // Functions for Listing 5.2
    void L5_2_printGrade(double score);                         // Print grade for the score

    // Functions for Listing 5.3
    char L5_3_getGrade(double score);                           // Return the grade for the score

    // Functions for Listing 5.4
    int L5_4_gcd(int n1, int n2);                               // Return the gcd of two integers

    // Functions for Listing 5.5
    bool L5_5_isPrime(int number);                              // Check whether number is prime
    void L5_5_printPrimeNumbers(int numberOfPrimes);            // Test if a number is prime, and print list of primes to console

    // Functions for Listing 5.6
    int L5_6_max(int num1, int num2);                           // Return the max between two int values
    double L5_6_max(double num1, double num2);                  // Find the max between two double values
    double L5_6_max(double num1, double num2, double num3);     // Find the max among three double values

    // Listing 5.7
    /* Prototypes. Copy these into your program and include before functions being invoked (prototypes are declared
     *in this class header file under different function names)
     * int max(int, int); double max(double, double); double max(double, double, double); */
    // Functions.
    int L5_7_max(int num1, int num2);                           // Return the max between two int values
    double L5_7_max(double num1, double num2);                  // Find the max between two double values
    double L5_7_max(double num1, double num2, double num3);     // Find the max among three double values

    // Listing 5.8 / 5.9 combined
    /* Functions below were meant to be included in a separate header file called "MyLib.h"
     */
    bool L5_8_isEven(int number);                               // <-- the header file is Listing 5.8
    /* Statements below should be included at top of .cpp file UseMyLib.cpp
     * #include "MyLib.h"                                       // <-- the .cpp file is Listing 5.9 */

    // Listing 5.10 / 5.11 combined
    /* Prototype below is meant to be the prototype that is placed in a separate file called "MyLib.h"
     * */
    bool L5_10_isEven(int number);                              // <-- header file is Listing 5.10
    /* Function implementation of L_5_10_isEven is meant to be included in a file called "MyLib.cpp"
     */

    // Listing 5.12 / 5.13 combined
    /* Functions named by the prototypes below are intended to be included in the file "RandomCharacter.h", which
     * would then be included in "TestRandomCharacter.cpp" by the directive #include "RandomCharacter.h"
     *
     * The RandomCharacter.h file is Listing 5.12, and the TestRandomCharacter.cpp file is Listing 5.13*/
    char L5_12_getRandomCharacter(char ch1, char ch2);          // Generate a random character between ch1 and ch2
    char L5_12_getRandomLowerCaseLetter();                      // Generate a random lowercase letter
    char L5_12_getRandomUpperCaseLetter();                      // Generate a random uppercase letter
    char L5_12_getRandomDigitCharacter();                       // Generate a random digit character
    char L5_12_getRandomCharacter();                            // Generate a random character

    // Listing 5.12
    // Intentionally blank. There are no dependents to include here


public:
    /* The functions here are the main() functions shown in each of the Listings. If you wish to use one of these
     * elsewhere, ensure you also copy the corresponding private function(s). */

    int TestMax();                                              // Listing 5.1
    int TestVoidFunction();                                     // Listing 5.2
    int TestReturnGradeFunction();                              // Listing 5.3
    int GreatestCommonDivisorFunction();                        // Listing 5.4
    int PrimeNumberFunction();                                  // Listing 5.5
    int TestFunctionOverloading();                              // Listing 5.6
    int TestFunctionPrototype();                                // Listing 5.7
    int UseMyLib();                                             // Listing 5.8 / 5.9 combined
    int MyLib();                                                // Listing 5.10 / 5.11 combined
    int TestRandomCharacter();                                  // Listing 5.12 / 5.13 combined
    int MathFunctions();                                        // Listing 5.14
    int CharacterFunctions();                                   // Listing 5.15
};


#endif //TESTLOCATIONLOCALFORCPP_CHAPTER5LISTINGS_H

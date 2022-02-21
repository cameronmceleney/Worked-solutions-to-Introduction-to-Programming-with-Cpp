#ifndef TESTLOCATIONLOCALFORCPP_CHAPTER6LISTINGS_H
#define TESTLOCATIONLOCALFORCPP_CHAPTER6LISTINGS_H

#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

class Chapter6Listings {

private:
    // Functions for Listing 6.1
    void L6_1_increment(int n);

    // Functions for Listing 6.2
    void L6_2_swap(int n1, int n2);

    // There are no functions for Listing 6.3

    // Functions for Listing 6.4
    void L6_4_increment(int &n);

    // Functions for Listing 6.5
    void L6_5_swap(int &n1, int &n2);

    // Functions for Listing 6.6
    void L6_6_t1();
    void L6_6_t2();

    // Functions for Listing 6.7
    void L6_7_t1();

    // Functions for Listing 6.8
    // This function is defined in "Chapter6Listings.cpp"

    // There are no functions for Listing 6.9

    // Functions for Listing 6.10
    void L6_10_printArea(double radius);
    /* Note: If you wish to declare a function with a default value, then this must be done in EITHER the -prototype or
     * function-declaration, but not both. Else this will throw a 'redeclaration error' from the compiler. Here,
     * the default value is declared in the .cpp file*/

public:
    /* These functions serve as main() functions. The filename that they should be associated with is given as a
     * comment to the right */

    int Listing6_1();                           // Increment.cpp
    int Listing6_2();                           // TestPassByValue.cpp
    int Listing6_3();                           // TestReferenceValue.cpp
    int Listing6_4();                           // IncrementWithPassByReference.cpp
    int Listing6_5();                           // TestPassByReference.cpp
    int Listing6_6();                           // VariableScopeDemo.cpp
    int Listing6_7();                           // StaticVariableDemo.cpp
    int Listing6_8();                           // InlineDemo.cpp
    int Listing6_9();                           // InlineDemo1.cpp
    int Listing6_10();                          // DefaultArgumentsDemo.cpp

};


#endif //TESTLOCATIONLOCALFORCPP_CHAPTER6LISTINGS_H

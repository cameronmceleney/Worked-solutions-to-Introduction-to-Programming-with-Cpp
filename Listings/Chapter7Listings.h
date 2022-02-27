#ifndef TESTLOCATIONLOCALFORCPP_CHAPTER7LISTINGS_H
#define TESTLOCATIONLOCALFORCPP_CHAPTER7LISTINGS_H

#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

class Chapter7Listings {
private:

    // Notes for Listing 7.0
    /* These examples were not a Listing example, but instead were short pieces of code to substantiate a text
     * description. They're included here to allow for easy referral when studying, and also for copying/pasting
     * when solving examples later on.*/
    void L7_0_declareArrays();
    void L7_0_processArrays();
    void L7_0_randomValues(double myList[], int ARRAY_SIZE);
    void L7_0_printingArrays(double myList[], int ARRAY_SIZE);
    void L7_0_copyingArrays(double myList[], int ARRAY_SIZE);
    // Notes for Listing 7.1
    /* No functions for Listing 7.1 . To run this Listing as the book suggests, copy/paste the code into a file called
     * LottoNumbers.cpp and compile. Next, create a .txt file called LottoNumbers.txt which contains the data
     * '2 5 6 5 4 3 23 43 2 0' (without the apostrophes). Then, in the terminal, type
     * 'LottoNumbers.exe < LottoNumbers.txt'

     */

public:
    //
    int Listing7_0();                           // Collection of examples from the start of Chapter 7
    int Listing7_1();                           // LottoNumbers.cpp
};

#endif //TESTLOCATIONLOCALFORCPP_CHAPTER7LISTINGS_H

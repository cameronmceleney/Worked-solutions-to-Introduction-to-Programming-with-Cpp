#ifndef TESTLOCATIONLOCALFORCPP_CHAPTER7LISTINGS_H
#define TESTLOCATIONLOCALFORCPP_CHAPTER7LISTINGS_H

#include <cmath>
#include <cstring>
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
    void L7_0_sumAllElements(double myList[], int ARRAY_SIZE);
    void L7_0_findLargestElement(double myList[], int ARRAY_SIZE);
    void L7_0_findSmallestIndex(double myList[], int ARRAY_SIZE);
    void L7_0_randomShuffling(double myList[], int ARRAY_SIZE);
    void L7_0_shiftingElements(double myList[], int ARRAY_SIZE);

    // Notes for Listing 7.1
    /*To run this Listing as the book suggests, copy/paste the code into a file called
     * LottoNumbers.cpp and compile. Next, create a .txt file called LottoNumbers.txt which contains the data
     * '2 5 6 5 4 3 23 43 2 0' (without the apostrophes). Then, in the terminal, type
     * 'LottoNumbers.exe < LottoNumbers.txt'
     */

    // Functions for Listing 7.2
    void L7_2_displayRank(int rank);
    void L7_2_displaySuit(int suit);

    // Functions for Listing 7.3
    void L7_3_printArray(int list[], int arraySize);

    // Functions for Listing 7.4
    void L7_4_m(int number, int numbers[0]);

    // Functions for Listing 7.5
    void L7_5_p(const int list[], int arraySize);

    // Functions for Listing 7.6
    void L7_6_reverse(const int list[], int newList[], int size);
    void L7_6_printArray(const int list[], int size);

    // Functions for Listing 7.7
    void L7_7_createArray(char []);
    char L7_7_getRandomCharacter(char, char);
    char L7_7_getRandomLowerCaseLetter();
    void L7_7_displayArray(const char []);
    void L7_7_countLetters(const char [], int []);
    void L7_7_displayCounts(const int []);

    // Functions for Listing 7.8 and Listing 7.9, which have the same .cpp file of Searches
    int L7_8_linearSearch(const int list[], int key, int arraySize); // Listing 7.8
    int L7_9_binarySearch(const int list[], int key, int arraySize); // Listing 7.9

    // Functions for Listing 7.10 and 7.11
    void L7_10_printArrayLinear(double list[], int listSize);
    void L7_10_printArrayInsert(double list[], int listSize);
    void L7_10_printArrayElements(double list[], int listSize);
    void L7_10_selectionSort(double list[], int listSize); // Listing 7.10
    void L7_10_insertionSort(double list[], int listSize); // Listing 7.11

public:
    //
    int Listing7_0();                           // Collection of examples from the start of Chapter 7
    int Listing7_1();                           // LottoNumbers.cpp
    int Listing7_2();                           // DeckOfCards.cpp
    int Listing7_3();                           // PassArrayDemo.cpp
    int Listing7_4();                           // PassByReferenceDemo.cpp
    int Listing7_5();                           // ConstArrayDemo.cpp
    int Listing7_6();                           // ReverseArray.cpp
    int Listing7_7();                           // CountLettersInArray.cpp
    int Listing7_8();                           // Searches.cpp. Contains headers which are Listing 7.8 & 7.9
    int Listing7_10();                          // SortingArrays.cpp
    int Listing7_12();                          // CStringFunctionDemo.cpp

};

#endif //TESTLOCATIONLOCALFORCPP_CHAPTER7LISTINGS_H

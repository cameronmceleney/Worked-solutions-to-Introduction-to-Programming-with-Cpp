#include "Chapter5Exercises.h"

int Chapter5Exercises::E5_1_getPentagonalNumber(int n) {
    // Test if the given number is a pentagonal number
    return n * (3*n - 1) / 2;
}
int Chapter5Exercises::Exercise5_1() {

    /* (- difficulty)
     *
     * A pentagonal number is defined as n*(3*n - 1)/2 for n = 1, 2, ..., and so on. So,the first few numbers
     * are 1, 5, 12, 22, ... . Write the following function that returns a pentagonal number:
     *
     *      int getPentagonalNumber(int n)
     *
     * Write a test program that displays the first 100 pentagonal numbers with 10 numbers on each line
     */

    const int NUMBERS_PER_LINE = 10, TEXT_WIDTH = 8, TOTAL_PENTAGONAL_NUMBERS = 100;

    cout << "The first " << TOTAL_PENTAGONAL_NUMBERS << " pentagonal numbers are:\n\n";
    cout << left;

    for (int iPentagonal = 1; iPentagonal <= TOTAL_PENTAGONAL_NUMBERS; iPentagonal++) {

        if (iPentagonal % NUMBERS_PER_LINE == 0)
            cout << setw(TEXT_WIDTH) << E5_1_getPentagonalNumber(iPentagonal) << '\n';
        else
            cout << setw(TEXT_WIDTH) << E5_1_getPentagonalNumber(iPentagonal);
    }

    return 0;
}

#include "Chapter7Listings.h"

void Chapter7Listings::L7_0_declareArrays() {

    // This is the minimal information that must be provided for an array to be declared.
    double myArray[10];

    // The arraySize must be passed as a constant expression; below shows how to do this. Useful technique when trying
    // to pass an array to a function as a parameter
    const int SIZE = 10;
    double myList[SIZE];

    // This is an illegal example
    /* int size = 4
     * double myList[size];
     */

    // Can declare multiple arrays together (of different sizes) so long as the arrays are of the same dtype. Otherwise,
    // one must use multiple statement to declare arrays of different dtypes
    const int size1 = 4, size2 = 6;
    double myArray1[size1], myArray2[size2];

    // This is the shorthand way to declare and initialise an array; known as the 'array initialiser'
    const int SIZE_SHORTHAND = 5;
    double myShorthandArray[SIZE_SHORTHAND] = {1.9, 2.9, 3.4, 3.5};

    // Illegal way to implement array initialiser, as the statement has been divided across two lines
    /* double myList[4];
     * myList = {1.9, 2.9, 3.4, 3.5}
     */

    // Additional way to use array initialiser. Here the arraySize is omitted as the compiler is able to automatically
    // detect how long the array is
    double myAutoList[] = {1.9, 2.9, 3.4, 3.5};
}
void Chapter7Listings::L7_0_processArrays() {
    const int ARRAY_SIZE = 10;
    double myList[ARRAY_SIZE];
    L7_0_randomValues(myList, ARRAY_SIZE);
    L7_0_printingArrays(myList,ARRAY_SIZE);
    L7_0_printingArrays(myList, ARRAY_SIZE);
}
void Chapter7Listings::L7_0_randomValues(double myList[], int ARRAY_SIZE) {
    // Shows how to initialise an array of a known length and fill with random values

    for (int i = 0; i < ARRAY_SIZE; i++) {
        myList[i] = rand() % 100;
    }
}
void Chapter7Listings::L7_0_printingArrays(double myList[], int ARRAY_SIZE) {
    // To print an array, you must print each element of it
    for (int i =0; i < ARRAY_SIZE; i++) {
        cout << myList[i];
    }
}
void Chapter7Listings::L7_0_copyingArrays(double myList[], int ARRAY_SIZE) {
    // You cannot copy two arrays  directly by assignment (myList1 = myList2). Instead, you must copy them elementwise
    double list[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        list[i] = myList[i];
    }
}
int Chapter7Listings::Listing7_1() {

    bool isCovered[99];
    int number; // number read from a file

    // Initialise the array
    for (int i = 0; i < 99; i++)
        isCovered[i] = false;

    // Read each number and mark its corresponding element covered
    cin >> number;
    while (number != 0)
    {
        isCovered[number - 1] = true;
        cin >> number;
    }

    // Check if all covered
    bool allCovered = true; // Assume all covered initially
    for (int i = 0; i < 99; i++)
    {
        if (!isCovered[i])
        {
            allCovered = false; // Find one number is not covered
            break;
        }
    }

    // Display result
    if (allCovered)
        cout << "The tickets cover all numbers" << endl;
    else
        cout << "The tickets don't cover all numbers" << endl;

    return 0;
}

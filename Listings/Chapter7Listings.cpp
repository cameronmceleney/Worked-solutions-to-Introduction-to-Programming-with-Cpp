#include "Chapter7Listings.h"

int Chapter7Listings::Listing7_0() {
    // A function that is more like an index in a book. Listing 7.0 is my own creation, and contains several examples
    // for the reader on how to declare, and use, arrays.
    L7_0_declareArrays();
    L7_0_processArrays();

    return 0;
}
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

    // None of these functions output anything, they're simply listed here to aid the reader in finding content
    L7_0_randomValues(myList, ARRAY_SIZE);
    L7_0_printingArrays(myList, ARRAY_SIZE);
    L7_0_copyingArrays(myList, ARRAY_SIZE);
    L7_0_sumAllElements(myList, ARRAY_SIZE);
    L7_0_findLargestElement(myList, ARRAY_SIZE);
    L7_0_findSmallestIndex(myList, ARRAY_SIZE);
    L7_0_randomShuffling(myList, ARRAY_SIZE);
    L7_0_shiftingElements(myList, ARRAY_SIZE);
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
void Chapter7Listings::L7_0_sumAllElements(double myList[], int ARRAY_SIZE) {
    // Use a variable declared out with a loop to track the total of elements
    double total = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        total += myList[i];
    }
}
void Chapter7Listings::L7_0_findLargestElement(double myList[], int ARRAY_SIZE) {
    // Use a variable declared out with a loop to track the largest element in an array
    double max = myList[0]; // Initialise max to be the 0th element, which always exists for an array of a non-NULL
                            // length
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (myList[i] > max)
            max = myList[i];
    }
}
void Chapter7Listings::L7_0_findSmallestIndex(double myList[], int ARRAY_SIZE) {
    // Often you may wish to find a particular value (here we look for the largest value in an array). C++ arrays
    // DO permit duplicate values, so it is common to want to find a value and the earliest occurrence (lowest index)
    // it occurs
    double max = myList[0];
    int indexOfMax = 0;

    for (int i = 1; i < ARRAY_SIZE; i++) {

        if (myList[i] > max) {
            max = myList[i];
            indexOfMax = i;
        }
    }
}
void Chapter7Listings::L7_0_randomShuffling(double myList[], int ARRAY_SIZE) {
    // Reordering the elements of an array is called shuffling. Often, this needs to be done so that the positions
    // of the elements are random in the new array

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        // Generate an index randomly
        int index = rand() % ARRAY_SIZE;

        // Swap myList[i] with myList[index]. This is the same as previous examples of swapping the contents of two
        // variables 'a' and 'b'.
        double temp = myList[i];
        myList[i] = myList[index];
        myList[index] = temp;
    }
}
void Chapter7Listings::L7_0_shiftingElements(double myList[], int ARRAY_SIZE) {
    // Sometimes you many need to shift all elements in an array (not recommended for large arrays!) a discrete
    // number of steps in a left- or right-direction

    double temp = myList[0]; // Retain the leftmost elements

    // Shift elements left
    for (int i = 0; i < ARRAY_SIZE; i++)
        myList[i - 1] = myList[i];

    // Move the first element to fill in the last position
    myList[ARRAY_SIZE - 1] = temp;
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

int Chapter7Listings::Listing7_2() {

    const int NUMBER_OF_CARDS = 52;

    int deck[NUMBER_OF_CARDS];

    for (int i = 0; i < NUMBER_OF_CARDS; i++) {
        // Initialise cards
        deck[i] = i;
    }

    // Shuffle the cards
    srand(time(0));

    for (int i = 0; i < NUMBER_OF_CARDS; i++) {
        // Generate an index randomly and shuffle the cards
        int index = rand() % NUMBER_OF_CARDS;
        int temp = deck[i];
        deck[i] = deck[index];
        deck[index] = temp;
    }

    for (int i = 0; i < 4; i++) {
        // Display the first four cards
        L7_2_displayRank(deck[i] % 13);
        L7_2_displaySuit(deck[i] / 13);
    }

    return 0;
}
void Chapter7Listings::L7_2_displayRank(int rank) {

    if (rank == 0)
        cout << "Ace of ";
    else if (rank == 10)
        cout << "Jack of ";
    else if (rank == 11)
        cout << "Queen of ";
    else if (rank == 12)
        cout << "King of ";
    else
        cout << rank << " of ";
}
void Chapter7Listings::L7_2_displaySuit(int suit) {

    if (suit == 0)
        cout << "Clubs" << '\n';
    else if (suit == 1)
        cout << "Diamonds" << '\n';
    else if (suit == 2)
        cout << "Hearts" << '\n';
    else if (suit == 3)
        cout << "Spades" << '\n';
}

int Chapter7Listings::Listing7_3() {

    int numbers[5] = {1, 4, 3, 6, 8};
    L7_3_printArray(numbers, 5);

    return 0;
}
void Chapter7Listings::L7_3_printArray(int list[], int arraySize) {

    for (int i = 0; i < arraySize; i++)
        cout << list[i] << " ";
}

int Chapter7Listings::Listing7_4() {
    // Purpose of this Listing is to highlight how arrays follow pass-by-reference, while variables can follow
    // pass-by-value

    int x = 1; // x represents an int value
    int y[10]; // y represents an array of int value
    y[0] = 1; // Initialise y[0]

    L7_4_m(x, y); // Invoke m with arguments x and y

    cout << "x is " << x << endl;
    cout << "y[0] is " << y[0] << endl;

    return 0;
}
void Chapter7Listings::L7_4_m(int number, int numbers[0]) {

    number = 1001; // Assign a new value to number
    numbers[0] = 5555; // Assign a new value to numbers[0]
}

int Chapter7Listings::Listing7_5() {

    int numbers[5] = {1, 4, 3, 6, 8};
    L7_5_p(numbers, 5);

    return 0;
}
void Chapter7Listings::L7_5_p(const int list[], int arraySize) {

    // Modify array accidentally
    //list[0] = 100; // Compile error
}
int Chapter7Listings::Listing7_6() {

    int size = 6;
    int list[] = {1, 2, 3, 4, 5, 6};
    int newList[6];

    L7_6_reverse(list, newList, size);

    cout << "The original array: ";
    L7_6_printArray(list, 6);
    cout << endl;

    cout << "The reversed array: ";
    L7_6_printArray(newList, 6);
    cout << endl;

    return 0;
}
void Chapter7Listings::L7_6_reverse(const int list[], int newList[], int size) {
    // newList is the reversal of list by copying the final element of list to the first element of newList, and so on

    for (int i = 0, j = size - 1; i < size; i++, j--)
        newList[j] = list[i];
}
void Chapter7Listings::L7_6_printArray(const int list[], int size) {
    // Prints array called 'list' element-by-element
    for (int i = 0; i < size; i++)
        cout << list[i] << " ";
}

const int L7_7_NUMBER_OF_RANDOM_LETTERS = 100;
int Chapter7Listings::Listing7_7() {


    // Declare and create an array
    char chars[L7_7_NUMBER_OF_RANDOM_LETTERS];

    // Initialise the array with random lowercase letters
    L7_7_createArray(chars);

    // Display the array
    cout << "The lowercase letters are: " << endl;
    L7_7_displayArray(chars);

    // Count the occurrences of each letter (26 as there are 26 letters in the English alphabet)
    int counts[26];

    // Count the occurrences of each letter
    L7_7_countLetters(chars, counts);

    // Display counts
    cout << "\nThe occurrences of each letter are: " << endl;
    L7_7_displayCounts(counts);

    return 0;
}
void Chapter7Listings::L7_7_createArray(char chars[]) {
    // Create an array of characters

    // Create lowercase letter randomly and assign them to the array
    srand(time(0));
    for (int i = 0; i < L7_7_NUMBER_OF_RANDOM_LETTERS; i++)
        chars[i] = L7_7_getRandomLowerCaseLetter();
}
char Chapter7Listings::L7_7_getRandomCharacter(char ch1, char ch2) {
    // Generate a random character between ch1 and ch2. Exact copy from Listing 5.12
    return static_cast<char>(ch1 + rand() % (ch2 - ch1 + 1));
}
char Chapter7Listings::L7_7_getRandomLowerCaseLetter() {
    // Generate a random lowercase letter
    return L7_7_getRandomCharacter('a', 'z');
}
void Chapter7Listings::L7_7_displayArray(const char chars[]) {
    // Display the array of characters

    for (int i = 0; i < L7_7_NUMBER_OF_RANDOM_LETTERS; i++) {
        // Display the characters in the array 20 on each line
        if ((i + 1) % 20 == 0)
            cout << chars[i] << " " << endl;
        else
            cout << chars[i] << " ";
    }
}
void Chapter7Listings::L7_7_countLetters(const char chars[], int counts[]) {
    // Count the occurrences of each letter

    for (int i = 0; i < 26; i++)
        // Initialise the array
        counts[i] = 0;

    for (int i = 0; i < L7_7_NUMBER_OF_RANDOM_LETTERS; i++)
        // For each lowercase letter in the array, count it. Knowing a char is an int value, 'a' - 'a' = 0 etc
        counts[chars[i] - 'a'] ++;
}
void Chapter7Listings::L7_7_displayCounts(const int counts[]) {
    // Display counts with slight alteration to make output more readable

    for (int i = 0; i < 26; i++) {

        if ((i + 1) % 10 == 0)
            cout << static_cast<char>(i + 'a') << ": " << counts[i] << endl;
        else
            cout << static_cast<char>(i + 'a') << ": " << counts[i] << " | ";
    }
}

int Chapter7Listings::Listing7_8() {
    // Traces the function to linearly search with the given examples

    int list[] = {1, 4, 4, 2, 5, -3, 6 ,2};
    int i = L7_8_linearSearch(list, 4, 8); // Should return 1 (found at element 1)
    int j = L7_8_linearSearch(list, -4, 8); // Should return -1 (doesn't exist in given array)
    int k = L7_8_linearSearch(list, -3, 8); // Should return 5 (found at element 5)

    cout << i << ", " << j << ", " << k << endl;

    return 0;
}
int Chapter7Listings::L7_8_linearSearch(const int list[], int key, int arraySize) {
    // Search through elements of array sequentially, and when first match is found, return index
    for (int i = 0; i < arraySize; i++) {

        if (key == list[i])
            return i;
    }

    return -1;
}
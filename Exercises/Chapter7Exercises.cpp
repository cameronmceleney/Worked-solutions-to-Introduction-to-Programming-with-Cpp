#include "Chapter7Exercises.h"

int Chapter7Exercises::Exercise7_1() {

    /* (- difficulty)
     *
     * Write a program that reads ten numbers, computes their average, and finds out how many numbers are above the
     * average. Here is a sample run of the program:
     *
     *          Enter ten numbers: 1 2.7 3 4 5 6 7 8 9 10
     *          The average is 5.57
     *          The number of values greater than the average is 5
     */

    int MAX_INPUT_NUMBERS = 10;

    // Prompt user for input
    cout << "Enter ten numbers: ";
    double list[MAX_INPUT_NUMBERS];

    for (int i = 0; i < MAX_INPUT_NUMBERS; i++)
        cin >> list[i];

    E7_1_greaterThanAverage(list, MAX_INPUT_NUMBERS);

    return 0;
}
void Chapter7Exercises::E7_1_greaterThanAverage(const double list[], const int &arraySize) {
    // Finds how many values in an array are greater than the average value in the array
    double average = E7_1_findAverage(list, arraySize);

    int countAboveAverage = 0;
    for (int i = 0; i < arraySize; i++) {
        if (list[i] > average)
            countAboveAverage++;
    }

    cout << "The number of values greater than the average is " << countAboveAverage << "\n";
}
double Chapter7Exercises::E7_1_findAverage(const double list[], const int &arraySize) {
    // Finds the average of a given array

    double sum = 0;
    for (int i = 0; i < arraySize; i++)
        sum += list[i];

    double average = sum / arraySize; // average = total(n) / n
    cout << "The average is " << average << "\n";

    return average;
}

int Chapter7Exercises::Exercise7_2() {

    /* (- difficulty)
     *
     * Write a program that reads ten integers and displays them in the reverse of the order in which they were read
     */

    const int MAX_INPUTS = 10;

    // Prompt user for input
    cout << "Enter ten numbers: ";
    int list[MAX_INPUTS], reversedList[MAX_INPUTS]; // No need to delete or overwrite original array here

    for (int i = 0; i < MAX_INPUTS; i++)
        cin >> list[i];

    E7_2_reverse(list, reversedList, MAX_INPUTS);

    // Output reversed array to user
    cout << "The reversed array: ";
    E7_2_printArray(reversedList, 10);
    cout << endl;

    return 0;
}
void Chapter7Exercises::E7_2_reverse(const int originalList[], int reversedList[], int arraySize) {
    // newList is the reversal of list by copying the final element of list to the first element of newList, and so on

    for (int i = 0, j = arraySize - 1; i < arraySize; i++, j--)
        reversedList[j] = originalList[i];
}
void Chapter7Exercises::E7_2_printArray(const int list[], int size) {
    // Prints array called 'list' element-by-element
    for (int i = 0; i < size; i++)
        cout << list[i] << " ";
}

int Chapter7Exercises::Exercise7_3() {

    /* (- difficulty)
     *
     * Write a program that accepts any number of integers from the uer in the range of 1 to 50. Count the occurrence
     * of each integer in the user input and print a report of the results. Assume the input ends when 0 is
     * encountered. Here is a sample run:
     *
     *              Enter any number of integers between 1 and 50: 3 5 3 8 12 8 0
     *              3 occurs 2 times
     *              5 occurs 1 time
     *              8 occurs 2 times
     *              12 occurs 1 time
     */

    const int UPPER_LIMIT = 50, LOWER_LIMIT = 1;
    int list[200] = {}; // Can't initialise array to undefined size with uninitialised contents
    int counts[UPPER_LIMIT]; // We are interested in two limits

    // Prompt user for inputs
    cout << "Enter any number of integer between 1 and 50: ";
    int inputValue, count = 0;
    cin >> inputValue;

    while (inputValue != 0) {
        // If input is not zero, and is within given range, then add to list. Otherwise, exit loop.
        if (inputValue >= LOWER_LIMIT && inputValue < UPPER_LIMIT) {
            list[count] = inputValue;
            count++; // Keep track of how many elements have been added to list
            cin >> inputValue;
        } else {
            cout << "Encountered value " << inputValue
                 << ", which is out with range of " << LOWER_LIMIT << " to " << UPPER_LIMIT << ". Exiting" << endl;
            break;
        }
    }

    E7_3_countOccurrences(list, counts, count, UPPER_LIMIT);
    E7_3_displayCounts(counts, UPPER_LIMIT);

    return 0;
}
void Chapter7Exercises::E7_3_countOccurrences(const int list[], int counts[], const int &arraySize, const int &upperLimit) {
    // Count the occurrences of each number. Based upon Listing 7.7

    for (int i = 0; i < upperLimit; i++)
        // Initialise the array
        counts[i] = 0;

    for (int i = 0; i < arraySize; i++) {
        counts[list[i] - 1]++;
    }
}
void Chapter7Exercises::E7_3_displayCounts(const int counts[], const int &upperLimit) {
    // Display counts where the number of counts is non-zero. Based upon Listing 7.7

    for (int i = 0; i < upperLimit; i++)

        if (counts[i] >= 2)
            cout << (i + 1) << " occurs " << counts[i] << " times" << "\n";
        else if (counts [i] == 1)
            cout << (i + 1) << " occurs " << counts[i] << " time" << "\n";
}

int Chapter7Exercises::Exercise7_4() {

    /* (Write a program that reads an unspecified number of sore and determines how many are above or equal to the
     * average and how many are below the average. Enter a negative number to signify the end of the unput. Assume
     * that the maximum number of scores is 100)
     */

    const int MAXIMUM_SCORES = 100;
    double list[MAXIMUM_SCORES];

    // Prompt user for inputs
    cout << "Enter the scores: ";
    int inputValue, count = 0;
    cin >> inputValue;

    while (inputValue >= 0) {
        // If is a positive number, then add to it to the list. Otherwise, exit loop.
        list[count] = inputValue;
        count++; // Keep track of how many elements have been added to list
        cin >> inputValue;
    }

    E7_4_compareToAverage(list, count);

    return 0;
}
void Chapter7Exercises::E7_4_compareToAverage(const double list[], const int &arraySize) {
    // Finds how many values in an array are greater than the average value in the array. Based upon Exercise 7.1
    double average = E7_4_findAverage(list, arraySize);

    int totalAboveAverage = 0, totalAtAverage = 0, totalBelowAverage = 0;
    for (int i = 0; i < arraySize; i++) {
        if (list[i] > average)
            totalAboveAverage++;
        else if (list[i] == average)
            totalAtAverage++;
        else
            totalBelowAverage++;
    }

    cout << "The number of values greater than the average is " << totalAboveAverage << "\n";
    cout << "The number of values equal to the average is " << totalAtAverage << "\n";
    cout << "The number of values lesser than the average is " << totalBelowAverage << "\n";
}
double Chapter7Exercises::E7_4_findAverage(const double list[], const int &arraySize) {
    // Finds the average of a given array. Based upon Exercise 7.1

    double sum = 0;
    for (int i = 0; i < arraySize; i++)
        sum += list[i];

    double average = sum / arraySize; // average = total(n) / n
    cout << "The average is " << average << "\n";

    return average;
}

int Chapter7Exercises::Exercise7_5() {

    /* (** difficulty)
     *
     * Write a program that reads in ten numbers and displays distinct numbers (i.e., if a number appears multiple
     * times, it is displayed only once). (Hint: Read a number and store it to an array if it is new. If the number is
     * already in the array, discard it. After the input, the array contains the distinct numbers.) Here is a
     * sample run of the program:
     *
     *          Enter ten numbers: 1 2 3 2 1 6 3 4 5 2
     *          The distinct numbers are: 1 2 3 6 4 5
     */

    const int MAX_SIZE = 10;
    int list[MAX_SIZE];

    // Prompt user for inputs
    cout << "Enter ten numbers: ";

    E7_5_printDistinctNumbers(list, MAX_SIZE);

    return 0;
}
void Chapter7Exercises::E7_5_printDistinctNumbers(int list[], const int &arraySize) {

    int i = 0, distinctNumbers = 0, inputValue ;

    do {
        // Take in one input
        cin >> inputValue;

        if (i == 0) {
            // First input can be saved straight to the array.
            list[i] = inputValue;
            distinctNumbers++;
            continue;
        }
        if (!E7_5_isInList(list, arraySize, inputValue)) {
            // A return of false means the current input is not in the array, and needs to be saved
            list[distinctNumbers] = inputValue;
            distinctNumbers++;
        }
    } while (++i < arraySize);

    E7_5_printArray(list, distinctNumbers);
}
bool Chapter7Exercises::E7_5_isInList(int list[], const int &arraySize, const int &testValue) {

    bool isValueInList = false; // Declared out with loop to ensure all control paths are covered.

    for (int i = 0; i < arraySize; i++) {

        if (list[i] == testValue)
            isValueInList = true;
    }

    return isValueInList;
}
void Chapter7Exercises::E7_5_printArray(const int list[], const int &arraySize) {
    // Prints array called 'list' element-by-element
    cout << "The distinct numbers are: ";

    for (int i = 0; i < arraySize; i++)
        cout << list[i] << " ";
}
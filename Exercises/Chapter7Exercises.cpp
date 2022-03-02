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
    // Sorts through the given 'list' to find all the distinct numbers within it
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
    // Tests if a given value is already within a list
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

int Chapter7Exercises::Exercise7_6() {

    /* (* difficulty)
     *
     * Listing 4.14 determines whether a number n is prime by checking 2, 3, 4, 5, 6, ..., n/2 is a divisor. If a
     * divisor is found, n is not prime. A more efficient approach to determine whether n is prime is to check whether
     * any of the prime numbers less than or equal to sqrt(n) can divide n evenly. If not, n is prime. Rewrite
     * Listing 4.14 to display the first 50 prime numbers using this approach. You need to use an array to store the
     * prime numbers and later use them to check whether they are possible divisors for n.
     */

    const int TOTAL_NUMBER_OF_PRIMES = 50;

    int list[TOTAL_NUMBER_OF_PRIMES]; // List to write the primes to within the main program

    E7_6_findPrimes(list, TOTAL_NUMBER_OF_PRIMES);

    return 0;
}
void Chapter7Exercises::E7_6_findPrimes(int listOfPrimes[], const int &numberOfPrimesToFind) {
    // Finds a set total number of primes, and saves them to an array, using a more efficient method than Listing 4.14

    // Start at n = 3, as 0 & 1 are not prime and two is the first prime
    int numberOfPrimes = 0, n = 3;

    // Include the first prime number to begin the list
    listOfPrimes[0] = 2; numberOfPrimes++;

    while (numberOfPrimes <= numberOfPrimesToFind) {

        bool isPrime = true;

        for (int i = 0; i <= sqrt(n) && isPrime; i++) {

            if (n % listOfPrimes[i] == 0) {
                isPrime = false;
            }
        }

        if (isPrime) {
            listOfPrimes[numberOfPrimes] = n;
            numberOfPrimes++;
        }

        n++;
    }

    E7_6_printArray(listOfPrimes, numberOfPrimesToFind);
}
void Chapter7Exercises::E7_6_printArray(const int list[], const int &arraySize) {
    // Prints array called 'list' element-by-element
    const int NUMBER_OF_PRIMES_PER_LINE = 10;

    cout << left;

    for (int i = 0; i < arraySize; i++)

        if ((i + 1) % NUMBER_OF_PRIMES_PER_LINE == 0)
            cout << setw(8) << list[i] << endl;
        else
            cout << setw(8) << list[i];
}

int Chapter7Exercises::Exercise7_7() {

    /* (* difficulty)
     *
     * Write a program that generates one hundred random integers between 0 and 9 and displays the count for each
     * number. (Hint: Use rand() % 10 to generate a random integer between 0 and 9. Use an array of ten integers,
     * say 'counts', to store the counts for the number of 0's, 1's, ..., 9's.)
     */

    srand(time(0));

    const int NUMBERS_TO_GENERATE = 100, UPPER_LIMIT = 10;
    int list[UPPER_LIMIT] = {0}; // Initialise all elements of array to be zero; prevent "garbage" interfering

    E7_7_countRandomNumbers(list, NUMBERS_TO_GENERATE, UPPER_LIMIT);

    return 0;
}
void Chapter7Exercises::E7_7_countRandomNumbers(int counts[], const int &totalToGenerate, const int &maxValue) {
    // Generate quantity of random numbers within a give range of [0, LIMIT] and record the frequency of each number
    int randomNumber;

    for (int i = 0; i < totalToGenerate; i++) {
        randomNumber = rand() % maxValue;
        counts[randomNumber]++;
    }

    cout << "Total numbers generated: " << totalToGenerate << endl;
    E7_7_printArray(counts, maxValue);

}
void Chapter7Exercises::E7_7_printArray(const int counts[], const int &maxValue) {
    // Print each element in array
    for (int i = 0; i < maxValue; i++) {
        // Match book's formatting
        cout << i << "'s: " << setw(4) << counts[i];
        if ((i+1) % 5 == 0)
            // Take new line every 5 elements
            cout << "\n";
        else
            cout << " | ";
    }
}

int Chapter7Exercises::Exercise7_8() {

    /* (- difficulty)
     *
     * Write a function that returns the index of the smallest element in an array of integers. If there are more such
     * elements than one, return the smallest index. Use the following header:
     *
     *          int indexOfSmallestElement(double array[], int size)
     *
     * Write a test program that prompts the user to enter ten numbers, invokes this function to return the index of
     * the smallest element, and displays the index.
     */
    const int MAX_TOTAL_INPUTS = 10;

    // Test program below
    cout << "Enter ten numbers: ";
    double userInputs[MAX_TOTAL_INPUTS];

    // Save each input to a successive array element
    for (int i = 0; i < MAX_TOTAL_INPUTS; i++) {
        cin >> userInputs[i];
    }

    cout << "Index of smallest value is " << E7_8_indexOfSmallestElement(userInputs, MAX_TOTAL_INPUTS);

    return 0;
}
int Chapter7Exercises::E7_8_indexOfSmallestElement(double array[], int size) {
    // Finds the index of the first instance of the smallest element in an array

    int index = 0;
    double smallestValue = array[0]; // Set first element to be the initial smallest value

    for (int i = 1; i < size; i++)
        if (array[i] > smallestValue) index++;

    return index;
}

int Chapter7Exercises::Exercise7_9() {

    /* (- difficulty)
     *
     * Write a function to find the largest element in an array of integers using the following function header:
     *
     *          double max(double array[], int size)
     *
     * Write a test program that prompts the user to enter eight double values, invokes this function, and displays the
     * maximum value in the array. Here is a sample program run:
     *
     *              Enter eight numbers: 29.2 11.24 8 192 2821.821 0.22 38 4.01
     *              The largest number is: 2821.821
     */
    const int MAX_TOTAL_INPUTS = 8;

    // Test program
    cout << "Enter eight numbers: ";
    double userInputs[MAX_TOTAL_INPUTS];

    // Saves each user input to successive array element
    for (int i = 0; i < MAX_TOTAL_INPUTS; i++)
        cin >> userInputs[i];

    cout << setprecision(12) << "The largest number is: " << E7_9_max(userInputs, MAX_TOTAL_INPUTS);

    return 0;
}
double Chapter7Exercises::E7_9_max(double array[], int size) {
    // Finds the largest value in an array

    double maxValue = array[0];

    for (int i = 1; i < size; i++)
        if (array[i] > maxValue) maxValue = array[i];

    return maxValue;
}

int Chapter7Exercises::Exercise7_10() {

    /* (- difficulty)
     *
     * Write two overloaded functions that return the average of an array with the following headers:
     *
     *
     *      int average(const int array[], int size);
     *      double average(const int array[], int size);
     *
     * Write a test program that prompts the user to enter ten double values, invokes this function, and displays the
     * average value.
     */

    const int MAX_TOTAL_INPUTS = 10;

    cout << "Enter ten double values: ";
    double userInputs[MAX_TOTAL_INPUTS];

    for (int i = 0; i < MAX_TOTAL_INPUTS; i++)
        cin >> userInputs[i];

    cout << "The average value is " << E7_10_average(userInputs, MAX_TOTAL_INPUTS);

    return 0;
}
int Chapter7Exercises::E7_10_average(const int array[], int size) {
    // Finds the average value of a given array

    double average = 0;

    for (int i = 0; i < size; i++)
        average += array[i];

    average /= size;

    return average;
}
double Chapter7Exercises::E7_10_average(const double array[], int size) {
    // Finds the average value of a given array

    double average = 0;

    for (int i = 0; i < size; i++)
        average += array[i];

    average /= size;

    return average;
}

int Chapter7Exercises::Exercise7_11() {

    /* (* difficulty)
     *
     * Exercise 5.21 computes the standard deviation for numbers. This exercise uses a different but equivalent
     * formula to compute the standard deviation of numbers.
     *
     *
     *
     *              mean = SUM(i = 1, n)[x_i] / n = (x1 + x2 + ... + xn) / n
     *              deviation = sqrt(SUM(i = 1, n)[pow((i - mean), 2)] / (n - 1))
     *
     * To compute deviation with this formula, you how to store the individual members using an array, so that they
     * can be used after the mean is obtained. Your program should include the following functions:
     *
     *                  // Compute the mean of an array of double values
     *                  double mean(const double x[], int size)
     *
     *                  // Compute the deviation of double values
     *                  double deviation(const double x[], int size)
     *
     * Write a test program that prompts the user to enter ten numbers and displays the mean and deviation, as shown in
     * the following sample run:
     *
     *
     *                  Enter ten numbers: 1.9 2.5 3.7 2 1 6 3 4 5 2
     *                  The mean is 3.11
     *                  The standard deviation is 1.55738
     */

    const int MAX_INPUTS = 10;

    // Test program
    cout << "Enter ten numbers: ";
    double userInputs[MAX_INPUTS];

    for (int i = 0; i < MAX_INPUTS; i++)
        cin >> userInputs[i];

    cout << "The mean is " << E7_11_mean(userInputs, MAX_INPUTS) << endl;
    cout << "The standard deviation is " << E7_11_deviation(userInputs, MAX_INPUTS) << endl;

    return 0;
}
double Chapter7Exercises::E7_11_deviation(const double x[], int size) {
    // Compute the deviation of double values
    double deviation = 0, summation = 0;
    double mean = E7_11_mean(x, size);

    for (int i = 0; i < size; i++)
        deviation += pow((x[i] - mean), 2);

    deviation = sqrt(deviation / (size - 1));
    return deviation;
}
double Chapter7Exercises::E7_11_mean(const double x[], int size) {
    // Compute the mean of an array of double values
    double mean = 0, summation = 0;

    for (int i = 0; i < size; i++)
        summation += x[i];

    mean = summation / size;

    return mean;
}

int Chapter7Exercises::Exercise7_12() {

    /* (* difficulty)
     *
     * Write a program that reads student scores, get the best score, and then assigns grades based on the following
     * scheme:
     *
     *                          Grade is A if score >= best - 10;
     *                          Grade is B if score >= best - 20;
     *                          Grade is C if score >= best - 30;
     *                          Grade is D if score >= best - 40;
     *                          Grade is F otherwise.
     *
     * The program prompts the user to enter the total number of students, then prompts the user to enter all the
     * scores, and concludes by displaying the grades. here is a sample run:
     *
     *                          Enter the number of students: 4
     *                          Enter 4 scores: 40 55 70 58
     *                          Student 0 score is 40 and grade is C
     *                          Student 1 score is 55 and grade is B
     *                          Student 2 score is 70 and grade is A
     *                          Student 3 score is 58 and grade is B
     */

    // Prompt user for input as stipulated in question
    cout << "Enter the number of students: ";
    int numberOfStudents;
    cin >> numberOfStudents;

    cout << "Enter " << numberOfStudents << " scores: ";
    double grades[numberOfStudents];
    for (int i = 0; i < numberOfStudents; i++) {cin >> grades[i];}

    // Invoke function which contains all cout statements and computations
    E7_12_assignGrades(grades, numberOfStudents);

    return 0;
}
void Chapter7Exercises::E7_12_assignGrades(const double grades[], const int &arraySize) {
    // Assigns a grade to each student based upon what the top score was
    double best = E7_12_findBestGrade(grades, arraySize);

    for (int i = 0; i < arraySize; i++) {

        cout << "Student " << i << " score is " << grades[i] << " and grade is "; // Format as given in question

        if      (grades[i] >= (best - 10))   {cout << "A";}
        else if (grades[i] >= (best - 20))   {cout << "B";}
        else if (grades[i] >= (best - 30))   {cout << "C";}
        else if (grades[i] >= (best - 40))   {cout << "D";}
        else                                 {cout << "E";}

        cout << "\n";
    }
}
double Chapter7Exercises::E7_12_findBestGrade(const double grades[], const int &arraySize) {
    // Finds the largest value in an array, which equates to being the top grade. Copy of Exercise 7.8

    double highestValue = grades[0];

    for (int i = 1; i < arraySize; i++)
        if (grades[i] > highestValue) highestValue = grades[i];

    return highestValue;
}

int Chapter7Exercises::Exercise7_13() {

    /* (- difficulty)
     *
     * Rewrite Programming Exercise 4.37 using the binary search approach. Since the sales amount is between 1 and
     * (COMMISSION_SOUGHT / 0.08), you can use a binary search to improve the solution.
     */

    // All variables are in dollars. Reduce value of individualSale to increase precision of finding targetSalary
    const double individualSale = 1.0, COMMISSION_SOUGHT = 25000; // Compute salary

    double targetSalary = 30000;
    /*
    double salesAmount = 0, commissionEarned = 0;
    while (commissionEarned <= COMMISSION_SOUGHT) {
        salesAmount += individualSale;

        if (salesAmount <= 5000) {
            commissionEarned += 0.08 * individualSale;
        } else if (salesAmount <= 10000) {
            commissionEarned += 0.1 * individualSale;
        } else {
            commissionEarned += 0.12 * individualSale;
        }
    }
    */
    int salesValues[] = {0};

    int arraySize = 0;
    for (int i = 1; i < (COMMISSION_SOUGHT / 0.08); i += 10000) {
        salesValues[arraySize] = i;
        arraySize++;
    }

    double commissionNeeded = E7_13_binarySearch(salesValues, (targetSalary - 5000), arraySize);
    cout << fixed << setprecision(2)
         << "For commission total of $" << COMMISSION_SOUGHT
         << ", one must generate $" << commissionNeeded << " in sales,"
         << endl;

    return 0;
}
double Chapter7Exercises::E7_13_binarySearch(const int list[], int key, int arraySize) {
    // list[] must be ordered before a binarySearch can be used (typically ordered in ascending order)
    int low = 0;
    int high = arraySize - 1;

    cout << setw(12) << low << setw(12) << high << setw(12);

    while (high >= low) {
        // Require >= operator, otherwise search may miss possible matches
        int mid = (low + high) / 2;
        if (key < list[mid])
            // Only search first half of array
            high = mid - 1;
        else if (key == list[mid]) {
            // End search with a match
            cout << setw(20) << mid << endl;
            return mid;
        } else
            // Only search second half of array
            low = mid + 1;
    }

    cout << setw(20) << -1 << endl;
    return -1;
}

int Chapter7Exercises::Exercise7_14() {

    /* (- difficulty)
     *
     * Write a program that randomly generates an array of 100000 integers and a key. Estimate the execution time of
     * invoking the linearSearch function in Listing 7.8. Sort the array and estimate the execution of invoking the
     * binarySearch function in Listing 7.9. You may use the following code:
     *
     *                      long startTime = time(0);
     *                      perform the task;
     *                      long endTime = time(0);
     *                      long executionTime = endTime - startTime();
     */
    srand(time(0));

    const int TOTAL_NUMBERS = 100000, LOWER_LIMIT = 0, UPPER_LIMIT = 100000;
    int key = LOWER_LIMIT + rand() % UPPER_LIMIT;

    cout << "key: " << key << endl;
    int arrayLinear[TOTAL_NUMBERS], arrayBinary[TOTAL_NUMBERS];

    for (int i = 0; i < TOTAL_NUMBERS; i++) {
        int randomInt = LOWER_LIMIT + rand() % UPPER_LIMIT;
        arrayLinear[i] = randomInt;
        arrayBinary[i] = randomInt;
    }

    long startTimeLinear = time(0);
    int keyIndexLinear = E7_14_linearSearch(arrayLinear, key,TOTAL_NUMBERS);
    long endTimeLinear = time(0);
    long executionTimeLinear = endTimeLinear - startTimeLinear;
    cout << "The time taken was " << executionTimeLinear << " to find the key at index: " << keyIndexLinear << endl;

    // binarySearch is slower here as it needs to sort the data first.
    long startTimeBinary = time(0);
    int keyIndexBinary = E7_14_binarySearch(arrayBinary, key,TOTAL_NUMBERS);
    long endTimeBinary = time(0);
    long executionTimeBinary = endTimeBinary - startTimeBinary;
    cout << "The time taken was " << executionTimeBinary << " to find the key at index: " << keyIndexBinary << endl;

    return 0;
}
int Chapter7Exercises::E7_14_linearSearch(const int list[], int key, int arraySize) {
    // Search through elements of array sequentially, and when first match is found, return index
    for (int i = 0; i < arraySize; i++) {

        if (key == list[i])
            return i;
    }

    return -1;
}
int Chapter7Exercises::E7_14_binarySearch(int list[], int key, int arraySize) {
    // list[] must be ordered before a binarySearch can be used (typically ordered in ascending order)
    E7_14_selectionSort(list, arraySize);

    int low = 0;
    int high = arraySize - 1;

    while (high >= low) {
        // Require >= operator, otherwise search may miss possible matches
        int mid = (low + high) / 2;
        if (key < list[mid])
            // Only search first half of array
            high = mid - 1;
        else if (key == list[mid]) {
            // End search with a match
            return mid;
        } else
            // Only search second half of array
            low = mid + 1;
    }

    return -1;
}
void Chapter7Exercises::E7_14_selectionSort(int list[], int arraySize) {
    // Works LHS to RHS along the array, swapping the i_th element with the smallest remaining value to the right of it

    for (int i = 0; i < arraySize; i++) {

        double currentMin = list[i];
        int currentMinIndex = i;

        for (int j = i + 1; j < arraySize; j++) {
            //Find the minimum in the list[i,...,listSize-1]
            if (currentMin > list[j]) {
                // Value at current index is lower than position currently sorting
                currentMin = list[j];
                currentMinIndex = j;
            }
        }

        if (currentMinIndex != i) {
            // Swap the smallest unsorted element (list[currentMinIndex]) with the current position (list[i])
            list[currentMinIndex] = list[i];
            list[i] = currentMin;
        }
    }
}
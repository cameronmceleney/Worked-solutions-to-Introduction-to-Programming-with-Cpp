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

int Chapter5Exercises::E5_2_sumDigits(long n) {
    // Sum the individual digits of n (e.g. if n = 234 then the return would be 2+3+4=9

    int sumOfDigits = 0;

    if (n < 0)
        // Ensures n is positive
        n *= -1;

    do {
        // Add last digit of n to sumOfDigits, then removes the last digit from n.
        sumOfDigits += n % 10;
        n /= 10;
    } while (n > 0);
    return sumOfDigits;
}
int Chapter5Exercises::Exercise5_2() {
    /* (* difficulty)
    *
    * Write a program that computes the sum of the digits in an integer. Use the following function header:
    *
    *              int sumDigits(long n);
    *
    * For example, sumDigits(234) returns 2 + 3 + 4 = 9. Write a program that prompts the user to enter an integer and
    * displays the sum of all its digits.
     *
     * (Hint: Use the % operator to extract a digit and the / operator to remove the extracted digit, for instance, to
     * extract 4 from 234, use 234 % 10 (=4). To remove 4 from 234, use 234 / 10 (=23). Use a loop to repeatedly
     * extract and remove a digit until all digits are extracted.)
    */

    cout << "Enter a positive integer: ";
    int inputInteger;
    cin >> inputInteger;

    cout << "The sum of the digits of " << inputInteger << " is " << E5_2_sumDigits(inputInteger) << '\n';

    return 0;
}

int Chapter5Exercises::E5_3_sumDigits(int number) {
    // Sum the digits of the given parameter

    int sumOfDigits = 0;

    do {
        // Add last digit of 'number' to 'sum', and then remove that last digit from 'number'.
        sumOfDigits += number % 10;
        number /= 10;
    } while (number > 0);

    return sumOfDigits;
}
int Chapter5Exercises::Exercise5_3() {

    /* (- difficulty)
     *
     * Write the following function to return the sum of the digits in an integer.
     *
     *              int sumDigits(int number)
     *
     * For example, sumDigits(9382) returns 22. Write a test program that prompts the user to enter an integer value and
     * then displays the sum of the digits of that value.
     *
     * (Note: Effectively identical to Exercise 5.2)
     */

    cout << "Enter a number: ";
    int number;
    cin >> number;

    cout << "The sum of the digit in " << number << " is " << E5_3_sumDigits(number) << '\n';

    return 0;
}

int Chapter5Exercises::E5_4_reverse(int number) {
    // Reverses 'number' e.g. a parameter of 3456 would be returned as 6543

    int reversedNumber = 0;
    do {
        // Moves the 'writing position' along by one column (no effect when reversedNumber = 0), and then adds the last
        // digit of 'number' to 'reversedNumber'.
        reversedNumber = reversedNumber * 10 + number % 10;
        number /= 10; // Removes the added digit

    } while (number > 0);

    return reversedNumber;
}
int Chapter5Exercises::Exercise5_4() {

    /* (** difficulty)
     *
     * Write the following function to return an integer reversed:
     *
     *              int reverse(int number);
     *
     * For example, reverse(3456) returns 6543. Write a test program that prompts the user to enter an integer and
     * displays its reversal.
     */

    cout << "Enter an integer to reverse: ";
    int numberToReverse;
    cin >> numberToReverse;

    cout << "The reversed integer of " << numberToReverse << " is " << E5_4_reverse(numberToReverse) << '\n';

    return 0;
}

bool Chapter5Exercises::E5_5_isPalindrome(int number) {
    // Returns true/false for if a given 'number' is a palindrome
    int reversedNumber = 0;
    int tempNumber = number; // Need to create temporary copy so that can compare reversed number with original

    do {
        // Add last digit of number to reversed number, after moving digits to the left.
        reversedNumber = reversedNumber * 10 + tempNumber % 10;
        tempNumber /= 10; // Remove added digit from temporary number

    } while (tempNumber > 0);

    if (number == reversedNumber)
        return true;
    else
        return false;
}
int Chapter5Exercises::Exercise5_5() {

    /* (* difficulty)
     *
     * A positive integer is a palindrome if its reversal is the same as itself. Write the following function to check
     * whether an integer is a palindrome:
     *
     *              bool isPalindrome(int number)
     *
     * For example, isPalindrome(53435) returns true. Write a test program that prompts the user to enter an integer and
     * reports whether the integer is a palindrome.
     *
     * (Note: See Exercise 5.4 for hint on how to reverse a number)
     */

    cout << "Enter an integer to check if it's a palindrome: ";
    int number;
    cin >> number;

    // Function only outputs bool values, so conditional statement turns the output 1/0 into a true/false string
    cout << "Is the entered number " << number << " a palindrome? "
         <<  ((E5_5_isPalindrome(number)) ? "True" : "False");

    return 0;
}

void Chapter5Exercises::E5_6_displayPattern(int n) {
    /* Displays the pattern of integers from 1,...,n in a pyramid shape such that:
     *
     *                              1
     *                          2   1
     *                      3   2   1
     *                      ...
     *              n   n-1 3   2   1
     */

    for (int row = 1; row <= n; row++) {
        for (int columnPad = n; columnPad >= row; columnPad--) {
            // Adds spacing to LHS of each row (for no extra tab spacing set [int columnPad = n-1])
            cout << "\t";
        }
        for (int columnValue = row; columnValue >= 1; columnValue--) {
            // Add values to elements of pyramid for current row
            cout << columnValue << "\t";
        }
        cout << '\n';
    }

    return;
}
int Chapter5Exercises::Exercise5_6() {

    /* (* difficulty)
     *
     * Write the following function to display a pattern:
     *
     *          void displayPattern(int n)
     *
     *                                                  1
     *                                              2   1
     *                                          3   2   1
     *                                      4   3   2   1
     *                              n  n-1 ...  3   2   1
     */

    cout << "Enter how many rows you wish the pyramid to have: ";
    int numberOfRows;
    cin >> numberOfRows;

    cout << "The pattern for " << numberOfRows << " is:\n\n\n";
    E5_6_displayPattern(numberOfRows); // void function so cannot be treated as statement

    return 0;
}

double Chapter5Exercises::E5_7_computeCommission(double salesAmount) {
    // Adapted version of Exercise 4.37 to calculate the amount of commission to be paid for an amount of sales
    double totalCommission = 0, individualSale = 1.0; // Assumes smallest unit of sale is $1.00


    for (double iSales = 0.0 + individualSale; iSales <= salesAmount; iSales += individualSale) {
        if (iSales <= 5000.0)
            totalCommission += 0.08 * individualSale;
        else if (iSales <= 10000.0)
            totalCommission += 0.1 * individualSale;
        else
            totalCommission += 0.12 * individualSale;
    }

    return totalCommission;
}
int Chapter5Exercises::Exercise5_7() {

    /* (- difficulty)
     *
     * Use the scheme in Exercise 4.37 to write a function that computes the commission. The header of the function is:
     *
     *          double computeCommission(double salesAmount)
     *
     * Write a program that displays the following table:
     *
     *                  SalesAmount             Commission
     *                  10000                   900.0
     *                  15000                   1500.0
     *                  ...                     ...
     *                  95000                   11100.0
     *                  100000                  11700.0
     */

    const double MINIMUM_SALES = 10000.0, MAXIMUM_SALES = 100000.0, SALES_INCREMENT = 5000.0;

    // Creates table header
    cout << left << setw(12) << "SalesAmount" << setw(8) << ' '
         << right << setw(12) << "Commission" << "\n\n";

    for (double salesAmount = MINIMUM_SALES; salesAmount <= MAXIMUM_SALES; salesAmount += 5000.0) {
        // Calculates each row of table. Different precisions to match table formatting
        cout << fixed << setprecision(0) << setw(8) << salesAmount << setw(12) << ' '
             << fixed << setprecision(1) << setw(8) << E5_7_computeCommission(salesAmount) << '\n';
    }

    return 0;
}

double Chapter5Exercises::E5_8_footToMeter(double foot) {
    // Converts from feet to meters
    return foot * 0.305;
}
double Chapter5Exercises::E5_8_meterToFoot(double meter) {
    // Converts from meters to feet
    return meter / 0.305;
}
int Chapter5Exercises::Exercise5_8() {

    /* (- difficulty)
     *
     * Write a header file that contains the following two functions:
     *
     *          / Converts from feet to meters /
     *          double footTOMeter(double foot);
     *
     *          / Converts from meters to feet /
     *          double meterToFoot(double meter);
     *
     * The formula for the conversion is: meter = 0.305 * foot
     *
     * Implement the header file and write a test program that invokes these functions to display the following tables:
     *
     *      Feet        Meters      |       Meters      Feet
     *
     *      1.0         0.305       |       20.0        65.574
     *      2.0         0.61        |       25.0        81.967
     *
     *      ...         ...         |       ...         ...
     *      9.0         2.745       |       60.0        196.721
     *
     *      10.0        3.05        |       65.0        213.115
     */

    // #include "UnitConversions.h"
    const double FEET_INCREMENT = 1.0, FEET_STARTING = 1.0, MAX_FEET = 10.0;
    const double METERS_INCREMENT = 5.0, METERS_STARTING = 20.0, TEXT_WIDTH = 12.0;

    // Set table header
    cout << left
         << setw(TEXT_WIDTH) << "Feet"
         << setw(TEXT_WIDTH) << "Meters"
         << "|\t"
         << setw(TEXT_WIDTH) << "Meters"
         << setw(TEXT_WIDTH) << "Feet" << "\n\n";

    for (double iRow = 0; iRow < static_cast<int>(MAX_FEET); iRow++) {

        // Use function to convert from feet to meters
        double footToConvert = iRow * FEET_INCREMENT + FEET_STARTING;
        cout << left
             << fixed << setprecision(1) << setw(TEXT_WIDTH) << footToConvert
             << fixed << setprecision(3) << setw(TEXT_WIDTH) << E5_8_footToMeter(footToConvert);

        cout << "|";

        // Use function to convert from meters to feet
        double meterToConvert = iRow * METERS_INCREMENT + METERS_STARTING;
        cout << right
             << fixed << setprecision(1) << setw(TEXT_WIDTH - 4) << meterToConvert
             << fixed << setprecision(3) << setw(TEXT_WIDTH) << E5_8_meterToFoot(meterToConvert) << '\n';
    }

    return 0;
}

bool Chapter5Exercises::E5_9_isPrime(int number) {
    // Check whether number is prime (exact copy of Listing 5.5)

    for (int divisor = 2; divisor <= number / 2; divisor++)
    {
        if (number % divisor == 0)
        {
            // If true, number is not prime
            return false; // Number is not a prime
        }
    }
    return true; // Number is prime

}
int Chapter5Exercises::Exercise5_9() {

    /* (- difficulty)
     *
     * Listing 5.5, PrimeNumberFunction.cpp, provides the isPrime(int number) function for testing whether a number
     * is prime. Use this function to find the sum of the first 100 primes.  Write a test program that displays the
     * prime numbers, ten per line, and then displays the sum.
     */

    const int PRIMES_PER_LINE = 10, TOTAL_PRIMES_TO_FIND = 100;

    int totalPrimesFound = 0, sumOfPrimes = 0;
    int numberToTest = 2; // The first prime number

    cout << left;

    while (totalPrimesFound < TOTAL_PRIMES_TO_FIND) {

        if (E5_9_isPrime(numberToTest)) {
        // if function outputs true then the given 'number' is prime
            if ((totalPrimesFound+1) % PRIMES_PER_LINE == 0)
                cout << setw(4) << numberToTest << '\n';
            else
                cout << setw(4) << numberToTest << '\t';

            totalPrimesFound++;
            sumOfPrimes += numberToTest; // Add current number (which is prime) to the sum
        }
        numberToTest++; // Move to next number and test while-continuation-condition again
    }

    cout << "\nThe sum of the first " << TOTAL_PRIMES_TO_FIND << " primes is " << sumOfPrimes;

    return 0;
}

double Chapter5Exercises::E5_10_celsiusToFahrenheit(double celsius) {
    // Converts from Celsius to Fahrenheit
    return (9.0 / 5) * celsius + 32.0;
}
double Chapter5Exercises::E5_10_fahrenheitToCelsius(double fahrenheit) {
    // Converts from Fahrenheit to Celsius
    return (fahrenheit - 32) * (5 / 9.0);
}
int Chapter5Exercises::Exercise5_10() {

    /* (- difficulty)
     *
     * Write a header file that contains the following two functions:
     *
     *      / Converts from Celsius to Fahrenheit
     *      double celsiusToFahrenheit(double celsius);
     *
     *      / Converts from Fahrenheit to Celsius /
     *      double fahrenheitToCelsius(double fahrenheit);
     *
     * The formula for the conversion is:
     *
     *              fahrenheit = (9.0 / 5.0) * celsius + 32
     *
     * Implement the header file and write a test program that invokes these functions to display the following tables:
     *
     *              Celsius     Fahrenheit      |       Fahrenheit      Celsius
     *
     *              40.0        104.0           |       120.0           48.89
     *              39.0        102.2           |       110.0           43.33
     *
     *              ...         ...             |       ...             ...
     *
     *              32.0        89.6            |       40.0            4.44
     *              31.0        87.8            |       30.0            -1.11
     */

    // This is the file where the other functions for this exercise should be copied to, and then invoked from
    // #include "TempConversions.h"

    const int MAX_ROWS = 10, TEXT_SPACING = 12;
    const double CELSIUS_INCREMENT = -1.0, CELSIUS_START = 40.0, FAHRENHEIT_INCREMENT = -10.0, FAHRENHEIT_START = 120.0;

    // Create table header
    cout << left << '\n'
         << setw(TEXT_SPACING) << "Celsius"
         << setw(TEXT_SPACING) << "Fahrenheit"
         << right << "|"
         << setw(TEXT_SPACING) << "Fahrenheit"
         << setw(TEXT_SPACING) << "Celsius" << "\n\n";

    for (int iRow = 0; iRow < MAX_ROWS; iRow++) {
        // Loop through each row of table

        // Find Celsius value for the current row, and then convert it to Fahrenheit
        double celsiusToConvert = iRow * CELSIUS_INCREMENT + CELSIUS_START;
        cout << left << fixed << setprecision(1)
             << setw(TEXT_SPACING) << celsiusToConvert
             << setw(TEXT_SPACING) << E5_10_celsiusToFahrenheit(celsiusToConvert);

        cout << right << "|";

        // Find Fahrenheit value for the current row, and then convert it to Celsius
        double fahrenheitToConvert = iRow * FAHRENHEIT_INCREMENT + FAHRENHEIT_START;
        cout << setw(TEXT_SPACING) << fahrenheitToConvert
             << setprecision(2)
             << setw(TEXT_SPACING) << E5_10_fahrenheitToCelsius(fahrenheitToConvert);

        cout << '\n';
    }

    return 0;
}

int Chapter5Exercises::E5_11_printChars(char ch1, char ch2, int numberPerLine) {
    // Prints the characters between 'ch1' and 'ch2', and returns the number of characters that were printed.

    int totalPrintedChars = 0;

    cout << '\n';

    for (int printChar = static_cast<int>(ch1 + 1); printChar < static_cast<int>(ch2); printChar++) {
        // Offset in loop conditions is to ensure only chars BETWEEN ch1 and ch2 are printed
        totalPrintedChars++;
        if (totalPrintedChars % numberPerLine == 0)
            cout << static_cast<char>(printChar) << '\n';
        else
            cout << static_cast<char>(printChar) << '\t';
    }
    cout << '\n';

    return totalPrintedChars;
}
int Chapter5Exercises::Exercise5_11() {
    /* (- difficulty)
     *
     * Write a function that prints characters using the following header:
     *
     *      int printChars(char ch1, char ch2, int numberPerLine)
     *
     * This function prints the characters between ch1 and ch2 with the specified number of characters per line and
     * returns the number of characters that were printed. Write a test program that prints five characters per line
     * between '!' and 'a' and then prints the total number of printed characters.
     */

    const char START_CHAR = '!', END_CHAR = 'a';
    const int CHARS_PER_LINE = 5;

    int totalPrintedChars = E5_11_printChars(START_CHAR, END_CHAR, CHARS_PER_LINE);

    cout << "\nThe total number of characters between " << START_CHAR << " and " << END_CHAR
         << " is: " << totalPrintedChars;

    return 0;
}

double Chapter5Exercises::E5_12_sumSeries(int seriesLimit) {
    // Computes the summation of the series m(i) = 1/2 + 2/3 + ... + i/(i+1)

    double m = 0;

    for (int i = 1; i <= seriesLimit; i++) {
        m += i / static_cast<double>(i + 1.0);
    }

    return m;
}
int Chapter5Exercises::Exercise5_12() {

    /* (* difficulty)
     *
     * Write a function to compute the following series:
     *
     *          m(i) = 1/2 + 2/3 + ... + i/(i+1)
     *
     * Write a test program that displays the following table:
     *
     *          i               m(i)
     *
     *          1               0.5
     *          2               1.1667
     *          ...             ...
     *          19              16.4023
     *          20              17.3546
     *
     * (Note: Due to the question's wording, I interpreted this as the function only computes series sums' but does not
     * complete any console outputs
     */

    const int MINIMUM_I = 1, MAXIMUM_I = 20, TEXT_SPACING = 16;

    // Set table header
    cout << left
         << setw(TEXT_SPACING) << "i"
         << setw(TEXT_SPACING) << "m(i)" << "\n\n";

    // Use function to find series summation for each number between constant limits
    for (int number = MINIMUM_I; number <= MAXIMUM_I; number++)
        cout << setw(TEXT_SPACING) << number
             << setw(TEXT_SPACING) << E5_12_sumSeries(number) << '\n';

    return 0;
 }

 double Chapter5Exercises::E5_13_sumSeries(unsigned int seriesLimit) {
    // Computes the sum of the series: m(i) = 4*(1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 - ... - 1/(2*i-1) + 1/(2i+1)
    double summation = 0.0;

     for (int i = 0; i < seriesLimit; i++) {
         // (-1)**n on the numerator. Thus, even values of n are +ve and odd values of n are -ve
         if (i % 2 == 0)
             summation += 1.0 / (2.0 * i + 1.0);
         else
             summation -= 1.0 / (2.0 * i + 1.0);
     }
     summation *= 4.0;

     return summation;
}
int Chapter5Exercises::Exercise5_13() {

    /* (* difficulty)
     *
     * Write a function to compute the following series:
     *
     *          m(i) = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 - ... - 1/(2i - 1) + 1/(2i + 1)
     *
     * (Note: This is the same formula that was used to estimate the value of Pi in Exercise 4.25
     */

    const int TEXT_SPACING = 12;

    cout << left
         << setw(TEXT_SPACING) << "i"
         << setw(TEXT_SPACING) << "m(i)" << "\n\n";

    for (int i = 5000; i <= 50000; i += 5000) {
        cout << left
             << setw(TEXT_SPACING) << i
             << setw(TEXT_SPACING) << E5_13_sumSeries(i) << "\n";
    }

    return 0;
}

double Chapter5Exercises::E5_14_computeTax(int status, double taxableIncome) {
    // Computes the tax of an individual based upon their filing status and the total taxable income reported. See
    // Listing 3.4 for details

    double payableTax = 0;
    unsigned int taxRateBand1, taxRateBand2, taxRateBand3, taxRateBand4, taxRateBand5;

    // Sets the tax band (upper) limits based upon the filing status of the user
    switch (status) {
        // Calculate tax band limits for 'Single Filers'
        case 0:
            taxRateBand1 = 6000;
            taxRateBand2 = 27950;
            taxRateBand3 = 67700;
            taxRateBand4 = 141250;
            taxRateBand5 = 307050;
            break;

        case 1:
            // Calculate tax band limits for 'Married Filing Jointly' or 'Qualifying Widow/Widower'
            taxRateBand1 = 12000;
            taxRateBand2 = 46700;
            taxRateBand3 = 112850;
            taxRateBand4 = 171950;
            taxRateBand5 = 307050;
            break;

        case 2:
            // Calculate tax band limits for 'Married Filing Separately'
            taxRateBand1 = 6000;
            taxRateBand2 = 23350;
            taxRateBand3 = 56425;
            taxRateBand4 = 85975;
            taxRateBand5 = 153525;
            break;

        case 3:
            // Calculate tax band limits for 'Head of Household'
            taxRateBand1 = 10000;
            taxRateBand2 = 37450;
            taxRateBand3 = 96700;
            taxRateBand4 = 156600;
            taxRateBand5 = 307050;
            break;

        default:
            cout << "\nERROR. The status that you entered was incorrect. Exiting..." << endl;
            exit(0);
    }


    /* Calculates the tax that must be paid. Normally would write this as a separate function, but for speed I just
     * created it in this form within the class function */

    if (taxableIncome <= taxRateBand1) {
        payableTax = taxableIncome * 0.1;
    } else if (taxableIncome <= taxRateBand2) {
        payableTax = taxRateBand1 * 0.1 + (taxableIncome - taxRateBand1) * 0.15;
    } else if (taxableIncome <= taxRateBand3) {
        payableTax = taxRateBand1 * 0.1 + (taxRateBand2 - taxRateBand1) * 0.15 + (taxableIncome - taxRateBand2) * 0.27;
    } else if (taxableIncome <= taxRateBand4) {
        payableTax = taxRateBand1 * 0.1 + (taxRateBand2 - taxRateBand1) * 0.15 + (taxRateBand3 - taxRateBand2) * 0.27
                     + (taxableIncome - taxRateBand3) * 0.3;
    } else if (taxableIncome <= taxRateBand5) {
        payableTax = taxRateBand1 * 0.1 + (taxRateBand2 - taxRateBand1) * 0.15 + (taxRateBand3 - taxRateBand2) * 0.27
                     + (taxRateBand4 - taxRateBand3) * 0.3 + (taxableIncome - taxRateBand4) * 0.35;
    } else {
        payableTax = taxRateBand1 * 0.1 + (taxRateBand2 - taxRateBand1) * 0.15 + (taxRateBand3 - taxRateBand2) * 0.27
                     + (taxRateBand4 - taxRateBand3) * 0.3 + (taxRateBand5 - taxRateBand4) * 0.35
                     + (taxableIncome - taxRateBand5) * 0.386;
    }

    return payableTax;
}
int Chapter5Exercises::Exercise5_14() {

    /* (* difficulty)
     *
     * Listing 3.4, ComputeTax.cpp, is a program to compute tax. Write a function for computing tax using the
     * following header:
     *
     *          double computeTax(int status, double taxableIncome)
     *
     * Use this function to write a program that prints a tax table for taxable income from $50,000 to $60,000 with
     * intervals of $50 for all for statuses, as follows:
     *
     *      Taxable         Single          Married         Married         Head of
     *      Income                          Joint           Separate        a House
     *
     *      50000           9846            7296            10398            8506
     *      50050           9860            7310            10412            8520
     *
     *      ...             ...             ...             ...             ...
     *
     *      59950          12533            9983            13190           11193
     *      60000          12546            9996            13205           11206
     *
     * (Note: This code was a direct copy of Listing 3.4 (my solution) followed by some minor adaptations
     */

    const int MINIMUM_INCOME = 50000, MAXIMUM_INCOME = 60000, INCREMENT_INCOME = 50, SPACING_WIDTH = 12;

    // Creates table header
    cout << left << fixed << setprecision(0);
    cout << setw(SPACING_WIDTH) << "Taxable" << setw(SPACING_WIDTH) << "Single" << setw(SPACING_WIDTH) << "Married" << setw(SPACING_WIDTH) << "Married" << setw(SPACING_WIDTH) << "Head of" << '\n'
         << setw(SPACING_WIDTH) << "Income"  << setw(SPACING_WIDTH) << ' '      << setw(SPACING_WIDTH) << " Joint"   << setw(SPACING_WIDTH) << "Separate"<< setw(SPACING_WIDTH) << "a House" << "\n\n";

    for (double iIncome = MINIMUM_INCOME; iIncome <= MAXIMUM_INCOME; iIncome += INCREMENT_INCOME) {

        cout << setw(SPACING_WIDTH) << iIncome;
        for (int filingStatus = 0; filingStatus < 4; filingStatus++)
            cout << setw(SPACING_WIDTH) << E5_14_computeTax(filingStatus, iIncome);
        cout << '\n';
    }

    return 0;
}

int Chapter5Exercises::E5_15_numberOfDaysInAYear(int year) {
    // Returns the number of days in a given year

    // Equation from Exercise 3.18 to test whether a year is a leap year
    int totalDaysInYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 366 : 365;

    return totalDaysInYear;
}
int Chapter5Exercises::Exercise5_15() {

    /* (* difficulty)
     *
     * Write a function that returns the number of days in a year using hte following header:
     *
     *          int numberOfDaysInAYear(int year);
     *
     * Write a test program that displays the number of days in a year 2000,..., and 2010.
     */

    const int STARTING_YEAR = 2000, FINAL_YEAR = 2010;

    cout << left << setw(12) << "Year" << setw(24) << "Number of Days in Year" << "\n\n";

    for (int year = STARTING_YEAR; year <= FINAL_YEAR; year++)
        cout << setw(12) << year << setw(12) << ' ' << setw(12) << E5_15_numberOfDaysInAYear(year) << '\n';


    return 0;
}

void Chapter5Exercises::E5_16_printMatrix(int n) {
    // Displays an n by n matrix where each element is randomly 1 or 0

    // Seed rand within function to ensure that each function call is unique
    srand(time(0));

    // Ensures correct formatting, and that matrix is printed on new line
    cout << left << "\n\n";

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++)
            cout << rand() % 2 << '\t';
        cout << '\n';
    }

    return;
}
int Chapter5Exercises::Exercise5_16() {

    /* (* difficulty)
     *
     * Write a function that displays an n-by-n matrix using the following header:
     *
     *
     *              void printMatrix(int n)
     *
     * Each element is 0 or 1, which is generated randomly. Writea test program that prints a 3-by-3 matrix that may
     * look like this:
     *
     *              0   1   0
     *              0   0   0
     *              1   1   1
     */

    const int MATRIX_DIMENSION = 3;
    E5_16_printMatrix(MATRIX_DIMENSION);

    return 0;
}

double Chapter5Exercises::E5_17_maxRand(int num) {
    // Generate a random list of floating-point numbers, and find the maximum

    srand(time(0));
    double largestNumber = 0.0;

    cout << left << "\n";

    for (int i = 0; i < num; i++) {

        double randomNumber = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) * 1.0;
        cout << setw(12) << randomNumber;

        if (randomNumber > largestNumber)
            largestNumber = randomNumber;
    }

    return largestNumber;
}
int Chapter5Exercises::Exercise5_17() {
    /**/

    cout << "Enter the number of random numbers to generate: ";
    unsigned int totalNumbers;
    cin >> totalNumbers;

    double maxNumber = E5_17_maxRand(totalNumbers);
    cout << "\n\nThe maximum number in the list of random numbers was " << maxNumber;

    return 0;
}

int Chapter5Exercises::Exercise5_18() {

    /* (- difficultY)
     *
     * Write a program that prints the following table using the sqrt function:
     *
     *              Number              SquareRoot
     *              0                   0.0000
     *              2                   1.4142
     *             ...                   ...
     *              18                  4.2426
     *              20                  4.4721
     */

    // Create table header
    cout << left << fixed << setprecision(4)
         << setw(12) << "Number" << setw(12) << "SquareRoot" << '\n';

    for (int i = 0; i <= 20; i+=2)
        cout << setw(24) << i << setw(12) << sqrt(i) << '\n';

    return 0;
}

int Chapter5Exercises::Exercise5_19() {

    /* (- difficulty)
     *
     * Print the following table to display the sine value and cosine value of degrees from 0 to 360 with increments
     * of 10 degrees. Round the value to keep four digits after the decimal point.
     *
     *              Degree          Sin             Cos
     *              0               0.0000          1.0000
     *              10              0.1736          0.9848
     *
     *              ...             ...             ...
     *
     *              350             -0.1736         0.9848
     *              360             0.0000          1.0000
     */

    cout << left
         << setw(12) << "Degrees" << setw(12) << "Sin" << setw(12) << "Cos" << "\n\n";

    for (double degrees = 0; degrees <= 360; degrees += 10) {
        // Default output for TRIG functions is in radians, so need to convert our degrees before supplying as a
        // parameter. M_PI, and the TRIG functions, come from <cmath>
        double RadsToDegrees = degrees * M_PI / 180;

        cout << fixed << setprecision(0) <<  setw(12) << degrees
             << fixed << setprecision(4) << setw(12) << sin(RadsToDegrees) << setw(12) << cos(RadsToDegrees)
             << "\n";
    }

    return 0;
}

bool Chapter5Exercises::E5_20_isValid(double side1, double side2, double side3) {
    // Returns true if the sum of any two sides is greater than the third side

    // The argument of the IF statement comes from the 'Triangle Inequality Theorem'
    if ((side1 + side2 > side3) &&
        (side2 + side3 > side1) &&
        (side3 + side1 > side2))
        return true;
    else
        return false;
}
double Chapter5Exercises::E5_20_area(double side1, double side2, double side3) {
    // Returns the area of the triangle. Formulae are from Exercise 2.19
    double s = (side1 + side2 + side3) / 2;

    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}
int Chapter5Exercises::Exercise5_20() {

    /* (* difficulty)
     *
     * Create a header file named MyTriangle.h that contains the following two functions:
     *
     *      / Returns true if the sum of any two sides is greater than the third side /
     *      bool isValid(double side1, double side2, double side3)'
     *
     *      / Returns the area of the triangle /
     *      double area(double side1, double side2, double side3);
     *
     * The formula for computing the area is given in Exercise 2.19. Implement the header file and write a test program
     * that reads three sides for a triangle and computes the area if the input is valid. Otherwise, display that the
     * input is invalid
     */

    // #include "MyTriangle.h"

    cout << "Enter the three sides of the triangle as floats: ";
    double side1, side2, side3;
    cin >> side1 >> side2 >> side3;

    if (E5_20_isValid(side1, side2, side3)) {
        cout << "The input is valid.\n"
             << "The area of the triangle is " << E5_20_area(side1, side2, side3);
        return 0;
    } else {
        cout << "The input is invalid.\n";
        return 0;
    }
}

double Chapter5Exercises::E5_21_computeMean(double i, double n) {
    // Computes the mean of a given dataset. 'i' us the starting value, and 'n' is the maximum
    double mean = 0;

    // Function body
    for (int x_i = i; x_i <= n; x_i++)
        mean += x_i;

    mean /= n;

    return mean;
}


#include "Chapter5Listings.h"

int Chapter5Listings::L5_1_max(int num1, int num2) {

    int result;
    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}
int Chapter5Listings::TestMax() {
    // This method acts as main() for Listing 5.1 and is the book's version

    int i = 5;
    int j = 2;
    int k = L5_1_max(i, j);

    cout << "The maximum between " << i << " and " << j << " is " << k;

    return 0;
}

void Chapter5Listings::L5_2_printGrade(double score) {
    // Print grade for the score

    if (score >= 90.0)
        cout << 'A';
    else if (score >= 80.0)
        cout << 'B';
    else if (score >= 70.0)
        cout << 'C';
    else if (score >= 60.0)
        cout << 'D';
    else
        cout << 'F';
}
int Chapter5Listings::TestVoidFunction() {
    // This method acts as main() for Listing 5.2 and is the book's version

    cout << "Enter a score: ";
    double score;
    cin >> score;

    cout << "The grade is: ";
    L5_2_printGrade(score);

    return 0;
}

char Chapter5Listings::L5_3_getGrade(double score) {
    // Return the grade for the score

    if (score >= 90.0)
        return 'A';
    else if (score >= 80.0)
        return 'B';
    else if (score >= 70.0)
        return 'C';
    else if (score >= 60.0)
        return 'D';
    else
        return 'F';
}
int Chapter5Listings::TestReturnGradeFunction() {
    // This method acts as main() for Listing 5.3 and is the book's version

    cout << "Enter a score: ";
    double score;
    cin >> score;

    cout << "The grade is: ";
    cout << L5_3_getGrade(score) << endl;

    return 0;
}

int Chapter5Listings::L5_4_gcd(int n1, int n2) {
    // Return the gcd of two integers

    int gcd = 1; // Initial gcd is 1
    int k = 2; // Possible gcd

    while (k <= n1 && k <= n2)
    {
        if(n1 % k == 0 && n2 % k == 0)
            gcd = k; // Update gcd
        k++;
    }
    return gcd; // Return gcd;
}
int Chapter5Listings::GreatestCommonDivisorFunction() {
    // This method acts as main() for Listing 5.4 and is the book's version

    // Prompt the user to enter two integers
    cout << "Enter first integer: ";
    int n1;
    cin >> n1;

    cout << "Enter second integer: ";
    int n2;
    cin >> n2;

    cout << "The greatest common divisor for " << n1
    << " and " << n2 << " is " << L5_4_gcd(n1, n2);

    return 0;
}

bool Chapter5Listings::L5_5_isPrime(int number) {
    // Check whether number is prime

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
void Chapter5Listings::L5_5_printPrimeNumbers(int numberOfPrimes) {
    // Test if a number is prime, and print list of primes to console

    const int NUMBER_OF_PRIMES = 50; // Number of primes to display
    const int NUMBER_OF_PRIMES_PER_LINE = 10; // Display 10 per line
    int count = 0; // Count the number of prime numbers
    int number = 2; // A number to be tested for primeness

    // Repeatedly find prime numbers
    while (count < numberOfPrimes)
    {
        // Print the prime number and increase the count
        if (L5_5_isPrime(number))
        {
            count++; // Increase the count

            if (count % NUMBER_OF_PRIMES_PER_LINE == 0)
            {
                // Print the number and advance to the new line
                cout << setw(4) << number << endl;
            }
            else
                cout << setw(4) << number << " ";
        }

        // Check if the next number is prime
        number++;
    }
}
int Chapter5Listings::PrimeNumberFunction() {
    // This method acts as main() for Listing 5.5 and is the book's version
    cout << "The first 50 prime numbers are \n";
    L5_5_printPrimeNumbers(50);

    return 0;
}

int Chapter5Listings::L5_6_max(int num1, int num2) {
    // Return the max between two int values
    if (num1 > num2)
        return num1;
    else
        return num2;
}
double Chapter5Listings::L5_6_max(double num1, double num2) {
    // Find the max between two double values
    if (num1 > num2)
        return num1;
    else
        return num2;
}
double Chapter5Listings::L5_6_max(double num1, double num2, double num3) {
    // Find the max among three double values
    return L5_6_max( L5_6_max(num1, num2), num3);
}
int Chapter5Listings::TestFunctionOverloading() {
    // This method acts as main() for Listing 5.6 and is the book's version

    // Invoke the max function with int parameters
    cout << "The maximum between 3 and 4 is " << L5_6_max(3,4) << endl;

    // Invoke the max function with the double parameters
    cout << "The maximum between 3.0 and 5.4 is "
         << L5_6_max(3.0,5.4) << endl;

    // Invoke the max function with three double parameters
    cout << "The maximum between 3.0, 5.4, and 10.14 is "
         << L5_6_max(3.0, 5.4, 10.14) << endl;

    return 0;
}
#include "Chapter4Listings.h"

void Chapter4Listings::GuessNumberOneTime() {

    /* My solution to Listing 4.1 in Section 4.2.1 in Chapter 4.
     *
     * Write a program thar randomly generates an integer between 0 and 100, inclusive. The program prompts the
     * user to enter a number continuously until it matches the randomly generated umber. For each user input,
     * the program reports whether it is too low or too high, so the user can choose the next input intelligently.
     */

    using namespace std;

    // See rand() and declare variables
    srand(time(0));
    int guess, number;

    // Generate a random number between 0-100
    number = rand() % 101;
    // Initial guess out with the range of the randomly generated number, so that the program doesn't immediately end
    guess = -1;

    // Inform user between which limits they will be guessing
    cout << "Guess a magic number between 0 and 100 (inclusive)" << endl;

    // Note this program will enter an infinite loop if the entered guess is not a number
    while (guess != number) {

        // Prompt the user to guess a number
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == number)
            cout << "Yes, the number is " << number << endl;
        else if (guess > number)
            cout << "Your guess is too high" << endl;
        else
            cout << "Your guess is too low" << endl;
    }

}

void Chapter4Listings::SubtractionQuizLoop() {

    /* My solution for Listing 4.3 in Section 4.2.2 in Chapter 4
     *
     * Use a loop to generate questions repeatedly, building upon the code found in Listing 3.5. After 5 questions,
     * and once the student has answered them all, report the number of correct answers
     */

    using namespace std;

    srand(time(0));

    int iCount, correctCount;
    long startTime, endTime, testTime;
    const int NUMBER_OF_QUESTIONS = 5;

    // Initialise iteration counter, and the number of correct answers, as zero
    iCount = 0;
    correctCount = 0;

    // Record current time
    startTime = time(0);

    while (iCount < NUMBER_OF_QUESTIONS) {

        int answer, number1, number2;
        // 1. Generate two random single-digit integers
        number1 = rand() % 10;
        number2 = rand() % 10;

        // 2. If number1 < number2, swap number1 with number2
        if (number1 < number2) {
            int temp = number1;
            number1 = number2;
            number2 = temp;
        }

        // 3. Prompt the student to answer "what is number1 - number2?"
        cout << "\nWhat is " << number1 << " - " << number2 << "? ";
        cin >> answer;

        // 4. Grade the asnwer and display the result
        if (number1 - number2 == answer) {
            cout << "You are correct!\n";
            correctCount++;
        } else {
            cout << "Your answer is wrong.\n" << number1 << " - " << number2 << " should be "
                 << (number1 - number2) << endl;
        }

        // Increase the count
        iCount++;
    }

    // Record current time at end
    endTime = time(0);
    testTime = endTime - startTime;

    // Report time taken and number of correct answers to user
    cout << "\nCorrect count is " << correctCount << "\nTest time is " << testTime << " seconds" << endl;
}

void Chapter4Listings::SentinelValue() {

    /* My solution to Listing 4.4 in Section 4.2.4 of Chapter 4
     *
     * Write a program that reads and calculates the sum of an unspecified number of integers. The input zero
     * signifies the end of the input.
     */

    using namespace std;

    int data, sum;
    cout << "Enter an int value (the program exits if the input is zero): ";
    cin >> data;

    // Keep reading data until the input is zero
    sum = 0;
    while (data != 0) {
        sum += data;

        // Read the next data
        cout << "Enter an int value: ";
        cin >> data;
    }

    cout << "\nThe sum is " << sum << endl;
}

void Chapter4Listings::TestDoWhile() {

    /* My solution to Listing 4.5 in Section 4.3 in Chapter 4
     *
     * The same scenario as Listing 4.4 except use a do-while loop to read in the data
     */

    using namespace std;

    int data, sum;
    cout << "Enter an int value (the program exits if the input is zero): ";
    cin >> data;

    // Keep reading data until the input is zero
    sum = 0;
    do {
        sum += data;

        // Read the next data
        cout << "Enter an int value: ";
        cin >> data;
    } while (data != 0);

    cout << "\nThe sum is " << sum << endl;
}

void Chapter4Listings::TestMultiplicationTable() {

    /* My solution to Listing 4.6 in Section 4.5 in Chapter 4
     *
     * Write a program that uses nested for loops to print a multiplication table like you saw in school
     */

    using namespace std;

    cout << "       Multiplication Table\n----------------------------\n";

    // Display the number title
    cout << "  | ";
    for (int j = 1; j <= 9; j++)
        cout << setw(3) << j;

    cout << endl;

    // Print table body
    for (int i = 1; i <= 9; i++) {

        cout << i << " | ";
        for (int j = 1; j <= 9; j++)
            cout << setw(3) << i * j;
        cout << endl;
    }
}

void Chapter4Listings::TestSum() {

    /* My solution to Listing 4.7 in Section 4.7 in Chapter 4
     *
     * Write a program that sums a series which starts with 0.01 and ends with 1.0, where the numbers increment
     * in values of 0.01
     */

    using namespace std;

    // Initialise sum
    double sumDouble, sumInt;
    sumDouble = 0;

    // Add 0.01, 0.02, ..., 0.99, 1 to sum
    for (double i = 0.01; i <= 1.0; i += 0.01)
        sumDouble += i;

    // Display result
    cout << "The sum using a double dtype initial-action is " << sumDouble << endl;

    // Set starting value
    sumInt = 0;
    double currentValue = 0.01;
    for (int iCount = 0; iCount < 100; iCount++) {

        sumInt += currentValue;
        currentValue += 0.01;
    }

    // Display result
    cout << "The sum using an int dtype initial-action is " << sumInt << endl;

}

void Chapter4Listings::GreatestCommonDivisor() {

    /* My solution to Listing 4.8 in Section 4.8.1 in Chapter 4
     *
     * Write a program to find the greatest common divisor (gcd) of two integers
     */

    using namespace std;

    int number1, number2, gcd;
    gcd = 1;

    cout << "Enter first integer: ";
    cin >> number1;

    cout << "Enter second integer: ";
    cin >> number2;

    for (int iCount = 2; iCount <= number1 && iCount <= number2; iCount++ ) {
        if (number1 % iCount == 0 && number2 % iCount == 0)
            gcd = iCount;
    }

    cout << "The greatest common divisor for " << number1 << " and " << number2 << " is " << gcd << endl;
}

void Chapter4Listings::FutureTuition() {

    /* My solution to Listing 4.9 in Section 4.8.2 in Chapter 4
     *
     * Suppose that tuition for a university is $10,000 this year and increases 7% every year. In how many years
     * will the tuition have doubled?*/

    using namespace std;

    // Declare and initialise variables at same time for variety from previous code
    int numberOfYears = 1;
    double totalTuition = 10000;
    const double ANNUAL_INTEREST = 1.07;

    // Add annual interest to the total tuition and ensure that the number of years increases
    do {
        totalTuition *= ANNUAL_INTEREST;
        numberOfYears++;
    } while (totalTuition < 20000);

    // Output to user
    cout << "The tuition will double in " << numberOfYears << " years" << endl;
}

void Chapter4Listings::MonteCarloSimulation() {

    /* My solution to Listing 4.10 in Section 4.8.3 in Chapter 4
     *
     * Write a program that randomly generates 1000000 points that fall in the square and let numberOfHits denote
     * the number of points that fall in the circle. So, numberOfHits is approximately 1000000 * (pi * 4). Pi can
     * be approximated as 4 * numberOfHits / 1000000. Assume that the radius of the circle is 1, so the length of the
     * square is 2.
     *
     * (Hint: The probability that the point falls in the circle is circleArea / squareArea = Pi/4)*/

    using namespace std;

    srand(time(0));

    // Increasing MAX_NUMBER_OF_THROWS can increase precision at the expense of computation time
    const int MAX_NUMBER_OF_THROWS = 1000000;
    const double SQUARE_LENGTH = 2.0;

    int numberOfHits = 0;
    double piApproximation;

    for (int i = 0; i < MAX_NUMBER_OF_THROWS; i++) {

        double xInSquare, yInSquare;
        // Finds if a point lands in the square by generating a random coordinate
        xInSquare = rand() * SQUARE_LENGTH / RAND_MAX - 1;
        yInSquare = rand() * SQUARE_LENGTH / RAND_MAX - 1;
        if (pow(xInSquare,2) + pow(yInSquare,2) <= 1)
            // if x**2+y**2 <= 1 then the point also lands in the circle
            numberOfHits++;
    }

    // Calculates the approximate value of pi using the given formula
    piApproximation = 4.0 * numberOfHits / MAX_NUMBER_OF_THROWS;

    // Outputs to console
    cout << "Pi is " << piApproximation << endl;
}

void Chapter4Listings::TestBreak() {

    /* Copy of their solution to Listing 4.11 in Section 4.9 in Chapter 4
     *
     * This program illustrates the use of the keyword break in a loop
     */

    using namespace std;

    int sum = 0, number = 0;

    while (number < 20) {

        number++;
        sum += number;

        if (sum >= 100)
            break;
    }

    cout << "The number is " << number << endl;
    cout << "The sum is " << sum << endl;
}

void Chapter4Listings::TestContinue() {

    /* Copy of their solution to Listing 4.12 in Section 4.9 in Chapter 4
     *
     * Program to illustrate the use of the continue keyword in a loop
     */

    using namespace std;

    int sum = 0, number = 0;

    while (number < 20) {

        number++;
        if (number == 10 || number == 11)
            // values 10 and 11 are omitted from sum due to the continue keyword breaking their iteration uses
            continue;
        sum += number;
    }

    cout << "The sum is " << sum << endl;
}

void Chapter4Listings::GuessNumberUsingBreak() {

    /* A copy of their solution to Listing 4.13 in Section 4.9 in Chapter 4
     *
     * Write a program for guessing a number, by amending code from Listing 4.2 to include a BREAK statement
     */

    using namespace std;

    srand(time(0));
    int number = rand() % 101;

    cout << "Guess a magic number between 0 and 100: ";

    while (true) {

        // Prompt the user to guess the number
        cout << "\nEnter your guess: ";
        int guess;
        cin >> guess;

        if (guess == number) {

            cout << "Yes, the number is " << number << endl;
            break;
        } else if ( guess > number)
            cout << "Your guess is too high" << endl;
        else
            cout << "Your guess is too low" << endl;
    } // End of loop
}

void Chapter4Listings::PrimeNumber() {

    /* My solution to Listing 4.14 in Section 4.10 in Chapter 4
     *
     * Write a program to display the first 50 prime numbers. The output should include 10 numbers
     * over 5 lines.
     */

    using namespace std;

    int numberOfPrimes = 0, numberToTest = 1;
    const int TOTAL_NUMBER_OF_PRIMES = 50, NUMBER_OF_PRIMES_PER_LINE = 10;

    cout << "The first 50 prime numbers are:\n\n";

    while (numberOfPrimes < TOTAL_NUMBER_OF_PRIMES) {

        // Don't assume number is prime; more flexible code for later development
        bool isPrime;

        if (numberToTest == 1 || numberToTest == 2)
            // Exception for 1 & 2 which can sometimes raise errors
            isPrime = true;
        else {
            // Test if number is prime. FOR loop continues so long as isPrime==true still holds
            for (int divisor = 2; divisor <= numberToTest / 2 && isPrime; divisor++) {
                if (numberToTest % divisor == 0)
                    // If true condition, the number is not prime. Due to the loop-continuation-conditions,
                    // setting isPrime = true also ends the FOR loop
                    isPrime = false;
            }
            // If FOR loop completes then number is not prime
            isPrime = true;
        }

        if (isPrime) {
            // Print the prime number and increase the count
            numberOfPrimes++;

            if (numberOfPrimes % NUMBER_OF_PRIMES_PER_LINE == 0)
                // If there are n*10 number of primes, then take print before taking new line
                cout << setw(5) << numberToTest << endl;
            else
                cout << setw(5) << numberToTest;
        }

        // Check if the next number is prime
        numberToTest++;
    }
}
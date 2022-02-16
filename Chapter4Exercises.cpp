#include "Chapter4Exercises.h"

void Chapter4Exercises::Exercise4_1() {

    /* (* difficulty)
     *
     * Write a program that reads an unspecified number of integers, determines how many positive and negative values
     * have been read, and computes the total and average of the input numbers (not counting zeros). Your program
     * ends with an input 0. Display the average as a floating-point number. Your outputs to console should
     * follow the given sample.
     */

    using namespace std;

    int numberOfPositives = 0, numberOfNegatives = 0, numberOfInputs = 0;
    double sumOfInputs = 0; // Setting sumOfInputs to dtype double (instead of int) removes need for casting later

    // Step 1. Receive initial input from the user
    cout << "Enter an int value, the program exits if the input is 0: ";
    int value;
    cin >> value;

    // Step 2. Loop through, accepting more inputs, until a 0 is entered

    while (value != 0) {

        // numberOfInputs is inside while loop to ensure the first input isn't counted twice, as it would if
        // numberOfInputs++ was also outside this loop
        numberOfInputs++;
        sumOfInputs += value;

        // Checks if value is +ve or -ve, then increments the appropriate counter
        if (value > 0)
            numberOfPositives++;
        else
            numberOfNegatives++;

        // Takes new input from user
        cout << "Enter an int value: ";
        cin >> value;
    }
    // Step 3. Output data to user
    if (numberOfInputs != 0) {
        // If the initial input is 0, then a divide by 0 would occur (ERROR)
        double average = sumOfInputs / numberOfInputs;
        cout << "The number of positives is " << numberOfPositives << "\n";
        cout << "The number of negatives is " << numberOfNegatives << "\n";
        cout << "The total is " << sumOfInputs << "\n";
        cout << "The average is " << average << endl;
    } else
        cout << "No nonzero input was entered" << endl;
}

void Chapter4Exercises::Exercise4_2() {

    /* ( difficulty)
     *
     * Listing 4.3, SubtractionQuizLoop.cpp, generates five random subtraction questions. Revise the program to generate
     * ten random addition questions for two integers between 1 and 15. Display the correct count and test time. A
     * copy of my solution to Listing 4.3 is below.

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

        // 4. Grade the answer and display the result
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
    */

    using namespace std;

    srand(time(0));

    int iCount, correctCount; // iCount stands for 'iteration Count'
    long startTime, endTime, testTime;
    const int NUMBER_OF_QUESTIONS = 10;

    // Initialise iteration counter, and the number of correct answers, as zero
    iCount = 0;
    correctCount = 0;

    // Record current time
    startTime = time(0);

    // Recall, due to 0 being the first value of iCount, the 10th question is when iCount = 9
    while (iCount < NUMBER_OF_QUESTIONS) {

        int answer, number1, number2;
        // 1. Generate two random integers between 1- 15
        number1 = rand() % 15 + 1;
        number2 = rand() % 15 + 1;

        // 2. If number1 < number2, swap number1 with number2
        if (number1 < number2) {
            int temp = number1;
            number1 = number2;
            number2 = temp;
        }

        // 3. Prompt the student to answer "what is number1 - number2?"
        cout << "\nQ" << iCount + 1 << ". What is " << number1 << " + " << number2 << "? ";
        cin >> answer;

        // 4. Grade the answer and display the result
        if (number1 + number2 == answer) {
            cout << "You are correct!\n";
            correctCount++;
        } else {
            cout << "Your answer is wrong.\n" << number1 << " + " << number2 << " should be "
                 << (number1 + number2) << endl;
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

void Chapter4Exercises::Exercise4_3() {

    /* (- difficulty)
     *
     * A stone is a British measurement of mass that equals 6.35 kilograms. Write a program that displays the conversion
     * to stones for every kilogram value from 1 to 199 in a table, that looks like:
     *
     *          Kilograms           Pounds          Stone
     *          1                   2.2             ???
     *          3                   6.6             ???
     *          ...                 ...             ...
     *          197                 433.4           ???
     *          199                 437.8           ???
     *
     * Note: Your code should all intermediary values which are indicated by  '...' above
     */

    using namespace std;

    // Step 1. Set constants from values given in question
    const double KILOGRAM_TO_STONE = 1 / 6.35, KILOGRAM_TO_POUNDS = 2.2;
    const int MAX_KILOGRAM = 200, TEXT_WIDTH = 12;

    // Parameters to keep table tidy
    cout << left << fixed << setprecision(2);
    // Output title line. Each setw() must be wide enough to fully contain each word. WARNING: If "\n\n" is in the same
    // string as "Stone" then the setw(TEXT_WIDTH) spacing will continue into the next line. Try changing it to see!
    cout << setw(TEXT_WIDTH) << "Kilograms" << setw(TEXT_WIDTH) << "Pounds" << setw(TEXT_WIDTH) << "Stone" << "\n\n";

    // Step 2. Loop through each odd-numbered kilogram in the given range
    for (int kilograms = 1; kilograms < MAX_KILOGRAM; kilograms+=2) {

        // Step 3. Calculate corresponding pounds and stones for each kilogram
        // Calculate each value out with cout statement for readability
        double pounds = kilograms * KILOGRAM_TO_POUNDS;
        double stones = kilograms * KILOGRAM_TO_STONE;

        // Step 4. Output data of each line of the table to user
        cout << setw(TEXT_WIDTH) << kilograms
             << setw(TEXT_WIDTH) << pounds
             << setw(TEXT_WIDTH) << stones <<"\n";
    }
}

void Chapter4Exercises::Exercise4_4() {

    /* (* difficulty)
     *
     * Write a program that displays the following two tables side by side (note that 1 kilogram is 2.2 pounds);
     *
     *      Kilograms       Pounds      |       Pounds      Kilograms
     *
     *      1               2.2         |       20          9.09
     *      3               6.6         |       25          11.36
     *      ...             ...         |       ...         ...
     *      197             433.4       |       510         231.82
     *      199             437.8       |       515         234.09
     */

    using namespace std;

    // Declare constants taken from question
    const int TEXT_WIDTH = 12, DIVIDER_WIDTH = 5;
    const double KILOGRAMS_TO_POUNDS = 2.2, POUNDS_TO_KILOGRAMS = 1/ 2.2, MAX_COUNT = 100;

    // Set formatting options to ensure table is tidy
    cout << left << fixed << setprecision(2) << setw(TEXT_WIDTH);

    // Display table title to user
    cout << setw(TEXT_WIDTH) << "Kilograms" << setw(TEXT_WIDTH) << "Pounds"
         << setw(DIVIDER_WIDTH) << "|"
         << setw(TEXT_WIDTH) << "Pounds" << setw(TEXT_WIDTH) << "Kilograms" << "\n\n";

    // Use iCount to ensure both tables iterate at same rate
    for (int iCount = 0; iCount < MAX_COUNT; iCount ++) {

        // Calculate current kilogram for LHS table, and then convert value to pounds
        int kilograms =  iCount * 2 + 1; // Kilograms are every odd number beginning with 1
        double kilogramToPounds = kilograms * KILOGRAMS_TO_POUNDS;

        // Calculate current pound for RHS table, and then convert value to kilograms
        int pounds = iCount * 5 + 20; // Pounds are in multiples of 5 beginning with 20
        double poundsToKilograms = pounds * POUNDS_TO_KILOGRAMS;

        // Display data from current iteration to user in the formatted table
        cout << setw(TEXT_WIDTH) << kilograms << setw(TEXT_WIDTH) << kilogramToPounds
             << setw(DIVIDER_WIDTH) << "|"
             << setw(TEXT_WIDTH) << pounds << setw(TEXT_WIDTH) << poundsToKilograms << "\n";
    }
}

void Chapter4Exercises::Exercise4_5() {

    /* (- difficulty)
     *
     * Write a program that displays the following table (note that 1 mile is 1.609 kilometers):
     *
     *      Miles       Kilometers
     *      1           1.609
     *      2           3.218
     *      ...         ...
     *      9           14.481
     *      10          16.0990
     */

    using namespace std;

    // Set constants from question
    const int TEXT_WIDTH = 10;
    const double MILES_TO_KILOMETERS = 1.609, MAX_COUNT = 10;

    // Set table formatting to keep table tidy and match precision in question
    cout << left << fixed << setprecision(3);

    // Display table title
    cout << setw(TEXT_WIDTH) << "Miles" << setw(TEXT_WIDTH) << "Kilometers" << "\n\n";

    for (int miles = 1; miles <= MAX_COUNT; miles ++) {

        // Convert miles to kilometers
        double kilometers = miles * MILES_TO_KILOMETERS;

        // Output conversion for current iteration to table
        cout << setw(TEXT_WIDTH) << miles << setw(TEXT_WIDTH) << kilometers << "\n";
    }


}

void Chapter4Exercises::Exercise4_6() {

    /* (* difficulty)
     *
     * Write a program that displays the following two tables side by side (note that 1 mile is 1.609 pounds);
     *
     *      Miles           Kilometers      |       Kilometers      Miles
     *
     *      1               2.2             |       20              9.09
     *      3               6.6             |       25              11.36
     *      ...             ...             |       ...             ...
     *      197             433.4           |       510             231.82
     *      199             437.8           |       515             234.09
     *
     * Note: This code is just a copy of Exercise4_4() with the minimum necessary changes
     */

    using namespace std;

    // Declare constants taken from question
    const int TEXT_WIDTH = 12, DIVIDER_WIDTH = 3;
    const double MILES_TO_KILOMETERS = 1.609, KILOMETERS_TO_MILES = 1/ 1.609, MAX_COUNT = 10;

    // Set formatting options to ensure table is tidy
    cout << left << fixed << setprecision(3) << setw(TEXT_WIDTH);

    // Display table title to user
    cout << setw(TEXT_WIDTH) << "Miles" << setw(TEXT_WIDTH) << "Kilometers"
         << setw(DIVIDER_WIDTH) << "|"
         << setw(TEXT_WIDTH) << "Kilometers" << setw(TEXT_WIDTH) << "Miles" << "\n\n";

    // Use iCount to ensure both tables iterate at same rate
    for (int iCount = 0; iCount < MAX_COUNT; iCount ++) {

        // Calculate current miles for LHS table, and then convert value to kilometers
        int miles = iCount + 1; // Miles are the count offset by 1
        double milesToKilometers = miles * MILES_TO_KILOMETERS;

        // Calculate current kilometers for RHS table, and then convert value to miles
        int kilometers = iCount * 5 + 20; // Kilometers are in multiples of 5 beginning with 20
        double kilometersToMiles = kilometers * KILOMETERS_TO_MILES;

        // Display data from current iteration to user in the formatted table
        cout << setw(TEXT_WIDTH) << miles << setw(TEXT_WIDTH) << milesToKilometers
             << setw(DIVIDER_WIDTH) << "|"
             << setw(TEXT_WIDTH) << kilometers << setw(TEXT_WIDTH) << kilometersToMiles << "\n";
    }
}

void Chapter4Exercises::Exercise4_7() {

    /* (** difficulty)
     *
     * Suppose that the tuition for a university is $10,000 this year and increases 5% every year. Write a program
     * that compute the tuition iin ten years and the total cost of four years' worth of tuition starting ten years
     * from now.
     */

    using namespace std;

    // Data from question
    const int INITIAL_TUITION_COST = 10000, WAITING_YEARS = 10, MAX_STUDY_TIME = 4;
    const double ANNUAL_INCREASE = 0.05; // Annual increase in tuition cost is 5%

    // tuition and futureTotalCost must be doubles else the truncation of decimals leads to inaccuracies
    double tuition = INITIAL_TUITION_COST;
    double futureTotalCost = 0;

    // Loop over the total time (time to wait between now and beginning tuition) plus (total time in education)
    for (int years = 1; years < WAITING_YEARS + MAX_STUDY_TIME; years++) {

        tuition *= (1 + ANNUAL_INCREASE);

        // At the 10-year mark, inform the user of the current cost for one year of tuition
        if (years == WAITING_YEARS)
            cout << "Cost of tuition, in 10 years, for one year of teaching is $" << tuition << "\n";

        // Once beyond the 10 year point, then begin adding tuition costs to the total
        if (years >= WAITING_YEARS)
            futureTotalCost += tuition;
    }

    // Display cost of 4 years' worth of tuition
    cout << MAX_STUDY_TIME << " years' worth of tuition, beginning in " << WAITING_YEARS << " years, would cost $"
         << futureTotalCost << endl;
}

void Chapter4Exercises::Exercise4_8() {

    /* (- difficulty)
     *
     * Write a program that prompts the user to enter the number of students and each student's score, and displays
     * the highest score.
     */

    using namespace std;

    // Prompts user for a number of students
    cout << "Enter how many students you have: ";
    int numberOfStudents;
    cin >> numberOfStudents;
    cout << "\n";

    // Saves outside of IF statement in case highestScore is needed later in code
    int highestScore;

    if (numberOfStudents > 0) {

        for (int currentStudent = 1; currentStudent <= numberOfStudents; currentStudent++) {

            // Prompts user for a score for a student
            cout << "Enter a score: ";
            int score;
            cin >> score;

            // If the current score is higher than the saved highest score, the highest score is updated
            if (score > highestScore)
                highestScore = score;
        }

        // Outputs highest score to user
        cout << "\nThe highest entered score was " << highestScore << endl;
    } else {
        // Code doesn't do anything if the number of students is 0
    }
}

void Chapter4Exercises::Exercise4_9() {

    /* (* difficulty)
     *
     * Write a program that prompts the user to enter the number of students and each student's score, and displays
     * the highest and lowest scores.
     *
     * Note: this code is built upon Exercise4_9 using only the minimum necessary changes
     */

    using namespace std;

    // Prompts user for a number of students
    cout << "Enter how many students you have: ";
    int numberOfStudents;
    cin >> numberOfStudents;
    cout << "\n";

    // Saves outside of IF statement in case highestScore is needed later in code
    int highestScore;
    int lowestScore;

    if (numberOfStudents > 0) {

        for (int currentStudent = 1; currentStudent <= numberOfStudents; currentStudent++) {

            // Prompts user for a score for a student
            cout << "Enter a score: ";
            int score;
            cin >> score;

            // If the current score is higher than the saved highest score, the highestScore is updated
            if (score > highestScore)
                highestScore = score;

            // If the current score is lower than the saved lowest score, and non-negative, then lowestScore is updated
            if (score >= 0 && score < lowestScore)
                lowestScore = score;
        }

        // Outputs highest score to user
        cout << "\nThe highest entered score was " << highestScore
             << ", and the lowest score was " << lowestScore << endl;
    } else {
        // Code doesn't do anything if the number of students is 0
    }
}

void Chapter4Exercises::Exercise4_10() {

    /* (- difficulty)
     *
     * Wire a program that displays, 10 numbers per line, all the numbers from 100 to 1000 that are divisible by 5
     * and 6.
     */

    using namespace std;

    const int MINIMUM_NUMBER = 100, MAXIMUM_NUMBER = 1000, LOWER_DIVISOR = 5, UPPER_DIVISOR = 6, NUMBERS_PER_LINE = 10;
    int numberOfFactors = 0;

    cout << "The numbers between " << MINIMUM_NUMBER << " to " << MAXIMUM_NUMBER << ", that are divisible by both "
         << LOWER_DIVISOR << " and " << UPPER_DIVISOR << ", are: \n";

    for (int currentNumber = MINIMUM_NUMBER; currentNumber <= MAXIMUM_NUMBER; currentNumber++) {

        // Checks these boolean conditions to see if the current number
        if ((currentNumber % LOWER_DIVISOR == 0) && (currentNumber % UPPER_DIVISOR == 0)) {

            // Position of current number
            numberOfFactors++;

            if (numberOfFactors % NUMBERS_PER_LINE == 0)
                // If there are 10 numbers on the previous line, then a new line is taken
                cout << setw(4) << currentNumber <<"\n";
            else
                cout << setw(4) << currentNumber;
        }
    }
}

void Chapter4Exercises::Exercise4_11() {

    /* (- difficulty)
     *
     * Write a program that displays, ten numbers per line, all the numbers from 100 to 200 that are divisible by 5 or
     * 6, but not both.
     *
     * Note: this code was made by making the minimum necessary changes to Exercise4_10 (see also Exercise3_22)
     */

    using namespace std;

    const int MINIMUM_NUMBER = 100, MAXIMUM_NUMBER = 200, LOWER_DIVISOR = 5, UPPER_DIVISOR = 6, NUMBERS_PER_LINE = 10;
    int numberOfFactors = 0;

    cout << "The numbers between " << MINIMUM_NUMBER << " to " << MAXIMUM_NUMBER << " that are divisible by "
         << LOWER_DIVISOR << " or " << UPPER_DIVISOR << ", but not both, are: \n";

    for (int currentNumber = MINIMUM_NUMBER; currentNumber <= MAXIMUM_NUMBER; currentNumber++) {

        // Checks these boolean conditions to see if the current number is divisible by one or the other, but not both
        if ((currentNumber % LOWER_DIVISOR == 0) || (currentNumber % UPPER_DIVISOR == 0) &&
            (currentNumber % LOWER_DIVISOR != 0  || currentNumber % UPPER_DIVISOR != 0)) {

            // Position of current number
            numberOfFactors++;

            if (numberOfFactors % NUMBERS_PER_LINE == 0)
                // If there are 10 numbers on the previous line, then a new line is taken
                cout << setw(4) << currentNumber <<"\n";
            else
                cout << setw(4) << currentNumber;
        }
    }
}

void Chapter4Exercises::Exercise4_12() {

    /* (- difficulty)
     *
     * Use a while loop to find the smallest integer n such that pow(n, 2) is greater than 12,000
     */

    using namespace std;

    // Initialises n as an integer which begins at zero
    int n = 0;

    // Checks to see if the square of n is greater than the condition
    while (pow(n, 2) < 12000)
        // If loop-continuation-condition is true, then try  next n value
        n++;

    // Displays the smallest integer that fulfils n**2 < 12000
    cout << "The smallest integer such that n**2 is greater than 1200 is: " << n << endl;
}

void Chapter4Exercises::Exercise4_13() {

    /* (- difficulty)
     *
     * Use a while loop to find the largest integer n such that n**4 is less than 12000
     *
     * Note: this code was made by making the minimum necessary changes to Exercise4_13
     */

    using namespace std;

    // Initialises n as an integer which begins at zero
    int n = 0;

    // Checks to see if the square of n is greater than the condition
    while (pow(n, 4) < 12000)
        // If loop-continuation-condition is true, then try  next n value
        n++;

    // Displays the largest integer that fulfils n**4 < 12000
    cout << "The largest integer n such that n**4 is less than 12000 is: " << n << endl;
}

void Chapter4Exercises::Exercise4_14() {

    /* (* difficulty)
     *
     * Write a program that prints the characters in the ASCII character table from '!' to '~'. Print ten characters
     * per line.
     */

    using namespace std;

    const char LOWER_ASCII = '!', UPPER_ASCII = '~'; // Use char dtypes directly as the loop boundaries
    const int NUMBERS_PER_LINE = 10; // Set maximum numbers per line

    int numberOfChars = 0; // Track how many characters have been printed to the current console line

    for (char currentASCII = LOWER_ASCII; currentASCII <= UPPER_ASCII; currentASCII++) {
        // While the current character is between the two ASCII characters (inclusive) continue the loop

        numberOfChars++; // Position of current number

        if (numberOfChars % NUMBERS_PER_LINE == 0)
            // If there are 10 numbers on the previous line, then a new line is taken
            cout << setw(4) << currentASCII <<"\n";
        else
            cout << setw(4) << currentASCII;
    }
}

void Chapter4Exercises::Exercise4_15() {

    /* (* difficulty)
     *
     * For Listing 4.8, another solution to find the greatest common divisor of two integers n1 and n2 is as
     * follows: First find d to be the minimum of n1 and n2, then check whether d, d-1, d-2,...,2 or 1 is a
     * divisor for both n1 and n2 in this order. The first such common divisor is the greatest common divisor for
     * n1 and n2.
     */

    using namespace std;

    int n1, n2, gcd = 0;

    // Prompt user for two integers
    cout << "Enter the first integer: ";
    cin >> n1;

    cout << "Enter the second integer: ";
    cin >> n2;

    // Ensure that the upper limit for the loop comes from the larger number
    int d = 0;
    if (n2 > n1)
        d = n2;
    else
        d = n1;

    for (int number = d+1; number >= 1; number--) {
        // Finds the largest factor which is common to both numbers
        if (n1 % number == 0 && n2 % number == 0) {
            // breaks out of FOR loop when common factor is found
            gcd = number;
            break;
        }
    }

    // Outputs GCD to user
    cout << "The greatest common divisor (gcd) is " << gcd;
}

void Chapter4Exercises::Exercise4_16() {

    /* (** difficulty)
     *
     * Write a program that reads an integer and displays all its smallest factors, also known as prime factors. For
     * example, if the input integer is 120, the output should be as follows: 2, 2, 2, 3, 5
     */

    using namespace std;

    // Prompt user to enter an integer
    cout << "Enter an integer to see its prime factors: ";
    int number;
    cin >> number;

    cout << "The prime factors of " << number << " are: ";

    // Find the number of times that number has 2 as a factor. Continues until number is odd
    while (number % 2 == 0) {
        number /= 2;
        cout << 2 << ", ";
    }

    // Loops through all odd numbers until the factors being tested are larger than n itself
    for (int testFactor = 3; testFactor <= pow(number, 0.5); testFactor += 2) {

        while (number % testFactor == 0) {
            // when i divides number, output this to console and then divide number by i
            cout << testFactor << ", ";
            number /= testFactor;
        }
    }

    // Handles case where the final value of number is an odd prime number (this would be not outputted by the loops)
    if (number > 2)
        cout << number << "." << endl;
}

void Chapter4Exercises::Exercise4_17() {

    /* (** difficulty)
     *
     * Write a nested for loop that prints the following output
     *
     *      Figure shows an image in the style of Pascal's Pyramid, except it's all in powers of 2
     *
     *                                      1
     *                                 1    2   1
     *                             1   2    4   2   1
     *
     * and so on.
     */

    using namespace std;

    const int MAX_ROWS = 7;
    const int BASE = 2;

    /* Can't define the function within the class, but here is some code that would find pow(a,b)
    void powerfinder(int base, int exponent) {

        int answer = 1;
        int i = 1;

        while (i <= exponent) {
            val *= BASE;
            i++;
        }
    }
    */
    for (int row = 0; row <= MAX_ROWS; row++) {

        for (int columnPad = 1; columnPad <= MAX_ROWS - row; columnPad++) {
            // Pad refers to the padding (blank space) before the LHS most digit is printed
            cout << '\t';
        }

        for (int columnLHS = 0; columnLHS <= row; columnLHS++) {
            // Print LHS of row (excluding central value)

            int val = pow(BASE, columnLHS);

            if (val < 10)
                cout << "   " << val;
            else if (val < 100)
                cout << "  " << val;
            else
                cout << " " << val;
        }
        for (int columnRHS = row - 1; columnRHS >= 0; columnRHS--) {
            // Print RHS of row (including central value)
            int val = pow(BASE, columnRHS);
            if (val < 10)
                cout << "   " << val;
            else if (val < 100)
                cout << "  " << val;
            else
                cout << " " << val;
        }

        // Start a new line
        cout << endl;
    }
}

void Chapter4Exercises::Exercise4_18() {

    /* (* difficulty)
     *
     * Use nested loops that print the following patterns in four separate programs:
     *
     *
     *
     * 1.
     *
     * 1
     * 1    2
     * 1    2   3
     * 1    2   3   4
     * 1    2   3   4   5
     * 1    2   3   4   5   6
     *
     *
     *
     * 2.
     *
     * 1    2   3   4   5   6
     * 1    2   3   4   5
     * 1    2   3   4
     * 1    2   3
     * 1    2
     * 1
     *
     *
     * 3.
     *
     *                     1
     *                 2   1
     *             3   2   1
     *         4   3   2   1
     *     5   4   3   2   1
     * 6   5   4   3   2   1
     *
     *
     *
     * 4.
     *
     * 1    2   3   4   5   6
     *      1   2   3   4   5
     *          1   2   3   4
     *              1   2   3
     *                  1   2
     *                      1
     *
     *
     * NOTE: This program will do everything within one program for my ease when writing
     */

    using namespace std;

    const int MAX_ROWS = 6;

    cout << "\t\tPattern 1\n";
    for (int row = 1; row <= MAX_ROWS; row++) {
        // Outputs Pattern 1
        for (int column = 1; column <= row; column++)
            // Initial-action is column=1 to remove need for applying any offset to print correct integer
            cout << column << "\t";

        cout << '\n'; // Start new line after current line is complete
    }
    cout << "\n\n\n\t\tPattern 2\n"; // Add space between patterns

    for (int row = 0; row < MAX_ROWS; row++) {
        // Outputs Pattern 2
        for (int column = 1; column <= MAX_ROWS - row; column++)
            cout << column << '\t';

        cout << '\n';
    }

    cout << "\n\n\n\t\tPattern 3\n"; // Add space between patterns

    for (int row = 1; row <= MAX_ROWS; row++) {
        // Outputs Pattern 3
        for (int columnPad = MAX_ROWS - row; columnPad >= 1; columnPad-- )
            // Largest space is on row 1, so a decrement counter is the most natural fit
            cout << '\t';

        for (int column = row; column >= 1; column--)
            // Largest value is on LHS of row
            cout << column << '\t';

        cout << '\n';

    }
    cout << "\n\n\n\t\tPattern 4\n"; // Add space between patterns

    for (int row = 0; row <= MAX_ROWS - 1; row++) {
        // Outputs Pattern 4
        for (int columnPad = 0; columnPad < row; columnPad++)
            // Adds the number of indents (pad == Padding) based upon current row.
            cout << '\t';

        for (int columnValue = 1; columnValue <= MAX_ROWS - row; columnValue++)
            // columnValue represents the column position, value in that position and is an index all in one
            cout << columnValue << '\t';

        cout << '\n';
    }
}

void Chapter4Exercises::Exercise4_19() {

    /* (** difficulty)
     *
     * Write a program that prompts the user to enter an integer form 1 to 10 and displays a pyramid with the input
     * number on top, as shown below for an input of 7:
     *
     *                                      7
     *                                  7   6   7
     *                              7   6   5   6   7
     *                          7   6   5   4   5   6   7
     *                      7   6   5   4   3   4   5   6   7
     *                  7   6   5   4   3   2   3   4   5   6   7
     *              7   6   5   4   3   2   1   2   3   4   5   6   7
     */

    using namespace std;

    // Prompts user for number of lines in pyramid
    cout << "Enter the number of lines: ";
    int numberOfLines;
    cin >> numberOfLines;

    for (int row = 0; row < numberOfLines; row++) {

        for (int columnPad = numberOfLines - row; columnPad > 1; columnPad--)
            cout << '\t';

        for (int columnValueLHS = numberOfLines; columnValueLHS >= numberOfLines - row; columnValueLHS--)
            // Prints the LHS of the pyramid, including the central column
            if (columnValueLHS == numberOfLines - row)
                cout << columnValueLHS;
            else
                cout << columnValueLHS << '\t';

        // Prints RHS of pyramid
        int columnValueRHS = numberOfLines - row;
        while (columnValueRHS < numberOfLines) {
            // Mixture of loops to show FOR and WHILE loops can be used interchangeably
            cout << '\t' << columnValueRHS + 1;
            columnValueRHS++;
        }

        cout << '\n'; // Starts new line of pyramid
    }
}

void Chapter4Exercises::Exercise4_20() {

    /* (* difficulty)
     *
     * Modify Listing 4.14 to print all the prime numbers between 2 and 1000, inclusive. Display eight prime numbers
     * per line
     *
     * Note: The basis for this program is my solution to Listing 4.14
     */

    using namespace std;

    const int MIN_NUMBER = 2, MAX_NUMBER = 1000, NUMBER_OF_PRIMES_PER_LINE = 8;

    int numberOfPrimes = 0;

    cout << "The all of the primes between 2 and 1000 (inclusive) are:\n\n";

    for(int numberToTest = MIN_NUMBER; numberToTest <= MAX_NUMBER; numberToTest++) {

        // Assume number is prime, then use FOR loop to test if it is not
        bool isPrime = true;

        // Break condition is when isPrime becomes false, or if all possible divisors are tested
        for (int divisor = 2; divisor <= numberToTest / 2 && isPrime; divisor++) {
            //Due to the loop-continuation-conditions setting isPrime = true also ends the FOR loop
            if (numberToTest % divisor == 0)
                // If true condition, the number is not prime
                isPrime = false;
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
    }
}

void Chapter4Exercises::Exercise4_21() {

    /* (** difficulty)
     *
     * Write a program that lets the user enter the loan amount and loan period in number of years, and displays the
     * monthly and total payments for each interest rate starting from 5% to 8%, with an increment of 1/8.
     */

    using namespace std;

    // The final value (MAXIMUM_RATE) can sometimes be excluded due to floating-point errors. Increasing it resolves this
    const double MINIMUM_RATE = 0.05, MAXIMUM_RATE = 0.08 + 1e-4, RATE_INCREASE = 0.00125;

    // Prompt user for inputs
    cout << "Loan Amount: ";
    double loanAmount = 10000;
    cin >> loanAmount;

    cout << "Number of Years: ";
    int totalYears = 5;
    cin >> totalYears;

    cout << left << fixed << setprecision(2) << endl;
    // Create title for table
    cout << setw(20) << "Interest Rate" << setw(20) << "Monthly Payment" << setw(20) << "Total Payment" << '\n';

    for (double annualInterest = MINIMUM_RATE; annualInterest <= MAXIMUM_RATE; annualInterest += RATE_INCREASE) {

        // To find monthlyPayment, use the equation given in Listing 2.9.
        double monthlyInterest = annualInterest / 12;
        double monthlyPayment = loanAmount * monthlyInterest / (1 - 1 / pow(1 + monthlyInterest, totalYears * 12));

        double totalPayment = monthlyPayment * totalYears * 12;

        // Output to console in same format as table (using the annual interest as a percentage)
        cout << setw(20) << to_string(annualInterest * 100) + '%' << setw(20) << monthlyPayment << setw(20) << totalPayment << '\n';
    }
}

void Chapter4Exercises::Exercise4_22() {

    /* (** difficulty)
     *
     * The monthly payment for a given loan pays the principal and the interest. The monthly interest is computed by
     * multiplying the monthly interest rate and the balance (the remaining principal). The principal paid for the month
     * is therefore the monthly payment minus the monthly interest. Write a program that lets the user enter the loan
     * amount, number of years, and interest rate, then displays the amortisation schedule for the loan.
     */

    using namespace std;

    // Step 1. Prompt user for inputs
    cout << "Loan Amount: ";
    double loanAmount;
    cin >> loanAmount; // The loan amount is also the starting balance, so this is needed to calculate the principals

    cout << "Number of Years: ";
    int numberOfYears;
    cin >> numberOfYears;
    int numberOfMonths = 12 * numberOfYears; // Declared and initialised to reduce repeated calculation of it

    cout << "Annual Interest Rate (e.g. 7.5 is 7.5%): ";
    double annualInterest;
    cin >> annualInterest;

    // Divide by 12 for twelve months in a year. Also divide by 100 to convert from percentage to decimal
    double monthlyInterest = annualInterest / 1200;
    double monthlyPayment = loanAmount * monthlyInterest / (1 - 1 / pow(1 + monthlyInterest, numberOfMonths));

    cout << left << fixed << setprecision(2);

    // Recreate table header from problem
    cout << "\nMonthly Payment: " << monthlyPayment;
    cout << "\nTotal Payment: " << monthlyPayment * numberOfMonths;
    cout << "\n\n" << setw(15) << "Payment#" << setw(15) << "Interest" << setw(15) << "Principal" << setw(15) <<"Balance" << "\n";

    for (int paymentNumber = 1; paymentNumber <= numberOfMonths; paymentNumber++) {

        // Expressions here come from question
        double paymentInterest = monthlyInterest * loanAmount;
        double paymentPrincipal = monthlyPayment - paymentInterest;
        loanAmount -= paymentPrincipal; // Must update remaining loan amount before printing or final payment will be missed out
        cout << setw(15) << paymentNumber << setw(15) << paymentInterest << setw(15) << paymentPrincipal << setw(15) << loanAmount << '\n';
    }
}

void Chapter4Exercises::Exercise4_23() {

    /* (* difficulty)
     *
     * Cancellation errors occur when manipulating a number that is very large with a very small number. For example,
     * the result of 10000000.00 + 0.000000001 is 10000000.00. Careful selection of the order of computation can avoid
     * cancellation errors and obtain more accurate results. For example, when computing the following series, you will
     * obtain more accurate results by from right to left rather than from left to right:
     *
     *                                  1 + 1/2 + 1/3 + ... + 1/n
     *
     * Write a program that compares the result of the summation of the proceeding series from left to right with the
     * result when summed from right to left, using n = 7000.
     */

    using namespace std;

    // Step 1. Declare variables
    const int LIMIT_N = 7000; // Value taken from question
    cout << fixed << setprecision(20); // Limit must be less than size of dtype <double> to ensure sane outputs

    // names stand for: sum[summation]; L[Left]; 2[To]; R[Right]
    double sumL2R = 0;
    double sumR2L = 0;

    // Step 2. Compute summations
    // Use of n as index is to match question's example
    for (int n = 1;  n <= LIMIT_N; n++)
        // Left to right summation
        sumL2R += 1.0 / n; // Needs to be 1.0 to ensure floating-point division instead of integer

    for (int n = LIMIT_N; n >= 1; n--)
        // Right to left summation
        sumR2L += 1.0 / n;

    // Step 3. Output results to user
    cout << "The summation from left to right is: " << sumL2R <<'\n';
    cout << "The summation from right to left is: " << sumR2L <<'\n';
}

void Chapter4Exercises::Exercise4_24() {

    /* (* difficulty)
     *
     * Write a program to sum the following series:
     *
     *      1/3 + 3/5 + 5/7 + 7/9 + 9/11 + 11/13 + ... + 95/97 + 97/99
     */

    using namespace std;

    const int N_LIMIT = 99; // Limit comes from largest value in question
    double sum = 0;

    for (int n = 3; n <= N_LIMIT; n += 2)
        // Largest value occurs in denominator, so the numerator will be offset by 2 to ensure only one index is used
        // Casting is required here otherwise integer division occurs
        sum += static_cast<double>(n - 2) / n;

    // Output to user
    cout << "The summation of this series is: " << sum << endl;
}

void Chapter4Exercises::Exercise4_25() {

    /* (** difficulty)
     *
     * You can approximate PI (mathematical constant) by using the following series:
     *
     *      PI = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 - ... - 1 / (2i - 1) + 1/(2i + 1)
     *
     * Write a program that displays the PI value for i = 10000, 20000, ... , and 100000
     */

    using namespace std;

    // Step 1. Formatting and table header
    cout << left << fixed << setprecision(10);
    cout << setw(15) << "Iterations" << setw(15) << "Pi (Est.) [10 d.p.]" << '\n';

    // Step 2. Find estimate of Pi for each iteration limit
    for (int iLimit = 10000; iLimit <= 100000; iLimit += 10000) {
        // Loops through the given iteration limits from question. Higher iLimit should give greater precision

        // Formula is (-1)**n/(2i + 1)
        double piEstimate = 0.0;

        for (int i = 0; i < iLimit; i++) {
            // (-1)**n on the numerator. Thus, even values of n are +ve and odd values of n are -ve
            if (i % 2 == 0)
                piEstimate += 1.0 / (2.0 * i + 1.0);
            else
                piEstimate -= 1.0 / (2.0 * i + 1.0);
        }
        piEstimate *= 4.0;

        // Step 3. Output to console
        cout << setw(15) << iLimit << setw(15) << piEstimate << '\n';
    }
}

void Chapter4Exercises::Exercise4_26() {

    /* (** difficulty)
     *
     * You can approximate e (Euler's number) by using the following series:
     *
     *          e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ... + 1/i!
     *
     * Write a program that displays the e value for i = 10000, 20000,..., and 100000.
     *
     * (Hint: Since i! = i*(i-1)*...*2*1, then 1/i! is 1/i(i-1)!. Initialise e and item to be 1 and keep adding a new
     * item to e. The new item is the previous item divided by i for i = 2, 3, 4, ... .)
     */

    using namespace std;

    const int I_LOWER_LIMIT = 10000, I_UPPER_LIMIT = 100000, I_STEPSIZE = 10000;

    // Step 1. Formatting and table header
    cout << left << fixed << setprecision(30);
    cout << setw(15) << "Iterations" << setw(15) << "e (Est.) [10 d.p.]" << '\n';

    // Step 2. Estimate value of e
    for (int iLimit = I_LOWER_LIMIT; iLimit <= I_UPPER_LIMIT; iLimit += I_STEPSIZE) {
        // Loops through the given iteration limits from question. Higher iLimit should give greater precision

        double eEst = 1.0; // The estimate for euler's number
        double term = 1.0; // The value of the current factorial

        for (int count = 1; count <= iLimit; count++) {
            // Set out using the hint. To find 1/(i+1)! you find 1/i! and then divide this by (i+1)
            term = term / count;
            eEst += term;
        }

        // Step 3. Output to console
        cout << setw(15) << iLimit << setw(15) << eEst << '\n';
    }
}

void Chapter4Exercises::Exercise4_27() {

    /* (** difficulty)
     *
     * Write a program that prompts the user to enter the year and first day of the year and displays on the console
     * the calendar table for the year. For example, if the user entered year 2005, and 6 for Saturday, January 1, 2005,
     * your program should display the calendar for each month in the year, as follows:
     *
     *                                          January 2005
     *
     *                      Sun     Mon     Tues    Wed     Thurs   Fri     Sat
     *                                                                      1
     *                      2       3       4       5       6       7       8
     *                      9       10      11      12      13      14      15
     *                      16      17      18      19      20      21      22
     *                      23      24      25      26      27      28      29
     *                      30      31
     *
     *                     ...
     *
     *                                         December 2005
     *
     *                      Sun     Mon     Tues    Wed     Thurs   Fri     Sat
     *                                                      1       2       3
     *                      4       5       6       7       8       9       10
     *                      11      12      13      14      15      16      17
     *                      18      19      20      21      22      23      24
     *                      25      26      27      28      29      30      31
     */

    using namespace std;
}

void Chapter4Exercises::Exercise4_28() {

    /* ( difficulty)
     *
     *
     */
}

void Chapter4Exercises::Exercise4_29() {

    /* ( difficulty)
     *
     *
     */
}

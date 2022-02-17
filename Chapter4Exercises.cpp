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

    // Minimum value of SPACING_WIDTH is 4 (size of a single \t)
    const int DAYS_PER_LINE = 7, SPACING_WIDTH = 8, MAX_MONTH = 12;

    // Prompt user for all required inputs here
    cout << "Enter the year: ";
    int year;
    cin >> year;

    cout << "Enter the first day of the year (1: Monday,...,7: Sunday): ";
    int firstDay; // This will be overwritten after each iteration of MONTH FOR loop
    cin >> firstDay;

    for (int month = 1; month <= MAX_MONTH; month++) {

        int daysInMonth; // Initialised within switch statement
        int daysInLine; // A counter,

        switch(month) {
            case 1:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t January " << year;
                daysInMonth = 31;
                break;
            case 2:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t February " << year;
                daysInMonth = 28;
                break;
            case 3:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t March " << year;
                daysInMonth = 31;
                break;
            case 4:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t April " << year;
                daysInMonth = 30;
                break;
            case 5:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t May " << year;
                daysInMonth = 31;
                break;
            case 6:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t June " << year;
                daysInMonth = 30;
                break;
            case 7:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t July " << year;
                daysInMonth = 31;
                break;
            case 8:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t August " << year;
                daysInMonth = 31;
                break;
            case 9:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t September " << year;
                daysInMonth = 30;
                break;
            case 10:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t October " << year;
                daysInMonth = 31;
                break;
            case 11:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t November " << year;
                daysInMonth = 30;
                break;
            case 12:
                cout << setw(SPACING_WIDTH + SPACING_WIDTH) << ' '
                     << "\t December " << year;
                daysInMonth = 31;
                break;

        }

        // Test if leap year (from Listing 3.7)
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear && month == 2)
            daysInMonth++;

        // Table headers and subheaders
        cout << "\n---------------------------------------------------\n";
        cout << left
             << setw(SPACING_WIDTH) << "Sun"
             << setw(SPACING_WIDTH) << "Mon"
             << setw(SPACING_WIDTH) << "Tue"
             << setw(SPACING_WIDTH) << "Wed"
             << setw(SPACING_WIDTH) << "Thu"
             << setw(SPACING_WIDTH) << "Fri"
             << setw(SPACING_WIDTH) << "Sat" << right << "\n\n";

        // Sunday should have no padding as it's the 1st column, and all other days are offset to the right by one
        // column, compared to the user input (e.g. Monday==1 from input, but is 2nd column)
        if (firstDay < 7) {
            // Do if not Sunday
            daysInLine  = firstDay;

            for (int tablePad = 1; tablePad <= daysInLine; tablePad++)
                // Add required amount of padding. Extra ' ' is so setw() can be used as it requires some char content
                cout << setw(SPACING_WIDTH) << ' ';

            daysInLine++; // Add offset
        } else {
            // Do if Sunday
            daysInLine = 1;
        }

        for (int day = 1; day <= daysInMonth; day++) {
            // Prints each day in separate column
            cout << setw(3) << day;

            if (daysInLine % DAYS_PER_LINE == 0) {
                // No need to add extra spacing if new line will be taken anyway
                cout << '\n';
            } else {
                // Ensures total spacing after each iteration equals SPACING_WIDTH to keep column widths consistent
                cout << setw(SPACING_WIDTH - 3) << ' ';
            }

            daysInLine++; // Must be inside DAY FOR loop, after IF statement
        }

        cout << "\n\n\n"; // Add spacing between months of calendar

        // Remove offset so the next month of the calendar has the correct start date
        if (daysInLine % 7 == 0)
            // (if daysInLine%7==0 then daysInLine % 7 - 1 == -1). The next month should start on a Saturday so
            // can hardcode this in
            firstDay = 6;
        else
            firstDay = daysInLine % 7 - 1;
    }
}

void Chapter4Exercises::Exercise4_28() {

    /* (** difficulty)
     *
     * Write a program that prompts the user to enter the year and first day of the year, and displays the first day
     * of each month in the year on the console. For example, if the user entered the year 2005, and 6 for Saturday,
     *  January 1, 2005, your program should display:
     *
     *              January 1, 2005 is Saturday
     *              ...
     *              December 1, 2005 is Thursday
     */

    using namespace std;

    // Prompt user for all inputs
    cout << "\nEnter the year: ";
    int year;
    cin >> year;

    cout << "Enter the first day of the year as an integer (1: Monday,...,7: Sunday): ";
    int day;
    cin >> day;

    // Formula to test for leap year comes from Listing 3.7
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // The FOR loop contains switch statements as arrays haven't yet been introduced
    for (int month = 1; month <= 12; month++) {
        // Initial-action must be (month = 1), and loop-continuation-condition can be (month <= 2) to (month <= 12)
        string dayName;

        switch (day % 7) {
            // Finds the current day based upon conditions from previous iteration of loop
            case 0:
                dayName = "Sunday";
                break;

            case 1:
                dayName = "Monday";
                break;

            case 2:
                dayName = "Tuesday";
                break;

            case 3:
                dayName = "Wednesday";
                break;

            case 4:
                dayName = "Thursday";
                break;

            case 5:
                dayName = "Friday";
                break;

            case 6:
                dayName = "Saturday";
                break;
        }

        switch (month) {
            // Format of text is from question
            case 1:
                cout << "\nJanuary 1, " << year << " is " << dayName;
                day += 31;
                break;

            case 2:
                cout << "\nFebruary 1, " << year << " is " << dayName;
                if (isLeapYear)
                    day += 29;
                else
                    day += 28;
                break;

            case 3:
                cout << "\nMarch 1, " << year << " is " << dayName;
                day += 31;
                break;

            case 4:
                cout << "\nApril 1, " << year << " is " << dayName;
                day += 30;
                break;

            case 5:
                cout << "\nMay 1, " << year << " is " << dayName;
                day += 31;
                break;

            case 6:
                cout << "\nJune 1, " << year << " is " << dayName;
                day += 30;
                break;

            case 7:
                cout << "\nJuly 1, " << year << " is " << dayName;
                day += 31;
                break;

            case 8:
                cout << "\nAugust 1, " << year << " is " << dayName;
                day += 31;
                break;

            case 9:
                cout << "\nSeptember 1, " << year << " is " << dayName;
                day += 30;
                break;

            case 10:
                cout << "\nOctober 1, " << year << " is " << dayName;
                day += 31;
                break;

            case 11:
                cout << "\nNovember 1, " << year << " is " << dayName;
                day += 30;
                break;

            case 12:
                cout << "\nDecember 1, " << year << " is " << dayName;
                day += 31;
                break;

        }
    }
}

void Chapter4Exercises::Exercise4_29() {

    /* (- difficulty)
     *
     * Write a program that displays, in five values per line, all leap years in the twentieth century (from the
     * year 1901 to 2000)
     *
     * Note: Don't just search online and hardcode this all in! Use formula from Listing 3.7
     */

    using namespace std;

    // Constant values come from question
    const int MIN_YEAR = 1901, MAX_YEAR = 2000, YEARS_PER_LINE = 5;

    int yearsOnLine = 0; // tracks how many years have been output to the current line
    bool isLeapYear = false;

    cout << "The leap years in the 20th century are: \n";

    for (int year = MIN_YEAR; year <= MAX_YEAR; year++) {

        // Formula to find leap year comes from Listing 3.7
        isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (isLeapYear) {

            cout << year << '\t';

            if (++yearsOnLine % YEARS_PER_LINE == 0)
                // Pre-increment to account for cout<<year, then tests if there are 5 lines on year
                // Less readable, but I wished to practice pre- and post-incrementation
                cout << '\n';
        }
    }
}

void Chapter4Exercises::Exercise4_30() {

    /* (* difficulty)
     *
     * Suppose you save $100 each month into a savings account with the annual interest rate 5%. So, the monthly
     * interest rate is 0.05 / 12 = 0.00417. After the first month, the value in the account becomes:
     *
     *                                  100 * (1 + 0.00417) = 100.417
     *
     *                    After the second month, the value in the account becomes:
     *
     *                           (100 + 100.147) * (1 + 0.00417) = 201.252
     *
     *                    After the second month, the value in the account becomes:
     *
     *                           (100 + 201.252) * (1 + 0.00417) = 302.507
     *
     *                    and so on.
     *
     * Write a program that prompts the user to enter an amount (e.g., 100), the annual interest rate (e.g., 5), and the
     * number of months (e.g., 6), and displays the amount in the savings account after each month.
     */

    using namespace std;

    const int SPACING_WIDTH = 12; // Minimum value is 11 due to largest header length

    cout << "Enter the monthly amount to save: $";
    int monthlyDeposit;
    cin >> monthlyDeposit;
    double balance = 0;

    cout << "Enter the annual interest rate: ";
    int interestRate;
    cin >> interestRate;
    double monthlyInterest = interestRate / 1200.0;

    cout << "Enter the total number of months to save: ";
    int totalMonths;
    cin >> totalMonths;

    cout << fixed << setprecision(2);
    cout<< left << setw(SPACING_WIDTH) << "Month" << setw(SPACING_WIDTH) << "Balance ($)" << right << '\n';

    for (int month = 1; month <= totalMonths; month++) {

        balance = (monthlyDeposit + balance) * (1 + monthlyInterest);

        cout << setw(5) << month << setw(SPACING_WIDTH - 5) << ' '
             << setw(11) << balance << setw(SPACING_WIDTH - 11) << ' '
             <<  '\n';
    }
}

void Chapter4Exercises::Exercise4_31() {

    /* (* difficulty)
     *
     * Suppose you put $10,000 into a CD with an annual percentage yield of 5.75%.
     *
     *          After one month, the CD is worth:    10000 + 10000 * 5.75 / 1200 = 10047.91
     *          After two months, the CD is worth:   100047.91 + 10047.91 * 5.75 / 1200 = 10096.06
     *          After three months, the CD is worth: 10096.06 + 10096.06 * 5.75 / 1200 = 10144.43
     *
     * and so on.
     *
     * Write a program that prompts the user to enter an amount (e.g., 10000), the annual percentage yield (e.g., 5.75),
     * and the number of months (e.g., 18), and displays a table.
     */

    using namespace std;

    const int SPACING_WIDTH = 12;

    cout << "\nEnter the initial deposit amount: ";
    double balance;
    cin >> balance;

    cout << "Enter the annual percentage yield: ";
    double yieldPercentage; // Is an annual percentage at this point
    cin >> yieldPercentage;
    yieldPercentage /=  1200; // Is a monthly decimal from this point

    cout << "Enter the maturity period (number of months): ";
    int totalMonths;
    cin >> totalMonths;

    cout << fixed << setprecision(2) << '\n';

    cout << left
         << setw(SPACING_WIDTH) << "Month" << setw(SPACING_WIDTH) << "CD Value($)"
         << right << '\n';

    for (int month = 1; month <= totalMonths; month++) {

        balance = balance + balance * yieldPercentage;

        cout << setw(5) << month << setw(SPACING_WIDTH - 5) << ' '
             << setw(11) << balance << setw(SPACING_WIDTH - 11) << ' '
             << '\n';
    }
}

void Chapter4Exercises::Exercise4_32() {

    /* (** difficulty)
     *
     * A positive integer is called a perfect number if it is equal to the sum of all of its positive divisors,
     * excluding itself. For example, 6 is the first perfect number, because 6 = 3 + 2 + 1. The next is 28 = 13 + 7 + 4
     * + 2 +1. There are four perfect numbers less than 10000. Write a program to find these four numbers
     */

    using namespace std;

    // The 5th perfect number is 33550336 (don't test for it as it will take a while with this algorithm!)
    const int LIMIT_TO_SEARCH =  10000;

    cout << "The perfect numbers below " << LIMIT_TO_SEARCH << " are:\n";
    for (int number = 6; number < LIMIT_TO_SEARCH; number++) {

        int perfectSum = 1; // 1 is a divisor of all positive integers. No need to test for it, just initialise sum at 1

        for (int i = 2; i <= number/2.0; i++) {
            // Dealing with +ve integers. Largest divisor (d) is thus 1/2 of a given number (n) [n/d = 2]
            if (number % i == 0)
                // Condition to handle when a divisor is found
                perfectSum += i;
        }

        if (perfectSum == number)
            cout << left << setw(6) << number << "\t";
    }
}

void Chapter4Exercises::Exercise4_33() {

    /* (** difficulty)
     *
     * Revise Listing 3.8, Lottery.cpp, to generate a lottery of a two-digit number. The two digits in the number are
     * distinct. (Hint: Generate the first digit. Use a loop to continuously generate the second digit until it is
     * different from the first digit.
     *
     * Note: This is based off my solution to Listing 3.8
     */

    using namespace std;

    srand(time(0));

    // Informs the user of the prizes on offer
    cout << "Play the lottery! Guess a two-digit number for a chance to win. The prizes are:"
         << "\n- 1st: $10,000 (two digits match and are in the correct order)"
         << "\n- 2nd: $3,000  (two digits match)"
         << "\n- 3rd: $1,000  (one digit matches)" << endl;

    // Prompts user for their guess
    cout << "Enter your guess: ";
    int  guess;
    cin >> guess;

    // Generate the lottery's digits. digit 1 is the tens, and digit 2 is the units
    int lotteryDigit1 = rand() % 10;
    int lotteryDigit2 = rand() % 10;

    // Loop ends when the two lottery digits are different
    while (lotteryDigit2 == lotteryDigit1)
        lotteryDigit2 = rand() % 10;

    // Obtains the user's digits
    int guessDigit1 = guess / 10;
    int guessDigit2 = guess % 10;

    // Informs user of winning number. No need to display lotteryDigit1 if it's zero
    if (lotteryDigit1 == 0)
        cout << "\nThe lottery number is: " << lotteryDigit2 << "." << endl;
    else
        cout << "\nThe lottery number is: " << lotteryDigit1 << lotteryDigit2 << "." << endl;

    if (guessDigit1 == lotteryDigit1 && guessDigit2 == lotteryDigit2) {
        // Checks whether the guess matches the lottery exactly
        cout << "Congratulations! You won the top prize (worth $10,000) with your guess of " << guess << "." << endl;
    } else if ((guessDigit1 == lotteryDigit1 || guessDigit2 == lotteryDigit1) &&
               (guessDigit1 == lotteryDigit2 || guessDigit2 == lotteryDigit2)) {
        // Checks whether the reversal of digits matches the lottery. Written in this way for scalability
        cout << "Congratulations! You won the 2nd prize(worth $3000) with your guess of " << guess << "." << endl;
    } else if (guessDigit1 == lotteryDigit1 || guessDigit2 == lotteryDigit1
               || guessDigit1 == lotteryDigit2 || guessDigit2 == lotteryDigit2) {
        // Checks if one digit is in the lottery
        cout << "Congratulations! You won the 3nd prize (worth $1000) with your guess of " << guess << "." << endl;
    } else {
        // States nothing matches
        cout << "Unfortunately your guess of " << guess << " did not win this time." << endl;
    }
}

void Chapter4Exercises::Exercise4_34() {

    /* (*** difficulty)
     *
     * Exercise 3.14 gives a program that plays the scissor-rock-paper game. Revise the program to let the user
     * continuously play until either the user or the computer wins more than two times
     *
     * Note: This program is built upon my solution to Exercise 3.15, not the given example
     */

    using namespace std;

    srand(time(0));

    // Inform user of game's rules
    cout << "The codes for each move are:\n"
         << " - 0 : Scissors\n"
         << " - 1 : Rock\n"
         << " - 2 : Paper\n";

    unsigned short userScore = 0, computerScore = 0;
    while (userScore < 3 && computerScore < 3) {

        cout << "Enter your move: ";
        unsigned short userHand;
        cin >> userHand;

        // Sets the computers hand according the questions conditions (0: SCISSORS, 1: ROCK, 2: PAPER)
        unsigned short computerHand = rand() % 3;

        // Switch to handle each of the user's choices. Nested IF statement deals with whether the user won, lost or
        // drew. Score counters increase if a player wins.
        switch (userHand) {
            case 0:
                if (computerHand == 2) {
                    cout << "You won! Your SCISSORS beat the computer's PAPER!" << endl;
                    userScore++;
                } else if (computerHand == 1) {
                    cout << "You lost! Your SCISSORS fell to the computer's ROCK!" << endl;
                    computerScore++;
                } else if (computerHand == userHand)
                    cout << "You drew! The computer also used SCISSORS!" << endl;
                break;

            case 1:
                if (computerHand == 0) {
                    cout << "You won! Your ROCK beat the computer's SCISSORS!" << endl;
                    userScore++;
                } else if (computerHand == 2) {
                    cout << "You lost! Your ROCK fell to the computer's PAPER!" << endl;
                    computerScore++;
                } else if (computerHand == userHand)
                    cout << "You drew! The computer also used ROCK!" << endl;
                break;

            case 2:
                if (computerHand == 1) {
                    cout << "You won! Your PAPER beat the computer's ROCK" << endl;
                    userScore++;
                } else if (computerHand == 0) {
                    cout << "You lost! Your PAPER fell to the computer's SCISSORS!" << endl;
                    computerScore++;
                } else if (computerHand == userHand)
                    cout << "You drew! The computer also used PAPER!" << endl;
                break;

            default:
                cout << "This match encountered an error. Please play again." << endl;
                break;
        }

        cout << "Score | User: " << userScore << " | Computer: " << computerScore << " |\n";
        // End of WHILE loop
    }
}

void Chapter4Exercises::Exercise4_35() {

    /* (* difficulty)
     *
     * You can prove that the following summation is 24:
     *
     *      1/(1 + sqrt[2]) + 1/(sqrt[2] + sqrt[3]) + 1/(sqrt[3] + sqrt[4]) + ... + 1/(sqrt[624]+sqrt[625])
     *
     * Write a program to verify your result.
     */

    using namespace std;

    double summation = 0;

    for (int i = 1; i < 625; i++) {

        summation += 1 / (pow(i, 0.5) + pow(i+1, 0.5));
    }

    cout << summation;
}

void Chapter4Exercises::Exercise4_36() {

    /* (** difficulty)
     *
     * Use loops to simplify Exercise 3.17
     *
     * Note: This exercise was solved using my solution to Exercise 3.17
     */

    using namespace std;

    // I believe a single number is easier to input that a 9 digit space separated list
    cout << "Enter the first nine digits as integers of your ISBN: ";
    int inputDigits;
    cin >> inputDigits;

    int checkSum = 0; // What will hold the total of Sum[d_n * n] % 11
    cout << "Your ISBN is: ";

    for (int digit = 1; digit <= 9; digit++) {
        // Finds each ISBN digit. Written using pow(10, n) to illustrate finding the digits in base10 system.
        int digitValue = inputDigits / static_cast<int>(pow(10, 9 - digit)) % 10;
        checkSum += digitValue * digit;

        if (digit == 1 || digit == 3)
            // Add correct formatting
            cout << digitValue << "-";
        else
            cout << digitValue;
    }

    // Finds the 10th digit, which is found by doing a 'checksum' of the other 9 digits
    checkSum %= 11;

    if (checkSum == 10)
        // Output format with hyphens is from standard ISBN10 formatting.
        cout << "-X" << endl;
    else
        cout << "-" << checkSum << endl;
}

void Chapter4Exercises::Exercise4_37() {

    /* (* difficulty)
     *
     * You have just started a sales job in a department store. Your pay consists of a base salary and a commission. The
     * base salary is $5,000. The scheme shown below is used to determine the commission rate.
     *
     *
     *                                  Sales Amount                  Commission Rate
     *                                  $0.01 - $5,000                8 percent
     *                                  $5,000.01 - $10,0000          10 percent
     *                                  $10,000.01 and above          12 percent
     *
     * Your goal is to earn £30,000 a year. Write a program that finds out the minimum amount of sales you have to
     * generate in order to make $30,000.
     */

    using namespace std;

    // All variables are in dollars. Reduce value of individualSale to increase precision of finding targetSalary
    const double BASE_SALARY = 5000.0, individualSale = 1.0, targetSalary = 30000;

    double salary = BASE_SALARY; // Compute salary

    double totalSales = 0;
    while (salary <= targetSalary) {
        totalSales += individualSale;

        if (totalSales <= 5000) {
            salary += 0.08 * individualSale;
        } else if (totalSales <= 10000) {
            salary += 0.1 * individualSale;
        } else {
            salary += 0.12 * individualSale;
        }
    }

    cout << fixed << setprecision(2)
         << "For a salary of $" << salary
         << ", one must generate $" << totalSales << " in sales,"
         << " with a base salary of $" << BASE_SALARY << endl;
}

void Chapter4Exercises::Exercise4_38() {

    /* (* difficulty)
     *
     * Rewrite Exercise 4.37 as follows:
     *      - Use a FOR loop instead of a do-while loop
     *      - Let the user enter COMMISSION_SOUGHT instead of fixing it as a constant.
     *
     * Note: I used a FOR loop the first time in Exercise 4.37, so I'll only be needing to add the second part. This
     * question was very vague in changes to be made; not worth lingering on.
     */

    using namespace std;

    // All variables are in dollars. Reduce value of individualSale to increase precision of finding targetSalary
    const double BASE_SALARY = 5000.0, individualSale = 1.0, targetSalary = 30000;
    double salary = BASE_SALARY; // Compute salary

    cout << "Enter the commission you receive: ";
    double commissionSought;
    cin >> commissionSought;

    double totalSales = 0;
    while (salary <= targetSalary) {
        totalSales += individualSale;

        if (totalSales <= 5000) {
            salary += 0.08 * individualSale;
        } else if (totalSales <= 10000) {
            salary += 0.1 * individualSale;
        } else {
            salary += commissionSought * individualSale;
        }
    }

    cout << fixed << setprecision(2)
         << "For a salary of $" << salary
         << ", one must generate $" << totalSales << " in sales,"
         << " with a base salary of $" << BASE_SALARY << endl;
}

void Chapter4Exercises::Exercise4_39() {

    /* (** difficulty)
     *
     * Write a program that reads integers, finds the largest of them, and counts its occurrences. Assume that the input
     * ends with the number 0. Suppose that you entered 3 5 2 5 5 0; the program finds that the largest is 5 and the
     * occurrence count for 5 is 4.
     *
     * (Hint: Maintain two variables max and count. max stores the current max number,
     * and count stores its occurrences. Initially, assign the first number to max and 1 to count. Compare each
     * subsequent number with max. If the number is greater than max, assign it to max and reset count to 1. If
     * the number is equal to max, increment count by 1.
     */

    using namespace std;

    int count = 0, max = 0, inputInteger;

    // Prompt user for space separated list
    cout << "\nEnter a space-separated list of integers to find the largest int, and its frequency.\n"
         << "An input of 0 (zero) ends the program.\n";
    cout << "Enter numbers: ";

    do {
        // Loops until a zero is entered
        cin >> inputInteger;

        if (max < inputInteger) {
            // Sets max to new largest integer, and reset count to 1
            max = inputInteger;
            count = 1;
        } else if (max == inputInteger)
            // Increments count when another instance of current max is found
            count++;

    } while (inputInteger != 0);

    // Output to console in format of question
    cout << "The largest number is " << max << '\n'
         << "The occurrence count of the largest number is " << count << '\n';
}

void Chapter4Exercises::Exercise4_40() {

    /* (- difficulty)
     *
     * Write a program that simulates flipping a coin one million times and displays the number of heads and tails.
     */

    using namespace std;

    srand(time(0));

    const int TOTAL_FLIPS = 1000000;

    // Let a 0 represent HEADS and a 1 represent TAILS on the random number generator
    int flipResult = 0, totalHeads = 0, totalTails = 0;

    int iFlips = 0;
    while (iFlips++ < TOTAL_FLIPS) {
        // Test loop-continuation-condition, then iterate flip counter
        flipResult = rand() % 2;

        if (flipResult == 0)
            totalHeads++;
        else
            totalTails++;
    }

    // Output to console
    cout << "There were " << totalHeads << " heads, and "
         << totalTails << " tails, after " << TOTAL_FLIPS << " flips.\n";
}

void Chapter4Exercises::Exercise4_41() {

    /* (* difficulty)
     *
     * Write a program that prompts the user to enter the number of seconds to be counted down. Display a message
     * each second of the countdown and include an additional warning every 5 seconds. Terminate when time expires.
     * Here is a sample run:
     *
     *                      Enter number of seconds: 6
     *                      6 seconds remaining
     *                      Warning: 5 seconds remaining!
     *                      4 seconds remaining
     *                      3 seconds remaining
     *                      2 seconds remaining
     *                      1 second remaining
     *                      Time up!
     */

    using namespace std;

    cout << "\nEnter number of seconds: ";
    int seconds;
    cin >> seconds;

    do {
        // seconds functions as the loop iterator, and is decremented at the end of the do-while loop
        if (seconds % 5 == 0)
            cout << "Warning: " << seconds << " seconds remaining!\n";
        else if (seconds == 1)
            cout << seconds << " second remaining\n";
        else
            cout << seconds << " seconds remaining\n";
    } while (--seconds != 0);

    cout << "Time up!\n";
}

void Chapter4Exercises::Exercise4_42() {

    /* (** difficulty)
     *
     * A square is divided into four smaller regions as shown below in (a). If you throw a dart into the square
     * 1,000,000 times, what is the probability for a stone to fall into the odd region? Write a program to simulate
     * the process and display the result
     *
     * (Hint: Place the center of the square in the center of a coordinate system, as shown in (b). Randomly generate
     * a point in the square and count the number of times for a point to fall in the odd region.
     *
     * Note: For help on how to find points in a triangle try:
     *      - https://discuss.codechef.com/t/best-way-to-check-if-a-point-lies-inside-a-triangle-or-not/13528/3
     *      - https://stackoverflow.com/a/51479401
     */

    using namespace std;

    srand(time(0));
    // Will make a 10x10 region with the center at (5,5).

    const int TOTAL_THROWS = 1000000, REGION_WIDTH = 5;
    const double x_centre = 5.0, y_centre = 5;

    int hitsRegion1 = 0, hitsRegion2 = 0, hitsRegion3 = 0, hitsRegion4 = 0;

    int throws = 1;
    while (throws <= TOTAL_THROWS) {

        double xPoint = (double)rand() * (REGION_WIDTH * 2) / (double)RAND_MAX;
        double yPoint = (double)rand() * (REGION_WIDTH * 2) / (double)RAND_MAX;



        if (xPoint < REGION_WIDTH)
            // Checks for region 1
            hitsRegion1++;



        /* Assume that p1, p2, p3 are ordered in counterclockwise, then we can check if p lies at left of the 3 oriented
         * edges [p1, p2], [p2, p3] and [p3, p1], if all the dot products are of the same sign then p is on the same side
         * of all, and thus inside. For that, consider 3 vectors v1, v2 and v3 that are respectively left-orthogonal to
         * [p1, p2], [p2, p3] and [p3, p1].
         */



        double dot1Region2 = (REGION_WIDTH - (REGION_WIDTH * 2)) * (xPoint - REGION_WIDTH)
                           + (-(REGION_WIDTH * 2) + REGION_WIDTH) * (yPoint - (REGION_WIDTH * 2));

        double dot2Region2 = ((REGION_WIDTH * 2) - REGION_WIDTH) * (xPoint - (REGION_WIDTH * 2))
                           + (-(REGION_WIDTH * 2) + (REGION_WIDTH * 2)) * (yPoint - REGION_WIDTH);

        double dot3Region2 = ((REGION_WIDTH * 2) - (REGION_WIDTH * 2)) * (xPoint - (REGION_WIDTH * 2))
                           + (-REGION_WIDTH + (REGION_WIDTH * 2)) * (yPoint - (REGION_WIDTH * 2));

        if ((dot1Region2 >= 0 && dot2Region2 >= 0 && dot3Region2 >= 0) ||
            (dot1Region2 <= 0 && dot2Region2 <= 0 && dot3Region2 <= 0))
            /* For Region2: the top-centre point is p1; the furthest right point is p2; the top-right point (at the right
             * angle) is p3.
             */
            hitsRegion2++;



        double dot1Region3 = (REGION_WIDTH - (REGION_WIDTH * 2)) * (xPoint - REGION_WIDTH)
                           + (-REGION_WIDTH + REGION_WIDTH) * (yPoint - (REGION_WIDTH * 2));

        double dot2Region3 = (REGION_WIDTH - REGION_WIDTH) * (xPoint - REGION_WIDTH) + (-(REGION_WIDTH * 2)
                           + REGION_WIDTH) * (yPoint - REGION_WIDTH);

        double dot3Region3 = ((REGION_WIDTH * 2) - REGION_WIDTH) * (xPoint - (REGION_WIDTH * 2))
                           + (-REGION_WIDTH + (REGION_WIDTH * 2)) * (yPoint - REGION_WIDTH);

        if ((dot1Region3 >= 0 && dot2Region3 >= 0 && dot3Region3 >= 0) ||
            (dot1Region3 <= 0 && dot2Region3 <= 0 && dot3Region3 <= 0))
            /* For Region3: the top-centre point is p1; the centre-point (at the right angle) is p2; the furthest right
             * point is p3.
             */
            hitsRegion3++;



        if (xPoint >= REGION_WIDTH && yPoint < REGION_WIDTH)
            // Checks for region 4
            hitsRegion4++;

        throws++;
    }

    cout << "\nHits are as follows for " << TOTAL_THROWS << " throws:\n\n"
         << "Region 1: " << hitsRegion1 << " hits\n"
         << "Region 2: " << hitsRegion2 << " hits\n"
         << "Region 3: " << hitsRegion3 << " hits\n"
         << "Region 4: " << hitsRegion4 << " hits\n";

}



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

//Currently, working here
void Chapter4Exercises::Exercise4_15() {

    /* (* difficulty)
     *
     * For Listing 4.8, another solution to find the greatest common divisor of two integers n1 and n2 is as
     * follows: First find d to be the minimum of n1 and n2, then check whether d, d-1, d-2,...,2 or 1 is a
     * divisor for both n1 and n2 in this order. The first such common divisor is the greatest common divisor for
     * n1 and n2.
     */

    using namespace std;

    int n1, n2, gcd;
}
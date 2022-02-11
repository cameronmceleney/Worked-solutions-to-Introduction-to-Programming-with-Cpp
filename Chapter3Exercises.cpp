#include "Chapter3Exercises.h"

void Chapter3Exercises::Exercise3_1() {

    /* My solution to this problem which covers content from Sections 3.2-3.10 (* difficulty)
     *
     * The problem description was (Algebra: solving linear equations) You can use Cramer's Rule to solve
     * the following 2x2 system of linear equations.
     *
     * ax + by = e ; cx + dy = f; x = (ed - bd)/(ad-bc); y = (af - ec)/(ad - bc)
     *
     * Write a program that prompts the user to enter a,b,c,d,e, and f, and display the result. If
     * ad-bc==0m report that "The equation has no solution"
     * */
    using namespace std;

    // Don't want to use single letters as variable names
    double aVar, bVar, cVar, dVar, eVar, fVar;
    double xCramer, yCramer, determinantCramer;
    // Prompt user for variables
    cout << "Enter a, b, c, d, e, f: ";
    cin >> aVar >> bVar >> cVar >> dVar >> eVar >> fVar;

    xCramer = (eVar * dVar - bVar * fVar) / (aVar * dVar - bVar * cVar);
    yCramer = (aVar * fVar - eVar * cVar) / (aVar * dVar - bVar * cVar);
    determinantCramer = aVar * dVar - bVar * cVar;

    if (determinantCramer == 0) {
        cout << "The equation has no solutions" << endl;
        exit(0);
    } else {
        cout << fixed << setprecision(1) << "x is " << xCramer << " and y is " << yCramer << "." << endl;

    }

}

void Chapter3Exercises::Exercise3_2(){

    /* My solution to the this problem which covers content from SEctions 3.2-3.10 in Chapter 3
     *
     * (Checking whether a number is even) Write a program that reads an integer and checks whether it
     * is even.
     */

    using namespace std;

    int number;
    bool isIntegerEven;

    // Prompts user for input
    cout << "Enter an integer: ";
    cin >> number;

    // Uses a condition statement (instead of an IF statement) to determine and output whether a number is even
    cout << "Is " << number << " an even number? " << ((number % 2 == 0) ? "true" : "false");

}

void Chapter3Exercises::Exercise3_3() {

    /* My solution to Exercise 3.3 covering Sections 3.2-3.10 in Chapter 3 (* difficulty)
     *
     * (Algebra: Solving Quadratic Equations) The twp roots of a quadratic equation ax^2 + bc + c = 0 can be obtained
     * using the Quadratic Formula where b^2 - 4ac is called the discriminant. If it is positive, then the equation
     * has two real roots. If it is zero, the equations has one root. If iti s negative, the equation has no real
     * roots.
     *
     * Write a program that prompts the user to enter v alues for a,b, and c, and displays the result based  on the
     * discriminant. If the discriminant is positive, display two roots. If the discriminant is 0, display one root.
     * Otherwise, display "The equation has no real roots".
     *
     * Note you can use Math.pow(x, 0.5) to compute sqrt(x).*/

    using namespace std;

    double aVal, bVal, cVal;
    double root1, root2, determinant;

    cout << "Enter a, b, c: ";
    cin >> aVal >> bVal >> cVal;

    determinant = bVal * bVal - 4 * aVal * cVal;
    root1 = (-1 * bVal + sqrt(determinant)) / (2 * aVal);
    root2 = (-1 * bVal - sqrt(determinant)) / (2 * aVal);

    if (determinant > 0) {
        cout << "The roots are " << root1 << " and " << root2 << endl;
    } else if ( determinant == 0){
        cout << "The root is " << root1 << endl;
    } else {
        cout << "The equation has no real roots" << endl;
    }


}

void Chapter3Exercises::Exercise3_4() {

    /* My solution for Problem 3.4 covering Sections 3.2-3.10 in Chapter 3
     *
     * (Financial Application: monetary units) Modify Listing 2.10, ComputerChange.cpp, to display only
     * the nonzero denominations, using singular words for singular units such as 1 dollar and 1 penny, and plural
     * words for more than one unit such as 2 dollars and 3 pennies.
     *
     * For consistency, I will be working off the book's version for Listing2.10 (seen below) and not my own version*/

    /*
    using namespace std;

    // Receive the amount
    cout << "Enter an amount in double, for example, 11.56: ";
    double amount;
    cin >> amount;

    int remainingAmount = static_cast<int>(amount * 100);

    // Find the number of one dollars
    int numberOfOneDollars = remainingAmount / 100;
    remainingAmount %= 100;

    // Find the number of quarters in the remaining amount
    int numberOfQuarters = remainingAmount / 25;
    remainingAmount %= 25;

    // Find the number of dimes in the remaining amount
    int numberOfDimes = remainingAmount / 10;
    remainingAmount %= 10;

    // Find the number of nickels in the remaining amount
    int numberOfNickels = remainingAmount / 5;
    remainingAmount %= 5;

    // Find the number of dimes in the remaining amount
    int numberOfPennies = remainingAmount;

    // Display results
    cout << "Your amount " << amount << " consists of \n" <<
        "\t" << numberOfOneDollars << " dollars\n" <<
        "\t" << numberOfQuarters << " quarters\n" <<
        "\t" << numberOfDimes << " dimes\n" <<
        "\t" << numberOfNickels << " nickels\n" <<
        "\t" << numberOfPennies << " pennies\n";

     */

    using namespace std;

    // Receive the amount
    cout << "Enter an amount in double, for example, 11.56: ";
    double amount;
    cin >> amount;

    int remainingAmount = static_cast<int>(amount * 100);

    // Find the number of one dollars
    int numberOfOneDollars = remainingAmount / 100;
    remainingAmount %= 100;

    // Find the number of quarters in the remaining amount
    int numberOfQuarters = remainingAmount / 25;
    remainingAmount %= 25;

    // Find the number of dimes in the remaining amount
    int numberOfDimes = remainingAmount / 10;
    remainingAmount %= 10;

    // Find the number of nickels in the remaining amount
    int numberOfNickels = remainingAmount / 5;
    remainingAmount %= 5;

    // Find the number of dimes in the remaining amount
    int numberOfPennies = remainingAmount;

    // Display results. Kept this code simple to follow what was taught in the book
    cout << "Your amount " << amount << " consists of \n";

    // Outputs number of dollar(s) to user with an exception for the case of there only being a single dollar
    if (numberOfOneDollars == 1)
        cout << "\t" << numberOfOneDollars << " dollar\n";
    else if (numberOfOneDollars >= 1)
        cout << "\t" << numberOfOneDollars << " dollars\n";

    // Outputs number of quarter(s) to user with an exception for the case of there only being a single quarter
    if (numberOfQuarters == 1)
        cout << "\t" << numberOfQuarters << " quarter\n";
    else if (numberOfQuarters >= 1)
        cout << "\t" << numberOfQuarters << " quarters\n";

    // Outputs number of dime(s) to user with an exception for the case of there only being a single dime
    if (numberOfDimes == 1)
        cout << "\t" << numberOfDimes << " dime\n";
    else if (numberOfDimes >= 1)
        cout << "\t" << numberOfDimes << " dimes\n";

    // Outputs number of nickel(s) to user with an exception for the case of there only being a single nickel
    if (numberOfNickels == 1)
        cout << "\t" << numberOfNickels << " nickel\n";
    else if (numberOfNickels >= 1)
        cout << "\t" << numberOfNickels << " nickels\n";

    // Outputs number of penny(ies) to user with an exception for the case of there only being a single penny
    if (numberOfPennies == 1)
        cout << "\t" << numberOfPennies << " penny\n";
    else if (numberOfPennies >= 1)
        cout << "\t" << numberOfPennies << " pennies\n";

    // End of function
 }

void Chapter3Exercises::Exercise3_6() {

    /* My solution to Problem 3.5 covering Sections 3.2-3.10 in Chapter 3
     *
     * (Random Character) Write a program that displays a random uppercase letter
     * */

    using namespace std;

    // Seeds rand() with the current time to ensure each run of the program is unique
    srand(time(0));

    int randomInt;

    // From ASCII decimal, uppercase letters are values 65-90 (inclusive). Remember operator precedence which means
    // the (rand() % 25) is computed first. Thus the minimum value of randomInt occurs when rand()%25 == 0.
    randomInt = rand() % 25 + 1 + 65; // The +1 is to show that rand()%25 would be [0,24]

    // Outputs the random character to console
    cout << "Your random uppercase letter is: \'" << static_cast<char>(randomInt) << "\'" << endl;

    /* Another method would be to create a char variable and then print that, as char displays an int value
    char randomCharacter;
    randomCharacter = randomInt;
    cout << "Your random uppercase letter is: \'" << randomCharacter << "\'" << endl;
     */
}

void Chapter3Exercises::Exercise3_7() {

    /* My solution to Problem 3.7 covering Sections 3.2-3.10 in Chapter 3 (* difficulty)
     *
     * (Sorting Integers) Write a program that sorts five integers. The integers are entered from the console
     * and stored in the variables num1, num2, num3, num4, and num5, respectively. The program sorts the numbers
     * in descending order, so that the biggest number is first and the smallest number is last. Print the numbers
     * to the console in the sorted order.*/

    using namespace std;

    int num1, num2, num3, num4, num5;
    // Array to hold values. Using instead of vectors for sake of variety.
    std::array<int,5> numArray;

    // Prompts user for input
    cout << "Enter five integers to be sorted: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    numArray = {num1, num2, num3, num4, num5};

    // Although they haven't been introduced yet, for the sake of time to avoid many IF statements,
    // I will use arrays and sort(). rbegin() and rend() are to use descending order.
    sort(rbegin(numArray), rend(numArray));

    // Hardcoded as there will only ever be 5 integers to output, and I wanted to show off calling elements
    // of an array (instead of looping through the array)
    cout << "Your sorted numbers are [" <<
            numArray[0] << ", " <<
            numArray[1] << ", " <<
            numArray[2] << ", " <<
            numArray[3] << ", " <<
            numArray[4] << "]"  << endl;
}

void Chapter3Exercises::Exercise3_8() {

    /* My solution to Problem 3.8 covering Sections 3.2-3.10 in Chapter 3
     *
     * (Science: Day of the week) Zeller's congruence is an algorithm developed by Christian Zeller
     * to calculate the day of the week. The formula is:
     *
     * h = (q + (26*(m+1)/10) + k + (k/4) + (j/4) +5*j) % 7 where:
     *
     *  - h is the day of the week (0: Saturday, 1: Sunday, ... , 6: Friday
     *  - q is the day of the month
     *  - m is the month (3: March, 4: April, ... , 12: December. January (13) and February (14) are
     *    counted as months of the previous year
     *  - j is the century (i.e. (year/10)
     *  - k is the year of the century (i.e. year % 7)
     *
     *  Write a program that prompts the user to enter a year, month, ad day of the month, and display the name of
     *  the day of the week.
     *
     *  (Hint: ensure that all variables are int when using %. January and February are counted as 13 and 14 in
     *  the formula. So, you need to convert the user input 1 to 13 and 2 to 14 for the month and change the year
     *  to the previous year.*/

    using namespace std;

    int dayOfTheWeek, day, month, year, century, yearOfTheCentury;

    // Prompts user for the year, and then calculates the century
    cout << "Enter year: (e.g., 2008): ";
    cin >> year;

    // Prompts user for month. SWITCH statement converts user inputs from conventional January/February integer
    // representation to that required by the algorithm, and then decrements the year to be the previous year.
    cout << "Enter month: 1-12: ";
    cin >> month;
    switch (month) {
        case 1: month = 13;
                year--;
                break;
        case 2: month = 14;
                year--;
                break;
        default: break;
    }

    // Computation of century and yearOfTheCentury must be done after the Jan/Feb conversion to avoid LOGIC ERROR
    century = year / 100;
    yearOfTheCentury = year % 100;

    // Prompt user for day of the month
    cout << "Enter the day of the month: 1-31: ";
    cin >> day;

    // Uses Zeller's algorithm to find the day of the week
    dayOfTheWeek = (day
            + (26 * (month + 1) / 10)
            + yearOfTheCentury
            + (yearOfTheCentury / 4)
            + (century / 4)
            + (5 * century)) % 7;

    // Outputs day of the week to the user. Using a SWITCH statement is neater than nested IF statements
    cout << "Day of the week is ";
    switch (dayOfTheWeek) {
        case 0: cout << "Saturday" << endl;
                break;
        case 1: cout << "Sunday" << endl;
                break;
        case 2: cout << "Monday" << endl;
                break;
        case 3: cout << "Tuesday" << endl;
                break;
        case 4: cout << "Wednesday" << endl;
                break;
        case 5: cout << "Thursday" << endl;
                break;
        case 6: cout << "Friday" << endl;
                break;
    }
}

void Chapter3Exercises::Exercise3_9() {

    /* My solution to Problem 3.9 covering Sections 3.2-3.10 in Chapter 3 (* difficulty)
     *
     * (Game: Addition Quiz) Listing 3.5, SubtractionQuiz.cpp, randomly generates a subtraction quiz. Revise the
     * program to randomly generate an addition question with two integers less than 100.
     *
     * //SubtractionQuiz.cpp (below) is taken directly from the book and is not my solution, for consistency.
     *
    #include <iostream>
    #include <ctime>
    #include <cstdlib>
    using namespace std;

    // 1. Generate two random single-digit integers
    srand(time(0));
    int number1 = rand() % 10;
    int number2 = rand() % 10;

    // 2. If number1 < number2, swap number1 with number2
    if (number1 < number2)
    {
       int temp = number1;
       number1 = number2;
       number2 = temp;
    }

    // 3. Prompt the student to answer "What is number1 - number2?"
    cout << "What is " << number1 << " - " << number2 << "? ";
    int answer;
    cin >> answer;

    //4. Grade the answer and display the result
    if (number1 - number2 == answer)
        cout << "You are correct!";
    else
       cout << "Your answer is wrong.\n" << number1 << " - " << number2 << " should be " << (number1 - number2) << endl;
    */

    using namespace std;

    // 1. Generate two random integers less than 100
    srand(time(0));
    int number1 = rand() % 99;
    int number2 = rand() % 99;

    // 3. Prompt the student to answer "What is number1 + number2 + number3?"
    cout << "What is " << number1 << " + " << number2 << "? ";
    int answer;
    cin >> answer;

    //4. Grade the answer and display the result
    if (number1 + number2 == answer)
        cout << "You are correct!";
    else
        cout << "Your answer is wrong.\n" << number1 << " + " << number2 << " should be " << (number1 + number2) << endl;

}

void Chapter3Exercises::Exercise3_10() {

    /* My solution to Problem 3.10 covering Sections 3.2-3.10 in Chapter 3 (* difficulty)
     *
     * (Game: Addition Quiz) Listing 3.5, SubtractionQuiz.cpp, randomly generates a subtraction quiz. Revise the
     * program to randomly generate an addition question with three integers less than 100.
     *
     * //SubtractionQuiz.cpp (below) is taken directly from the book and is not my solution, for consistency.
     *
    #include <iostream>
    #include <ctime>
    #include <cstdlib>
    using namespace std;

    // 1. Generate two random single-digit integers
    srand(time(0));
    int number1 = rand() % 10;
    int number2 = rand() % 10;

    // 2. If number1 < number2, swap number1 with number2
    if (number1 < number2)
    {
       int temp = number1;
       number1 = number2;
       number2 = temp;
    }

    // 3. Prompt the student to answer "What is number1 - number2?"
    cout << "What is " << number1 << " - " << number2 << "? ";
    int answer;
    cin >> answer;

    //4. Grade the answer and display the result
    if (number1 - number2 == answer)
        cout << "You are correct!";
    else
       cout << "Your answer is wrong.\n" << number1 << " - " << number2 << " should be " << (number1 - number2) << endl;
    */

    using namespace std;

    // 1. Generate three random integers less than 100
    srand(time(0));
    int number1 = rand() % 99;
    int number2 = rand() % 99;
    int number3 = rand() % 99;

    // 3. Prompt the student to answer "What is number1 + number2 + number3?"
    cout << "What is " << number1 << " + " << number2 << " + " << number3 << "? ";
    int answer;
    cin >> answer;

    //4. Grade the answer and display the result
    if (number1 + number2 + number3 == answer)
        cout << "You are correct!";
    else
        cout << "Your answer is wrong.\n" << number1 << " + " << number2 << " + " << number3 << " should be " << (number1 + number2 + number3) << endl;

}

void Chapter3Exercises::Exercise3_11() {

    /* My solution to Problem 3.11 covering Sections 3.2-3.10 in Chapter 3 (* difficulty)
     *
     * (Game: Guess a Number) Write a program that lets the user guess a number and see if it matches a random
     * number generated by the program. The program randomly generates an integral number between 1 and 100. The
     * program prompts the user to enter a guess and reports if the guess matched the number generated by the program.
     */
    using namespace std;

    srand(time(0));

    int randomInteger, userGuess;
    // Generates a random integer between [1,100]
    randomInteger = rand() % 100 + 1;

    // Prompts user for their guess
    cout << "Guess an integer from 1 to 100 (including these limits): ";
    cin >> userGuess;

    // Informs the user if they were correct. If not, they are told the randomly generated number
    if (randomInteger == userGuess)
        cout << "You guessed correctly!" << endl;
    else
        cout << "You guessed incorrectly. The correct number was " << randomInteger << endl;

}

void Chapter3Exercises::Exercise3_12() {

    /* My solution for Problem 3.12 covering Sections 3.2-3.10 in Chapter 3. (* difficulty)
     *
     * (Health Application: BMI) Revise Listing 3.3, ComputeBMI.cpp, to let the user enter weight,
     * feet, and inches. For example, if a person is 5 feet and 10 inches, you will enter 5 for feet
     * and 10 for inches.
     *
     * For consistency, the code will build upon the code from Listing 3.3 (below) */
    /*
    // ComputeBMI.cpp
    using namespace std;

    // Prompt the user to enter weight in pounds
    cout << "Enter weight in pounds: ";
    double weight;
    cin >> weight;

    // Prompt the user to enter height in inches
    cout << "Enter height in inches: ";
    double height;
    cin >> height;

    const double KILOGRAMS_PER_POUND = 0.45359237; // Constant
    const double METERS_PER_INCH = 0.0254; // Constant

    // Compute BMI
    double weightInKilogram = weight * KILOGRAMS_PER_POUND;
    double heightInMeter = height * METERS_PER_INCH;
    double bmi = weightInKilogram / (heightInMeter * heightInMeter);

    // Display result
    cout << "Your BMI is " << bmi << endl;
    if (bmi < 16)
        cout << "You are seriously underweight" << endl;
    else if (bmi < 18)
        cout << "You are underweight" << endl;
    else if (bmi < 24)
        cout << "You are normal weight" << endl;
    else if (bmi < 29)
        cout << "You are overweight" << endl;
    else if (bmi < 35)
        cout << "You are seriously overweight" << endl;
    else
        cout << "You are gravely overweight" << endl;
    */

    using namespace std;

    // Prompt the user to enter weight in pounds
    cout << "Enter weight in pounds: ";
    double weight;
    cin >> weight;

    // Prompt the user to enter height
    cout << "Enter height in feet and inches (e.g. 5ft 10in would be 5 10): ";
    double heightInches, heightFeet;
    cin >> heightFeet >> heightInches;

    const double KILOGRAMS_PER_POUND = 0.45359237; // Constant
    const double METERS_PER_INCH = 0.0254; // Constant
    const double INCHES_PER_FEET = 12.0;

    // Compute BMI
    double height = heightFeet * INCHES_PER_FEET + heightInches;
    double weightInKilogram = weight * KILOGRAMS_PER_POUND;
    double heightInMeter = height * METERS_PER_INCH;
    double bmi = weightInKilogram / (heightInMeter * heightInMeter);

    // Display result
    cout << "Your BMI is " << bmi << endl;
    if (bmi < 16)
        cout << "You are seriously underweight" << endl;
    else if (bmi < 18)
        cout << "You are underweight" << endl;
    else if (bmi < 24)
        cout << "You are normal weight" << endl;
    else if (bmi < 29)
        cout << "You are overweight" << endl;
    else if (bmi < 35)
        cout << "You are seriously overweight" << endl;
    else
        cout << "You are gravely overweight" << endl;
}

void Chapter3Exercises::Exercise3_13() {

    /* My solution to Problem 3.13 covering Sections 3.11-3.17 in Chapter 3 (*** difficulty)
     *
     * (Game: lottery) Revise Listing 3.8, Lottery.cpp, to generate a lottery of a three-digit number. The
     * program prompts the user to enter a three-digit number abd determines whether the user wins according to
     * the following rules:
     *      1. If the user input matches the lottery in exact order, the award is ¢10,000
     *      2. If the user input matches the lottery, the award is ¢3,000
     *      3. If one digit in the user input matches a digit in the lottery, the award is ¢1,000
     *
     * For consistency, this will be built upon the code from Lottery.cpp (below)*/

    /*
    //Lottery.cpp
    using namespace std;

    // Generate a lottery
    srand(time(0));
    int lottery = rand() % 100;

    // Prompt the user to enter a guess
    cout << "Enter your lottery pick (two digits): ";
    int guess;
    cin >> guess;

    // Get digits from lottery
    int lotteryDigit1 = lottery / 10;
    int lotteryDigit2 = lottery % 10;

    // Get digits from guess
    int guessDigit1 = guess / 10;
    int guessDigit2 = guess % 10;

    cout << "The lottery number is " << lottery << endl;

    // Check the guess
    if (guess == lottery)
        cout << "Exact match: you win $10,000" << endl;
    else if (guessDigit2 == lotteryDigit1
            && guessDigit1 == lotteryDigit2)
        cout << "Match all digits: you win $3,000" << endl;
    else if (guessDigit1 == lotteryDigit1
          || guessDigit1 == lotteryDigit2
          || guessDigit2 == lotteryDigit1
          || guessDigit2 == lotteryDigit2)
        cout << "Match one digit: you win $1,000" << endl;
    else
        cout << "Sorry, no match" << endl;
    */

    using namespace std;

    // Generate a lottery
    srand(time(0));
    int lottery = rand() % 1000;

    // Prompt the user to enter a guess
    cout << "Enter your lottery pick (three digits): ";
    int guess;
    cin >> guess;

    // Get digits from lottery
    int lotteryDigit1 = lottery / 100;
    int lotteryDigit2 = (lottery / 10) % 10;
    int lotteryDigit3 = lottery % 10;

    // Get digits from guess
    int guessDigit1 = guess / 100;
    int guessDigit2 = (guess / 10) % 10;
    int guessDigit3 = guess % 10;

    cout << "The lottery number is " << lottery << endl;

    // Check the guess
    if (guess == lottery)
        cout << "Exact match: you win $10,000" << endl;
    else if ((guessDigit1 == lotteryDigit2 || guessDigit1 == lotteryDigit3)
           &&(guessDigit2 == lotteryDigit1 || guessDigit2 == lotteryDigit3)
           &&(guessDigit3 == lotteryDigit1 || guessDigit3 == lotteryDigit2))
        cout << "Match all digits: you win $3,000" << endl;
    else if (guessDigit1 == lotteryDigit1
             || guessDigit1 == lotteryDigit2
             || guessDigit1 == lotteryDigit3
             || guessDigit2 == lotteryDigit1
             || guessDigit2 == lotteryDigit2
             || guessDigit2 == lotteryDigit3
             || guessDigit3 == lotteryDigit1
             || guessDigit3 == lotteryDigit2
             || guessDigit3 == lotteryDigit3)
        cout << "Match one digit: you win $1,000" << endl;
    else
        cout << "Sorry, no match" << endl;
}

void Chapter3Exercises::Exercise3_14() {

    /* My solution to Problem 3.14 covering Sections 3.11-3.17 in Chapter 3 (* difficulty)
     *
     * (Game: scissors, rock, paper) Write a program that plays the popular scissors-rock-paper game. (Scissors
     *  can cut a paper, a rock can knock scissors, and a paper can wrap a rock.) The program randomly
     * generates a number 0, 1, or 2, representing scissor, rock, or paper. It prompts the user to enter a number
     * 0, 1, or 2, and displays a message indicating whether the user or the computer wins or draws*/

    using namespace std;

    srand(time(0));

    unsigned short userHand, computerHand;

    // Prompt user to enter their move for the game scissors-rock-paper
    cout << "The codes for each move are:\n" <<
            " - 0 : Scissors\n" <<
            " - 1 : Rock\n" <<
            " - 2 : Paper\n" <<
            "Enter your move: ";
    cin >> userHand;

    // Sets the computers hand according the questions conditions (0: SCISSORS, 1: ROCK, 2: PAPER)
    computerHand = rand() % 3;
    // New line to make console output more readable
    cout << "\n";

    // Switch to handle each of the user's choices. Nested IF statement deals with whether the user won, lost or drew.
    switch (userHand) {
        case 0:
            if (computerHand == 2)
                cout << "You won! Your SCISSORS beat the computer's PAPER!" << endl;
            else if (computerHand == 1)
                cout << "You lost! Your SCISSORS fell to the computer's ROCK!" << endl;
            else if (computerHand == userHand)
                cout << "You drew! The computer also used SCISSORS!" << endl;
            break;

        case 1:
            if (computerHand == 0)
                cout << "You won! Your ROCK beat the computer's SCISSORS!" << endl;
            else if (computerHand == 2)
                cout << "You lost! Your ROCK fell to the computer's PAPER!" << endl;
            else if (computerHand == userHand)
                cout << "You drew! The computer also used ROCK!" << endl;
            break;

        case 2:
            if (computerHand == 1)
                cout << "You won! Your PAPER beat the computer's ROCK" << endl;
            else if (computerHand == 0)
                cout << "You lost! Your PAPER fell to the computer's SCISSORS!" << endl;
            else if (computerHand == userHand)
                cout << "You drew! The computer also used PAPER!" << endl;
            break;

        default:
            cout << "This match encountered an error." << endl;
            break;
    }
}

void Chapter3Exercises::Exercise3_15() {

    /* My solution to Problem 3.15 covering Sections 3.11-3.17 in Chapter 3. (* difficulty)
     *
     * (Science: wind chill temperature) Exercise 2.15 includes a formula to compute wind chill temperature.
     * The formula:
     *
     *      t_wc = 35.74 + 0.6215 * ta - 35.75 * pow(v, 0.16) + 0.4275 * ta * pow(v,0.16)
     *
     * is valid for temperatures in the range -58 Fahrenheit to +41 Fahrenheit, where the wind speed
     * is greater than or equal to 2.
     *
     * Write a program that prompts the user to enter a temperature and a wind speed. Check whether the
     * input values are valid. If not, display a message indicating which value(s) are invalid. If both
     * input values are valid, display the resulting wind chill value.*/

    using namespace std;

    double ambientTemperature, windChillTemperature, windSpeed;

    // Prompt user for ambient temperature within the accepted range
    cout << "Enter a temperature in Fahrenheit, between -58F and 41F: ";
    cin >> ambientTemperature;

    // Check if the temperature is in the accepted range, and exit if it is not
    if (ambientTemperature < -58.0 || ambientTemperature > 41.0) {
        cout << "You entered a temperature of " << ambientTemperature << "F.\n" <<
             "This is out with the accepted range of -58F to 41F." << endl;
        exit(0);
    }

    // Prompt user for a wind speed
    cout << "Enter a wind speed (v) in feet per second, where v > 2f/s: ";
    cin >> windSpeed;

    // Exit program if the wind speed is out with the accepted range
    if (windSpeed < 2.0) {
        cout << "You entered a wind speed of " << windSpeed << "f/s.\n" <<
             "This is out with the accepted range, as it must be >= 2f/s." << endl;
        exit(0);
    }

    // Calculate the wind chill temperature from the given formula
    windChillTemperature = 35.74 + 0.6215 * ambientTemperature - 35.75 * pow(windSpeed, 0.16) +
                           0.4275 * ambientTemperature * pow(windSpeed, 0.16);

    // Display the formula to the user
    cout << "\nThe wind chill temperature is " << windChillTemperature << "F" << endl;

}

void Chapter3Exercises::Exercise3_16() {

    /* My solution to Problem 3.16 covering Sections 3.11-3.17 in Chapter 3
     *
     * (Computing the perimeter of a triangle) Write a program that reads three edges for a triangle and computes
     * the perimeter if the input is valid. Otherwise, display that the input is invalid. The input is valid
     * if the sum of any two edges is greater than the third edge.*/

    using namespace std;

    // Length of each edge of the triangle
    double length1,length2, length3;

    // Prompts user for input of lengths
    cout << "Enter the lengths of each edge of the triangle: ";
    cin >> length1 >> length2 >> length3;

    // Use < as > would often lead to the first condition being TRUE and then the following tests not being completed
    if ((length1 + length2 < length3)
      ||(length1 + length3 < length2)
      ||(length2 + length3 < length1))
        cout << "Invalid entry as the sum of two sides is not greater than the third" << endl;
    else
        cout << "The perimeter of this triangle is " << (length1 + length2 + length3) << endl;
}

void Chapter3Exercises::Exercise3_17() {

    /* My solution to Problem 3.17 covering Sections 3.11-3.17 in Chapter 3 (** difficulty)
     *
     * (Business: checking ISBN) An ISBN (International Standard Book Number) consists of 10 digits
     * d1-d2-d3-d4-d5-d6-d7-d8-d9-d10 (without the hyphens). The last digit d10 is a checksum which
     * is calculated from the other 9 digits using the following formula:
     *
     *       (d1*1 + d2*2 + d3*3 + d4*4 + d5*5 + d6*6 + d7*7 + d8*8 + d9*9) % 11
     *
     * According to the ISBN convention, if the checksum is 10, the last digit is denoted X. Write a
     * program that prompts the user to enter the first 9 digits and displays the 10-digit ISBN (including
     * leading zeros). Your program should read the input as an integer.*/

    using namespace std;

    int inputDigits, d1, d2, d3, d4, d5, d6, d7, d8, d9, checksum;

    // Prompts user for input as a single number (I believe this is easier to input that a 9 digit space separated list
    cout << "Enter the first nine digits as integers of your ISBN: ";
    cin >> inputDigits;

    // Finds each ISBN digit. Written using Scientific Notation to illustrate finding digits in base10 system.
    d9 = inputDigits / static_cast<int>(1e0) % 10;
    d8 = inputDigits / static_cast<int>(1e1) % 10;
    d7 = inputDigits / static_cast<int>(1e2) % 10;
    d6 = inputDigits / static_cast<int>(1e3) % 10;
    d5 = inputDigits / static_cast<int>(1e4) % 10;
    d4 = inputDigits / static_cast<int>(1e5) % 10;
    d3 = inputDigits / static_cast<int>(1e6) % 10;
    d2 = inputDigits / static_cast<int>(1e7) % 10;
    d1 = inputDigits / static_cast<int>(1e8) % 10;

    // Finds the 10th digit, which is found by doing a 'checksum' of the other 9 digits
    checksum = (d1*1 + d2*2 + d3*3 + d4*4 + d5*5 + d6*6 + d7*7 + d8*8 + d9*9) % 11;

    // Tests if the checksum is equal to the special condition from the problem. Output format with hyphens is
    // from standard ISBN10 formatting.
    if (checksum == 10)
        cout << "Your ISBN is: " << d1 << "-"
             << d2 << d3 << "-"
             << d4 << d5 << d6 << d7 << d8 << d9 << "-"
             << "X" << endl;
    else
        cout << "Your ISBN is: " << d1 << "-"
                                 << d2 << d3 << "-"
                                 << d4 << d5 << d6 << d7 << d8 << d9 << "-"
                                 << checksum << endl;
}

void Chapter3Exercises::Exercise3_18() {

    /* My solution to Problem 3.18 covering Sections 3.11-3.17 in Chapter 3 (** difficulty)
     *
     * (Finding the number of days in a month) Write a program that prompts the user to enter the year and month in
     * this order, and displays the number of days in the month. For example, if the user entered month 2 and year
     * 2000, the program should display that February 2000 has 29 days. If the user entered month 3 and year 2005, the
     * program should display that March 2005 has 31 days*/

    using namespace std;

    int month, year;
    bool isLeapYear;

    cout << "Enter the month using the code (1-January, ... , 12-December): ";
    cin >> month;

    cout << "Enter the year: ";
    cin >> year;

    // Code to find if isLeapYear comes from Listing3.7 (Section 3.12) in Chapter 3
    isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // Separate case for each month, with an IF statement for February
    switch(month){

        case 1:
            cout << "January " << year << " has 31 days" << endl;
            break;

        case 2:
            if (isLeapYear)
                cout << "February " << year << " has 29 days" << endl;
            else
                cout << "February " << year << " has 28 days" << endl;
            break;

        case 3:
            cout << "March " << year << " has 31 days" << endl;
            break;

        case 4:
            cout << "April " << year << " has 30 days" << endl;
            break;

        case 5:
            cout << "May " << year << " has 31 days" << endl;
            break;

        case 6:
            cout << "June " << year << " has 3 days" << endl;
            break;

        case 7:
            cout << "July " << year << " has 31 days" << endl;
            break;

        case 8:
            cout << "August " << year << " has 31 days" << endl;
            break;

        case 9:
            cout << "September " << year << " has 30 days" << endl;
            break;

        case 10:
            cout << "October " << year << " has 31 days" << endl;
            break;

        case 11:
            cout << "November " << year << " has 30 days" << endl;
            break;

        case 12:
            cout << "December " << year << " has 31 days" << endl;
            break;

        default:
            cout << "You entered a month that doesn't exist. Exiting" << endl;
            exit(0);
    }
}

void Chapter3Exercises::Exercise3_19() {

    /* My solution for Problem 3.19 covering Sections 3.11-3.17 in Chapter 3 (** difficulty)
     *
     * Geometry: point in a circle?) Write a program that prompts the user to enter a point (x,y) and checks whether
     * the point is within the circle centered at (0,0) with radius 10. For example, (4,5) is inside the circle and
     * (9,9) is outside the circle, as shown in Fig 3.6(a)
     *
     * (Hint: A point is in the circle if its distance to (0,0) is less than or equal to 10. The formula for computing
     * the distance is sqrt( (x2-x1)**2 + (y2-y1)**2 ) */

    using namespace std;

    double centreX, centreY, userX, userY, radius;
    bool isInCircle;

    // Initialisation according to question parameters
    radius = 10; centreX = 0; centreY = 0;

    cout << "Find if a point (x,y) lies within a circle centered at (" << centreX << ", " << centreY << ") "
         << "which has a radius of " << radius << endl;
    cout << "Enter point coordinates as integers (e.g. for (5,4) enter 5 4): ";
    cin >> userX >> userY;

    /*
     * Using conditional statement purely for practice. In reality, the bool isInCircle is redundant as the conditional
     * statement could be included within the condition of the IF statement e.g. :
     * if (sqrt(pow((userX - centreX),2) + pow((userY - centreY),2)) < radius)
     *      cout << "text";
     */
    isInCircle = (sqrt(pow((userX - centreX),2) + pow((userY - centreY),2)) < radius) ? true : false;

    cout << setprecision(2);
    if (isInCircle)
        cout << "The point (" << showpoint <<  userX << ", " << userY << ") is in the circle" << endl;
    else
        cout << "The point (" << showpoint << userX << ", " << userY << ") is not in the circle" << endl;

}

void Chapter3Exercises::Exercise3_20() {

    /* My solution to Problem 3.20 covering Sections 3.11-3.17 in Chapter 3 (** difficulty)
     *
     * (Geometry: point in a rectangle?) Write a program that prompts the user to enter a point (x,y) and checks
     * whether it is within the rectangle centered at (0,0 with width 10 and height 5. for example, (2, 1.1) is inside
     * the rectangle and (6,2) is outside the rectangle, as shown in Fig 3.6(b).
     *
     * (Hint: A point is in the rectangle if its horizontal distance to (0,0) is less than or equal to 10/2 nad its
     * vertical distance to (0,0) is less than or equal to 5/2) Note: The values of 10 and 5 given in the hint come
     * from how the question was defined.*/

    using namespace std;

    double width, height, centreX, centreY; // Declare preset conditions
    double userX, userY; // Declare user inputs

    centreX = 0; centreY = 0;
    width = 10;
    height = 5;

    // Inform user of preset parameters before taking their input using format given in question
    cout << "Enter a point with two coordinates: ";
    cin >> userX >> userY;

    cout << setprecision(2);
    if ((userX <= width / 2) && (userY <= height / 2))
        cout << "Point (" << showpoint << userX << ", " << userY << ") is in the rectangle" << endl;
    else
        cout << "Point (" << showpoint << userX << ", " << userY << ") is not the rectangle" << endl;
}

void Chapter3Exercises::Exercise3_21() {

    /* My solution to Problem 3.21 covering Sections 3.11-3.17 in Chapter 3 (** difficulty)
     *
     * (Game: pick a card) Write a program that simulates picking a card from a deck of 52 cards. For each card your
     * program should display the rank (Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King) and suit (Clubs, Diamonds,
     * Hearts, Spades).
     */

    using namespace std;

    // Seeds rand() to start time
    srand(time(0));

    int randomRank, randomSuit;
    string cardName, cardSuit;

    randomRank = rand() % 13;
    randomSuit = rand() % 4;

    // Use randomly selected int to find which card is selected. Only need special conditions for named cards like
    // 'King' as a cast works well otherwise
    switch (randomRank) {
        case 0:
            cardName = "Ace";
            break;

        case 10:
            cardName = "Jack";
            break;

        case 11:
            cardName = "Queen";
            break;

        case 12:
            cardName = "King";
            break;

        default:
            cardName = to_string(randomRank);
    }

    // Uses randomly generated int to select the suit name
    switch (randomSuit) {

        case 0:
            cardSuit = "Clubs";
            break;

        case 1:
            cardSuit = "Diamonds";
            break;

        case 2:
            cardSuit = "Hearts";
            break;

        case 3:
            cardSuit = "Spades";
            break;
    }

    // Output to console using format given in question
    cout << "The card you picked is " << cardName << " of " << cardSuit << endl;
}

void Chapter3Exercises::Exercise3_22() {

    /* My solution to Problem 3.22 covering Sections 3.11-3.17 in Chapter 3
     *
     * (Using the && and || operators) Write a program that prompts the user to enter an integer and determines whether
     * it is divisible by 5 and 6, whether it is divisible by 5 or 6, and whether it is divisible by 5 or 6 but not
     * both. Note: This is almost identical to Listing 3.6*/

    using namespace std;

    int userNumber;

    // Prompts user for integer input
    cout << "Enter an integer: ";
    cin >> userNumber;

    // Checks if number divisible by both. First line of cout is out with loop to reduce repetition
    cout << "Is divisible by 5 and 6? ";
    if (userNumber % 5 == 0 && userNumber % 6 == 0)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    // Checks if number divisible by at least one
    cout << "Is divisible by 5 or 6? ";
    if (userNumber % 5 == 0 || userNumber % 6 == 0)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    // Checks if number divisible by at least one but not both
    cout << "Is divisible by 5 or 6, but not both? ";
    if ((userNumber % 5 == 0 || userNumber % 6 == 0) &&
        (userNumber % 5 != 0 || userNumber % 6 != 0))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

void Chapter3Exercises::Exercise3_23() {

    /* My solution to Problem 3.23 covering Sections 3.11-3.17 in Chapter 3 (* difficulty)
     *
     * (Validating Triangles) Write a program that reads three edges for a triangle and determines whether the input
     * is valid. The input is valid if the sum of any two edges is greater than the third.
     */

    using namespace std;

    double edge1, edge2, edge3;

    // Prompt user for three edges as a space separated list
    cout << "Enter three edges: ";
    cin >> edge1 >> edge2 >> edge3;

    // Output to console using question's format
    cout << "Can edges " << edge1 << ", " << edge2 << ", and " << edge3 << " form a triangle? ";

    // Using conditional statement for practice here as operators will give boolean outputs
    cout << ((edge1 + edge2 < edge3 ||edge1 + edge3 < edge2 ||edge2 + edge3 < edge1) ? "false" : "true");
}

void Chapter3Exercises::Exercise3_24() {

    /* My solution to Problem 3.24 covering Sections 3.11-3.17 in Chapter 3 (* difficulty)
     *
     * (Phone key pads) The international standard letter/number mapping found on the telephone is shown below:
     *
     *       1          2 ABC     3 DEF
     *       4 GHI      5 JKL     6 MNO
     *       7 PQRS     8 TUV     9 WXYZ
     *                  0
     *
     * Write a program that prompts the user to enter an uppercase letter and displays its corresponding number
     */

    using namespace std;

    char uppercaseLetter;
    int telephoneNumber;

    cout << "Enter an uppercase letter: ";
    cin >> uppercaseLetter;

    // Outputs to console using given format in question. The values in the IF statement conditions come from the
    // ASCII character set in Decimal Index. No need to cast char dtype, as char is already an int
    if (uppercaseLetter >= 65 && uppercaseLetter <= 67)
        cout << "The corresponding number is 2" << endl;
    else if (uppercaseLetter >= 68 && uppercaseLetter <= 70)
        cout << "The corresponding number is 3" << endl;
    else if (uppercaseLetter >= 71 && uppercaseLetter <= 73)
        cout << "The corresponding number is 4" << endl;
    else if (uppercaseLetter >= 74 && uppercaseLetter <= 76)
        cout << "The corresponding number is 5" << endl;
    else if (uppercaseLetter >= 77 && uppercaseLetter <= 79)
        cout << "The corresponding number is 6" << endl;
    else if (uppercaseLetter >= 80 && uppercaseLetter <= 83)
        cout << "The corresponding number is 7" << endl;
    else if (uppercaseLetter >= 84 && uppercaseLetter <= 86)
        cout << "The corresponding number is 8" << endl;
    else if (uppercaseLetter >= 87 && uppercaseLetter <= 90)
        cout << "The corresponding number is 9" << endl;
    else
        cout << "Invalid input" << endl;
}

void Chapter3Exercises::Exercise3_25() {

    /* My solution to Problem 3.25 covering Sections 3.11-3.17 in Chapter 3 (** difficulty)
     *
     * (Geometry: points in triangle?) Suppose a right triangle is placed in a two-dimensional plane as shown below:
     *
     *  (in Figure, vertices are at (0,0), (0,100), and (200,0) with the whole triangle being shaded grey and fully
     *  lying in the upper-right quadrant)
     *
     * The right angle point is placed at (0,0), and the other two points are placed at (200,0), and (0,100). Write
     * a program that prompts the user to enter a point with x- and y-coordinates and determines whether the point is
     * inside the triangle.*/

    using namespace std;

    // Declare preset conditions from question
    double x1, y1, x2, y2, x3, y3, areaABC, areaPBC, areaPAC, areaPAB;

    x1 = 0; y1 = 0;
    x2 = 200; y2 = 0;
    x3 = 0; y3 = 100;

    // Declare user inputs separately for ease of reading
    double userX, userY;

    // Prompt user for input of their point's coordinates
    cout << "Enter a point's x- and y-coordinates: ";
    cin >> userX >> userY;

    /* Intentionally did not use Barycentric coordinates here as these aren't intuitive for first-time users. Instead,
     * exploited checking the areas of triangles. For a given triangle ABC, if a point P is placed then the areas of
     * PAC + PBC + PCA must sum to the area of ABC for the point to lie within the triangle */

    // Calcuate areas of each triangle
    areaABC = abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
    areaPBC = abs((userX*(y2-y3) + x2*(y3-userY)+ x3*(userY-y2))/2.0);
    areaPAC = abs((x1*(userY-y3) + userX*(y3-y1)+ x3*(y1-userY))/2.0);
    areaPAB = abs((x1*(y2-userY) + x2*(userY-y1)+ userX*(y1-y2))/2.0);

    // Test boolean condition to see if point is inside triangle ABC. Only an exact match of areas will work
    if (areaABC == areaPBC + areaPAC + areaPAB)
        cout << "The point is in the triangle" << endl;
    else
        cout << "The point is not in the triangle" << endl;
}
#include "Chapter3Listings.h"

void Chapter3Listings::SimpleIfDemo() {

    // My solution to the problem in Listing3.1 in Chapter 3, Section 3.3

    using namespace std;

    int userInputInteger;

    // Receives user input
    cout << "Enter an integer:";
    cin >> userInputInteger;

    if (userInputInteger % 5 == 0){
        // Example IF statement to indicate whether an inputted value is a multiple of 5
        cout << "HiFive" << endl;
    }

    if (userInputInteger % 2 == 0) {
        // Separate example IF statement to indicate whether an inputted value is even
        cout << "HiEven" << endl;
    }
}

void Chapter3Listings::GuessBirthDate() {

    // My solution to problem in Listing 3.2 in Chapter 3, Section 3.4

    using namespace std;

    unsigned short birthDay;
    birthDay = 0;
    char answerToQuestion;

    // Query the user if their birthdate is in Set 1
    cout << "\nHere is a list of numbers that comprised Set(1):\n"
         << "1, 3, 5, 7,\n"
         <<"9, 11, 13, 15,\n"
         <<"17, 19, 21, 23,\n"
         <<"25, 27, 29, 31." << endl;
    cout << R"(If your birthdate is in Set(1), enter Y for 'Yes'. Otherwise enter N for 'No': )";
    cin >> answerToQuestion;

    if (answerToQuestion == 'Y') {
        birthDay += 1;
    }

    // Query the user if their birthdate is in Set 2
    cout << "\nHere is a list of numbers that comprised Set(2):\n"
         << "2, 3, 6, 7,\n"
         <<"10, 11, 14, 15,\n"
         <<"18, 19, 22, 23,\n"
         <<"26, 27, 30, 31." << endl;
    cout << R"(If your birthdate is in Set(2), enter Y for 'Yes'. Otherwise enter N for 'No': )";
    cin >> answerToQuestion;

    if (answerToQuestion == 'Y') {
        birthDay += 2;
    }

    // Query the user if their birthdate is in Set 3
    cout << "\nHere is a list of numbers that comprised Set(3):\n"
         << "4, 5, 6, 7,\n"
         <<"12, 13, 14, 15,\n"
         <<"20, 21, 22, 23,\n"
         <<"28, 29, 30, 31." << endl;
    cout << R"(If your birthdate is in Set(3), enter Y for 'Yes'. Otherwise enter N for 'No': )";
    cin >> answerToQuestion;

    if (answerToQuestion == 'Y') {
        birthDay += 4;
    }

    // Query the user if their birthdate is in Set 4
    cout << "\nHere is a list of numbers that comprised Set(4):\n"
         << "8, 9, 10, 11,\n"
         <<"12, 13, 14, 15,\n"
         <<"24, 25, 26, 27,\n"
         <<"28, 29, 30, 31." << endl;
    cout << R"(If your birthdate is in Set(4), enter Y for 'Yes'. Otherwise enter N for 'No': )";
    cin >> answerToQuestion;

    if (answerToQuestion == 'Y') {
        birthDay += 8;
    }

    // Query the user if their birthdate is in Set 5
    cout << "\nHere is a list of numbers that comprised Set(5):\n"
         << "16, 17, 18, 19,\n"
         <<"20, 21, 22, 23,\n"
         <<"24, 25, 26, 27,\n"
         <<"28, 29, 30, 31." << endl;
    cout << R"(If your birthdate is in Set(5), enter Y for 'Yes'. Otherwise enter N for 'No': )";
    cin >> answerToQuestion;

    if (answerToQuestion == 'Y') {
        birthDay += 16;
    }

    cout << "\nYour birthdate is " << birthDay << "." << endl;
}

void Chapter3Listings::ComputeBMI() {

    // My solution to the problem in Listing 3.3 in Chapter 3, Section 3.8

    using namespace std;

    double weightPounds, weightKilos, heightInch, heightM, bmiValue;

    // Uses conversion rates given in the book to go from [lb] -> [kg] and [in] -> [m]
    const double POUNDS_TO_KILO = 0.45359237; ;
    const double INCH_TO_METRE = 0.0254;

    // Interact with user to receive their weight in pounds
    cout << "Enter your weight in pounds (lb): ";
    cin >> weightPounds;

    // Convert weight into [kg]
    weightKilos = weightPounds * POUNDS_TO_KILO;

    // Interact with user to receive their height in inches
    cout << "Enter your height in inches (\"): ";
    cin >> heightInch;

    // Convert height into [m]
    heightM = heightInch * INCH_TO_METRE;

    // Calculates BMI
    bmiValue = weightKilos / (heightM * heightM);

    // Outputs the BMI value to the console
    cout << "Your BMI (Body Mass Index) is: " << bmiValue << "." << endl;

    /* Prepares the statement of informing the user how their BMI has been interpreted. No new line is intentional to
     * enable the conclusion to be appended the string below*/
    cout << "Your BMI is interpreted as meaning you are ";

    // Categorises the user's BMI based upon the table presented in the problem description
    if (bmiValue <= 0) {
        // Small separate
        cout << "...\n ERROR. Your BMI was calculated as being less than zero. Please try again." << endl;
    } else if (bmiValue < 16) {
        cout << "seriously underweight." << endl;
    } else if (bmiValue < 18) {
        cout << "underweight." << endl;
    } else if (bmiValue < 24) {
        cout << "of a normal weight." << endl;
    } else if (bmiValue < 29) {
        cout << "overweight." << endl;
    } else if (bmiValue < 35) {
        cout << "seriously overweight." << endl;
    } else {
        cout << "gravely overweight." << endl;
    }
}

void Chapter3Listings::ComputeTaxes() {

    // My solution to the problem in Listing 3.4 in Chapter 3, Section 3.9

    using namespace std;

    unsigned int filingStatus;
    double taxableIncome, payableTax;
    unsigned int taxRateBand1, taxRateBand2, taxRateBand3, taxRateBand4, taxRateBand5;

    // Informs the user of the different tax statuses they can select
    cout << "The filing status codes for this program are:"
         << "\n- 0 = Single Filers"
         << "\n- 1 = Married Filing Jointly / Qualifying Widow/Widower"
         << "\n- 2 = Married Filing Separately"
         << "\n- 3 = Head of Household"
         << "\n\nEnter your filing status: ";
    cin >> filingStatus;

    // Prompts the user to input their filing status
    cout << "Enter your taxable income in US Dollars: $";
    cin >> taxableIncome;

    // Sets the tax band (upper) limits based upon the filing status of the user
    if (filingStatus == 0) {
        // Calculate tax band limits for 'Single Filers'
        taxRateBand1 = 6000;
        taxRateBand2 = 27950;
        taxRateBand3 = 67700;
        taxRateBand4 = 141250;
        taxRateBand5 = 307050;
    } else if (filingStatus == 1){
        // Calculate tax band limits for 'Married Filing Jointly' or 'Qualifying Widow/Widower'
        taxRateBand1 = 12000;
        taxRateBand2 = 46700;
        taxRateBand3 = 112850;
        taxRateBand4 = 171950;
        taxRateBand5 = 307050;
    } else if (filingStatus == 2){
        // Calculate tax band limits for 'Married Filing Separately'
        taxRateBand1 = 6000;
        taxRateBand2 = 23350;
        taxRateBand3 = 56425;
        taxRateBand4 = 85975;
        taxRateBand5 = 153525;
    } else if (filingStatus == 3) {
        // Calculate tax band limits for 'Head of Household'
        taxRateBand1 = 10000;
        taxRateBand2 = 37450;
        taxRateBand3 = 96700;
        taxRateBand4 = 156600;
        taxRateBand5 = 307050;
    } else {
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
    cout << "\nThe personal tax that you must pay is $" << payableTax << ".";
}

void Chapter3Listings::SubtractionQuiz() {

    // My solution to the problem in Listing 3.5 in Chapter 3, Section 3.10

    // Each step (referenced in comments) refers to the stated steps of the problem, which can be found in the book
    using namespace std;

    // Uses the current time (in seconds; total seconds since UNIX epoch) as a seed for rand()
    srand(time(0));

    // Step 1. Generate two single-digit integers into number1 and number2
    int number1, number2, studentsAnswer, trueAnswer;
    number1 = rand() % 10;
    number2 = rand() % 10;
    // Step 2. If number1 < number2, swap number1 with number2
    if (number1 < number2){
        // tempNumber only has scope within this IF statement
        int tempNumber;
        tempNumber = number1;
        number1 = number2;
        number2 = tempNumber;
    }

    // Computes the correct answer to reduce multiple calculations of it later on; more efficient
    trueAnswer = number1 - number2;

    // Step 3. Prompt the student to answer "What is number1 - number2?"
    cout << "What is " << number1 << " - " << number2 << "?\n";
    cout << "Your answer: ";
    cin >> studentsAnswer;

    // Step 4. Check the student's answer and display whether it is correct.
    if (studentsAnswer == trueAnswer) {
        cout << "Your answer is correct!" << endl;
    } else {
        cout << "Your answer is incorrect.\n"
             << number1 << " - " << number2 << " = " << trueAnswer << endl;
    }
}

void Chapter3Listings::TestBooleanOperators() {

    // My solution to the problem in Listing 3.6 in Chapter 3, Section 3.11

    using namespace std;

    int number;
    // Prompts user for an integer
    cout << "Enter an integer: ";
    cin >> number;

    if (number % 2 == 0 && number % 3 == 0) {
        // Tests if the number is divisible by both 2 and 3.
        cout << "Your number " << number << " is divisible by 2 and 3." << endl;
    }

    if (number % 2 == 0 || number % 3 == 0) {
        // Tests if the number is divisible by 2 or 3.
        cout << "Your number " << number << " is divisible by 2 or 3." << endl;
    }

    if ((number % 2 == 0 || number % 3 == 0) && (number % 2 != 0 || number % 3 != 0)){
        // Test if the number is divisible by 2 or 3, but not both.
        cout << "Your number " << number << " is divisible by 2 or 3, but not both." << endl;
    }
}

void Chapter3Listings::LeapYear() {

    // My solution to the problem in Listing 3.7 in Chapter 3, Section 3.12

    using namespace std;

    unsigned int year;
    bool isLeapYear;

    // Prompts user for input year
    cout << "Enter a year: ";
    cin >> year;

    // Tests if the given year is a leap year based upon the three key conditions (given in the book in Section 3.12)
    isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // Displays result to user
    if (isLeapYear){
        cout << "The year " << year << " is a leap year." << endl;
    } else {
        cout << "The year " << year << " is not a leap year." << endl;
    }
}

void Chapter3Listings::Lottery() {

    // My solution to the problem in Listing 3.8 in Chapter 3, Section 3.13

    using namespace std;

    srand(time(0));
    int lotteryNumber = rand() % 100, guess;
    int lotteryDigit1, lotteryDigit2, guessDigit1, guessDigit2; // digit 1 is the tens, and digit 2 is the units

    // Informs the user of the prizes on offer
    cout << "Play the lottery! Guess a two-digit number for a chance to win. The prizes are:"
         << "\n- 1st: $10,000 (two digits match and are in the correct order)"
         << "\n- 2nd: $3,000  (two digits match)"
         << "\n- 3rd: $1,000  (one digit matches)" << endl;

    // Prompts user for their guess
    cout << "Enter your guess: ";
    cin >> guess;

    // Informs user of winning number
    cout << "\nThe lottery number is: " << lotteryNumber << "." << endl;

    // Obtains the lottery's digits
    lotteryDigit1 = lotteryNumber / 10;
    lotteryDigit2 = lotteryNumber % 10;

    // Obtains the user's digits
    guessDigit1 = guess / 10;
    guessDigit2 = guess % 10;

    if (guess == lotteryNumber) {
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

void Chapter3Listings::Test() {

    using namespace std;

    int x = 11, y = 1;

    cout << (x > 0 && x < 10) << endl;
    cout << ((x > 0) && (x < 10)) << endl;
    cout << (x > 0 || x < 10) << endl;
    cout << ((x > 0) || (x < 10)) << endl;
    cout << (x > 0 || x < 10 && y < 0) << endl;
    cout << (x > 0 || (x < 10 && y < 0)) << endl;

}
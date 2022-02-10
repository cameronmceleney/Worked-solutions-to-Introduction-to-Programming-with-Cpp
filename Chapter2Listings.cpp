#include "Chapter2Listings.h"

void Chapter2Listings::ComputeArea() {
    /* My solution to the problem of 'Compute the area of a circle' given in Listing 2
     * in Section 2.2 in Chapter 2*/

    double circleRadius, circleArea;

    // Takes user input for radius
    std::cout << "Enter the radius of the circle: ";
    std::cin >> circleRadius;

    // Calculates the area of the circle without using functions or raising to powers
    circleArea = circleRadius * circleRadius * M_PI;

    // Outputs area of circle to user
    std::cout << "The area of your circle is " << circleArea << "."<< std::endl;
}

void Chapter2Listings::ComputeAreaConsoleInput() {

    /* Their solution to Listing 2.2 in Section 2.3 in Chapter 2
     *
     * Rewrite Listing 2.1 to include taking user input. For this program, I will be
     * using their version of Listing 2.1 for consistency.
     */

    using namespace std;

    // Step 1. Read in radius
    double radius;
    cout << "Enter a radius: ";
    cin >> radius;

    // Step 2. Compute area
    double area = radius * radius * 3.14159;

    // Step 3. Display the area
    cout << "The area is " << area << endl;
}

void Chapter2Listings::ComputeAverage() {

    /* Solves the problem 'Compute the average of three numbers' given in Listing 2.3
     * in Section 2.3 in Chapter 2
     */

    double number1, number2, number3, average;

    std::cout << "Enter any three numbers, separated by spaces, to find their average: ";
    std::cin >> number1 >> number2 >> number3;

    average = (number1 + number2 + number3) / 3;

    std::cout   << "The average of (" << number1 << ", " << number2 << ", "
                << number3 << ") is : " << average << "." << std::endl;
}

void Chapter2Listings::ComputeAreaWithConstant() {

    /* Their solution to Listing 2.4 in Section 2.7 in Chapter 2.
     *
     * Rewrite Listing 2.2 to include Pi as a constant
     */

    using namespace std;

    const double PI = 3.14159;

    // Step 1. Read in radius
    double radius;
    cout << "Enter a radius: ";
    cin >> radius;

    // Step 2. Compute area
    double area = radius * radius * PI;

    // Step 3. Display the area
    cout << "The area is " << area << endl;
}

void Chapter2Listings::ComputeArea5() {

    /* Their solution to Listing 2.5 in Section 2.7 in Chapter 2
     *
     * Rewrite Listing 2.4 to define PI using the preprocessor directive
     */
    #define PI 3.14159
    using namespace std;

    // Step 1. Read in radius
    double radius;
    cout << "enter a radius: ";
    cin >> radius;

    // Step 2. Computea rea
    double area = radius * radius * PI;

    // Step 3. Display the area
    cout << "The area is" << area << endl;
}

void Chapter2Listings::DisplayTime() {

    /* Solves problem given in Listing 2.6 in Section 2.8.2 in Chapter 2
     *
     * Write a program to obtain minutes and remaining seconds from an amount of time in seconds
     */

    int remainingSecsFromHrs, remainingSecFromMins,seconds, minutes, hours;
    std::cout << "Enter a number of seconds: ";
    std::cin >> seconds;

    // Calculates the number of hours. Anything less than 3600s becomes 0 hrs
    hours = seconds / (60*60);

    //  Finds how many seconds don't createa a whole hour
    remainingSecsFromHrs = seconds % (60*60);

    // Calculates the number of minutes. Anything less than 60s becomes 0 mins
    minutes = remainingSecsFromHrs / 60;

    // All unassigned seconds are the remaining seconds
    remainingSecFromMins = remainingSecsFromHrs % (60);

    // Outputs to user
    std::cout   << seconds << " seconds is: " << hours << "hrs, " << minutes
                << "mins & " << remainingSecFromMins << "s." << std::endl;
}

void Chapter2Listings::FahrenHeitToCelcius() {

     /* Solves problem given in Listing 2.7 fin Section 2.8.3 in Chapter 2
      *
      * Write a program to convert Fahrenheit degrees to Celsius using the formula
      *
      * celsius = (5/9) * (fahrenheit - 32)
      */

     double fahrenheit, celcius;
     std::cout << "Enter temperature in Fahrenheit: ";
     std::cin >> fahrenheit;

     // Need 5.0/9 instead of 5/9 to ensure that the result is a double and not an int
    celcius = (fahrenheit - 32) * (5.0/9);

    std::cout << fahrenheit << "F is " << celcius << " degrees Celcius." << std::endl;
}

void Chapter2Listings::SalesTax() {

    /* Their solution to Listing 2.8 in Section 2.9 in Chapter 2
     *
     * Write a program that displays the sales tax with two digits after the decimal point
     */

    using namespace std;

    // Enter purchase amount
    double purchaseAmount;
    cout << "Enter purchase amount: ";
    cin >> purchaseAmount;

    double tax  = purchaseAmount * 0.06;
    cout << "Sales tax is " << static_cast<int>(tax * 100) / 100.0;
}

void Chapter2Listings::MyComputeLoan() {

    /* My solution to Listing 2.9 in Section 2.11.1 in Chapter 2
     *
     * Write a program that calculates monthly loan payment amounts using the following formula:
     *
     * (loanAmount * monthlyInterestRate) / (1 - (1 / pow((1 + monthlyInterestRate), numberOfYears * 12)))
     */

    double InterestRate;
    unsigned int totalYears;
    double loanAmount;
    double monthlyPayments, totalPayments;
    std::string currency;

    std::cout << "Enter the total loan you are receiving: ";
    std::cin >> loanAmount;

    std::cout << "Enter the number of years the loan is for: ";
    std::cin >> totalYears;

    std::cout << "Enter the annual interest rate: ";
    std::cin >> InterestRate;

    std::cout << "Enter the currency as a symbol ($): ";
    std::cin >> currency;

    /* Convert annual interest rate to monthly by dividing by 12. Convert from percentage
     * to decimal by dividing annual interest rate by 100 */
    InterestRate /= 1200;

    // Use given formula to calculate monthlly and total payments
    monthlyPayments = ( loanAmount * InterestRate ) / ( 1 - ( 1 / (pow(1+InterestRate, totalYears*12)) ) );
    totalPayments = monthlyPayments * 12 * totalYears;

    std::cout   << "You will need to pay "+currency << monthlyPayments << " each month. After " << totalYears
                << " years this will cost "+currency << totalPayments << " in total." << std::endl;
}

void Chapter2Listings::TheirComputeLoan() {

    /* My solution to Listing 2.9 in Section 2.11.1 in Chapter 2
     *
     * Write a program that calculates monthly loan payment amounts using the following formula:
     *
     * (loanAmount * monthlyInterestRate) / (1 - (1 / pow((1 + monthlyInterestRate), numberOfYears * 12)))
     */

    using namespace std;
    // Enter yearly interest rate
    cout << "Enter yearly interest rate, for example 8.25: ";
    double annualInterestRate;
    cin >> annualInterestRate;

    // Obtain monthly interest rate
    double monthlyInterestRate = annualInterestRate / 1200;

    // Enter number of years
    cout << "Enter number of years as an integer, for example 5: ";
    int numberOfYears;
    cin >> numberOfYears;

    // Enter loan amount
    cout << "Enter loan amount, for example 120000.95: ";
    double loanAmount;
    cin >> loanAmount;

    // Calculate payment
    double monthlyPayment = loanAmount * monthlyPayment / (1 - 1/ pow(1 + monthlyInterestRate, numberOfYears * 12));
    double totalPayment = monthlyPayment * numberOfYears * 12;

    // Display results
    cout << "The monthly payment is " << monthlyPayment << "\nThe total payment is " << totalPayment << endl;
}

void Chapter2Listings::ComputeChange() {

    /* Their solution to Listing 2.10 in Section 2.11.2 in Chapter 2
     *
     * Write a program that classifies a given amount of money into smaller monetary units. The program
     * shoud let the user enter an amount as a double value representing a total in dollars and cents, and
     * output a report listing the monetary equivalent in dollars, quarters, dimes, nickels, and pennies.
     */

    using namespace std;

    // Receive the amount
    cout << "Enter an amount in double, for example 11.56: ";
    double amount;
    cin >> amount;

    int remainingAmount = static_cast<int>(amount * 100);

    // Find the number of one dollars
    int numberOfOneDollars = remainingAmount / 100;
    remainingAmount = remainingAmount % 100;

    // find the number of quarters in the remaining amount
    int numberOfQuarters = remainingAmount / 25;
    remainingAmount = remainingAmount % 25;

    // Find the number of dimes in the remaining amount
    int numberOfDimes = remainingAmount / 10;
    remainingAmount = remainingAmount % 10;

    // Find the number of nickels in the remaining amount
    int numberOfNickels = remainingAmount / 5;
    remainingAmount = remainingAmount % 5;

    // Find the number of pennies in the remaining amount
    int numberOfPennies = remainingAmount;

    // Display results
    cout << "Your amount " << amount   << "consists of \n"
         << "\t" << numberOfOneDollars << " dollars\n"
         << "\t" << numberOfQuarters   << " quarters\n"
         << "\t" << numberOfDimes      << " dimes\n"
         << "\t" << numberOfNickels    << " nickels\n"
         << "\t" << numberOfPennies    << " pennies\n";
}

void Chapter2Listings::ShowCurrentTime() {

    /* My solution to Listing 2.11 in Section 2.11.3 in Chapter 2
     *
     * Develop a program that displays the current time in GMT in the format HH::MM::SS
     */

    unsigned int totalSeconds, totalMinutes, totalHours;
    unsigned short currentSeconds, currentMinutes, currentHours;

    // Finds the total enlapsed seconds since the UNIX epoch [time(0)], and convert that to minutes and hours
    totalSeconds    =   time(0);
    totalMinutes    =   totalSeconds / 60;
    totalHours      =   totalMinutes / 60;

    // Find the current time
    currentSeconds   =   totalSeconds % 60;
    currentMinutes   =   totalMinutes % 60;
    currentHours    =   totalHours % 24;

    // Display current time to user in HH:MM:SS format
    std::cout   << "Since the UNIX epoch " << totalSeconds << "s have passed.\nThis leads us to find that the current time is "
                << currentHours << ":" << currentMinutes << ":" << currentSeconds << "." << std::endl;

}
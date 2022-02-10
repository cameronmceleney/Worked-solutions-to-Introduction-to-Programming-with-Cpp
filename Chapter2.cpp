#include "Chapter2.h"

void Chapter2::ComputeArea() {
    /* Solves the problem of 'Compute the area of a circle' given in Chapter 2,
     * Section 2.2 */

    double circleRadius, circleArea;

    // Takes user input for radius
    std::cout << "Enter the radius of the circle: ";
    std::cin >> circleRadius;

    // Calculates the area of the circle without using functions or raising to powers
    circleArea = circleRadius * circleRadius * M_PI;

    // Outputs area of circle to user
    std::cout << "The area of your circle is " << circleArea << "."<< std::endl;
}

void Chapter2::ComputeAverage() {
    /* Solves the problem 'Compute the average of three numbers' given in
     * Chapter 2, Section 2.3 */

    double number1, number2, number3, average;

    std::cout << "Enter any three numbers, separated by spaces, to find their average: ";
    std::cin >> number1 >> number2 >> number3;

    average = (number1 + number2 + number3) / 3;

    std::cout   << "The average of (" << number1 << ", " << number2 << ", "
                << number3 << ") is : " << average << "." << std::endl;
}

void Chapter2::DisplayRemainingTime() {

    /* Solves problem given in Listen 2.6 found in Chapter 2, section 2.8.2*/

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

void Chapter2::FahrenHeitToCelcius() {

     /* Solves problem given in Listing 2.7 found in Chapter 2, Section 2.8.3 */

     double fahrenheit, celcius;
     std::cout << "Enter temperature in Fahrenheit: ";
     std::cin >> fahrenheit;

     // Need 5.0/9 instead of 5/9 to ensure that the result is a double and not an int
    celcius = (fahrenheit - 32) * (5.0/9);

    std::cout << fahrenheit << "F is " << celcius << " degrees Celcius." << std::endl;
}

void Chapter2::MyComputeLoan() {

    /* My solution to Problem 2.11.1 in Chapter 2, Section 2.11 which I wrote at speed as
     * a test*/

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

void Chapter2::TheirComputeLoan() {

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

void Chapter2::MyShowCurrentTime() {
    /* My solution to Problem 2.11.3 in Chapter 2, Section 2.11 which I wrote at speed as
     * a test*/

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

void Chapter2::PComputeCylinderVolume() {

    // My solution to Programming Exercise 2.1 in Chapter 2
    using namespace std;

    double cylinderRadius, cylinderLength, cylinderArea, cylinderVolume;

    cout << "Enter the radius and length of a cylinder: ";
    cin >> cylinderRadius >> cylinderLength;

    // Compute the area and volume with units m^2 and m^3
    cylinderArea = cylinderRadius * cylinderRadius * M_PI;
    cylinderVolume = cylinderArea * cylinderLength;

    std::cout << "The area is " << cylinderArea << endl;
    std::cout << "The volume is " << cylinderVolume << endl;
}

void Chapter2::PCelciusToFahrenheit() {

    // My solution to Programming Exercise 2.2 in Chapter 2. It converts a temperature in Celsius to one in Fahrenheit.

    using namespace std;

    double celsius, fahrenheit;

    cout << "Enter a degree in Celsius: ";
    cin >> celsius;

    fahrenheit = (9.0 / 5) * celsius + 32;

    cout << "Fahrenheit degree is " << fahrenheit << endl;
}

void Chapter2::PUSD2EUR() {

    /* My solution to Programming Exercise 2.3 in Chapter 2. It converts an amount of US Dollar to Euros
     * In the book it states $1.00 == 0.755 EUR */

    using namespace std;

    double dollarAmount, euroAmount, conversionRate;

    // Sets the conversion rate between USD to EUR as per the book's given value
    conversionRate = 0.755;

    // Takes in USD amount
    cout << "Enter an amount in US Dollars: ";
    cin >> dollarAmount;

    // Converts USD value to EUR value
    euroAmount = dollarAmount * conversionRate;

    // Tells user what the equivalent amount of EUR are to the entered USD amount
    cout << dollarAmount << " USD = " << euroAmount << " EUR" << endl;
}

void Chapter2::PPoundstoKilo(){

    /* My solution to Programming Exercise 2.3 in Chapter 2. It converts an amount of US Dollar to Euros
     * In the book it states 1.00 [lb] == 0.454 [kg] */

    using namespace std;

    double weightInPounds, weightInKilos, conversionRate;

    // Sets conversion rate of [lb] to [kg] as per the book's value
    conversionRate = 0.454;

    // Takes in the user's weight in [lb] from console input
    cout << "Enter a number in pounds:";
    cin >> weightInPounds;

    // Converts weight from [lb] to [kg]
    weightInKilos = weightInPounds * conversionRate;

    // Displays equivalent weight in [kg] to console
    cout << "The kilograms is " << weightInKilos << endl;
}
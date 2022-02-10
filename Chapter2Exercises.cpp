#include "Chapter2Exercises.h"

void Chapter2Exercises::Exercise2_1() {

    /* My solution to this problem which covers content from Sections 2.2 - 2.9
     *
     * Write a program that reads in the radius and length of cylinder and computes the volume using the following
     * formula:
     *                  area  = radius * radius * PI
     *                  volume = area * length
     */

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

void Chapter2Exercises::Exercise2_2() {

    /* My solution to this problem which covers content from Sections 2.2-2.9
     *
     * Write a program that reads a Celsius degree in double, converts it to Fahrenheit, and displays the result. The
     * formula for the conversion is as follows:
     *
     *          fahrenheit = (9 / 5) * celsius + 32
     *
     * (Hint: In C++, 9/ 5 is 1, so you need to write 9.0 / 5 in the program to obtain the correct result)
     */

    using namespace std;

    double celsius, fahrenheit;

    cout << "Enter a degree in Celsius: ";
    cin >> celsius;

    fahrenheit = (9.0 / 5) * celsius + 32;

    cout << "Fahrenheit degree is " << fahrenheit << endl;
}

void Chapter2Exercises::Exercise2_3() {

    /* My solution to the problem covering content from Sections 2.2-2.9
     *
     * Write a program that reads an amount in US dollars, converts the amount entered to Euros, and displays
     * the result. $1.00 USD is equivalent, for this purpose, to 0.755 EUR.
     */

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

void Chapter2Exercises::Exercise2_4(){

    /* My solution to the problem which covers content from Sections 2.2-2.9
     *
     * Write a program that converts pounds into kilograms. The program prompts the user to enter a number in pounds,
     * converts it to kilograms, and displays the result. One pound is equivalent to 0.454 kilogram.
     */

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

void Chapter2Exercises::Exercise2_5() {

    /* ( difficulty)
     *
     * Write a program that accepts a subtotal and a sales tax rate and computes the sales tax and the total amount
     * due. Prompt the user for the total and the sales tax rate
     */
}

void Chapter2Exercises::Exercise2_6() {

    /* (** difficulty)
     *
     * Write a program that reads an integer between 0 and 1000 and adds all the digits in the integer. For example,
     * if an integer is 932, the sum of all its digits is 14.
     */
}

void Chapter2Exercises::Exercise2_7() {

    /* (* difficulty)
     *
     * Write a program that receives an ASCII code (an integer between 0 and 128) and displays its character. For
     * example, if the user enters 97, the program displays character 'a'.
     */
}

void Chapter2Exercises::Exercise2_8() {

    /* (* difficulty)
     *
     * Write a program that propts the user to enter an uppercase letter and converts it to a lowercase letter.
     *
     * (Hint: In the ASCII table (see Appendix B)), uppercase letters appear before lowercase letters. The offset
     * between any uppercase letter and its corresponding lowercase letter is the same. So you can find a lowercase
     * letter from its corresponding uppercase letter as shown below)
     *
     *      int offset = 'a' - 'A';
     *      char lowercase = (char)(uppercase+offset);
     */
}

void Chapter2Exercises::Exercise2_9() {

    /* (* difficulty)
     *
     * Rewrite Listing 2.10, ComputeChange.cpp, to fix the possible loss of accuracy when converting a double value
     * to an int value. Enter the input as an integer whose last two digits represent the cents. For example, the input
     * 1156 represents 11 dollars and 56 cents.
     */
}

void Chapter2Exercises::Exercise2_10() {

    /* ( difficulty)
     *
     * If you know the balance and annual percentage interest rate, you can compute the interest on the next
     * monthly payment using the following formula:
     *
     *      interest = balance * (annualInterestRate / 1200)
     *
     * Write a program that reads the balance and annual percentage interest rate in this order and displays the
     * interest for the next month.
     */
}

void Chapter2Exercises::Exercise2_11() {

    /* (* difficulty)
     *
     * Write a program that reads in the payment for each compounding period, the interest rate that would be
     * compounded for each period of time, and the number of payment periods. The program then displays the future
     * value of the annuity using the following formula:
     *
     *          futureValue = payment * pow(1 + interestRate, numberOfPaymentPeriods) - 1 / numberOfPaymentPeriods
     *
     * (Hint: Use the pow(a,b) function to compute a raised to the power of b.)
     */
}

void Chapter2Exercises::Exercise2_12() {

    /* (** difficulty)
     *
     * Suppose you save $100 each month into a savings account with annual interest rate 5%. So, the monthly interest
     * rate is 0.05 / 12 = 0.00417. After the first month, the value in the account becomes:
     *
     *      100 * (1 + 0.00417) = 100.417
     *
     * After the second month, the value in the account becomes:
     *
     *      (100 + 100.417) * (1 + 0.00417) = 201.252
     *
     * After the third month, the value in the account becomes:
     *
     *      (100 + 201.252) * (1 + 0.00417) = 302.507
     *
     * and so on. Write a program to display the account value after the sixth month. (In Exercise 4.30, you
     * will use a loop to simplify the code and display the account value for any month.)
     */
}

void Chapter2Exercises::Exercise2_13() {

    /* (* difficulty)
     *
     * Body Mass Index (BMI) is a measure of health on weight. It can be calculated by taking your weight in
     * kilograms and dividing by the square of your height in meters. Write a program that prompts the user to enter a
     * weight in pounds and height in inches and display te BMI. Note that one pound is 0.45359237 kilograma and one
     * inch is 0.0254 meter.
     */
}

void Chapter2Exercises::Exercise2_14() {

    /* ( difficulty)
     *
     * Write a program that calculates the energy needed to heat water from an initial temperature to a final
     * temperature. Your program should prompt the user to enter the water amount in kilograms and its initial and
     * final temperatures. The formula to compute the energy is:
     *
     *          Q = M * (finalTemperature - initialTemperature) * 4184
     *
     * where M is the mass of the water in kilograms, temperatures are in degrees Celsius, and energy Q is measured
     * in Joules.
     */
}

void Chapter2Exercises::Exercise2_15() {

    /* (* difficulty)
     *
     * How cold is it outside? We need to know more than the temperature alone. Other factors, including wind speed,
     * relative humidity, and sunshine, play important roles in determining coldness outside. In 2001, the National
     * Weather Service (NWS) implemented the new wind-chill temperature to measure the coldness using temperature
     * and wind speed. The formula is:
     *
     *          t_wc = 35.74 + 0.6215 * t_a - 35.75 * pow(v, 0.16) + 0.4275 * t_a * pow(v, 0.16)
     *
     * where t_a is the outside temperature in degrees Fahrenheit and v is the speed in miles per hour. t_wc is the
     * wind-chill temperature. The formula cannot be used for wind speeds below 2 mph temperatures below -58F or
     * above 41F.
     *
     * Write a program that prompts the user to enter a temperature between -59F and 41F and a wind speed greater than
     * or equal to 2 and displays the wind-chill temperature. Use pow(a, b) to compute v^0.16.
     */
}

void Chapter2Exercises::Exercise2_16() {

    /* ( difficulty)
     *
     * Write a program that displays the following table:
     *
     *      a       b       pow(a, b)
     *      1       2       1
     *      2       3       8
     *      3       4       81
     *      4       5       1024
     *      5       6       15625
     */
}

void Chapter2Exercises::Exercise2_17() {

    /* ( difficulty)
     *
     * Write a program that prompts the user to enter two points (x1, y1) and (x2, y2) and displays their distances.
     * The formula for computing the distance is sqrt( pow((x2 - x1), 2) + pow((y2 - y1), 2) ). Note that your can use
     * pow(a, 0.5) to compute sqrt(a).
     */
}

void Chapter2Exercises::Exercise2_18() {

    /* ( difficulty)
     *
     * Write a program that prompts the user to enter the side of a hexagon and displays its area. The formula for
     * computing the area of a hexagon is:
     *
     *              Area = (3 * sqrt(3) / 2) * pow(s, 2)
     *
     * where s is the length of a side and sqrt(3) = 1.732.
     */

}

void Chapter2Exercises::Exercise2_19() {

    /* (* difficulty)
     *
     * Write a program that prompts the user to enter three points (x1, y1), (x2, y2), (x3, y3) of a triangle and
     * displays its area. The formula for computing the area of a triangle is:
     *
     *              s = (side1 + side2 + side3) / 2
     *              area = sqrt(s * (s - side1) * (s - side2) * (s - side3))
     */
}

void Chapter2Exercises::Exercise2_20() {

    /* ( difficulty)
     *
     * Average acceleration is defined as the change of velocity divided by the time taken to make the change, as
     * shown in the following formula:
     *
     *              a = (v1 - v0) / t
     *
     * Write a program that prompts the user to enter the starting velocity 'v0' in meters/second, ending velocity 'v1'
     * in meters/second, and display time span 't' in seconds, and displays the average acceleration 'a'.
     */
}

void Chapter2Exercises::Exercise2_21() {

    /* ( difficulty)
     *
     * Given an airplane's acceleration 'a' and take-off speed 'v', you can compute the minimum runway length needed
     * for the airplane to take off using the following formula:
     *
     *              length = pow(v, 2) / (2 * a)
     *
     * Write a program that prompts the user to enter 'v' in meters/second and acceleration 'a' in
     * meters / (seconds * seconds), and displays the minimum runway length.
     */

}
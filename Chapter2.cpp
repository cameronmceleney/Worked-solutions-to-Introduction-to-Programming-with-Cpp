#include "Chapter2.h"

int Chapter2::ComputeArea() {
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

    return 0;
}

int Chapter2::ComputeAverage() {
    /* Solves the problem 'Compute the average of three numbers' given in
     * Chapter 2, Section 2.3 */

    double number1, number2, number3, average;

    std::cout << "Enter any three numbers, separated by spaces, to find their average: ";
    std::cin >> number1 >> number2 >> number3;

    average = (number1 + number2 + number3) / 3;

    std::cout   << "The average of (" << number1 << ", " << number2 << ", "
                << number3 << ") is : " << average << "." << std::endl;

    return 0;
}


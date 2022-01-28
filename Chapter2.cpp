#include "Chapter2.h"

int Chapter2::ComputeArea() {
    /* This code solves the problem of 'Compute the area of a circle' given in Chapter 2,
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




#include "Chapter6Exercises.h"

void Chapter6Exercises::E6_1_sort(double &n1, double &n2, double &n3) {
    // Sort three numbers such that into the order n1 <= n2 <= n3

    if (n2 < n1)
        E6_1_swap(n2, n1);

    if (n3 < n2) {

        E6_1_swap(n3, n2);

        if (n2 < n1)
            E6_1_swap(n2, n1);
    }
}
void Chapter6Exercises::E6_1_swap(double &n1, double &n2) {
    // Swap number 'n1' with number 'n2'
    double tempNumber = n1;
    n1 = n2;
    n2 = tempNumber;
}
int Chapter6Exercises::Exercise6_1() {
    // Sort three numbers into ascending order;

    double num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    E6_1_sort(num1, num2, num3);

    cout << "The sorted numbers are: " << num1 << ", " << num2 << ", " << num3 << '\n';

    return 0;
}

double Chapter6Exercises::L6_2computeDiscriminant(double a, double b, double c) {
    // Calculates the discriminant of the quadratic equation
    double discriminant = pow(b, 2) - 4 * a * c;
    return discriminant;
}
double Chapter6Exercises::L6_2_solveQuadraticR1(double a, double b, const double &discriminant) {
    // Finds the first root of the quadratic equation
    double root = (-b + sqrt(discriminant)) / (2 * a);

    return root;
}
double Chapter6Exercises::L6_2_solveQuadraticR2(double a, double b, const double &discriminant) {
    // Finds the first root of the quadratic equation
    double root = (-b - sqrt(discriminant)) / (2 * a);

    return root;
}
void Chapter6Exercises::L6_2_solveQuadraticEquation(double a, double b, double c, double &discriminant, double &r1, double &r2) {

    discriminant = L6_2computeDiscriminant(a, b, c);

    if (discriminant > 0) {

        r1 = L6_2_solveQuadraticR1(a, b, discriminant);
        r2 = L6_2_solveQuadraticR2(a, b, discriminant);
        cout << "The roots are " << r1 << " and " << r2 << endl;
    } else if (discriminant == 0) {

        r1 = L6_2_solveQuadraticR1(a, b, discriminant);
        cout << "The root is " << r1 << endl;
    } else
        cout << "The equation has no roots\n";

}
int Chapter6Exercises::Exercise6_2() {

    /* (* difficulty)
     *
     * The roots of a quadratic equation a*x**2 + b*x + x = 0 can be obtained by using the following formulae:
     *
     *              r1 = (-b + sqrt(b**2 + 4*a*c)) / (2*a)
     *              r2 = (-b - sqrt(b**2 + 4*a*c)) / (2*a)
     *
     *
     * Write a function with the following header
     *
     *          void solveQuadraticEquation(double a, double b, double c, double &discriminant, double &r1, double &r2);
     *
     * (b**2 - 4*a*c) is called the discriminant of the quadratic equation. If the discriminant is less than 0, the
     * equation has no roots. In this case, ignore the value in r1 and r2.
     *
     * Write a test program that prompts the user to enter values of a, b, and c, and displays the result based on the
     * discriminant. If the discriminant is greater than or equal to 0, display the two roots. If the discriminant is
     * equal to 0, display the one root. Otherwise, display "the equation has no roots". See Exercise 3.3 for
     * sample runs.
     */

    // Prompt the user for inputs
    cout << "Enter the values a, b, and c: ";
    double a, b, c;
    cin >> a >> b >> c;

    double discriminant = 0, r1 = 0, r2 = 0;

    L6_2_solveQuadraticEquation(a, b, c, discriminant, r1, r2);

    return 0;
}

double Chapter6Exercises::L6_3_computeDenominator(const double &a, const double &b, const double &c, const double &d) {
    // Finds the denominator for 'x' and 'y' for Cramer's Rule

    double denominator = a * d - b * c;

    return denominator;
}
bool Chapter6Exercises::L6_3_findIfSolvable(const double &denominator) {
    // checks if a solution exists

    if (denominator != 0)
        // A solution exists
        return true;
    else
        return false;
}
double Chapter6Exercises::L6_3_computeX(const double &a, const double &b, const double &c, const double &d, const double &e, const double &f, const double &denominator) {
    // Finds the value of 'x' in Cramer's Rule

    double xValue = (e * d - b * f) / denominator;

    return xValue;
}
double Chapter6Exercises::L6_3_computeY(const double &a, const double &b, const double &c, const double &d, const double &e, const double &f, const double &denominator) {
    // Finds the value of 'x' in Cramer's Rule

    double yValue = (a * f - e * c) / denominator;

    return yValue;
}
void Chapter6Exercises::L6_3_solveEquation() {
    // Solves the equation for Cramer's Rule

    // Prompts user for inputs
    cout << "Enter a, b, and e, for the first equation: ";
    double a, b, e;
    cin >> a >> b >> e;

    cout << "Enter c, d, and f, for the first equation: ";
    double c, d , f;
    cin >> c >> d >>f;

    double denominator = L6_3_computeDenominator(a, b, c ,d);
    double x = L6_3_computeX(a, b, c , d, e, f, denominator);
    double y = L6_3_computeY(a, b, c , d, e, f, denominator);
    bool isSolvable = L6_3_findIfSolvable(denominator);

    if (isSolvable) {
        cout << "The solutions are " << x << " and " << y << endl;
    } else
        cout << "The equation has no solution" << endl;
}
int Chapter6Exercises::Exercise6_3() {

    /* (* difficulty)
     *
     * YOu can use Cramer's rule to solve the following 2 x 2 system of linear equations:
     *
     *                              a*x + b*y = e
     *                              c*x + d*y = f
     *
     *                              x = (e*d - b*f) / (a*d + b*c)
     *                              y = (a*f - e*c) / (a*d - b*c)
     *
     * Write a function with the following header:
     *
     *
     *          void solveEquation(double a, double b, double c, double d, double e,
     *                             double f, double &x, double &y, bool &isSolvable)
     *
     * If (a*d - b*c) is 0, the equation has no solution and isSolvable should be false. Write a program that prompts
     * the user to enter a, b, c, d, e, and f, and displays the result. If (a*d - b*c) is 0, report that "The
     * equation has no solution". See Exercise 3.1 for sample runs.
     *
     * (Note: I thought the given header was illogical, so I've ignored using it to abstract the implementation of
     * the solveEquation() function more sensibly.
     */

    L6_3_solveEquation();

    return 0;
}

int Chapter6Exercises::Exercise6_4() {
    /* (*** difficulty)
     *
     * Listing 2.11, ShowCurrentTime.cpp, displays the current time. Improve this example to display the current date
     * and time. The calendar example in Section 6.8 (see code in Listing 6.11) to give ideas on how to find the
     * year, month, and day.
     */

    L6_4_printCurrentDateTime();
    return 0;
}
void Chapter6Exercises::L6_4_printCurrentDateTime() {
    // Finds the current date, and time, and prints this to the user.

    L6_4_printCurrentTime();
    L6_4_printCurrentDate();

}
void Chapter6Exercises::L6_4_printCurrentTime() {
    // Finds and prints the current time

    unsigned int totalSeconds, totalMinutes, totalHours;
    unsigned short currentSeconds, currentMinutes, currentHours;

    // Finds the total elapsed seconds since the UNIX epoch [time(0)], and convert that to minutes and hours
    totalSeconds    =   time(0);
    totalMinutes    =   totalSeconds / 60;
    totalHours      =   totalMinutes / 60;

    // Find the current time
    currentSeconds   =   totalSeconds % 60;
    currentMinutes   =   totalMinutes % 60;
    currentHours    =   totalHours % 24;

    // Display current time to user in HH:MM:SS format
    std::cout   << currentHours << ":" << currentMinutes << ":" << currentSeconds << "." << std::endl;
}
void Chapter6Exercises::L6_4_printCurrentDate() {
    // Finds and prints the current date in DD/MM/YYYY format

    L6_4_printYear();
}
void Chapter6Exercises::L6_4_printYear() {

    cout << "Enter the year";
    int year;
    cin >> year;

    cout << "The year is: " << year;
}
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

    unsigned int totalSeconds, totalMinutes, totalHours;
    totalSeconds = time(0);
    totalMinutes = totalSeconds / 60;
    totalHours = totalMinutes / 60;

    L6_4_printCurrentTime(totalSeconds, totalMinutes, totalHours);
    L6_4_printCurrentDate(totalSeconds, totalHours);

}
void Chapter6Exercises::L6_4_printCurrentTime(const unsigned int &totalSeconds,
                                              const unsigned int &totalMinutes,
                                              const unsigned int &totalHours) {
    // Finds and prints the current time

    // Finds the total elapsed seconds since the UNIX epoch [time(0)], and convert that to minutes and hours


    // Find the current time
    L6_4_printHours(totalHours);
    cout << ":";
    L6_4_printMinutes(totalMinutes);
    cout << ":";
    L6_4_printSeconds(totalSeconds);
    cout << endl;
}
void Chapter6Exercises::L6_4_printHours(unsigned int totalHours) {
    // Prints the current number of seconds

    unsigned short currentHours = totalHours % 24;

    if (currentHours < 10) {
        cout << "0" << currentHours;
    } else
        cout << currentHours;
}
void Chapter6Exercises::L6_4_printMinutes(unsigned int totalMinutes) {
    // Prints the current number of seconds

    unsigned short currentMinutes = totalMinutes % 60;

    if (currentMinutes < 10) {
        cout << "0" << currentMinutes;
    } else
        cout << currentMinutes;
}
void Chapter6Exercises::L6_4_printSeconds(unsigned int totalSeconds) {
    // Prints the current number of seconds

    unsigned short currentSeconds = totalSeconds % 60;

    if (currentSeconds < 10) {
        cout << "0" << currentSeconds;
    } else
        cout << currentSeconds;
}
void Chapter6Exercises::L6_4_printCurrentDate(const unsigned int &totalSeconds,
                                              const unsigned int &totalHours) {

    // Finds and prints the current date in DD/MM/YYYY format

    unsigned int totalDays = totalHours / 24;
    unsigned short currentYear = 1970, totalYearsSinceEpoch = 0; // UNIX Epoch is 1 Jan 1970
    unsigned int currentDay = 0; // Which day today is
    unsigned short numberOfLeapYears = 0; // How many leap years between Epoch and this year

    L6_4_findYear(currentYear, totalDays, totalYearsSinceEpoch, numberOfLeapYears);
    bool isCurrentYearLeapYear = (currentYear % 400 == 0 || (currentYear % 4 == 0 && currentYear % 100 != 0)) ? true : false;

    // The +1 is an offset due to the first day of the year being 1st Jan, not 0th Jan, which is where code would begin
    // to count
    int totalDaysOfCurrentYear = totalDays - (totalYearsSinceEpoch * 365) - numberOfLeapYears + 1;

    string currentMonth = L6_4_findCurrentMonth(totalDaysOfCurrentYear, currentDay, isCurrentYearLeapYear);

    cout << currentDay << " " << currentMonth << " " << currentYear << endl;
}
void Chapter6Exercises::L6_4_findYear(unsigned short &currentYear,
                                      const unsigned int &totalDays,
                                      unsigned short &totalYearsSinceEpoch,
                                      unsigned short &numberOfLeapYears) {
    // Increment multiple function-wide counters to find the current year, number of leap years, and how many
    // years have passed since the UNIX Epoch

    // The starting year is the UNIX Epoch: 1st Jan 1970
    unsigned short startingYear = currentYear;

    // Be careful! currentYear, totalYearsSinceEpoch, and numberOfLeapYears, are references! This means each time they
    // are changing in this function, they are changed for the rest of the program!

    for (int tempdays = 0; tempdays <= totalDays; tempdays += 365) {
        // Adds
        currentYear++;

        if (currentYear % 400 == 0 || (currentYear % 4 == 0 && currentYear % 100 != 0)) {
            // If the current year is a leap year, add to counter
            numberOfLeapYears++;
            tempdays++;
        }
    }
    currentYear--; // Counter oversteps, so this excludes endpoint
    totalYearsSinceEpoch = currentYear - startingYear; // Exclude starting year itself from count
}

string Chapter6Exercises::L6_4_findCurrentMonth(unsigned int totalDaysOfCurrentYear, unsigned int &currentDay, const bool &isCurrentYearLeapYear) {
    // Output the name of the current month as a string


    // If current year is leap year, add extra day to February
    unsigned short leapYearAddition = (isCurrentYearLeapYear ? 1 : 0);

    // List of how many days in each month
    unsigned short daysOfJan = 31,
                   daysOfFeb = daysOfJan + 28 + leapYearAddition,
                   daysOfMar = daysOfFeb + 31,
                   daysOfApr = daysOfMar + 30,
                   daysOfMay = daysOfApr + 31,
                   daysOfJun = daysOfMay + 30,
                   daysOfJul = daysOfJun + 31,
                   daysOfAug = daysOfJul + 31,
                   daysOfSep = daysOfAug + 30,
                   daysOfOct = daysOfSep + 31,
                   daysOfNov = daysOfOct + 30,
                   daysOfDec = daysOfNov + 31;

    // Range for totalDaysOfCurrentYear is [0, 364] (inclusive) in a non-leap year. This means that if the
    // totalDaysOfCurrentYear < 31 then the date is January (and so on)
    if (totalDaysOfCurrentYear < daysOfJan)
    {
        currentDay = totalDaysOfCurrentYear;
        return "Jan";
    }
    else if (totalDaysOfCurrentYear < daysOfFeb)
    {
        currentDay = totalDaysOfCurrentYear % daysOfJan;
        return "Feb";
    }
    else if (totalDaysOfCurrentYear < daysOfMar)
    {
        currentDay = totalDaysOfCurrentYear % daysOfFeb;
        return "Mar";
    }
    else if (totalDaysOfCurrentYear < daysOfApr)
    {
        currentDay = totalDaysOfCurrentYear % daysOfMar;
        return "Apr";
    }
    else if (totalDaysOfCurrentYear < daysOfMay)
    {
        currentDay = totalDaysOfCurrentYear % daysOfApr;
        return "May";
    }
    else if (totalDaysOfCurrentYear < daysOfJun)
    {
        currentDay = totalDaysOfCurrentYear % daysOfMay;
        return "Jun";
    }
    else if (totalDaysOfCurrentYear < daysOfJul)
    {
        currentDay = totalDaysOfCurrentYear % daysOfJun;
        return "Jul";
    }
    else if (totalDaysOfCurrentYear < daysOfAug)
    {
        currentDay = totalDaysOfCurrentYear % daysOfJul;
        return "Aug";
    }
    else if (totalDaysOfCurrentYear < daysOfSep)
    {
        currentDay = totalDaysOfCurrentYear % daysOfAug;
        return "Sep";
    }
    else if (totalDaysOfCurrentYear < daysOfOct)
    {
        currentDay = totalDaysOfCurrentYear % daysOfSep;
        return "Oct";
    }
    else if (totalDaysOfCurrentYear < daysOfNov)
    {
        currentDay = totalDaysOfCurrentYear % daysOfOct;
        return "Nov";
    }
    else if (totalDaysOfCurrentYear < daysOfDec)
    {
        currentDay = totalDaysOfCurrentYear % daysOfNov;
        return "Dec";
    }
    else
        return "Unknown month";
}

int Chapter6Exercises::Exercise6_5() {

    /* (** difficulty)
     *
     * An emirp (prime spelled backward) is a prime number whose reversal is also a prime. For example, 79 is a prime
     * and 97 is a prime, therefore 79 and 97 and emirps. Write a program that displays the first 80 emirps. Display
     * 8 numbers per line and align the numbers properly, as follows:
     *
     *                      2   3   5   7   11  13  17  31
     *                      37  71  73  79  97  101 107 113
     */

    E6_5_findEmirp();

    return 0;
}
void Chapter6Exercises::E6_5_findEmirp() {
    // Find a set number of emirps - numbers who are prime, and when their digits are reversed, the reversed number is
    // also prime

    const int EMIRPS_PER_LINE = 8, TOTAL_EMIRPS_TO_FIND = 80;

    int totalEmirpsFound = 0;
    int numberToTest = 2; // The first prime number

    cout << left;

    while (totalEmirpsFound < TOTAL_EMIRPS_TO_FIND)
    {

        if (E6_5_isPrime(numberToTest))
        {
            // if function outputs true then the given 'number' is prime
            if (E6_5_isEmirp(numberToTest))
            {
                if ((totalEmirpsFound + 1) % EMIRPS_PER_LINE == 0)
                    cout << setw(4) << numberToTest << '\n';
                else
                    cout << setw(4) << numberToTest << '\t';
                totalEmirpsFound++;
            }
        }
        numberToTest++; // Move to next number and test while-continuation-condition again
    }
}
bool Chapter6Exercises::E6_5_isPrime(int number) {
    // Check whether number is prime (exact copy of Listing 5.5)

    for (int divisor = 2; divisor <= number / 2; divisor++)
    {
        if (number % divisor == 0)
        {
            // If true, number is not prime
            return false; // Number is not a prime
        }
    }
    return true; // Number is prime
}
bool Chapter6Exercises::E6_5_isEmirp(int number) {
    // Reverses 'number' using code from Exercise 5.4

    int reversedNumber = 0;
    do {
        // Moves the 'writing position' along by one column (no effect when reversedNumber = 0), and then adds the last
        // digit of 'number' to 'reversedNumber'.
        reversedNumber = reversedNumber * 10 + number % 10;
        number /= 10; // Removes the added digit

    } while (number > 0);

    if (E6_5_isPrime(reversedNumber))
        return true;
    else
        return false;
}
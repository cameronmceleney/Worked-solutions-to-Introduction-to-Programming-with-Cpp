#ifndef TESTLOCATIONLOCALFORCPP_CHAPTER6EXERCISES_H
#define TESTLOCATIONLOCALFORCPP_CHAPTER6EXERCISES_H

#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

class Chapter6Exercises {

private:

    // Functions for Exercise 6.1
    void E6_1_sort(double &n1, double &n2, double &n3);
    void E6_1_swap(double &num1, double &num2);

    // Functions for Exercise 6.2
    void E6_2_solveQuadraticEquation(double a, double b, double c, double &discriminant, double &r1, double &r2);
    double E6_2computeDiscriminant(double a, double b, double c);
    double E6_2_solveQuadraticR1(double a, double b, const double &discriminant);
    double E6_2_solveQuadraticR2(double a, double b, const double &discriminant);

    // Functions for Exercise 6.3
    double E6_3_computeDenominator(const double &a, const double &b, const double &c, const double &d);
    bool E6_3_findIfSolvable(const double &denominator);
    double E6_3_computeX(const double &a, const double &b, const double &c, const double &d, const double &e, const double &f, const double &denominator);
    double E6_3_computeY(const double &a, const double &b, const double &c, const double &d, const double &e, const double &f, const double &denominator);
    void E6_3_solveEquation();

    // Functions for Exercise 6.4
    void E6_4_printCurrentDateTime();
    void E6_4_printCurrentTime(const unsigned int &totalSeconds,
                               const unsigned int &totalMinutes,
                               const unsigned int &totalHours);
    void E6_4_printHours(unsigned int totalHours);
    void E6_4_printMinutes(unsigned int totalMinutes);
    void E6_4_printSeconds(unsigned int totalSeconds);
    void E6_4_printCurrentDate(const unsigned int &totalSeconds,
                               const unsigned int &totalHours);
    unsigned short  E6_4_findTotalLeapYears(const unsigned int &totalDays);
    string E6_4_findCurrentMonth(unsigned int totalDaysOfCurrentYear,
                                 unsigned int &day,
                                 const bool &isCurrentYearLeapYear);
    void E6_4_findYear(unsigned short &currentYear,
                       const unsigned int &totalDays,
                       unsigned short &totalYearsSinceEpoch,
                       unsigned short &numberOfLeapYears);

    // Functions for Exercise 6.5
    void E6_5_findEmirp();
    bool E6_5_isPrime(int number);
    bool E6_5_isEmirp(int number);

    // Functions for Exercise 6.6
    void E6_6_printPalindromicPrimes(const int &NUMBERS_PER_LINE, const int &TOTAL_PALINDROMICPRIMES_TO_FIND);
    bool E6_6_isPrime(int &number);
    bool E6_6_isPalindrome(int &number);

    // Functions for Exercise 6.7
    void E6_7_printMersennePrimes(const int &MAX_MERSENNE_PRIMES_TO_FIND);
    bool E6_7_isPrime(unsigned int number);
    bool E6_7_isPrime(unsigned long long number);
    unsigned long long E6_7_findMersennePrime(unsigned int number);

    // Functions for Exercise 6.8
    void E6_8_playCraps();
    void E6_8_playCrapsPoint(const unsigned short &pointToPlay);

    // Functions for Exercise 6.9
    void E6_9_playCraps();
    bool E6_9_playCrapsFirstThrow();
    bool E6_9_playCrapsPoint(const unsigned short &pointToPlay);
    bool E6_10_isPrime(int &number);

    // Functions for Exercise 6.10;
    void E6_10_findTwinPrimes();

    // Functions for Exercise 6.11
    /* These should all be included as prototypes at the top of PrintCalendar.cpp, and then have the function
     * implementations included after main()*/
    void E6_11_printMonth(int year, int month);
    void E6_11_printMonthTitle(int year, int month);
    void E6_11_printMonthName(int month);
    void E6_11_printMonthBody(int year, int month);
    int E6_11_getStartDay(int month, int year);
    int E6_11_getNumberOfDaysInMonth(int year, int month);
    bool E6_11_isLeapYear(int year);

    // Functions for Exercise 6.12
    void E6_12_areaOfPentagon();
    double E6_12_calculateArea(double length);

    // Functions for Exercise 6.13
    void E6_13_areaOfPolygons();
    double E6_13_regPolyArea(int n, double length);

    // Functions for Exercise 6.14
    void E6_14_intersectionOfTwoLines();

    // Functions for Exercise 6.15
    void E6_15_approximateSqrt();

public:

    // Covers content from all section
    int Exercise6_1();                          // (Sorting three numbers)
    int Exercise6_2();                          // (Algebra: solving quadratic equations)
    int Exercise6_3();                          // (Algebra: solving 2 x 2 linear equation)
    int Exercise6_4();                          // (Displaying the current date and time)
    int Exercise6_5();                          // (Math: Emirp)
    int Exercise6_6();                          // (Math: Palindromic prime)
    int Exercise6_7();                          // (Mersenne prime)
    int Exercise6_8();                          // (Game: craps)
    int Exercise6_9();                          // (Game: chance of winning at craps)
    int Exercise6_10();                         // (Math: twin primes)
    int Exercise6_11();                         // (Printing calendar)
    int Exercise6_12();                         // (Geometry: area of a pentagon)
    int Exercise6_13();                         // (Geometry: area of a regular polygon)
    int Exercise6_14();                         // (Geometry: intersection)
    int Exercise6_15();                         // (Approximating the square root)


};

#endif //TESTLOCATIONLOCALFORCPP_CHAPTER6EXERCISES_H

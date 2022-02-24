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
    void L6_2_solveQuadraticEquation(double a, double b, double c, double &discriminant, double &r1, double &r2);
    double L6_2computeDiscriminant(double a, double b, double c);
    double L6_2_solveQuadraticR1(double a, double b, const double &discriminant);
    double L6_2_solveQuadraticR2(double a, double b, const double &discriminant);

    // Functions for Exercise 6.3
    double L6_3_computeDenominator(const double &a, const double &b, const double &c, const double &d);
    bool L6_3_findIfSolvable(const double &denominator);
    double L6_3_computeX(const double &a, const double &b, const double &c, const double &d, const double &e, const double &f, const double &denominator);
    double L6_3_computeY(const double &a, const double &b, const double &c, const double &d, const double &e, const double &f, const double &denominator);
    void L6_3_solveEquation();

    // Functions for Exercise 6.4
    void L6_4_printCurrentDateTime();
    void L6_4_printCurrentTime(const unsigned int &totalSeconds,
                               const unsigned int &totalMinutes,
                               const unsigned int &totalHours);
    void L6_4_printHours(unsigned int totalHours);
    void L6_4_printMinutes(unsigned int totalMinutes);
    void L6_4_printSeconds(unsigned int totalSeconds);
    void L6_4_printCurrentDate(const unsigned int &totalSeconds,
                               const unsigned int &totalHours);
    unsigned short  L6_4_findTotalLeapYears(const unsigned int &totalDays);
    string L6_4_findCurrentMonth(unsigned int totalDaysOfCurrentYear,
                                 unsigned int &day,
                                 const bool &isCurrentYearLeapYear);
    void L6_4_findYear(unsigned short &currentYear,
                       const unsigned int &totalDays,
                       unsigned short &totalYearsSinceEpoch,
                       unsigned short &numberOfLeapYears);

    // Functions for Exercise 6.5
    void E6_5_findEmirp();
    bool E6_5_isPrime(int number);
    bool E6_5_isEmirp(int number);

public:

    // Covers content from all section
    int Exercise6_1();                          // (Sorting three numbers)
    int Exercise6_2();                          // (Algebra: solving quadratic equations)
    int Exercise6_3();                          // (Algebra: solving 2 x 2 linear equation)
    int Exercise6_4();                          // (Displaying the current date and time)
    int Exercise6_5();                          // (Math: Emirp)


};

#endif //TESTLOCATIONLOCALFORCPP_CHAPTER6EXERCISES_H

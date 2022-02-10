#include "Chapter2_My_Solutions.h"

void Chapter2_My_Solutions::ComputerChange() {

    // This is a very explicit way of solving the problem, written for speed.
    double totalAmount;
    int totalAmountinCents;

    // Takes the total value in from the user
    std::cout << "Enter the total amount of money as a decimal: ";
    std::cin >> totalAmount;

    // Convert from decimal to int (this means the value is in cents
    totalAmountinCents = totalAmount * 100;

    // Finds the number of dollars
    unsigned int numberOfDollars;
    numberOfDollars = totalAmountinCents / 100;
    unsigned short remainingCentsAfterDollars = totalAmountinCents % 100;

    // Finds the number of quarters
    unsigned int numberOfQuarters;
    unsigned short remainingCentsAfterQuarters;
    numberOfQuarters = remainingCentsAfterDollars / 25;
    remainingCentsAfterQuarters = remainingCentsAfterDollars % 25;

    // Finds the number of dimes
    unsigned int numberOfDimes;
    unsigned short remainingCentsAfterDimes;
    numberOfDimes = remainingCentsAfterQuarters / 10;
    remainingCentsAfterDimes = remainingCentsAfterQuarters % 10;

    // Finds the number of nickels
    unsigned int numberOfNickels;
    unsigned short remainingCentsAfterNickels;
    numberOfNickels = remainingCentsAfterDimes / 5;


    unsigned int numberOfCents;
    numberOfCents = remainingCentsAfterDimes % 5;

    std::cout << "You enter the total value of " << totalAmount << ". When broken down in to dollars and coins, it gives this composition.\n";
    std::cout << "Number of dollars: " << numberOfDollars
    << ".\nNumber of quarters: " << numberOfQuarters
    << ".\nNumber of dimes: " << numberOfDimes
    << ".\nNumber of nickels: " << numberOfNickels
    << ".\nNumber of cents: " << numberOfCents << std::endl;

}
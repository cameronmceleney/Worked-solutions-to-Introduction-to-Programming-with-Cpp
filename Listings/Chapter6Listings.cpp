#include "Chapter6Listings.h"

void Chapter6Listings::L6_1_increment(int n) {
    // Increment 'n' inside a function
    n++;
    cout << "\tn inside the function is " << n << endl;
}
int Chapter6Listings::Listing6_1() {
    // This method acts as main() for Listing 6.1, and is the book's version
    int x = 1;

    cout << "Before the call, x is " << x << endl;
    L6_1_increment(x);
    cout << "After the call, x is " << x << endl;

    return 0;
}

void Chapter6Listings::L6_2_swap(int n1, int n2) {
    // Attempt to swap two variables does not work!
    cout << "\tInside the swap function" << endl;
    cout << "\tBefore swappng n1 is " << n1
         << " n2 is " << n2 << endl;

    // Swap n1 with n2
    int temp = n1;
    n1 = n2;
    n2 = temp;

    cout << "\tAfter swapping n1 is " << n1
         << " n2 is " << n2 << endl;
}
int Chapter6Listings::Listing6_2() {
    // This method acts as main() for Listing 6.2, and is the book's version

    // Declare and initialise variables
    int num1 = 1;
    int num2 = 2;

    cout << "Before invoking the swap function, num1 is"
         << num1 << " and num2 is " << num2 << endl;

    // Invoke the swap function to attempt to swap two variables
    L6_2_swap(num1, num2);

    cout << "After invoking the swap function, num1 is " << num1
         << " and num2 is " << num2 << endl;

    return 0;
}

int Chapter6Listings::Listing6_3() {
    // Book's example of how to declare a reference variable

    int count = 1;
    int &aliasForcount = count;
    cout << "count is " << count << endl;
    cout << "aliasForcount is " << aliasForcount << endl;

    aliasForcount++;
    cout << "count is " << count << endl;
    cout << "aliasForcount is " << aliasForcount << endl;

    count = 10;
    cout << "count is " << count << endl;
    cout << "aliasForcount is " << aliasForcount << endl;

    return 0;
 }

void Chapter6Listings::L6_4_increment(int &n) {
    // Increment the value of n
    n++;
    cout << "\tThe address of n is " << &n << endl;
    cout << "\tn inside the function is " << n << endl;
}
int Chapter6Listings::Listing6_4() {
    // Book's example
    // Allows the incrementing of a variable 'x' by modifying an alias (which is within a separate function).
    int x = 1;
    cout << "The address of x is " << &x << endl;
    cout << "Before the call, x is " << x << endl;
    L6_4_increment(x);
    cout << "After the call, x is " << x << endl;

    return 0;
}

void Chapter6Listings::L6_5_swap(int &n1, int &n2) {
    // Swap two variables
    cout << "\tInside the swap function" << endl;
    cout << "\tBefore swapping n1 is " << n1
         << " n2 is " << n2 << endl;

    // Swap n1 with n2
    int temp = n1;
    n1 = n2;
    n2 = temp;

    cout << "\tAfter swapping n1 is " << n1
         << " n2 is " << n2 << endl;
}
int Chapter6Listings::Listing6_5() {
    // Book's version

    //Declare and initialise variables
    int num1 = 1;
    int num2 = 2;

    cout << "Before invoking the swap function, n1 is " << num1 << " and n2 is " << num2 << endl;

    // Invoke the swap function to attempt to swap two variables
    L6_5_swap(num1, num2);

    cout << "After invoking the swap function, n1 is " << num1 << " and n2 is " << num2 << endl;

    return 0;
}

// Below variables are used in Listing 6.6 ONLY
int L6_6_y; // Global variable, default to 0
int L6_6_v1 = 10; // Global variable initialised at 10
void Chapter6Listings::L6_6_t1() {

    int x = 1;
    cout << "x is " << x << endl;
    cout << "y is " << L6_6_y << endl;
    x++;
    L6_6_y++;
}
void Chapter6Listings::L6_6_t2() {

    int x = 1;
    cout << "x is " << x << endl;
    cout << "y is " << L6_6_y << endl;
}
int Chapter6Listings::Listing6_6() {

    L6_6_t1();
    L6_6_t2();

    int L6_6_v1 = 5;
    cout << "\nlocal variable v1 is " << L6_6_v1 << endl;
    cout << "global variable v1 is " << ::L6_6_v1 << endl;

    return 0;
}

void Chapter6Listings::L6_7_t1() {
    // Illustrates how x persists for the length of the program, whereas y is different each function call
    static int x = 1;
    int y = 1;
    x++;
    y++;
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
}
int Chapter6Listings::Listing6_7() {
    // Book's version

    L6_7_t1();
    L6_7_t1();

    return 0;
}

inline void L6_8_f(int month, int year) {

    cout << "month is " << month << endl;
    cout << "year is " << year << endl;
}
int Chapter6Listings::Listing6_8() {
    // Book's version
    int month = 10, year = 2008;
    L6_8_f(month, year); // Invoke inline function
    L6_8_f(9,2010); // Invoke inline function

    return 0;
}

int Chapter6Listings::Listing6_9() {
    // Book's version. Shows what Listing 6.8 could look like when inline function is expanded

    int month = 10, year = 2008;
    cout << "month is " << month << endl;
    cout << "year is " << year << endl;
    cout << "month is " << 9 << endl;
    cout << "year is " << 2010 << endl;

    return 0;
}

void Chapter6Listings::L6_10_printArea(double radius = 1) {
    // Display area of a circle
    double area = radius * radius * 3.14159;
    cout << "area is " << area << endl;
}
int Chapter6Listings::Listing6_10() {
    // Book's version. Highlights ability to declare a function with a default argument for pass-by-value parameters.

    L6_10_printArea(); // Uses default value when invoking function
    L6_10_printArea(4); // Passes parameter to function when invoked

    return 0;
}

int Chapter6Listings::Listing6_11() {

    // Prompt the user to enter year
    cout << "Enter full year (e.g. 2001): ";
    int year;
    cin >> year;
    // Check if the entered year is supported
    if (year < 1800) {cout << "You entered an invalid year";return 0;}

    // Prompt the user to select whether to print an annual calendar, or a single month
    cout << "Print an annual calendar (A) or a single month's calendar (M): ";
    char calendarChoice;
    cin >> calendarChoice;

    if (isalpha(calendarChoice)) {
        // Check if the user entered a letter, then proceed with further questions to select a calendar to print
        if (toupper(calendarChoice) == 'A') {
            // Prints a calendar for a full year

            for (int i = 1; i <= 12; i++)
                // Print calendar for each month of the year
                L6_11_printMonth(year, i);

            return 0;

        } else if (toupper(calendarChoice) == 'M') {
            // Print a single month as chosen by the user

            // Prompt the user to enter the month
            cout << "Enter month in number between 1 and 12: ";
            int month;
            cin >> month;

            // Check if the entered month is valid
            if (month < 1 || month > 12) {cout << "You entered an invalid month";return 0;}

            // Print calendar for the given month
            L6_11_printMonth(year, month);

            return 0;

        } else {
            // Output an error message if user enters an invalid letter
            cout << "You did not enter either character \'A\' or \'M\'";
            return 0;

        }
    } else {
        // Output an error message if user does not enter a letter char
        cout << "You did not enter a letter";
        return 0;

    }
}
void Chapter6Listings::L6_11_printMonth(int year, int month) {
    // Print the calendar for a month in a year

    // Add spacing before header is printed
    cout << "\n";

    // Print the headings of the calendar
    L6_11_printMonthTitle(year, month);

    // Print the body of the calendar
    L6_11_printMonthBody(year, month);

    // Add spacing after body is printed
    cout << "\n";
}
void Chapter6Listings::L6_11_printMonthTitle(int year, int month) {
    // Print the month title, e.g., May, 1999

    L6_11_printMonthName(month);
    cout << " " << year << '\n';
    cout << "----------------------------" << '\n';
    cout << " Sun Mon Tue Wed Thu Fri Sat" << '\n';
}
void Chapter6Listings::L6_11_printMonthName(int month) {
    // Get the English name for the month

    switch(month) {

        case 1:
            cout << setw(12) << "January";
            break;

        case 2:
            cout << setw(12) << "February";
            break;

        case 3:
            cout << setw(12) << "March";
            break;

        case 4:
            cout << setw(12) << "April";
            break;

        case 5:
            cout << setw(12) << "May";
            break;

        case 6:
            cout << setw(12) << "June";
            break;

        case 7:
            cout << setw(12) << "July";
            break;

        case 8:
            cout << setw(12) << "August";
            break;

        case 9:
            cout << setw(12) << "September";
            break;

        case 10:
            cout << setw(12) << "October";
            break;

        case 11:
            cout << setw(12) << "November";
            break;

        case 12:
            cout << setw(12) << "December";
            break;
    }
}
void Chapter6Listings::L6_11_printMonthBody(int year, int month) {
    // Print month body

    // Get start day of the week for the first date in the month
    int startDay = L6_11_getStartDay(year, month);

    // Get number of days in the month
    int numberOfDaysInMonth = L6_11_getNumberOfDaysInMonth(year, month);

    // Pad space before the first day of the month
    for (int i = 0; i < startDay; i++)
        cout << "\t";

    for (int i = 1; i <= numberOfDaysInMonth; i++) {
        cout << setw(4) << i;

        if ((i + startDay) % 7 == 0)
            cout << '\n';
    }
}
int Chapter6Listings::L6_11_getStartDay(int year, int month) {
    // Get the start day of the first day in a month

    // Get total number of days since 1st Jan 1800
    int startDay1800 = 3; // Happen to know this was a Wednesday
    int totalNumberOfDays = L6_11_getTotalNumberOfDays(year, month);

    // Return the start day
    return (totalNumberOfDays + startDay1800) % 7;
}
int Chapter6Listings::L6_11_getTotalNumberOfDays(int year, int month) {
    // Get the total number of days since January 1st, 1800

    int total = 0;

    // Get the total days from 1800 to (year - 1)
    for (int i = 1800; i < year; i++) {

        if (L6_11_isLeapYear(i))
            total += 366;
        else
            total += 365;
    }

    // Add days from Jan to the month prior to the calendar month
    for (int i = 1; i < month; i++)
        total += L6_11_getNumberOfDaysInMonth(year, i);

    return total;
}
int Chapter6Listings::L6_11_getNumberOfDaysInMonth(int year, int month) {
    // Get the number of days in a month

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        if (L6_11_isLeapYear(year))
            return 29;
        else
            return 28;
}
bool Chapter6Listings::L6_11_isLeapYear(int year) {
    // Determine if it is a leap year

    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}


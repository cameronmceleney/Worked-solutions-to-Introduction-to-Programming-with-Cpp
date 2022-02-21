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

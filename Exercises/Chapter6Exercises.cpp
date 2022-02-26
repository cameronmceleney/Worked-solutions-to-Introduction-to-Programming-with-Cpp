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

int Chapter6Exercises::Exercise6_6() {

    /* (** difficulty)
     *
     * A palindromic prime is a prime number and also a palindromic number. For example, 131 is a prime and also a
     * palindromic prime. So are 313 and 757. Write a program that displays the first 100 palindromic prime numbers.
     * Display 10 numbers per line and align the numbers properly, as follows:
     *
     *      2       3       5       7       11      101     131     151     181     191
     *    313     353     373     383      727      757     787     797     919     929
     *    ...     ...     ...     ...      ...      ...     ...     ...     ...     ...
     */

    const int NUMBERS_PER_LINE = 10, TOTAL_PALINDROMICPRIMES_TO_FIND = 100; // consts come from question

    E6_6_printPalindromicPrimes(NUMBERS_PER_LINE, TOTAL_PALINDROMICPRIMES_TO_FIND); // Invoke function to find palindromic primes

    return 0;
}
void Chapter6Exercises::E6_6_printPalindromicPrimes(const int &NUMBERS_PER_LINE,
                                                    const int &TOTAL_PALINDROMICPRIMES_TO_FIND) {
    // Prints a set number of 'palindromic primes' by first testing if the number is prime, before finding out if
    // it is also palindromic

    int totalPalinPrimesFound = 0;
    int number = 2; // 2 is the first palindromic prime, so can begin here

    while (totalPalinPrimesFound < TOTAL_PALINDROMICPRIMES_TO_FIND) {

        if(E6_6_isPrime(number)) {
            // Test if a number is prime

            if (E6_6_isPalindrome(number)) {
                // If number is prime, then test if number is a palindrome

                // If number is both prime and palindromic, then print to user
                if ((totalPalinPrimesFound + 1) % NUMBERS_PER_LINE == 0)
                    // Takes a new line when there NUMBERS_PER_LINE per each line
                    cout << setw(8) << number << endl;
                else
                    cout << setw(8) << number;

                totalPalinPrimesFound++; // Increment counter at end of all tests
            }
        }

        number++;
    }
}
bool Chapter6Exercises::E6_6_isPrime(int &number) {
    // Check whether number is prime (exact copy of Listing 5.5 and Exercise 5.9)

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
bool Chapter6Exercises::E6_6_isPalindrome(int &number) {
    // Returns true if a given 'number' is palindromic (Exact copy of Exercise 5.5).

    int reversedNumber = 0;
    int tempNumber = number; // copy original number to tempNumber; this is what we will remove digits from as we reverse it

    do {
        // Add last digit of number to reversed number, after moving digits to the left.
        reversedNumber = reversedNumber * 10 + tempNumber % 10;
        tempNumber /= 10; // Remove added digit from temporary number

    } while (tempNumber > 0);

    if (number == reversedNumber)
        return true;
    else
        return false;
}

int Chapter6Exercises::Exercise6_7() {

    /* (** difficulty)
     *
     * A prime is called a Mersenne prime if it can be written in the form (pow(2, p) - 1) for some positive integer
     * p. write a program that finds all Mersenne primes with p <= 61 and displays the output as shown below:
     *
     *                  p               Mp
     *
     *                  2                3
     *                  3                7
     *                  5               31
     *                  7              127
     *                ...              ...
     */

    int MAX_P_VALUE = 61;
    // Fails to find the p(61) mersenne number
    E6_7_printMersennePrimes(MAX_P_VALUE);

    return 0;
}
void Chapter6Exercises::E6_7_printMersennePrimes(const int &MAX_MERSENNE_PRIMES_TO_FIND) {
    // Finds the first MAX_MERSENNE_PRIMES_TO_FIND Mersenne Primes (Mp)

    unsigned int number = 2; // 2 is the first palindromic prime, so can begin here

    cout << setw(8) << 'p' << setw(20) << "Mp" << "\n\n";

    while (number <= MAX_MERSENNE_PRIMES_TO_FIND) {

        if (E6_7_isPrime(number)) {
            // First find a prime number

            // Test if number is a Mersenne prime
            auto mersennePrime = E6_7_findMersennePrime(number);

            // E6_7_findMersennePrime returns 1 (author's attempt to mirror error codes) if the number is not a Mp
            if (mersennePrime > 1.0) {cout << setw(8) << number << setw(16) << mersennePrime << '\n';}
        }

        number++;
    }
}
bool Chapter6Exercises::E6_7_isPrime(unsigned int number) {
    // Check whether number is prime (exact copy of Listing 5.5 and Exercise 5.9)

    for (int divisor = 2; divisor <= sqrt(number); divisor++)
    {
        if (number % divisor == 0)
        {
            // If true, number is not prime
            return false;
        }
    }

    return true; // Number is prime
}
bool Chapter6Exercises::E6_7_isPrime(unsigned long long number) {
    // Check whether number is prime (exact copy of Listing 5.5 and Exercise 5.9)

    auto number2 = static_cast<unsigned long long>(number);
    for (int divisor = 2; divisor <= sqrt(number) ; divisor++)
    {
        if (number2 % divisor == 0)
        {
            // If true, number is not prime
            return false;
        }
    }

    return true; // Number is prime
}
unsigned long long Chapter6Exercises::E6_7_findMersennePrime(unsigned int number) {
    // Use the formula [pow(2, p) - 1] to find a Mersenne prime

    auto possibleMersennePrime = static_cast<unsigned long long>(pow(2.0, number) - 1);

    if (E6_7_isPrime(possibleMersennePrime))
        return possibleMersennePrime;
    else
        return 1.0;
}

int Chapter6Exercises::Exercise6_8() {

    /* (** difficulty)
     *
     * Craps is a popular dice game played in casinos. Write a program to play a variation of the game, as follows:
     *
     *       Roll two dice. Each die has six faces representing values 1,2,..., and 6, respectively. Check
     *       the sum is 7 or 11. If the sum is 2,3, or 12 (called craps), you lose; if the sum is 7 or
     *       11 (called natural), you win; if the sum is another value (i.e. 4,5,6,8,9, or 10), a point
     *       is established. Continue until you roll either a 7 (you lose) or the same point value (you
     *       win).
     */

    E6_8_playCraps();

    return 0;
}
void Chapter6Exercises::E6_8_playCraps() {
    // Plays the game of Craps

    srand(time(0));

    unsigned short dice1 = rand() % 6 + 1;
    unsigned short dice2 = rand() % 6 + 1;

    unsigned short sumOfDice = dice1 + dice2;

    cout << "You rolled " << dice1 << " + " << dice2 << " = " << sumOfDice << "\n";

    if (sumOfDice == 2 || sumOfDice == 3 || sumOfDice == 12)
        cout << "You lose";
    else if (sumOfDice == 7 || sumOfDice == 11)
        cout << "You win";
    else {
        cout << "point is " << sumOfDice << "\n";
        E6_8_playCrapsPoint(sumOfDice);
    }
}
void Chapter6Exercises::E6_8_playCrapsPoint(const unsigned short &pointToPlay) {
    // If a point is established, continues play until the player wins or loses

    bool continuePoint = true;

    while (continuePoint) {

        unsigned short dice1 = rand() % 6 + 1;
        unsigned short dice2 = rand() % 6 + 1;
        unsigned short sumOfPointsDice = dice1 + dice2;

        cout << "You rolled " << dice1 << " + " << dice2 << " = " << sumOfPointsDice << "\n";

        if (sumOfPointsDice == 7) {
            cout << "You lose";
            continuePoint = false;
        } else if (sumOfPointsDice == pointToPlay) {
            cout << "You win";
            continuePoint = false;
        }
    }
}

int Chapter6Exercises::Exercise6_9() {

    /* (** difficulty)
     *
     * Revise Exercise 6.8 to run it 10000 times and display the number of winning games.
     */

    srand(time(0));

    E6_9_playCraps();

    return 0;
}
void Chapter6Exercises::E6_9_playCraps() {
    // Plays the game of Craps a set number of times

    const int MAX_GAMES = 10000;
    unsigned short totalGamesPlayed = 0, numberOfLoses = 0, numberOfWins = 0;

    while (++totalGamesPlayed < MAX_GAMES) {

        bool isPlayerWinner = E6_9_playCrapsFirstThrow();

        if (isPlayerWinner)
            // If function is true, then you won
            numberOfWins++;
        else
            // If function is false, then you lost
            numberOfLoses++;
    }

    // Inform user of their results
    cout << "For " << MAX_GAMES << " games, you had " << numberOfWins << " wins, and " << numberOfLoses << " loses.";
}
bool Chapter6Exercises::E6_9_playCrapsFirstThrow() {
    // Plays the first round of craps, to see whether a point needs to be played

    // As per game rules, two dice must be thrown. Also disables compiler warning about rand()
    int dice1 = 1 + rand() % 6; // NOLINT(cert-msc30-c, cert-msc50-cpp)
    int dice2 = 1 + rand() % 6; // NOLINT(cert-msc30-c, cert-msc50-cpp)

    unsigned short sumOfDice = dice1 + dice2; // Computes player's score for the throw

    bool didPlayerWin;

    if (sumOfDice == 2 || sumOfDice == 3 || sumOfDice == 12)
        // Conditions for player to lose
        didPlayerWin = false;
    else if (sumOfDice == 7 || sumOfDice == 11)
        // Conditions for player to win
        didPlayerWin = true;
    else
        // Player didn't win or lose, so a point must be played
        didPlayerWin = E6_9_playCrapsPoint(sumOfDice);

    // Returns result to main() function
    if (didPlayerWin)
        return true;
    else
        return false;
}
bool Chapter6Exercises::E6_9_playCrapsPoint(const unsigned short &pointToPlay) {
    // If a point is established, continues play until the player wins or loses

    bool isPointOver, didPlayerWin;

    do {

        // Throws dice & disables warnings about rand()
        int dice1 = rand() % 6 + 1; // NOLINT(cert-msc30-c, cert-msc50-cpp)
        int dice2 = rand() % 6 + 1; // NOLINT(cert-msc30-c, cert-msc50-cpp)

        unsigned short sumOfPointsDice = dice1 + dice2; // finds player's score

        if (sumOfPointsDice == 7) {
            // Condition for player to lose point
            isPointOver = true;
            didPlayerWin = false;
        } else if (sumOfPointsDice == pointToPlay) {
            // Condition for player to win point
            isPointOver = true;
            didPlayerWin = true;
        } else
            // Player had a NULL result, so point must continue to be played
            isPointOver = false;
    } while (!isPointOver);

    // Returns result to FirstThrow function
    if (didPlayerWin)
        return true;
    else
        return false;
}

int Chapter6Exercises::Exercise6_10() {

    /* (** difficulty)
     *
     * Twin primes are a pair of prime numbers that differ by 2. For example, 3 and 5 are prime numbers, as are 5 and 7,
     * and 11 and 13. Write a program to find all twin primes less than 1000. Display the output as follows:
     *
     *              (3, 5)
     *              (5, 7)
     */

    E6_10_findTwinPrimes();

    return 0;
}
void Chapter6Exercises::E6_10_findTwinPrimes() {
    // Searches below a given limit to find twin primes

    const int UPPER_LIMIT = 1000;
    int currentPrime = 3, previousPrime = 2, currentNumber = 3;

    while (++currentNumber <= UPPER_LIMIT) {

        if (E6_10_isPrime(currentNumber)) {
            previousPrime = currentPrime;
            currentPrime = currentNumber;

            if (previousPrime + 2 == currentPrime)
                cout << "(" << previousPrime << ", " << currentPrime << ")\n";
        }
    }
}
bool Chapter6Exercises::E6_10_isPrime(int &number) {
    // Check whether number is prime (exact copy of Listing 5.5)

    for (int divisor = 2; divisor <= sqrt(number); divisor++)
    {
        if (number % divisor == 0)
        {
            // If true, number is not prime
            return false; // Number is not a prime
        }
    }

    return true; // Number is prime
}

int Chapter6Exercises::Exercise6_11() {

    /* (** difficulty)
     *
     * Exercise 3.18 uses Zeller's congruence to calculate the day of the week. Simplify Listing 6.11,
     * PrintCalendar.cpp, using Zeller's algorithm to get the start day of the month.
     *
     * (Note: This code is a direct copy of Listing 6.11, before being amended to include Zeller's algorithm.)
     */

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
                E6_11_printMonth(year, i);

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
            E6_11_printMonth(year, month);

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
void Chapter6Exercises::E6_11_printMonth(int year, int month) {
    // Print the calendar for a month in a year

    // Add spacing before header is printed
    cout << "\n";

    // Print the headings of the calendar
    E6_11_printMonthTitle(year, month);

    // Print the body of the calendar
    E6_11_printMonthBody(year, month);

    // Add spacing after body is printed
    cout << "\n";
}
void Chapter6Exercises::E6_11_printMonthTitle(int year, int month) {
    // Print the month title, e.g., May, 1999

    E6_11_printMonthName(month);
    cout << " " << year << '\n';
    cout << "----------------------------" << '\n';
    cout << " Sun Mon Tue Wed Thu Fri Sat" << '\n';
}
void Chapter6Exercises::E6_11_printMonthName(int month) {
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

        default:
            // Error case
            exit(0);
    }
}
void Chapter6Exercises::E6_11_printMonthBody(int year, int month) {
    // Print month body

    // Get start day of the week for the first date in the month
    int startDay = E6_11_getStartDay(month, year);

    // Get number of days in the month
    int numberOfDaysInMonth = E6_11_getNumberOfDaysInMonth(year, month);

    // Pad space before the first day of the month. If startDay = 7, then Sunday is the first day of the month and
    // there should be no padding.
    for (int i = 0; startDay != 7 && i < startDay; i++)
        cout << "\t";

    // Print value of each day, taking a new line each time a row is full (final day of row is Saturday)
    for (int i = 1; i <= numberOfDaysInMonth; i++) {
        cout << setw(4) << i;

        if ((i + startDay) % 7 == 0)
            cout << '\n';
    }
}
int Chapter6Exercises::E6_11_getStartDay(int month, int year) {
    // Use Zeller's congruence algorithm from Exercise 3.8 to find the first day of the month
    int dayOfTheWeek, dayOfTheWeekZeller, day, century, yearOfTheCentury;

    // Zeller treats January and February as months of the following year, instead of being part of the current year
    switch (month) {
        case 1: month = 13;
            year--;
            break;
        case 2: month = 14;
            year--;
            break;
        default: break;
    }

    // Computation of century and yearOfTheCentury must be done after the Jan/Feb conversion to avoid LOGIC ERROR
    century = year / 100;
    yearOfTheCentury = year % 100;

    // Want the first day of the month, hence why 'day' is initialised as 1
    day = 1;

    // Uses Zeller's algorithm to find the day of the week
    dayOfTheWeekZeller = (day
                          + (26 * (month + 1) / 10)
                          + yearOfTheCentury
                          + (yearOfTheCentury / 4)
                          + (century / 4)
                          + (5 * century)) % 7;

    // Need to convert dayOfTheWeek output. Case number in switch statement is what Zeller uses, while the
    // initialisations of dayOfTheWeek is what PrintCalendar uses
    switch (dayOfTheWeekZeller) {
        case 0:
            // Saturday
            dayOfTheWeek = 6;
            break;

        case 1:
            // Sunday
            dayOfTheWeek = 7;
            break;

        case 2:
            // Monday
            dayOfTheWeek = 1;
            break;

        case 3:
            // Tuesdau
            dayOfTheWeek = 2;
            break;

        case 4:
            // Wednesday
            dayOfTheWeek = 3;
            break;

        case 5:
            // Thursday
            dayOfTheWeek = 4;
            break;

        case 6:
            // Friday
            dayOfTheWeek = 5;
            break;

        default:
            // Error case
            exit(0);
    }

    return dayOfTheWeek;
}
int Chapter6Exercises::E6_11_getNumberOfDaysInMonth(int year, int month) {
    // Get the number of days in a month

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        if (E6_11_isLeapYear(year))
            return 29;
        else
            return 28;
    else
        return 0;
}
bool Chapter6Exercises::E6_11_isLeapYear(int year) {
    // Determine if it is a leap year

    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int Chapter6Exercises::Exercise6_12() {

    /* (- difficulty)
     *
     * The area of a pentagon can be computed using the following formula:
     *
     *          area = (5 * pow(s,2)) / (4 * tan(Pi / 5))
     *
     * Write a program that prompt the user to enter the side of a pentagon and displays the pentagon's area.
     */

    E6_12_areaOfPentagon();

    return 0;
}
void Chapter6Exercises::E6_12_areaOfPentagon() {
    // Function to find the area of a pentagon

    // Prompt user for input
    cout << "Enter the length of the side of a pentagon: ";
    double length;
    cin >> length;

    cout << "The area of a pentagon, with sides of length "
         << fixed << setprecision(2) << length
         << ", is " << E6_12_calculateArea(length)
         << '\n';
}
double Chapter6Exercises::E6_12_calculateArea(double s) {
    // Calculates area of a pentagon, where 's' is the length of a side of the pentagon

    double area = (5 * pow(s, 2)) / (4 * tan(M_PI / 5));

    return area;
}

int Chapter6Exercises::Exercise6_13() {

    /* (* difficulty)
     *
     * A regular polygon is an n-sided polygon where all sides are of the same length and all angles have the same
     * degree (i.e., the polygon is both equilateral and equiangular). The formula for computing the area of a regular
     * polygon is:
     *
     *                      area = (n * pow(s, 2)) / (4 * tan(Pi / n))
     *
     * where n is the number of sides and s is the length of a side. Write a function that returns a regular polygon's
     * area using the following header:
     *
     *                  double regPolyArea(int n, double s)
     *
     *  Write a main function that prompts the user for the number of sides (n) and the length of a side (s). Display
     *  the number and length of the sides and the resulting area of the polygon in the following format:
     *
     *                  An n-sided polygon with sides of length s has an area of A.
     */

    E6_13_areaOfPolygons();

    return 0;
}
void Chapter6Exercises::E6_13_areaOfPolygons() {
    // Function to find the area of a pentagon

    // Prompt user for input
    cout << "Enter the number of sides: ";
    int numberOfSides;
    cin >> numberOfSides;

    cout << "Enter the length of a side of the polygon: ";
    double lengthOfSides;
    cin >> lengthOfSides;

    cout << fixed << setprecision(2)
         << "An " << numberOfSides << "-sided polygon with sides of length "
         << lengthOfSides << " has an area of "
         << E6_13_regPolyArea(numberOfSides, lengthOfSides) << ".\n";
}
double Chapter6Exercises::E6_13_regPolyArea(int n, double s) {
    // Calculates area of a pentagon, where 's' is the length of a side of the pentagon

    double area = (n * pow(s, 2)) / (4 * tan(M_PI / n));

    return area;
}
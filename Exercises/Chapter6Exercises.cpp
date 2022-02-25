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
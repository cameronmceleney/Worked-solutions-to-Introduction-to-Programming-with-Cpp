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


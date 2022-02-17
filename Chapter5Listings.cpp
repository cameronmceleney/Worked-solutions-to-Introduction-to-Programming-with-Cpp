#include "Chapter5Listings.h"

int Chapter5Listings::L5_1_max(int num1, int num2) {

    int result;
    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}

int Chapter5Listings::L5_1_MAIN() {

    using namespace std;

    int i = 5;
    int j = 2;
    int k = Chapter5Listings::L5_1_max(i, j);

    cout << "The maximum between " << i << " and " << j << " is " << k;

    return 0;
}

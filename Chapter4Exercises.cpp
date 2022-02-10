#include "Chapter4Exercises.h"

void Chapter4Exercises::Exercise4_1() {

    using namespace std;

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (i % 3 == 0) continue;
        sum += i;
    }

    cout << sum;
    int sum2 = 0;
    int j = 0;
    while (j < 4) {
        if (j % 3 == 0) {continue;}
        sum2 += j;
        j++;
    }
    cout << sum2;

}
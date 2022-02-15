#include "functions.h"
#include <iostream>
#include <limits>
using namespace std;



int* search_min(double *arr, int n) {
    int* new_arr = new int[4] {0};
    int min_1 = INT_MAX, min_2 = INT_MAX, min_3 = INT_MAX, min_4 = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min_1) {
            new_arr[3] = new_arr[2];
            new_arr[2] = new_arr[1];
            new_arr[1] = new_arr[0];
            new_arr[0] = i + 1;
            min_4 = min_3;
            min_3 = min_2;
            min_2 = min_1;
            min_1 = arr[i];
        } else if (arr[i] < min_2) {
            new_arr[3] = new_arr[2];
            new_arr[2] = new_arr[1];
            new_arr[1] = i + 1;
            min_4 = min_3;
            min_3 = min_2;
            min_2 = arr[i];
        } else if (arr[i] < min_3) {
            new_arr[3] = new_arr[2];
            new_arr[2] = i + 1;
            min_4 = min_3;
            min_3 = arr[i];
        } else if (arr[i] < min_4) {
            new_arr[3] = i + 1;
            min_4 = arr[i];
        }
    }
    return new_arr;
}


int checking_number(int n, string answer) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << answer;
        cin >> n;
    }
    return n;
}

// utility.cpp
// Anika Arora, Gabriel Fei
// 5/29/20

#include "utility.h"
#include <iostream> 
#include <algorithm>
using namespace std;

double med(double arr[], int x) {
    int midpoint = x/2;
    sort(arr, x + arr);
    if(x%2 == 0) {
        return (arr[midpoint] + arr[midpoint + 1])/2;
    }
    else {
        return arr[midpoint];
    }
}

double min(double arr[], int x) {
    double minimum = arr[0];
    for (int i = 0; i < x; i++) {
        if(arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

double max(double arr[], int x) {
    double maximum = arr[0];
    for (int i = 0; i < x; i++) {
        if(arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}
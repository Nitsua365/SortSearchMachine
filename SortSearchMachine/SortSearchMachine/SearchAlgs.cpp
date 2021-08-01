#include "SearchAlgs.hpp"


int SearchAlgorithms::BinarySearch(int a[], int key, const int& SIZE) {
    
    int lo = 0, hi = SIZE - 1, mid;
    
    while (lo <= hi) {
        
        mid = floor(lo + hi) / 2;
        
        if (key < a[mid]) {
            hi = mid - 1;
        }
        else if (key > a[mid]) {
            lo = mid + 1;
        }
        else if (key == a[mid]) {
            return mid;
        }
        else {
            break;
        }
    }
    
    return -1;
}

int SearchAlgorithms::LinearSearch(int a[], int key, const int& SIZE) {
    for (int i = 0; i < SIZE - 1; i++) {
        if (a[i] == key) { return i; }
    }
    return -1;
}

bool SearchAlgorithms::verifySort(int a[], const int& SIZE) {
    
    int count = 0;
    
    while (count-- > 1) {
        if (a[count] < a[count - 1])
            return false;
    }
    
    return true;
}

#include "SortAlgs.h"

SortingAlgorithms::SortingAlgorithms() {
    this->size = 0;
}

SortingAlgorithms::SortingAlgorithms(const int & size) {
    this->size = size;
}


void SortingAlgorithms::merge(int a[], int beg, int mid, int end) {
    
    const int lArrSize = mid - beg + 1, rArrSize = end - mid;
    
    int subArrayOneCounter = 0, subArrayTwoCounter = 0, combinedCount = beg;
    
    int lArr[lArrSize], rArr[rArrSize];
    
    for (int i = 0; i < lArrSize; i++) {
        lArr[i] = a[i + beg];
    }
    for (int i = 0; i < rArrSize; i++) {
        rArr[i] = a[i + mid + 1];
    }
    
    while (subArrayOneCounter < lArrSize || subArrayTwoCounter < rArrSize) {
        
        if (subArrayOneCounter < lArrSize && subArrayTwoCounter < rArrSize) {
            if (lArr[subArrayOneCounter] < rArr[subArrayTwoCounter]) {
                a[combinedCount] = lArr[subArrayOneCounter];
                subArrayOneCounter++;
            }
            else {
                a[combinedCount] = rArr[subArrayTwoCounter];
                subArrayTwoCounter++;
            }
        }
        else if (subArrayOneCounter < lArrSize) {
            a[combinedCount] = lArr[subArrayOneCounter];
            subArrayOneCounter++;
        }
        else if (subArrayTwoCounter < rArrSize) {
            a[combinedCount] = rArr[subArrayTwoCounter];
            subArrayTwoCounter++;
        }
        
        
        combinedCount++;
    }
    
}

void SortingAlgorithms::merge_sort(int a[], int begin, int end) {
    if (begin < end) {
    
        int mid = begin + (end - begin) / 2;
        
        this->merge_sort(a, begin, mid);
        this->merge_sort(a, mid + 1, end);
        this->merge(a, begin, mid, end);
    }
}

void SortingAlgorithms::bubbleDown(int a[], int ndx, const int& size) {
    int child1 = (2 * ndx) + 1;
    int child2 = (2 * ndx) + 2;
    
    if (child1 < size && (a[child1] > a[ndx] || a[child2] > a[ndx])) {
        
        int greaterChild = child1;
        
        if (child2 < size && a[child2] > a[greaterChild]) {
            greaterChild = child2;
        }
        
        if (a[greaterChild] > a[ndx]) {
            swap(a[greaterChild], a[ndx]);
            bubbleDown(a, greaterChild, size);
        }
    }
}

void SortingAlgorithms::bubbleUp(int a[], int ndx) {
    int parent = ((ndx - 1) / 2);
    
    if (a[parent] > a[ndx]) {
        return;
    }
    
    if (a[ndx] > a[parent]) {
        swap(a[ndx], a[parent]);
        bubbleUp(a, parent);
    }
}

void SortingAlgorithms::make_heap(int a[]) {
    for (int i = floor(this->size / 2) - 1; i >= 0; i--) {
        bubbleDown(a, i, this->size - 1);
    }
}

void SortingAlgorithms::heapSort(int a[]) {
    
    make_heap(a);
    
    int heapSize = this->size - 1;
    while (heapSize >= 0) {
        
        swap(a[0], a[heapSize]);
        
        bubbleDown(a, 0, heapSize);
        
        heapSize--;
    }
}

int SortingAlgorithms::partition(int a[], int left, int right) {
    
    int pivot = a[right];
     
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    
    swap(a[i + 1], a[right]);
    return (i + 1);
}

void SortingAlgorithms::quick_sort(int a[], int left, int right) {
    if (left < right) {
        int part = partition(a, left, right);
        quick_sort(a, left, part - 1);
        quick_sort(a, part + 1, right);
    }
}

void SortingAlgorithms::bubbleSort(int a[], const int& SIZE) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (a[i] < a[j]) { swap(a[i], a[j]); }
        }
    }
}

void SortingAlgorithms::insertionSort(int a[]) {
    
    const int SIZE = this->size;
    
    for (int i = 1; i < SIZE; i++) {
        
        int key = a[i];
        int j = i - 1;
        
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        
        a[j + 1] = key;
    }
    
}

void SortingAlgorithms::selectionSort(int a[]) {
    int minNdx = 0, j = 0;
    
    for (int i = 0; i < this->size - 1; i++) {
        
        minNdx = i;
        for (int j = i + 1; j < this->size; j++) {
            if (a[j] < a[minNdx])
                minNdx = j;
        }
        
        swap(a[i], a[minNdx]);
    }
}

void SortingAlgorithms::printArr(ostream &os, int a[]) {
    for (int i = 0; i < this->size -1; i++) {
        cout << a[i] << endl;
    }
}

int SortingAlgorithms::getMax(int a[]) {
    int max = INT_MIN;
    for (int i = 0; i < this->size; i++) {
        if (max < a[i]) { max = a[i]; }
    }
    
    return max;
}

int SortingAlgorithms::getMin(int a[]) {
    int min = INT_MIN;
    for (int i = 0; i < this->size; i++) {
        if (min < a[i]) { min = a[i]; }
    }
    
    return min;
}

void SortingAlgorithms::bogoSort(int a[], SearchAlgorithms &verify) {
    srand(time(0));
    
    while (!verify.verifySort(a, this->size)) {
        for (int i = 0; i < this->size; i++) {
            swap(a[i], a[rand() % this->size]);
        }
    }
}

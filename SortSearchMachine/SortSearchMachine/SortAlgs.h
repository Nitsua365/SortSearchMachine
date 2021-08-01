#ifndef SortAlgs_h
#define SortAlgs_h

#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
#include "SearchAlgs.hpp"

using namespace std;

class SortingAlgorithms {
private:
    int size;
    
    void merge(int a[], int beg, int mid, int end);
    void make_heap(int a[]);
    void bubbleDown(int a[], int ndx, const int& size);
    void bubbleUp(int a[], int ndx);
    
    int partition(int a[], int left, int right);
    
    void printArr(ostream &os, int a[]);
    
protected:
    void setSize(int a) { this->size = a; }
    int getMax(int[]);
    int getMin(int[]);
    
public:
    SortingAlgorithms();
    SortingAlgorithms(const int &size);
    
    void merge_sort(int[], int, int);
    void quick_sort(int[], int, int);
    void heapSort(int[]);
    void selectionSort(int[]);
    void bubbleSort(int[], const int&);
    void insertionSort(int[]);
    void bogoSort(int[], SearchAlgorithms&);
    
    int getSize() const { return this->size; }
    
};

#endif /* SortAlgs_h */

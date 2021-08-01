
#ifndef NonInplaceSortAlgs_h
#define NonInplaceSortAlgs_h

#include "SortAlgs.h"

class NonInplaceSortAlgs : protected SortingAlgorithms {
private:
    int* data;
    
public:
    NonInplaceSortAlgs(const int& size) { this->setSize(size); }
    ~NonInplaceSortAlgs() { delete [] data; }
    
    void radixSort(int[]);
    void bucketSort(int[]);
};


#endif /* NonInplaceSortAlgs_h */

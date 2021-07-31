#include "NonInplaceSortAlgs.h"

void NonInplaceSortAlgs::bucketSort(int a[]) {
    const int DATA_SIZE = getMax(a) + 1;
    
    this->data = new int [DATA_SIZE];
    
    const int SIZE = this->getSize();
    
    for (int i = 0; i < DATA_SIZE; i++) {
        this->data[i] = 0;
    }
    
    for (int i = 0; i < SIZE; i++) {
        this->data[a[i]]++;
    }
    
    int count = 0;
    
    for (int i = 0; i < DATA_SIZE; i++) {
            
        for (int j = 0; j < this->data[i]; j++) {
                
            a[count] = i;
            count++;
        }
            
    }
        

}

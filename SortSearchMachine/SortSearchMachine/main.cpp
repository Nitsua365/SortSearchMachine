#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <ctime>
#include "SortAlgs.h"
#include "SearchAlgs.hpp"
#include "NonInplaceSortAlgs.h"

using namespace std;

int main(int argc, const char * argv[]) {
   
    string inFileName;
    ifstream inFile;
    int arraySize = 0;
    
    cout << "Enter a file name of with integers: ";
    cin >> inFileName;
    cout << inFileName << endl;
    
    inFile.open(inFileName, ios::binary | ios::in);
    
    if (!inFile) {
        cerr << "INVALID FILE" << endl;
        inFile.close();
        exit(-1);
    }
    
    // get number of items in file
    int temp = 0;
    short selection = 1;
    while (inFile >> temp) { arraySize++; }
    
    // create main array
    int mainArray[arraySize];
    int count = 0;
    
    // reset the input file pointer
    inFile.clear();
    inFile.seekg(0, ios::beg);
    
    while (count < arraySize && inFile >> temp) { mainArray[count++] = temp; }
    
    cout << "Sorting " << arraySize << " items" << endl << endl;
    
    const int NUM_ALGS = 9;
    const string ALGS[NUM_ALGS] = {"Merge Sort", "Quick Sort", "Heap Sort", "Bubble Sort",
                            "Insertion Sort", "Selection Sort", "Bucket Sort", "Radix Sort",
                            "Bogo Sort"
                            };
    
    cout << "Sorting Algorithms: " << endl;
    for (int i = 0; i < NUM_ALGS; i++) {
        cout << (i + 1) << ". " << ALGS[i] << endl;
    }
    
    cout << endl;
    cout << "Select Sorting algorithm: ";
    cin >> selection;
    
    SearchAlgorithms searcher;
    
    time_t start, end;
    
    switch (selection) {
        case 1: {
            
            SortingAlgorithms sorter(arraySize);
            
            start = clock();
            sorter.merge_sort(mainArray, 0, arraySize - 1);
            end = clock();
            
            break;
        }
        case 2: {
            
            SortingAlgorithms sorter(arraySize);
            
            start = clock();
            sorter.quick_sort(mainArray, 0, arraySize - 1);
            end = clock();
            
            break;
        
        }
        case 3: {
            
            SortingAlgorithms sorter(arraySize);
            
            start = clock();
            sorter.heapSort(mainArray);
            end = clock();
            
            break;
        }
        case 4: {
            
            SortingAlgorithms sorter(arraySize);
            
            start = clock();
            sorter.bubbleSort(mainArray, arraySize);
            end = clock();
            
            break;
        }
        case 5: {
            
            SortingAlgorithms sorter(arraySize);
            
            start = clock();
            sorter.insertionSort(mainArray);
            end = clock();
            
            break;
        }
        case 6: {
            
            SortingAlgorithms sorter(arraySize);
            
            start = clock();
//            sorter.selectionSort(mainArray);
            end = clock();
            
            break;
        }
        case 7: {
            
            NonInplaceSortAlgs sorter(arraySize);
            
            start = clock();
            sorter.bucketSort(mainArray);
            end = clock();
            
            break;
        }
        case 8: {
            
            NonInplaceSortAlgs sorter(arraySize);
            
            start = clock();
//            sorter.radixSort(mainArray);
            end = clock();
            
            break;
        }
        case 9: {
            
            SortingAlgorithms sorter(arraySize);
            
            start = clock();
//            sorter.bogoSort(mainArray);
            end = clock();
            
            break;
        }
    }
    
    cout << "Verifying Sort... ";
    if (!searcher.verifySort(mainArray, arraySize)) {
        inFile.close();
        cerr << "FILE IS NOT SORTED" << endl;
        exit(-1);
    }
    cout << "FILE IS SORTED" << endl << endl;
    
    cout << endl;
    cout << "Sort Completed in " << (end - start) / (float)CLOCKS_PER_SEC << " seconds" << endl;
    
    
    // create output file for the sorted result
    ofstream outFile(inFileName.substr(0, inFileName.find(".txt")) + "_SORTED.txt");
    
    count = 0;
    while (count < arraySize && outFile << mainArray[count++]) { outFile << endl; }
    
    
    
    return 0;
}

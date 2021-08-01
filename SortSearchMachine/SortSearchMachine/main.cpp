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
    bool isValidSort = searcher.verifySort(mainArray, arraySize);
    if (!isValidSort) {
        inFile.close();
        cerr << "FILE IS NOT SORTED" << endl;
        return -1;
    }
    cout << "FILE IS SORTED" << endl << endl;
    
    cout << "Sort Completed in " << (end - start) / (float)CLOCKS_PER_SEC << " seconds" << endl;
    
    // create output file for the sorted result
    ofstream outFile(inFileName.substr(0, inFileName.find(".txt")) + "_SORTED.txt");
    
    count = 0;
    while (count < arraySize && outFile << mainArray[count++]) { outFile << endl; }
    
    
    
    char searchYes = 'n';
    int searchAlg = 1;
    int searchKey = 0;
    int searchNdx = 0;
    
    // prompting user to search the list
    do {
        cout << "Would you like to search an item? (y/n): ";
        cin >> searchYes;
        cout << endl;
    
        if (toupper(searchYes) == 'Y') {
            cout << "Search Algs: " << endl;
            cout << "1. Linear Search" << endl;
            cout << "2. Binary Search" << endl << endl;
            
            cout << "Select Search Algorithm: ";
            cin >> searchAlg;
            cout << endl;
            
            cout << "Input search key: ";
            cin >> searchKey;
            cout << endl;
            
            switch (searchAlg) {
                case 1:
                    
                    if ((searchNdx = searcher.LinearSearch(mainArray, searchKey, arraySize)) == -1) {
                        cout << "Item NOT found" << endl;
                    }
                    else {
                        cout << "Item found at index: " << searchNdx << endl;
                    }
                    
                    break;
                case 2:
                    
                    if ((searchNdx = searcher.BinarySearch(mainArray, searchKey, arraySize)) == -1) {
                        cout << "Item NOT found" << endl;
                    }
                    else {
                        cout << "Item found at index: " << searchNdx << endl;
                    }
                    
                    break;
                default:
                    cerr << "Invalid choice" << endl;
            }
            
        }
        
    }
    while (toupper(searchYes) == 'Y');
    
        
    
    
    return 0;
}

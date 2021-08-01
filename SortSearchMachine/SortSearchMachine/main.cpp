#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <ctime>
#include "SortAlgs.h"
#include "NonInplaceSortAlgs.h"

using namespace std;

int main(int argc, const char * argv[]) {
   
    string inFileName;
    ifstream inFile;
    int arraySize = 0;
    
    // prompt the file name
    cout << "Enter a file name of with integers: ";
    cin >> inFileName;
    cout << inFileName << endl;
    
    // open the input file
    inFile.open(inFileName, ios::binary | ios::in);
    
    // if the input file doesn't exist
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
    
    // initialize array
    while (count < arraySize && inFile >> temp) { mainArray[count++] = temp; }
    
    // display sorting size
    cout << "Sorting " << arraySize << " items" << endl << endl;
    

    const int NUM_ALGS = 9;
    const string ALGS[NUM_ALGS] = {"Merge Sort", "Quick Sort", "Heap Sort", "Bubble Sort",
                            "Insertion Sort", "Selection Sort", "Bucket Sort", "Radix Sort",
                            "Bogo Sort"
                            };
    
    // print the sorting algorithm menu
    cout << "Sorting Algorithms: " << endl;
    for (int i = 0; i < NUM_ALGS; i++) {
        cout << (i + 1) << ". " << ALGS[i] << endl;
    }
    
    // prompt the user to select sorting algorithm
    cout << endl;
    cout << "Select Sorting algorithm: ";
    cin >> selection;
    
    SearchAlgorithms searcher;
    
    time_t start, end;
    
    // switch to correct sorting algorithm based on user choice
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
            sorter.selectionSort(mainArray);
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
            
            if (arraySize >= 12) {
                cout << endl << "This could take a while..." << endl;
            }
            
            start = clock();
            sorter.bogoSort(mainArray, searcher);
            end = clock();
            
            break;
        }
    }
    
    // verify if the array is sorted
    cout << "Verifying Sort... ";
    bool isValidSort = searcher.verifySort(mainArray, arraySize);
    if (!isValidSort) {
        inFile.close();
        cerr << "FAILED" << endl;
        return -1;
    }
    cout << "PASSED" << endl << endl;
    
    // display the time it took to sort
    cout << "Sort Completed in " << (end - start) / (float)CLOCKS_PER_SEC << " seconds" << endl << endl;
    
    // create output file for the sorted result
    ofstream outFile(inFileName.substr(0, inFileName.find(".txt")) + "_SORTED.txt");
    
    // write the sorted array to output file
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
            
            switch (searchAlg) {
                case 1:
                    
                    cout << "Input search key: ";
                    cin >> searchKey;
                    cout << endl;
                    
                    if ((searchNdx = searcher.LinearSearch(mainArray, searchKey, arraySize)) == -1) {
                        cout << "Item NOT found" << endl;
                    }
                    else {
                        cout << "Item found at index: " << searchNdx << endl;
                    }
                    
                    break;
                case 2:
                    
                    cout << "Input search key: ";
                    cin >> searchKey;
                    cout << endl;
                    
                    if ((searchNdx = searcher.BinarySearch(mainArray, searchKey, arraySize)) == -1) {
                        cout << "Item NOT found" << endl;
                    }
                    else {
                        cout << "Item found at index: " << searchNdx << endl;
                    }
                    
                    break;
                default:
                    cerr << "Invalid menu item" << endl;
            }
            
        }
        
    }
    while (toupper(searchYes) == 'Y');
    
    return 0;
}

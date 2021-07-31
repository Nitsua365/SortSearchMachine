#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(int argc, char ** argv) {
    
    ofstream outFile("input.txt");
    unsigned int numberOfInts = 1;
    
    cout << "How many integers: ";
    cin >> numberOfInts;
    cout << numberOfInts << endl;
    
    int lBound = 0, uBound = 0;
    
    cout << "enter range of ints (lower bound, upper bound): ";
    cin >> lBound >> uBound;
    
    srand(time(NULL));
    
    for (int i = 0; i < numberOfInts; i++) {
        outFile << ((rand() % uBound) + lBound) << endl;
    }
    
    outFile.close();
    return 0;
}

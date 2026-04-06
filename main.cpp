//*****************************************************************************
// COMSC-210 | Lab 25 | Gabriel Marquez
// Description: this program times, records, and reports how long it takes each
// data structure (vector, list, & set) to run reading, sorting, insertion, and
// deletion operations.
//*****************************************************************************

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <algorithm> //for sorting vector
#include <fstream>
using namespace std;
using namespace std::chrono;

string FILE_NAME = "codes.txt";

int main() {
    //create empty containers
    vector<string> vector;
    list<string> list;
    set<string> set;

    auto start = high_resolution_clock::now();
    ifstream fin(FILE_NAME);
    if (fin.good( )) {
        string input;
        while (fin >> input)
            vector.push_back(input);       
        fin.close( );
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Time taken: " << duration.count() << " nanoseconds\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<nanoseconds>(end - start)
duration.count() references elapsed milliseconds
*/
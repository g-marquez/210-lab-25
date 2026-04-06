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

using namespace std;

int main() {
    //create empty containers
    vector<string> vector;
    list<string> list;
    set<string> set;

    ifstream fin("codes.txt");
    if (fin.good( )) {
        
        }
        fin.close( );
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
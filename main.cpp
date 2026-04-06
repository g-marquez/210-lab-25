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

void read_race (vector<string> &v, auto &v_time, list<string> &l, auto &l_time,
                set<string> &s, auto &s_time)
void sort_race (vector<string> &, auto &, list<string> &, auto &)
void insert_race (vector<string> &, auto &, list<string> &, auto &,
                  set<string> &, auto &)
void delete_race (vector<string> &, auto &, list<string> &, auto &,
                  set<string> &, auto &)

int main() {
    //create empty containers
    vector<string> vector;
    list<string> list;
    set<string> set;

    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<nanoseconds>(end - start)
duration.count() references elapsed milliseconds
*/

//description: read_race() determines which of the passed containers performs
// a read opeation the fastest
//arguments: vector, list, & set structures, and auto variables to store their
// respective operation times in nanoseconds (all passed by reference)
//returns: void
void read_race (vector<string> &v, auto &v_time, list<string> &l, auto &l_time,
                set<string> &s, auto &s_time) {
    string file = FILE_NAME;
    string input;

    //reading to vector
    auto start = high_resolution_clock::now();
    ifstream fin(FILE_NAME);
    if (fin.good( )) {
        while (fin >> input)
            v.push_back(input);   
        fin.close( );
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    v_time = duration.count();

    //reading to list
    }

//description: sort_race() determines which of the passed containers performs
// a sort opeation the fastest
//arguments: vector & list structures (set not needed), and auto variables
// to store their respective operation times in nanoseconds (all passed by reference)
//returns: void
void sort_race (vector<string> &v, auto &v_time, list<string> &l, auto &l_time) {
    
    }

//description: insert_race() determines which of the passed containers performs
// an insertion opeation the fastest
//arguments: vector, list, & set structures, and auto variables to store their
// respective operation times in nanoseconds (all passed by reference)
//returns: void
void insert_race (vector<string> &v, auto &v_time, list<string> &l, auto &l_time,
                  set<string> &s, auto &s_time) {
    
    }

//description: delete_race() determines which of the passed containers performs
// an deletion opeation the fastest
//arguments: vector, list, & set structures, and auto variables to store their
// respective operation times in nanoseconds (all passed by reference)
//returns: void
void delete_race (vector<string> &v, auto &v_time, list<string> &l, auto &l_time,
                  set<string> &s, auto &s_time) {
    
    }
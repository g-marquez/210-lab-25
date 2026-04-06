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
#include <iomanip>
using namespace std;
using namespace std::chrono;

string FILE_NAME = "codes.txt";
int SET_WIDTH = 15;

void read_race (vector<string> &, long &, list<string> &, long &,
                set<string> &, long &);
void sort_race (vector<string> &, long &, list<string> &, long &); //set not needed
void insert_race (vector<string> &, long &, list<string> &, long &,
                  set<string> &, long &);
void delete_race (vector<string> &, long &, list<string> &, long &,
                  set<string> &, long &);

int main() {
    //create empty containers
    /*vector<string> vector;
    list<string> list;
    set<string> set;

    //declare variable for recorded times
    long v_read, l_read, s_read;
    long v_sort, l_sort;
    int s_sort = -1; //set is already sorted
    long v_insert, l_insert, s_insert;
    long v_delete, l_delete, s_delete;

    read_race (vector, v_read, list, l_read, set, s_read);
    sort_race (vector, v_sort, list, l_sort);
    insert_race (vector, v_insert, list, l_insert, set, s_insert);
    delete_race (vector, v_delete, list, l_delete, set, s_delete);*/
    
    cout << setw(SET_WIDTH) << "Operation" << setw(SET_WIDTH) << "Vector" << setw(SET_WIDTH)
         << "List" << setw(SET_WIDTH) << "Set" << endl;

    return 0;
}

//description: read_race() determines which of the passed containers performs
// a read opeation the fastest
//arguments: vector, list, & set structures, and auto variables to store their
// respective operation times in nanoseconds (all passed by reference)
//returns: void
void read_race (vector<string> &v, long &v_time, list<string> &l, long &l_time,
                set<string> &s, long &s_time) {
    string file = FILE_NAME;
    string input;

    ifstream fin(file);
    if (fin.good( )) {
        //reading to vector
        auto start = high_resolution_clock::now();
        while (fin >> input)
            v.push_back(input);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        v_time = duration.count();

        fin.clear(); //clear flags
        fin.seekg(0); //go back to beginning of file

        //reading to list
        start = high_resolution_clock::now();
        while (fin >> input)
            l.push_back(input);
        end = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(end - start);
        l_time = duration.count();

        fin.clear(); //clear flags
        fin.seekg(0); //go back to beginning of file

        //reading to set
        start = high_resolution_clock::now();
        while (fin >> input)
            s.insert(input);
        end = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(end - start);
        s_time = duration.count();

        fin.close( );
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return;
    }
}

//description: sort_race() determines which of the passed containers performs
// a sort opeation the fastest
//arguments: vector & list structures (set not needed), and auto variables
// to store their respective operation times in nanoseconds (all passed by reference)
//returns: void
void sort_race (vector<string> &v, long &v_time, list<string> &l, long &l_time) {
    //sort vector
    auto start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    v_time = duration.count();

    //sort list
    start = high_resolution_clock::now();
    l.sort();
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    l_time = duration.count();
}

//description: insert_race() determines which of the passed containers performs
// an insertion opeation the fastest
//arguments: vector, list, & set structures, and auto variables to store their
// respective operation times in nanoseconds (all passed by reference)
//returns: void
void insert_race (vector<string> &v, long &v_time, list<string> &l, long &l_time,
                  set<string> &s, long &s_time) {
    string val = "TESTCODE";

    //insert into vector
    auto start = high_resolution_clock::now();
    v.insert(v.begin() + v.size() / 2, val);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    v_time = duration.count();

    //insert into list
    start = high_resolution_clock::now();
    auto it = l.begin();
    for (int i = 0; i < l.size() / 2; ++i)
        it++;
    l.insert(it, val);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    l_time = duration.count();

    //insert into set
    start = high_resolution_clock::now();
    s.insert(val);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    s_time = duration.count();
}

//description: delete_race() determines which of the passed containers performs
// an deletion opeation the fastest
//arguments: vector, list, & set structures, and auto variables to store their
// respective operation times in nanoseconds (all passed by reference)
//returns: void
void delete_race (vector<string> &v, long &v_time, list<string> &l, long &l_time,
                  set<string> &s, long &s_time) {
    //delete from vector
    auto start = high_resolution_clock::now();
    v.erase(v.begin() + v.size() / 2);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    v_time = duration.count();
    
    //delete from list
    start = high_resolution_clock::now();
    auto it = l.begin();
    for (int i = 0; i < l.size() / 2; ++i)
        it++;
    l.erase(it);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    l_time = duration.count();

    //delete from set
    start = high_resolution_clock::now();
    auto it1 = s.begin();
    for (int i = 0; i < s.size() / 2; ++i)
        it1++;
    s.erase(it1);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    s_time = duration.count();
}
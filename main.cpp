//lab 25 ds races

#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;


int main() {
    ifstream fin("codes.txt");
    string line;
    vector<string> vect;
    list<string> lists;
    set<string> sets;

    //reading string elements-------race 1
    while (getline(fin, line)){
        vect.push_back(line);
        lists.push_back(line);
        sets.insert(line);
    }

    //sorting string elements-------race 2
    //set is sorted by default
    lists.sort();
    sort(vect.begin(), vect.end());
    
    //inserting "TESTCODE"--------race 3
    int vectorindex = vect.size() / 2;
    int listindex = lists.size() / 2;
    //set will automatically insert into correct index

    vect.insert(vect.begin() + vectorindex, "TESTCODE");



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
//lab 25 ds races

#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;


int main() {
    ifstream fin("codes.txt");
    string line;
    vector<string> vect;
    list<string> lists;
    set<string> sets;

    //reading string elements-------race 1
    cout << "READING:\n";
    auto start = high_resolution_clock::now();
    while (getline(fin, line)){
        vect.push_back(line);
        lists.push_back(line);
        sets.insert(line);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " milliseconds\n";



    //sorting string elements-------race 2
    //set is sorted by default
    cout << "SORTING:\n";
    start = high_resolution_clock::now();
    lists.sort();
    sort(vect.begin(), vect.end());
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " milliseconds\n";
    
    //inserting "TESTCODE"--------race 3
    cout << "INSERTING:\n";
    start = high_resolution_clock::now();
    int vectorindex = vect.size() / 2;
    int listindex = lists.size() / 2;
    //set will automatically insert into correct index

    vect.insert(vect.begin() + vectorindex, "TESTCODE");
    auto i = lists.begin(); 
    advance(i, listindex);
    sets.insert("TESTCODE");
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " milliseconds\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
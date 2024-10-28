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
    auto vectdur = 0, listdur = 0, setdur = 0,
        vecsort = 0, listsort = 0, setsort = -1,
        vecinsert = 0, listinsert = 0, setinsert = 0;

    cout << "Operation\tVector\tList\tSet\n";

    //reading string elements-------race 1
    auto start = high_resolution_clock::now();
    while (getline(fin, line)){
        auto readS = high_resolution_clock::now();
        vect.push_back(line);
        auto readE = high_resolution_clock::now();
        vectdur += duration_cast<milliseconds>(readE - readS).count();

        readS = high_resolution_clock::now();
        lists.push_back(line);
        readE = high_resolution_clock::now();
        listdur += duration_cast<milliseconds>(readE- readS).count();

        readS = high_resolution_clock::now();
        sets.insert(line);
        readE = high_resolution_clock::now();
        setdur += duration_cast<milliseconds>(readE - readS).count();
    }
    cout << "Read\t" << vectdur << "\t" << listdur << "\t" << setdur << endl;

    //sorting string elements-------race 2
    //set is sorted by default
    auto sorts = high_resolution_clock::now();
    lists.sort();
    auto sortend = high_resolution_clock::now();
    listsort += duration_cast<milliseconds>(sortend - sorts).count();

    sorts = high_resolution_clock::now();
    sort(vect.begin(), vect.end());
    sortend = high_resolution_clock::now();
    vecsort = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " milliseconds\n";
    
    //inserting "TESTCODE"--------race 3
    cout << "INSERTING:\n";
    int vectorindex = vect.size() / 2;
    int listindex = lists.size() / 2;
    //set will automatically insert into correct index

    start = high_resolution_clock::now();
    vect.insert(vect.begin() + vectorindex, "TESTCODE");
    end = high_resolution_clock::now();
    auto i = lists.begin(); 
    start = high_resolution_clock::now();
    advance(i, listindex);
    end = high_resolution_clock::now();
    start = high_resolution_clock::now();
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
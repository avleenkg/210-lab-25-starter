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
    int vectdur = 0, listdur = 0, setdur = 0,
        vecsort = 0, listsort = 0, setsort = -1,
        vecinsert = 0, listinsert = 0, setinsert = 0;

    cout << "Operation\tVector\tList\tSet\n";

    //reading string elements-------race 1
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
    cout << "Read\t\t" << vectdur << "\t" << listdur << "\t" << setdur << endl; //my read is outputting 0 but im not sure why

    //sorting string elements-------race 2
    //set is sorted by default
    auto sorts = high_resolution_clock::now();
    lists.sort();
    auto sortend = high_resolution_clock::now();
    listsort += duration_cast<milliseconds>(sortend - sorts).count();

    sorts = high_resolution_clock::now();
    sort(vect.begin(), vect.end());
    sortend = high_resolution_clock::now();
    vecsort += duration_cast<milliseconds>(sortend - sorts).count();
    cout << "Sort\t\t" << vecsort << "\t" << listsort << "\t" << setsort << endl;
    
    //inserting "TESTCODE"--------race 3
    auto start = high_resolution_clock::now();
    int vectorindex = vect.size() / 2;
    vect.insert(vect.begin() + vectorindex, "TESTCODE");
    auto end = high_resolution_clock::now();
    vecinsert += duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    int listindex = lists.size() / 2;
    auto i = lists.begin(); 
    advance(i, listindex);
    end = high_resolution_clock::now();
    listinsert += duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    sets.insert("TESTCODE");
    end = high_resolution_clock::now();
    setinsert += duration_cast<milliseconds>(end - start).count();
    cout << "Insert\t\t" << vecinsert << "\t" << listinsert << "\t" << setinsert << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
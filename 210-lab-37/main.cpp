// 210 | Lab 37 | Neil Orton
// IDE used: Xcode
// Part 3
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);    // sum_ascii function prototype

int main() {
    map<int, list<char>> hash_table;
    ifstream reader;
    string fobj;
    int index;

    reader.open("lab-37-data.txt");    // file is opened
    
    if (!reader)
        cout << "Error. File opening failed" << endl;    // Error messag if file uable to be opened
    
    else {
        cout << "File opening successful" << endl;
        while (reader ){
            list<char> temp_list;    // temp_list of chars to later store the list into the map
            reader >> fobj;    // file contents extracted as a string
            
            for (int i = 0; i < fobj.size(); i++)    // fobj string char contents entered to a temp list of chars
                temp_list.push_back(fobj.at(i));
            
            
            index = gen_hash_index(fobj);    // index for hash map gets its value from the gen_hash_index function
            hash_table.insert(make_pair(index, temp_list));
        }
    }
    
    reader.close();    // file closed
    

    auto it = hash_table.begin();    // iterator declared at beginning of map
    
    for(int i = 0; i < 100; i++) {    // loop for first 100 elements of the map
        cout << it->first << ": ";    // index of map outputted with ->first

        for (char cha : it->second)    // ->second used to access the list
            cout << cha;

        cout << endl;
        it++;    // iterator moved through the map
    }

    
        
    return 0;
}

int gen_hash_index(string str) {    // sum_ascii function definition
    int ascii_sum = 0;
    
    for (int i = 0; i < str.size(); i++)    // string elements (characters) are summed in the loop
        ascii_sum += (int) str.at(i);
    
    return ascii_sum;    // sum of the string's ascii values returned
    
}

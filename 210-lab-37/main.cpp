// 210 | Lab 37 | Neil Orton
// IDE used: Xcode
// Part 3
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

const int CHOICES = 6;

int gen_hash_index(string);    // sum_ascii function prototype
int main_menu();    // Main menu function prototpye
void print_first_100(map<int, list<char>>);    //
void search_key(map<int, list<char>>);
void add_key(map<int, list<char>>&);
void remove_key(map<int, list<char>>&);
void modify_key(map<int, list<char>>&);

int main() {
    map<int, list<char>> hash_table;
    ifstream reader;
    string fobj;
    int index;

    reader.open("lab-37-data.txt");    // file is opened
    
    if (!reader)
        cout << "Error. File opening failed" << endl;    // Error messag if file unable to be opened
    
    else {
        cout << "File opening successful" << endl;
        while (reader ) {
            list<char> temp_list;    // temp_list of chars to later store the list into the map
            reader >> fobj;    // file contents extracted as a string
            
            for (int i = 0; i < fobj.size(); i++)    // fobj string char contents entered to a temp list of chars
                temp_list.push_back(fobj.at(i));
            
            
            index = gen_hash_index(fobj);    // index for hash map gets its value from the gen_hash_index function
            hash_table.insert(make_pair(index, temp_list));
        }
    }
    
    reader.close();    // file closed
    
    
    int choice = main_menu();
    while (choice != CHOICES) {
        switch(choice) {    // switch cases for each of the choices intputted by the user, while the have not selected to end the main menu
            case 1:
                print_first_100(hash_table);    // print_first_100 function call on selction 1
                break;
            case 2:
                search_key(hash_table);    // search_key function call on selction 2
                    break;
            case 3:
                add_key(hash_table);    // add_key function call on selction 3
                    break;
            case 4:
                remove_key(hash_table);    // remove_key function call on selction 4
                    break;
            case 5:
                modify_key(hash_table);    // modify_key function call on selction 5
                    break;
            default:
                cout << "Invalid";
                break;
        }
        choice = main_menu();
    }
    
    cout << "Thanks for using the Hash Table Manager" << endl;
    cout << "----------------------------" << endl;
        
    return 0;
}

int gen_hash_index(string str) {    // sum_ascii function definition
    int ascii_sum = 0;
    
    for (int i = 0; i < str.size(); i++)    // string elements (characters) are summed in the loop
        ascii_sum += (int) str.at(i);
    
    return ascii_sum;    // sum of the string's ascii values returned
}

int main_menu() {
        cout << "----------------------------" << endl;    // Main menu displaying allt h eoptions for the user
        cout << "*** Hash Table Manager ***" << endl;
        cout << "[1] Print first 100 entries" << endl;
        cout << "[2] Search for a key" << endl;
        cout << "[3] Add a key" << endl;
        cout << "[4] Remove a Key" << endl;
        cout << "[5] Modify a Key" << endl;
        cout << "[6] Exit" << endl;
        cout << "Choice --> ";
        int choice;
        cin >> choice;
    while (choice < 1 || choice > CHOICES) {    // validation loop to ensure user anters within range
        cout << "Invalid, try again --> ";
        cin >> choice;
    }
        cout << "----------------------------" << endl;
    
    return choice;
}

void print_first_100(map<int, list<char>> hash_table) {
    
    auto it = hash_table.begin();    // iterator declared at beginning of map
    
    for(int i = 0; i < 100; i++) {    // loop for first 100 elements of the map
        cout << it->first << ": ";    // index of map outputted with ->first
        
        for (char cha : it->second)    // ->second used to access the list
            cout << cha;
        
        cout << endl;
        it++;    // iterator moved through the map
    }
}


void search_key(map<int, list<char>> hash_table) {
    int search;
    
    cout << "Enter the key you wish to search: ";
    cin >> search;
    
    auto it = hash_table.find(search);
    if (it != hash_table.end()) {
        cout << it->first << " found\n";
        cout << "value at key: ";
        for (char cha : it->second)
            cout << cha;
    } else
        cout << search << " not found.";
    cout << endl;
    
}

void add_key(map<int, list<char>> &hash_table) {
    int index;
    string str_input;
    list<char> temp_list;
    
    cout << "Enter the value (string) you wish to add: ";
    cin >> str_input;
    
    for (int i = 0; i < str_input.size(); i++)
        temp_list.push_back(str_input.at(i));
    
    index = gen_hash_index(str_input);
    hash_table.insert(make_pair(index, temp_list));
    
    cout << "Index: " << index << ";r [" << str_input << "] added." << endl;
    
}
void remove_key(map<int, list<char>> &hash_table) {
    int index;
    
    cout << "Enter the key you wish to remove: ";
    cin >> index;
    
    auto it = hash_table.find(index);
    if (it != hash_table.end()) {
        hash_table.erase(it);
        cout << "Key: " << index << " removed.";
    } else
        cout << "Key: " << index << " not found";
    
    cout << endl;
}

void modify_key(map<int, list<char>> &hash_table) {
    int index;
    int new_index;
    string str_input;
    
    cout << "Enter the key you wish to modify: ";
    cin >> index;
    
    auto it = hash_table.find(index);
    if (it != hash_table.end()) {
        cout << "Enter the new value: ";
        cin >> str_input;
        
        list<char> temp_list;
        for (int i = 0; i < str_input.size(); i++)
            temp_list.push_back(str_input.at(i));
        
        hash_table.erase(index);
        new_index = gen_hash_index(str_input);
        hash_table.insert(make_pair(new_index, temp_list));
        
        cout << index << " modified. " << "New index: " << new_index << "; [" << str_input << "] added.";
        
    } else
        cout << "Key: " << index << " not found";
    
    cout << endl;
}

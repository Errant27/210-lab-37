// 210 | Lab 37 | Neil Orton
// IDE used: Xcode
// Part 2
#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(string);    // sum_ascii function prototype

int main() {
    ifstream reader;
    string fobj;
    static int sum;

    reader.open("lab-37-data.txt");    // file is opened
    
    if (!reader)
        cout << "Error. File opening failed" << endl;    // Error messag if file uable to be opened
    else {
        cout << "File opening successful" << endl;
        while (reader) {
            reader >> fobj;    // file contents extracted as a string
            sum += sum_ascii(fobj);    // sum_ascii function call, takes string as an argument
        }
    }
    cout << sum << endl;    // ascii sum of the file contents outputted
    
    reader.close();    // file closed

    
        
    return 0;
}

int sum_ascii(string test) {    // sum_ascii function definition
    int test_sum = 0;
    
    for (int i = 0; i < test.size(); i++)    // string elements (characters) are summed in the loop
        test_sum += (int) test.at(i);
    
    return test_sum;    // sum of the string's ascii values returned
    
}

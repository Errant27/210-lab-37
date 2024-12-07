// 210 | Lab 37 | Neil Orton
// IDE used: Xcode
// Part 1
#include <iostream>
using namespace std;

void sum_ascii(string);    // sum_ascii function prototype

int main() {

    sum_ascii("Defenestratee");    // sum_ascii function call, takes string as an argument

    return 0;
}

void sum_ascii(string test) {    // sum_ascii function definition
    int test_sum = 0;
    
    for (int i = 0; i < test.size(); i++)    // string elements (characters) are summed in the loop
        test_sum += (int) test.at(i);
    
    cout << test_sum << endl;    // sum of the string's ascii values is outputted
    
}

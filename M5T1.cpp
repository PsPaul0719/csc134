/*
CSC 134
M5T1
spencep
10/22/25
Prupose: Demo void and value returning funtions
*/

#include <iostream>
using namespace std;

// funtion delcarations (defintions at the bottom)
void say_hello();

int get_the_answer();

double double_a_number(double);

int main() {
    //program does nothing 
    double my_num;
    int another_num;

    
    cout << "Please enter a number (with or without deciaml place)." << endl;
    cin >> my_num;
    //my_num = my_num * 2;
    cout << "Double the number is: " << my_num << endl;
    cout << "But the only answer you need is: ";
    cout << get_the_answer() << endl;


}

void say_hello() {
    //says hi
    cout << "Welcome to IXL Math!" << endl;
}

int get_the_answer() {
    //provides the answer to everything 
    return 42;
}

double double_a_number(double the_num) {
    // num times two 
    double answer = the_num * 2;
    return answer;
}
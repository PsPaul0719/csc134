/*
CSC 134
spencep
Date: 9/29/25
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void letter_grader();
void combat();

int main() {

    letter_grader();
// combat();
    return 0;

}



void letter_grader() {
    // input a number grade
    // respond with a letter grade 
    double num_grade;
    string letter_grade;
    cout << "Enter a number grade 0-100: ";
    cin >> num_grade;

    // create if statments 
    letter_grade = "A";

    // Output the answer
    cout << "A number grade of " << num_grade << " is: " << letter_grade;
    cout << endl << endl;
}

/*
CSC 134
M2HW1
Paul Spence
Date: 
*/

#include <iostream>
#include <iomanip>
using namespace std; 


int main() {
double starting_bal;
double deposit;
double withdrawal;
double fin_bal;
double title;


cout << "Please enter name:" << endl;
cin >> title;
cout << "Hello, " << title << ".";
cout << "Enter your starting balence.";
cin >> starting_bal;
cout << "Enter your deposit:"; 
cin >> deposit;
cout << "Enter your widthdrawal:";
cin >> withdrawal;

double fin_bal = starting_bal + deposit - withdrawal;

cout << setprecision(2) << fixed;
cout << "Your final balence is" << fin_bal << endl;

return 0;
}
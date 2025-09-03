/*
CSC 134, M2T1
spencep
9/3/25

*/

#include <iostream>
using namespace std;

int main() {

 // Delcare our variables ("The Truth")
string item = "Hats";
double cost_per = 0.99;
int amount = 20;
 // variable for user input 
 int amount_purchased;
 double total_cost;
 // Greet the user 
cout << "Hi! Welcome to our, " << item << " store." << endl;
 // Ask for information
cout << "Each of the " << item << " cost $" << cost_per << endl;
cout << "We have " << amount << " for sale." << endl;
cout << endl;
cout << "How many would you like to buy?" << endl;
 // cin: put info from keyborad into a variable
cin >> amount_purchased;

 // Do some processing 
 // single equal as "gets"
total_cost = amount_purchased * cost_per;

 // Output the answer
 cout << "You are buying " << amount_purchased << " " << item << endl;
 cout << "The total is: $" << total_cost << endl; 
 cout << "Thank you for shopping with us." << endl;
    return 0;
}
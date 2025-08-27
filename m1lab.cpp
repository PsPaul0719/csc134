// magic words
#include <iostream>
using namespace std;

int main() {

string item_name = "apple";
int  num_items = 10;
double cost_per = 0.25;

cout << "Welcome to the " << item_name << " store! " << endl;
cout << "Each " << item_name << " is $" << cost_per <<endl;
cout << "We have " << num_items << " total." << endl;

double total_cost = num_items * cost_per;

cout << "Buying them all wil cost: $ " << total_cost << endl;
cout << "Thanks for shopping with us!" << endl;
return 0;

}
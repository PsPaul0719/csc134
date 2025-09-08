#include <iostream>
using namespace std ;

int main() {
// set up variables
double length, width, height; // crate's size
double cost_to_make, charge_to_customer; // pricing
double profit;
double volume;

const double Cost_Per_Cubic_Foot = 0.23; // relates to cost
const double Charge_Per_Cubic_Foot = 0.5; // relates to charge
// Get the crate info 
cout << "Welcome to the crate program." << endl;
cout << "Crate Length: ";
cin >> length;
cout << "Crate Width: ";
cin >> width;
cout << "Crate Height: ";
cin >> height;

// Calculate the cost and prices 
volume = length * width * height;
cost_to_make = volume * Cost_Per_Cubic_Foot;
charge_to_customer = volume * Charge_Per_Cubic_Foot;
profit = charge_to_customer - cost_to_make;

//Display the results 
cout << endl; 
cout << "Your crate is: " << volume  << " cubic feet." << endl;
cout << "Customer Price: $" << charge_to_customer << endl;
cout << "Cost to Build: $" << cost_to_make << endl; 
cout << "Profit: $" << profit << endl;

return 0;
}
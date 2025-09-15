#include <iostream>
#include <iomanip> 
using namespace std; 

int main() {

    // Declare variables
    string item = "McChicken";
    double menu_price = 5.99; // price of the item
    double tax_percent = 0.08; // 0.08 = 8/100 
    double tax_amount; // how much you are actually taxed
    double total_price;

    cout << "Order Up" << endl;
    cout << item << " (x1)";
    cout << "\t$" << menu_price << endl;

    // Calculate the values
    tax_amount = menu_price * tax_percent; // equation for tax amount
    total_price = menu_price + tax_amount; // equation for the total price

    // Print the results
    cout << setprecision(2) << fixed;
    cout << "Tax: \t\t$" << tax_amount << endl;
    cout << "Total: \t\t$" << total_price << endl;
    return 0;
}

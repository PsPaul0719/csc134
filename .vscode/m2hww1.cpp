

#include <iostream>
using namespace std;

int main(){

    string name;
    string acc_number;

double balance;
double starting_bal;
double amount;

void deposit(double amount) {

    if (amount > 0) {
        balance += amount;
        cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
    } else {
        cout << "Insufficient fund." << endl;
    }


}

return 0;
}
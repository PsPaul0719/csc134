/*
CSC 134
M2HW1
Paul Spence
Date: 9/26/25
*/


#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    string account_number;
    double balance;

public:
// Contructor to initialze the account
    BankAccount(string account_holder, string acc_number, double starting_balance) {
        name = account_holder;
        account_number = acc_number;
        balance = starting_balance;

    }

// How to Deposit 
void deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
    } 
    else {
        cout << "Deposit Cancelled." << endl;
    }
}

void withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        cout << "Widthdrew $" << amount << ". New balance: $" << balance << endl;
    }
    else {
        cout << "Withdraw cancelled." << endl;
    }
    }


void display_info() {
    cout << "\nSummary:" << endl;
    cout << "Account Holder: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Finale Balance: $" << balance << endl;
    }

};

int main() {
    string name, account_number;
    double starting_balance, deposit_amount, widthdraw_amount;

    //Ask the user for their info
cout << "Enter your name: ";
getline(cin, name);
cout << "Enter your account number: ";
getline(cin, account_number);
cout << "Enter your starting balance: $";
cin >> starting_balance;

//Create bank account
BankAccount account(name, account_number, starting_balance);

//Ask for their Deposit
cout << "Enter your deposit: $";
cin >> deposit_amount;
account.deposit(deposit_amount);

//Ask for their widthdraw
cout << "Enter your withdraw: $";
cin >> widthdraw_amount;
account.withdraw(widthdraw_amount);

account.display_info();
return 0;
};


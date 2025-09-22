/*
CSC 134
M2HW1
Paul Spence
Date: 
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
    // Constructor to initialize the account
    BankAccount(string account_holder, string acc_number, double starting_balance) {
        name = account_holder;
        account_number = acc_number;
        balance = starting_balance;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be greater than zero." << endl;
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    // Display account details
    void display_account_info() {
        cout << "\nAccount Summary:" << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Final Balance: $" << balance << endl;
    }
};

int main() {
    string name, account_number;
    double starting_balance, deposit_amount, withdrawal_amount;

    // Ask for user input
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your account number: ";
    getline(cin, account_number);
    cout << "Enter your starting account balance: $";
    cin >> starting_balance;

    // Create BankAccount object
    BankAccount account(name, account_number, starting_balance);

    // Ask for deposit amount
    cout << "Enter the deposit amount: $";
    cin >> deposit_amount;
    account.deposit(deposit_amount);

    // Ask for withdrawal amount
    cout << "Enter the withdrawal amount: $";
    cin >> withdrawal_amount;
    account.withdraw(withdrawal_amount);

    // Display account details
    account.display_account_info();

    return 0;
}

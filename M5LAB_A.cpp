/*
CSC 134
spencep
Date: 10/29/25
M5LAB_A
*/

#include <iostream> 
#include <string>

using namespace std;

void execrise_1 () {
    int energy = 30;
    int maxEnergy= 100;

    int choice;

    cout << "You're low on energy. Would you like to rest?" << endl;
    cout << "Yes or No"
    cin >> choice;

    if (choice == Yes) {
    while (energy < maxEnergy) {
        energy += 10;
    }
    while (energy == maxEnergy){
        cout << "You have been restored." << endl;
    }
    }
}

/*
CSC 134
spencep
Date: 10/7/25
M4LAB1
*/

#include <iostream>
#include <string>
using namespace std;

int choice;  // Changed from string to int

void exercise1_HealthRegen() {
    int health = 30;
    int maxHealth = 100;
    cout << "\n=== EXERCISE 1: HEALTH REGENERATION ===" << endl;
    cout << "Starting health: " << health << "/" << maxHealth << endl;
    cout << "Resting to recover health..." << endl << endl;

    while (health < maxHealth) {
        health += 10;
        cout << "Health:" << health << endl;
    }
    if (health == maxHealth) {
        cout << "Fully Recovered!" << endl;
    }
}

void exercise2_LevelUpstats(){

    cout << "\n=== EXERCISE 2: LEVEL UP STATS ===" << endl;
    cout << "Character progression from Level 1 to Level 10" << endl << endl;

    //Table header
    cout << "Level | Strength | Defense | Magic | HP" << endl;
    cout << "--------------------------------------" << endl;

    // loop through level 1 to 10 and diplay stats
    for (int level = 1; level <= 10; level++) {
        int strength = 10 + (level * 2);
        int defense = 5 + (level * 1);
        int magic = 8 + (level * 3);
        int hp = 50 + (level * 10);
        
        cout << level << "      " << strength << "        " 
             << defense << "        " << magic << "      " << hp << endl;

    }

// calulate and show the total growth 
    cout << "--------------------------------------" << endl;
    cout << "\nTotal Stats Growth:" << endl;
    cout << "Strength:      +18" << endl;
    cout << "Defense:       +9" << endl;
    cout << "Magic:         +27" << endl;
    cout << "HP:            +90" << endl;
}

void exercise3_InventorySystem() {
    cout << "\n=== EXERCISE 3: INVENTORY SYSTEM ===" << endl;

    // array of 5 equipment items 
    string inventory [5] = {"Phone", "Flashlight", "Keys", "Suspicious Necklace", "Wristwatch"};

    // display all items in a numbered list
    cout << "\nYour Inventory:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i + 1) << ". " << inventory [i] << endl;
    }

    // ask the sue to search for the item
    cout << "\nEnter item name to search: ";
    string searchitem;
    cin >> searchitem;

    // convert search input to lowercase for case-insensitive comparsion
    for (int i = 0; i < searchitem.length(); i++) {
        searchitem[i] = tolower(searchitem[i]);
    } 

    // use a loop to search through the array
    bool found = false;
    int position = -1;

    for (int i = 0; i < 5; i++) {
        // convert to lowercase for comparison
        string itemLower = inventory[i];
        for (int j = 0; j < itemLower.length(); j++){
        itemLower[j] = tolower(itemLower[j]);
        }
    //check if items match
    if (itemLower == searchitem) {
        found = true;
        position = i + 1;
        break;
    }

}

// diplay whether the item was found or not     
if (found) {
    cout << "\nItem found at position " << position << "!" << endl;
} else {
    cout << "\nItem not found in inventory" << endl;
    }

}

int main() {
    cout << "==================================" << endl;
    cout << "    LAB 7: LOOP FUNDAMENTALS      " << endl;
    cout << "==================================" << endl;
    cout << "1. Exercise 1: Health Regeneration" << endl;
    cout << "2. Exercise 2: Level Up Stats" << endl;
    cout << "3. Exercise 3: Inventory System" << endl;
    cout << "4. Run All Exercises" << endl;
    cout << "5. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            exercise1_HealthRegen();  // Match the exact function name
            break;
        case 2: 
            exercise2_LevelUpstats();
            break;
        case 3: 
            exercise3_InventorySystem();
            break;
        case 4: 
            exercise1_HealthRegen();
            exercise2_LevelUpstats();
            exercise3_InventorySystem();
            break;
        case 5:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
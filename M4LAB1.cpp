/*
CSC 134
spencep
Date: 10/6/25
*/

#include <iostream>
using namespace std;



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
}

int main() {
    void exercise1_HealthRegen();

return 0; }
// TODO: Implement your while loop here
// HINT: while (health < maxHealth)
// {
//     health = health + 10;
//     // Display current health
//     // BONUS: Add a visual health bar
// }



// TODO: Display "Fully recovered!" message

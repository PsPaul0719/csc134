/*
CSC 134
spencep
Date: 10/1/25
M3BONUS
*/


#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

// Function to display the game menu
void displayMenu() {
    cout << "\n=== CHOOSE YOUR MOVE ===" << endl;
    cout << "1. High Attack (30 damage)" << endl;
    cout << "2. Medium Attack (20 damage)" << endl;
    cout << "3. Low Attack (10 damage)" << endl;
    cout << "4. High Block" << endl;
    cout << "5. Medium Block" << endl;
    cout << "6. Low Block" << endl;
    cout << "7. Taunt" << endl;
    cout << "Enter choice (1-7): ";
}

// Function to get the computer's random choice
int getComputerChoice() {
    return (rand() % 7) + 1;  // Random number between 1 and 7
}

// Function to display what move was chosen
void displayMove(int choice, string player) {
    cout << player << " chose: ";
    
    if (choice == 1) {
        cout << "High Attack!";
    } else if (choice == 2) {
        cout << "Medium Attack!";
    } else if (choice == 3) {
        cout << "Low Attack!";
    } else if (choice == 4) {
        cout << "High Block!";
    } else if (choice == 5) {
        cout << "Medium Block!";
    } else if (choice == 6) {
        cout << "Low Block!";
    } else if (choice == 7) {
        cout << "Taunt!";
    }
    cout << endl;
}

// Function to resolve combat and return damage dealt to each player
void resolveCombat(int playerChoice, int computerChoice, int& playerDamage, int& computerDamage, 
                   int& playerHealth, int& computerHealth, int& playerBuff, int& computerBuff) {
    // Reset damage to 0 each round
    playerDamage = 0;
    computerDamage = 0;
    
    bool playerUsedAttack = false;
    bool computerUsedAttack = false;
    
    // BOTH TAUNTING - Special case!
    if (playerChoice == 7 && computerChoice == 7) {
        cout << "** Both fighters TAUNT each other! Damage buffs activated! **" << endl;
        playerBuff = 15;
        computerBuff = 15;
        cout << "Both players gain +15 damage on their next attack!" << endl;
        return;
    }
    
    // PLAYER TAUNTS
    if (playerChoice == 7) {
        if (computerChoice >= 4 && computerChoice <= 6) {
            // Computer is blocking - player heals!
            int healAmount = 20;
            playerHealth += healAmount;
            if (playerHealth > 100) playerHealth = 100;  // Cap at 100
            cout << "** Player taunts while Computer blocks! Player heals " << healAmount << " HP! **" << endl;
        } else if (computerChoice <= 3) {
            // Computer is attacking - player takes reduced damage!
            computerUsedAttack = true;
            if (computerChoice == 1) playerDamage = 30 - 5;  // High attack
            else if (computerChoice == 2) playerDamage = 20 - 5;  // Medium attack
            else if (computerChoice == 3) playerDamage = 10 - 5;  // Low attack
            
            // Apply computer's damage buff if they have one
            playerDamage += computerBuff;
            
            cout << "** Player taunts but gets hit! Damage reduced by 5! **" << endl;
        }
    }
    
    // COMPUTER TAUNTS
    if (computerChoice == 7) {
        if (playerChoice >= 4 && playerChoice <= 6) {
            // Player is blocking - computer heals!
            int healAmount = 20;
            computerHealth += healAmount;
            if (computerHealth > 100) computerHealth = 100;  // Cap at 100
            cout << "** Computer taunts while Player blocks! Computer heals " << healAmount << " HP! **" << endl;
        } else if (playerChoice <= 3) {
            // Player is attacking - computer takes reduced damage!
            playerUsedAttack = true;
            if (playerChoice == 1) computerDamage = 30 - 5;  // High attack
            else if (playerChoice == 2) computerDamage = 20 - 5;  // Medium attack
            else if (playerChoice == 3) computerDamage = 10 - 5;  // Low attack
            
            // Apply player's damage buff if they have one
            computerDamage += playerBuff;
            
            cout << "** Computer taunts but gets hit! Damage reduced by 5! **" << endl;
        }
    }
    
    // PLAYER ATTACKS (not taunt), COMPUTER BLOCKS OR ATTACKS (not taunt)
    if (playerChoice <= 3 && computerChoice != 7) {  // Player is attacking
        playerUsedAttack = true;
        
        if (computerChoice <= 3) {  // Computer is also attacking
            computerUsedAttack = true;
            // Both attack - both take damage!
            if (playerChoice == 1) computerDamage = 30;
            else if (playerChoice == 2) computerDamage = 20;
            else if (playerChoice == 3) computerDamage = 10;
            
            if (computerChoice == 1) playerDamage = 30;
            else if (computerChoice == 2) playerDamage = 20;
            else if (computerChoice == 3) playerDamage = 10;
            
            // Apply damage buffs
            computerDamage += playerBuff;
            playerDamage += computerBuff;
            
            cout << "** Both fighters attack! **" << endl;
        } else {  // Computer is blocking
            // Check if block is successful
            if ((playerChoice == 1 && computerChoice == 6) ||
                (playerChoice == 2 && computerChoice == 4) ||
                (playerChoice == 3 && computerChoice == 5)) {
                // Block failed! Player attack lands
                if (playerChoice == 1) computerDamage = 30;
                else if (playerChoice == 2) computerDamage = 20;
                else if (playerChoice == 3) computerDamage = 10;
                
                // Apply player's damage buff
                computerDamage += playerBuff;
                
                cout << "** Computer's block FAILED! Player's attack hits! **" << endl;
            } else {
                // Block successful!
                cout << "** Computer BLOCKED the attack! **" << endl;
            }
        }
    }
    
    // PLAYER BLOCKS (not taunt), COMPUTER ATTACKS OR BLOCKS (not taunt)
    if (playerChoice >= 4 && playerChoice <= 6 && computerChoice != 7) {  // Player is blocking
        if (computerChoice <= 3) {  // Computer is attacking
            computerUsedAttack = true;
            
            // Check if player's block is successful
            if ((computerChoice == 1 && playerChoice == 6) ||
                (computerChoice == 2 && playerChoice == 4) ||
                (computerChoice == 3 && playerChoice == 5)) {
                // Block failed! Computer attack lands
                if (computerChoice == 1) playerDamage = 30;
                else if (computerChoice == 2) playerDamage = 20;
                else if (computerChoice == 3) playerDamage = 10;
                
                // Apply computer's damage buff
                playerDamage += computerBuff;
                
                cout << "** Player's block FAILED! Computer's attack hits! **" << endl;
            } else {
                // Block successful!
                cout << "** Player BLOCKED the attack! **" << endl;
            }
        } else {  // Computer is also blocking
            cout << "** Both fighters are blocking! Nothing happens! **" << endl;
        }
    }
    
    // Remove buffs after attacks are used
    if (playerUsedAttack && playerBuff > 0) {
        cout << "Player's damage buff (+15) has been used!" << endl;
        playerBuff = 0;
    }
    if (computerUsedAttack && computerBuff > 0) {
        cout << "Computer's damage buff (+15) has been used!" << endl;
        computerBuff = 0;
    }
}

// Function to display current health
void displayHealth(int playerHealth, int computerHealth) {
    cout << "\n--- HEALTH STATUS ---" << endl;
    cout << "Player HP: " << playerHealth << endl;
    cout << "Computer HP: " << computerHealth << endl;
    cout << "---------------------" << endl;
}

// Function to display active buffs
void displayBuffs(int playerBuff, int computerBuff) {
    if (playerBuff > 0 || computerBuff > 0) {
        cout << "--- ACTIVE BUFFS ---" << endl;
        if (playerBuff > 0) {
            cout << "Player: +" << playerBuff << " damage on next attack!" << endl;
        }
        if (computerBuff > 0) {
            cout << "Computer: +" << computerBuff << " damage on next attack!" << endl;
        }
        cout << "--------------------" << endl;
    }
}

int main() {
    // Seed random number generator
    srand(time(0));
    
    cout << "==================================" << endl;
    cout << "   WELCOME TO FIGHTER ARENA!   " << endl;
    cout << "==================================" << endl;
    cout << "\nFIGHT MECHANICS:" << endl;
    cout << "- High Attack beats Low Block" << endl;
    cout << "- Medium Attack beats High Block" << endl;
    cout << "- Low Attack beats Medium Block" << endl;
    cout << "- Wrong block = you take damage!" << endl;
    cout << "- Both attack = both take damage!" << endl;
    cout << "\nTAUNT MECHANICS:" << endl;
    cout << "- Taunt vs Block = heal 20 HP!" << endl;
    cout << "- Taunt vs Attack = -5 damage reduction!" << endl;
    cout << "- Both Taunt = +15 damage buff next attack!" << endl;
    
    // Game variables
    int playerHealth = 100;
    int computerHealth = 100;
    int playerChoice;
    int computerChoice;
    int playerDamage;
    int computerDamage;
    int playerBuff = 0;  // Damage buff from taunting
    int computerBuff = 0;  // Damage buff from taunting
    int roundNumber = 1;
    
    // Main game loop - continues while both players have health
    while (playerHealth > 0 && computerHealth > 0) {
        cout << "\n\n======== ROUND " << roundNumber << " ========" << endl;
        displayHealth(playerHealth, computerHealth);
        displayBuffs(playerBuff, computerBuff);
        
        // Get player's choice
        displayMenu();
        cin >> playerChoice;
        
        // Validate input
        if (playerChoice < 1 || playerChoice > 7) {
            cout << "Invalid choice! Try again." << endl;
            continue;  // Skip to next iteration
        }
        
        // Get computer's choice
        computerChoice = getComputerChoice();
        
        // Show what each fighter chose
        cout << "\n--- BATTLE! ---" << endl;
        displayMove(playerChoice, "Player");
        displayMove(computerChoice, "Computer");
        
        // Resolve the combat
        resolveCombat(playerChoice, computerChoice, playerDamage, computerDamage, 
                     playerHealth, computerHealth, playerBuff, computerBuff);
        
        // Apply damage
        playerHealth -= playerDamage;
        computerHealth -= computerDamage;
        
        // Make sure health doesn't go below 0
        if (playerHealth < 0) playerHealth = 0;
        if (computerHealth < 0) computerHealth = 0;
        
        // Show damage dealt
        if (playerDamage > 0) {
            cout << "Player takes " << playerDamage << " damage!" << endl;
        }
        if (computerDamage > 0) {
            cout << "Computer takes " << computerDamage << " damage!" << endl;
        }
        
        roundNumber++;
    }
    
    // Game over - determine winner
    cout << "\n\n==================================" << endl;
    cout << "         FIGHT OVER!          " << endl;
    cout << "==================================" << endl;
    displayHealth(playerHealth, computerHealth);
    
    if (playerHealth > computerHealth) {
        cout << "\n🏆 YOU WIN! VICTORY! 🏆" << endl;
    } else {
        cout << "\n💀 YOU LOSE! DEFEATED! 💀" << endl;
    }
    
    return 0;
}
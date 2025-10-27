/*
CSC 134
spencep
Date: 10/1/25
M3BONUS
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Structure to hold opponent data
struct Opponent {
    string name;
    int health;
    int aggressiveness;  // 0-100: higher = more likely to attack
    int blockSkill;      // 0-100: higher = smarter blocking
    string description;
    bool hasSword;       // Special: sword attacks chip through blocks
};

// Function to display opponent selection menu
int selectOpponent(Opponent opponents[], int numOpponents) {
    cout << "\n==================================" << endl;
    cout << "    SELECT YOUR OPPONENT" << endl;
    cout << "==================================" << endl;
    
    for (int i = 0; i < numOpponents; i++) {
        cout << "\n" << (i + 1) << ". " << opponents[i].name << endl;
        cout << "   HP: " << opponents[i].health << endl;
        cout << "   " << opponents[i].description << endl;
    }
    
    int choice;
    cout << "\nEnter your choice (1-" << numOpponents << "): ";
    cin >> choice;
    
    // Validate input
    while (choice < 1 || choice > numOpponents) {
        cout << "Invalid choice! Enter (1-" << numOpponents << "): ";
        cin >> choice;
    }
    
    return choice - 1;  // Return array index
}

// Function to get computer's choice based on opponent personality
int getComputerChoice(Opponent& opp, int playerHealth, int computerHealth) {
    int random = rand() % 100;
    
    // If computer health is low, more likely to block or taunt to heal
    if (computerHealth < 30) {
        if (random < 40) {
            return (rand() % 3) + 4;  // Block (4-6)
        } else if (random < 50) {
            return 7;  // Taunt for healing
        }
    }
    
    // Aggressive opponents attack more
    if (random < opp.aggressiveness) {
        return (rand() % 3) + 1;  // Attack (1-3)
    } 
    // High block skill means better blocking choices
    else if (random < opp.aggressiveness + opp.blockSkill) {
        return (rand() % 3) + 4;  // Block (4-6)
    }
    // Otherwise taunt
    else {
        return 7;
    }
}

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

void resolveCombat(int playerChoice, int computerChoice, int& playerDamage, int& computerDamage, 
                   int& playerHealth, int& computerHealth, int& playerBuff, int& computerBuff, bool opponentHasSword) {
    playerDamage = 0;
    computerDamage = 0;
    
    bool playerUsedAttack = false;
    bool computerUsedAttack = false;
    
    // BOTH TAUNTING
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
            int healAmount = 20;
            playerHealth += healAmount;
            if (playerHealth > 100) playerHealth = 100;
            cout << "** Player taunts while Computer blocks! Player heals " << healAmount << " HP! **" << endl;
        } else if (computerChoice <= 3) {
            computerUsedAttack = true;
            if (computerChoice == 1) playerDamage = 30 - 5;
            else if (computerChoice == 2) playerDamage = 20 - 5;
            else if (computerChoice == 3) playerDamage = 10 - 5;
            
            playerDamage += computerBuff;
            cout << "** Player taunts but gets hit! Damage reduced by 5! **" << endl;
        }
    }
    
    // COMPUTER TAUNTS
    if (computerChoice == 7) {
        if (playerChoice >= 4 && playerChoice <= 6) {
            int healAmount = 20;
            computerHealth += healAmount;
            if (computerHealth > 100) computerHealth = 100;
            cout << "** Computer taunts while Player blocks! Computer heals " << healAmount << " HP! **" << endl;
        } else if (playerChoice <= 3) {
            playerUsedAttack = true;
            if (playerChoice == 1) computerDamage = 30 - 5;
            else if (playerChoice == 2) computerDamage = 20 - 5;
            else if (playerChoice == 3) computerDamage = 10 - 5;
            
            computerDamage += playerBuff;
            cout << "** Computer taunts but gets hit! Damage reduced by 5! **" << endl;
        }
    }
    
    // PLAYER ATTACKS, COMPUTER BLOCKS OR ATTACKS
    if (playerChoice <= 3 && computerChoice != 7) {
        playerUsedAttack = true;
        
        if (computerChoice <= 3) {
            computerUsedAttack = true;
            if (playerChoice == 1) computerDamage = 30;
            else if (playerChoice == 2) computerDamage = 20;
            else if (playerChoice == 3) computerDamage = 10;
            
            if (computerChoice == 1) playerDamage = 30;
            else if (computerChoice == 2) playerDamage = 20;
            else if (computerChoice == 3) playerDamage = 10;
            
            computerDamage += playerBuff;
            playerDamage += computerBuff;
            
            cout << "** Both fighters attack! **" << endl;
        } else {
            // Check if computer's block fails
            // High Block (4) fails to Low Attack (3)
            // Medium Block (5) fails to High Attack (1)
            // Low Block (6) fails to Medium Attack (2)
            if ((computerChoice == 4 && playerChoice == 3) ||
                (computerChoice == 5 && playerChoice == 1) ||
                (computerChoice == 6 && playerChoice == 2)) {
                if (playerChoice == 1) computerDamage = 30;
                else if (playerChoice == 2) computerDamage = 20;
                else if (playerChoice == 3) computerDamage = 10;
                
                computerDamage += playerBuff;
                cout << "** Computer's block FAILED! Player's attack hits! **" << endl;
            } else {
                cout << "** Computer BLOCKED the attack! **" << endl;
            }
        }
    }
    
    // PLAYER BLOCKS, COMPUTER ATTACKS OR BLOCKS
    if (playerChoice >= 4 && playerChoice <= 6 && computerChoice != 7) {
        if (computerChoice <= 3) {
            computerUsedAttack = true;
            
            // Check if player's block fails
            // High Block (4) fails to Low Attack (3)
            // Medium Block (5) fails to High Attack (1)
            // Low Block (6) fails to Medium Attack (2)
            if ((playerChoice == 4 && computerChoice == 3) ||
                (playerChoice == 5 && computerChoice == 1) ||
                (playerChoice == 6 && computerChoice == 2)) {
                if (computerChoice == 1) playerDamage = 30;
                else if (computerChoice == 2) playerDamage = 20;
                else if (computerChoice == 3) playerDamage = 10;
                
                playerDamage += computerBuff;
                cout << "** Player's block FAILED! Computer's attack hits! **" << endl;
            } else {
                // Block was successful, but check for sword chip damage
                if (opponentHasSword) {
                    int chipDamage = 0;
                    if (computerChoice == 1) chipDamage = 3;      // 10% of 30
                    else if (computerChoice == 2) chipDamage = 2; // 10% of 20
                    else if (computerChoice == 3) chipDamage = 1; // 10% of 10
                    
                    playerDamage = chipDamage;
                    cout << "** Player BLOCKED the attack, but the SWORD chips through for " << chipDamage << " damage! **" << endl;
                } else {
                    cout << "** Player BLOCKED the attack! **" << endl;
                }
            }
        } else {
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

void displayHealth(int playerHealth, int computerHealth, string opponentName) {
    cout << "\n--- HEALTH STATUS ---" << endl;
    cout << "Player HP: " << playerHealth << endl;
    cout << opponentName << " HP: " << computerHealth << endl;
    cout << "---------------------" << endl;
}

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
    srand(time(0));
    
    cout << "==================================" << endl;
    cout << "   WELCOME TO FIGHTER ARENA!   " << endl;
    cout << "==================================" << endl;
    cout << "\nFIGHT MECHANICS:" << endl;
    cout << "- High Block: Blocks High + Medium, weak to Low" << endl;
    cout << "- Medium Block: Blocks Medium + Low, weak to High" << endl;
    cout << "- Low Block: Blocks Low + High, weak to Medium" << endl;
    cout << "- Wrong block = you take damage!" << endl;
    cout << "- Both attack = both take damage!" << endl;
    cout << "\nTAUNT MECHANICS:" << endl;
    cout << "- Taunt vs Block = heal 20 HP!" << endl;
    cout << "- Taunt vs Attack = -5 damage reduction!" << endl;
    cout << "- Both Taunt = +15 damage buff next attack!" << endl;
    
    // Create array of opponents
    const int NUM_OPPONENTS = 5;
    Opponent opponents[NUM_OPPONENTS] = {
        {"Rookie Ralph", 80, 40, 30, "A beginner fighter. Easy to beat!", false},
        {"Balanced Bob", 100, 50, 50, "A well-rounded opponent. Fair challenge.", false},
        {"Aggressive Anna", 90, 80, 35, "Attacks relentlessly! Watch out!", false},
        {"Defensive Dan", 120, 25, 70, "Defensive master with high HP. Tricky!", false},
        {"Sword Master Sasha", 110, 75, 60, "⚔️ BOSS: Wields a deadly sword that chips through blocks!", true}
    };
    
    // Let player choose opponent
    int opponentIndex = selectOpponent(opponents, NUM_OPPONENTS);
    Opponent currentOpponent = opponents[opponentIndex];
    
    cout << "\n==================================" << endl;
    cout << "You will fight: " << currentOpponent.name << "!" << endl;
    if (currentOpponent.hasSword) {
        cout << "⚔️ WARNING: This opponent has a SWORD!" << endl;
        cout << "Even successful blocks take 10% chip damage!" << endl;
    }
    cout << "==================================" << endl;
    
    // Game variables
    int playerHealth = 100;
    int computerHealth = currentOpponent.health;
    int playerChoice;
    int computerChoice;
    int playerDamage;
    int computerDamage;
    int playerBuff = 0;
    int computerBuff = 0;
    int roundNumber = 1;
    
    // Main game loop
    while (playerHealth > 0 && computerHealth > 0) {
        cout << "\n\n======== ROUND " << roundNumber << " ========" << endl;
        displayHealth(playerHealth, computerHealth, currentOpponent.name);
        displayBuffs(playerBuff, computerBuff);
        
        displayMenu();
        cin >> playerChoice;
        
        if (playerChoice < 1 || playerChoice > 7) {
            cout << "Invalid choice! Try again." << endl;
            continue;
        }
        
        // Get computer's choice based on opponent AI
        computerChoice = getComputerChoice(currentOpponent, playerHealth, computerHealth);
        
        cout << "\n--- BATTLE! ---" << endl;
        displayMove(playerChoice, "Player");
        displayMove(computerChoice, currentOpponent.name);
        
        resolveCombat(playerChoice, computerChoice, playerDamage, computerDamage, 
                     playerHealth, computerHealth, playerBuff, computerBuff, currentOpponent.hasSword);
        
        playerHealth -= playerDamage;
        computerHealth -= computerDamage;
        
        if (playerHealth < 0) playerHealth = 0;
        if (computerHealth < 0) computerHealth = 0;
        
        if (playerDamage > 0) {
            cout << "Player takes " << playerDamage << " damage!" << endl;
        }
        if (computerDamage > 0) {
            cout << currentOpponent.name << " takes " << computerDamage << " damage!" << endl;
        }
        
        roundNumber++;
    }
    
    // Game over
    cout << "\n\n==================================" << endl;
    cout << "         FIGHT OVER!          " << endl;
    cout << "==================================" << endl;
    displayHealth(playerHealth, computerHealth, currentOpponent.name);
    
    if (playerHealth > computerHealth) {
        cout << "\n🏆 YOU WIN! YOU DEFEATED " << currentOpponent.name << "! 🏆" << endl;
    } else {
        cout << "\n💀 YOU LOSE! " << currentOpponent.name << " WINS! 💀" << endl;
    }
    
    return 0;
}
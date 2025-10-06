#include <iostream>
using namespace std;

// Function to display the game introduction
void showIntro() {
    cout << "\n===========================================\n";
    cout << "This is a story of a tyrannical ruler.  " << endl;
    cout << "They were belevied to have a heart of gold, " << endl; 
    cout << "But that was traded for gold that" << endl;
    cout << "would sit atop their head." << endl; 
    cout << "Will they meet their demise?" << endl;
    cout << "===========================================\n\n";

}

// Function for the first choice - the door
void doorChoice() {
    int choice;
    
    cout << "What do you do?\n";
    cout << "1. Try to break down the door\n";
    cout << "2. Search for a key\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cout << "\n";
    
    if (choice == 1) {
        cout << "The man tells you the tale of this tyranical ruler.";
        cout << "'Our kingdom is under rule by ";
;
    }
    else if (choice == 2) {
        cout << "Not Avalibale";
    }
    else {
        cout << "That's not a valid choice. The guard catches you!\n";
        cout << "GAME OVER!\n";
    }
}

int main() {
    showIntro();
    doorChoice();
    
    cout << "\nThanks for playing!\n";
    
    return 0;
}
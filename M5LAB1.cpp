/*CSC 134
spencep
11/5/25
M5LAB1*/

using namespace std;
#include <iostream>


int getPlayerchoice(int maxChoice);
void showChoices(string choice1, string choice2);

void game_start();
const int Max = 2;


void showChoices(string choice1, string choice2) {


    int num = 1;
    cout << num << ". " << choice1;
    num++;

    if (choice2 != "") {
        cout << num << ". " << choice2 << endl;
        num++;
    }
}
void game_start() {

        int choice;
        cout << R"(================================================================" 
This is a story of a tyrannical ruler. 
They were believed to have a heart of gold, 
But that was traded for gold that would sit atop their head. 
Will they meet their demise? 
================================================================

        You open your front door to investigate, and find an old man who appears to be mumbling.
    )";

    showChoices("Hear him out.", 
                " Write him off as crazy.");




    choice = getPlayerchoice(Max);
    
    if (choice == 1) {
        cout << "(The man tells you the tale of this tyrannical ruler.)";
    }

    if (choice == 2) {
        cout << "(You start to close the door to preserve your ignorance.)";
    }


            
        
    }




int getPlayerchoice(int maxChoice) {
    int choice;
    while (true){
        cout << "Your Choice: ";
        cin >> choice;


        if (choice >= 1 && choice <= maxChoice) {
            return choice;
        }

        cout << "Please choose between 1 and " << maxChoice << ".\n";
    }
}


    
    int main() {
    /*int choice;
    int max = 2;
    showChoices("1","2")
    cout << "TESTING: Choose 1, or 2" << endl;
    choice = getPlayerchoice(max);
    cout << "You chose: " << choice << endl;*/

    game_start();

    return 0;
}
/*
CSC 134
M3LAB1
spencep
9/24/25
*/

#include <iostream> 
#include <ctime>
#include <cstdlib>

using namespace std;

void start() {

    cout << "============================================" << endl;
    cout << "This is a story of a tyrannical ruler.  " << endl;
    cout << "They were belevied to have a heart of gold, " << endl; 
    cout << "But that was traded for gold that" << endl;
    cout << "would sit atop their head." << endl; 
    cout << "Will they meet their demise?" << endl;
    cout << "============================================" << endl;
}

void home() {
int choice;

     
    cout << "You open your front door to investigate, and find an old man who appears to be mumbling." << endl; 
    cout << "Do you choose to write him off as crazy or hear him out? \n1 = Hear him out. 2 = He's insane." << endl;
    cin >> choice;
    cout << "\n";

    if (choice == 1) {
        cout << "The man tells you the tale of this tyranical ruler.";
        cout << "[PLACEHOLDER]";
    }

    if (choice == 2){
    cout << "[PLACEHOLDER]";
    }

}

int main() {

    start();
    home();

    cout << "Thank You For Playing!";
    
    return 0;
    }




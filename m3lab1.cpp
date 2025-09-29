/*
CSC 134
spencep
9/24/25
*/

#include <iostream> 
using namespace std;

void home(); // the journey begins here
void forest(); // one possbile route 
void cave(); // another possbile route
void kingdom(); // final stage 
void freedom(); // possible ending 
void royalty(); // anthoer possbile ending 
void slain(); // you died 

int main() {

    cout << "============================================" << endl;
    cout << "This is a story of a tyrannical ruler.  " << endl;
    cout << "They were belevied to have a heart of gold, " << endl; 
    cout << "But that was traded for gold that" << endl;
    cout << "would sit atop their head." << endl; 
    cout << "Will they meet their demise?" << endl;
    cout << "============================================" << endl; 
    
}

{

void home() {

    cout << "/nYou are awoken by a loud knock at your old town home. " << endl; 
    cout << "You open your front door to investigate, and find an old man who appears to be mumbling." << endl; 
    cout << "Do you choose to write him off as crazy or hear him out? n/1 = Hear him out. 2 = He's insane." << endl;
    
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The man tells you the tale of this tyranical ruler.";
        cout << "'Our kingdom is under rule by ";

    }

    if (choice == 2){
    cout << "Not Avalibale";

    }
}



return 0;
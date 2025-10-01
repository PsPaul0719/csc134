/*
CSC 134
M3LAB2
spencep
Date: 9/29/25
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void letter_grader();
void combat();

int main() {

    letter_grader();
    //combat();
    return 0;
    
}



void letter_grader() {
    // input a number grade
    // respond with a letter grade 
    double num_grade;
    string letter_grade;

    //constants for grade breakpoints
    const double A_GRADE = 90;
    const double B_GRADE = 80;
    const double C_GRADE = 70;
    const double D_GRADE = 60;

    cout << "Enter a number grade 0-100: ";
    cin >> num_grade;

    // create if statments 
    if (num_grade >= A_GRADE) {
        letter_grade = "A";
    }
    else if (num_grade >= B_GRADE) {
        letter_grade = "B";
    }
    else if (num_grade >= C_GRADE) {
        letter_grade = "C";
    }
    else if (num_grade >= D_GRADE) {
        letter_grade = "D";
    }
    else {
        // anything under a D...
        letter_grade = "F";
    }

    // Output the answer
    cout << "A number grade of " << num_grade << " is: " << letter_grade;
    cout << endl << endl;
}

void combat() {

    int attack_roll, attack_bonus, enemy_amror;
    
    //int roll() {
        //const int SIDES = 20;
        //int my_roll;
        //my_roll = (rand() % SIDES) + 1;
        //return my_roll;

    cout << "You are fighting a goblin." << endl;
    cout << "Enter your attack bonus:";
    cin >> attack_bonus;
    cout << "Enemy armor class: ";
    cin >> enemy_amror;


    // Roll to hit
    //attack_roll = roll();
    cout << "Roll: " << attack_roll << " + " << attack_bonus << " = " << attack_roll+attack_bonus << endl;
    if (attack_roll + attack_bonus >= enemy_amror) {
        cout << "HIT!" << endl;
    }
    else {
        cout << "Miss!" << endl;
    }
    
    // try again?
    cout << "Again? (y/n): ";
    string again;
    cin >> again;
    if (again == "y") {
    // calls the function again 
    combat();
    }

    
    }
    

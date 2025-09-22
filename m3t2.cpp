/*
CSC
*/

#include <iostream>
#include <ctime> // for time
#include <cstdlib> // for random () and srand()

using namespace std;


int roll(); // declare helper fucntion

int main() {

    //int num = roll();
    //cout << num << endl;

    int roll1;
    int roll2;
    int point; // if not win or lose
    // seed RNG before roll
    srand(time(0));
    // ROll the dicee
    roll1 = roll();
    roll2 = roll();
    int sum = roll1+roll2;
    cout << "ROLL:" << sum << endl;

    // 7, or 11 you win
    if ( (sum == 7) || (sum == 11) ) {
    cout << "Lucky Seven or Eleven -- You Win!" << endl;
    }

    // 2, 3, 12, you lose 
    else if ( (sum == 2) || (sum == 3) || (sum == 12) ) {
        cout << "2, 3, 12 -- Sorry, you lose." << endl;
    }
    else {
        // set the point
        point = sum;
        cout << "Rolled a point." << endl;
        cout << "Your Point is: " << point << endl;
    }
    return 0;
}

// define helper fucntions 
int roll() { 
    int my_roll;
    my_roll = (rand() % 6) + 1;
    return my_roll;
}
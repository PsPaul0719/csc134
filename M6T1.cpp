/*
CSC 134
spencep
11/10/25
M6T1
*/

#include <iostream> 
using namespace std;


   
void method1();

void method2();

int main() {
    method1();
    method2();
}

    /*
    const int SIZE = 3;
    int temps[SIZE];

    for (int i=0; i < SIZE: i++) {

        cout << "Enter temp #" << i << ": ";
        cin >> temps[i];
    }
    for (int i=0; i < SIZE; i++)  {
        cout << "Temp #" << i << " = " << temps[i] << endl;
    }

    // same but with while loop
    int count=0;
    while (count < SIZE) {
        cout << "Temp #" << count " = " << temps[count] << endl;
        count++; // move to next 
    }

    count = 0;
    do{
        cout << "Temp #" << count << " = " << temps[count] << endl;
    }

    return 0; */


void method1() {

    cout << "Enter each Pokemon found per day." << endl;
    cout << "Day 0 = Monday, Day 4 = Friday." << endl;
    const int SIZE = 5;
    int count = 0;
    int poke_today;
    int poke_total = 0;
    double poke_avg = 0;

    while (count < SIZE) {
        cout << "Day " << count << ": ";
        cin >> poke_today;
        poke_total += poke_today;
        count++; 
    }
    cout << "Total = " << poke_total << endl;
    poke_avg = poke_total / SIZE;
    cout << "Average = " << poke_avg << endl;
}

void method2() {
const int SIZE = 5;
string days[SIZE] = { "M", "T", "W", "Th", "F"}; // intitialized
int pokemon[SIZE]; // not initialzed]
int poke_total = 0;
    double poke_avg = 0;


cout << "Day\tPokemon" << endl;
for (int i=0; i < SIZE; i++) {
    cout << "# on " << days[i] << ": ";
    cin >> pokemon[i];
}
for (int i=0; i < SIZE; i++) {
cout << days[i] << "\t" << pokemon[i] << endl;

poke_total += pokemon[i];
}
poke_avg = (double) poke_total / SIZE;
cout << "Total = " << poke_total << endl;
cout << "Average = " << poke_avg << endl;
}
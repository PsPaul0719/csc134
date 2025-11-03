/*
CSC 134
spencep
11/3/25
M5LAB2
*/

#include <iostream>
#include <string>
using namespace std;

void menu_main();
void menu_area();

// Delcare (write the prototypes for)
// getlength 
// getwidth, getarea, and displayData
// function

double getlength();
double getwidth();
double getarea(double length, double width, double area);
void    displayData(double length, double width, double area);

int main() {

    menu_main();
    return 0;
}



double getlength(){
    double length;
    cout << "What is the length? ";
    cin >> length;
    return 0.0;
}

double getwidth() {
    double width;
    cout << "What is the width? " << endl;
    cin >> width
    return 0.0;

}

double getarea(double length, double width) {
    double area;
    area = length * width;
    return 0.0;

}

void menu_area(){

    // this program calculates the area of a rectangle 
    // todo fix any syntax errors 

    double length, width, area;

    length = getlength();

    width = getwidth();

    area = getarea(length, width);

    displayData(length, width, area);
    return 0;
}

void menu_main() {

    cout << "MAIN MENU" << endl;
    cout << "---------" << endl;
    cout << "1. Area of a rectangle" << endl;
    cout << "2. Exit" << endl;
    cout << endl;
    cout << "Enter Choice: ";
    int choice
    cin >> choice:

    if (choice == 1) {
        menu_area();
        menu_main();
    }
    else if (choice == 2){
        cout << "Goodbye" << endl;
    }
    else {
        cout << "Invalid choice." << endl; << endl;
        cin.clear();

        menu_main();
    };
}

void    displayData(double length, double width) {
    cout << "Rectangle is " << length << " by " << width << "." endl;
    cout << "Area is: " << area << endl;
    return 0;
 }
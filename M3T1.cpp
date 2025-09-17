/*
Paul Spence
9/17/25
CSC 134
*/

#include <iostream>
using namespace std;

int main(){

// Variables
double length1, length2, width1, width2;
double area1, area2;

cout << "Enter the length and width of two rectagles." << endl;
cout << "First rectangle." << endl;
cout << "Length: ";
cin >> length1;
cout << "Width: ";
cin >> width1;
cout << endl;

cout << "Second rectangle." << endl;
cout << "Length: ";
cin >> length2;
cout << "Width: ";
cin >> width2;
cout << endl;

// Calculate the area
area1 = length1 * width1;
area2 = length2 * width2;

cout << "The first rectangle's area is: " << area1 << endl;
cout << "The second rectangle's area is: " << area2 << endl;


// Compare the rectanlges
if (area1 > area2) {
cout << "The first rectangle is larger." << endl;
}
if (area2 > area1){
cout << "The second rectangle is larger." << endl;
}
if (area1 == area2){ // "==" means "is equal to"
    cout << "Both rectangles are equal." << endl;
}
    return 0;
}
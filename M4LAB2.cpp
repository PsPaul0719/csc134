/*
CSC 134
spencep
Date: 10/8/25
M4LAB2*/

#include <iostream> 
using namespace std;

int main() {

    //declae variables 
    int length = 10;
    int height = 10;
    string tile = "⛈️ ";

    //example 1: print horizontally (in a row)
for (int i = 0; i < length; i++) {
    cout << tile;
}
cout << endl;

//example 2: same thing, with a while loop
int count = 0;
while (count < length) {
    cout << tile;
    count++; // count from 0 to just before length 
}
cout << endl;


// example 3: for loop< but printing in a colum
for (int i = 0; i < height ;i++) {
    cout << tile << endl;
}

// example 4: draw the entire ractangle 
cout << endl << endl; // white space
cout << "Draw a rectangle" << endl;
cout << "Length? ";
cin >> length;
cout << "Height? ";
cin >> height;
cout << "Rectangle " << length << " X " << height << endl;
// outer loop handles printing {height} number of lines.
// inner loop handles printingn each line as [length] number of tile.
for (int i=0; i < height; i++) {
    //print the line
    for (int j=0; j < length; j++) {
        cout << tile;
    }
    cout << endl;
}

return 0; // no errors
}
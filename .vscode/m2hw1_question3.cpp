/*
CSC 134
Paul Spence
M2HW1
Date: 9/26/25
*/

#include <iostream> 
using namespace std;

int main() {
    int pizza_order, pizza_slices, visitors_num;

    //Ask how many pizzas
    cout << "How many pizzas did you order? ";
    cin >> pizza_order;

    //Ask how many slices per pizza
    cout << "How many slices per pizza? ";
    cin >> pizza_slices;

    //Ask how many visitors are coming over
    cout << "How many vistors are coming over? ";
    cin >> visitors_num;

int total_slices = pizza_order * pizza_slices; // Total avalible pizza slices

int needed_slices = visitors_num * 3; // Every visitor gets 3 slices

int left_overs = total_slices - needed_slices; // How many lsices are left over

if (left_overs >= 0) {
    cout << "There are " << left_overs << " slice(s) of pizza up for grabs!" << endl;
} else {
    cout << "Theres not enough pizza. We need " << -left_overs << " more slice(s)." << endl;
}

    return 0;
}
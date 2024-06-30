// Question 1
#include <iostream>
#include <string>

using namespace std;

double calcPostage (double weight, int zone) {
    // GlobalMail
    double cost = 0;
    if (zone >= 1 && zone <= 3) {
        cost = 108;
    }
    if (zone >= 4 && zone <= 6) {
        cost = 130;
    }
    return cost*weight;
}

double calcPostage (double weight, double length, double width, double height) {
    // DHL Express
    double cost = 70;
    double volWeight = (length*width*height)/5000;
    if (volWeight > weight) {
        return volWeight*cost;
    } else {
        return weight*cost;
    }

}

void displayTotalCost (double cost) {
    cout << "Total cost: R " << cost << endl;
}

int main() {
    cout << "Hello, World!" << endl;
    char input;
    cout << "Enter 'G' for GlobalMail or 'D' for DHL Express: ";
    cin >> input;
    if (input == 'g') {
        // GlobalMail
        double weight;
        int zone;
        cout << "Enter weight: ";
        cin >> weight;
        cout << "Enter zone: ";
        cin >> zone;
        displayTotalCost(calcPostage(weight, zone));
    } else if (input == 'd') {
        // DHL Express
        double weight, length, width, height;
        cout << "Enter weight: ";
        cin >> weight;
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
        cout << "Enter height: ";
        cin >> height;
        displayTotalCost(calcPostage(weight, length, width, height));
    } else {
        cout << "Invalid input" << endl;
    }

    return 0;
}

//
// Created by Khangelani Mgoqi on 2024/06/15.
//

/*
Each line in the file contains the following data: the number of members in a family, the number
of family members that ordered the special, the number of bottles of wine that the family ordered,
and the total bill amount. Create the file orders.dat containing the orders of all the families that 
Peter served, as specified below. Declare variables of type int for the first three values and a 
variable of type float for the total bill amount.

read data from the file ordars.dat and display it on the screen.
orders.dat contains the following data:
2 1 2 200.00
4 2 4 400.00
3 1 3 300.00
*/

#include <iostream>
#include <string>
#include <fstream>
#include <array>

using namespace std;

struct order {
    int family_members;
    int special_members;
    int wine_bottles;
    float total_bill;
};

order orders[9];

void create_file() {
    std::ofstream outfile("orders.dat"); // Open the file for writing
    if (!outfile) {
        std::cerr << "Unable to create file" << std::endl;
        return;
    }

    // Write data to the file
    outfile << "5 2 2 670.60\n"; // 1
    outfile << "6 4 2 890.80\n"; // 2
    outfile << "2 2 0 220.00\n"; // 3
    outfile << "10 8 1 1340.60\n"; // 4
    outfile << "10 4 3 1430.70\n"; // 5
    outfile << "4 0 0 460.30\n"; // 6
    outfile << "5 3 1 700.00\n"; // 7
    outfile << "7 5 2 1100.80\n"; // 8
    outfile << "3 1 0 340.80\n"; // 9

    outfile.close(); // Close the file
}

void read_file() {
    std::ifstream infile("orders.dat"); // Open the file for reading
    if (!infile) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }

    int family_members, special_members, wine_bottles;
    float total_bill;

    while (infile >> family_members >> special_members >> wine_bottles >> total_bill) {
        int index;
        orders[index].family_members = family_members;
        orders[index].special_members = special_members;
        orders[index].wine_bottles = wine_bottles;
        orders[index].total_bill = total_bill;
        cout << "Order " << index + 1 << " done!" << endl;
        index++;
        // cout << "Family members: " << family_members << endl;
        // cout << "Special members: " << special_members << endl;
        // cout << "Wine bottles: " << wine_bottles << endl;
        // cout << "Total bill: " << total_bill << endl;
    }

    infile.close(); // Close the file
}

int main() {
    create_file();
    read_file();
    return 0;
}
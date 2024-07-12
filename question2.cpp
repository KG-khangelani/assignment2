//
// Created by Khangelani Mgoqi on 2024/06/15.
//

/*
Write a C++ program to validate if someone is allowed to vote or not. The person who is allowed
to vote should be at least 18 years old. The program should use the assert function to validate
that the year of birth is not equal to the current year and also that the year of birth entered is not
greater than the current year. The program should instruct the user to enter the year of birth. Run
your program twice, once with a year of birth that represents a person younger than 18 years;
and the second time with a year of birth that represents a person older than 18 years or at least
18 years old. Submit the output for both runs together with your source code.
*/

#include <iostream>
#include <cassert>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int yearOfBirth;
    cout << "Enter year of birth: ";
    cin >> yearOfBirth;
    assert(yearOfBirth != 2024);
    assert(yearOfBirth < 2024);
    if ((2024 - yearOfBirth) >= 18) {
        cout << "You are allowed to vote." << endl;
    } else {
        cout << "You are not allowed to vote." << endl;
    }
    return 0;
}
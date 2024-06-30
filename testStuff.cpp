#include<iostream>


using namespace std;

int main() {
    int n=1;
    cout << endl << "The numbers are;" << endl;
    do {
        cout << n << "\t";
        n++;
    } while (n<=100);
    cout << endl;
    return 0;
}
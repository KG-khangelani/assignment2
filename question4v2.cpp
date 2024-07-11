 //
// Created by Khangelani Mgoqi on 2024/07/01.
//
/*
Write a program that reads an input file with the letter character by character.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

vector<char> content = {};
vector<char> encoded_content = {};

void replaceCharWithString(vector<char> &full_letter, char char_to_replace, const vector<char>& replacement) {
    for (int i = 0; i < full_letter.size(); i++) {
        if (full_letter[i] == char_to_replace) {
            full_letter.erase(full_letter.begin() + i);
            for (char j : replacement) {
                full_letter.insert(full_letter.begin() + i, j);
                i++;
            }
        }

        if (full_letter[i] == toupper(char_to_replace)) {
            full_letter.erase(full_letter.begin() + i);
            for (char j: replacement) {
                full_letter.insert(full_letter.begin() + i, toupper(j));
                i++;
            }
        }
    }

    for (char i : full_letter) {
        cout << i;
    }
    cout << endl;
}

void encode_letter () {
    // open the file for reading.
    // read the file character by character.
    // encode the letter.
    // write the encoded letter to a new file.
}

int main () {
    vector<char> letter = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    vector<char> encoded_letter;
    char ch = 'a';
//    replaceCharWithString(letter, ch, "VV");
    encode_letter();
    cout << "loading..." << endl;
    replaceCharWithString(letter, ch, {'V', 'V'});
    return 0;
}
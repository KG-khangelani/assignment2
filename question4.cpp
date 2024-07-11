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
}

void encode_letter () {
    // open the file for reading.
    ifstream file;
    file.open("../letter.txt");
    if (!file) {
        cerr << "Unable to open file" << endl;
        return;
    }

    // read the file character by character.
    char ch;
    while (file >> noskipws >> ch) {
        content.push_back(ch);
    }
    file.close();

    // encode the letter.
    replaceCharWithString(content, 't', {'1', 'Y'});
    replaceCharWithString(content, 'h', {'1','O'});
    replaceCharWithString(content, 'j', {'1', 'X'});
    replaceCharWithString(content, 'd', {'1', 'B'});
    replaceCharWithString(content, 'a', {'1', 'S'});
    replaceCharWithString(content, 'p', {'1', 'M'});
    replaceCharWithString(content, 'i', {'1', 'Q'});

    // write the encoded letter to a new file.
    ofstream outfile("../encode.txt");
    if (!outfile) {
        cerr << "Unable to create file" << endl;
        return;
    }

    for (char i : content) {
        outfile << i;
    }
    outfile.close();

    cout << "Encoded letter saved to: encode.txt" << endl;
}

int main () {
    cout << "loading...\n" << endl;
    encode_letter();
    return 0;
}
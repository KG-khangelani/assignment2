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

void encode_letter (char path[]) {
    // open the file for reading.
    ifstream file;
    file.open(path);
    if (!file) {
        cerr << "Unable to open file. Make sure:\n"
                "-  Make sure you the directory level is correct (ie ../ or ../../)\n"
                "-  File extension is included(ie .txt)" << endl;
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
    cout << "File has been encoded successfully." << endl;
}

int main () {
    char filepath[] = "";
    cout << "---    Question 4 started    ---\n" << endl;
    cout << "Enter the file path: ";
    cin >> filepath;
    cout << endl;
    cout << "loading... path: \""<< filepath << "\"\n" << endl;
    encode_letter(filepath);
    cout << "---    End of programme    ---" << endl;
    return 0;
}
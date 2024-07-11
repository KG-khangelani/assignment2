 //
// Created by Khangelani Mgoqi on 2024/07/01.
//
/*
Write a program that reads an input file with the letter character by character.
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char content[] = "";
char encoded_content[] = "";

void replaceCharWithString(const char str[], char ch, const char newStr[]) {
    char result[] = "";
    char toReplace[] = {ch, ch &= ~' '}; // to replace both upper and lower case
}

void encode_letter () {
    // open the file for reading.
    // read the file character by character.
    // encode the letter.
    // write the encoded letter to a new file.
}

int main () {
    char letter[] = "Dear Julia, You are the";
    char encoded_letter[] = "";
    char ch = 'a';
//    replaceCharWithString(letter, ch, "VV");
    encode_letter();
    cout << "File has been created and encoded successfully" << endl;
    replaceCharWithString(letter, ch, "VV");
    return 0;
}
//
// Created by Khangelani Mgoqi on 2024/07/01.
//
/*
Write a program that reads an input file with the letter character by character.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <valarray>

using namespace std;

string content;
string encoded_content;

void create_file() {
    ofstream outfile("letter.txt"); // Open the file for writing
    if (!outfile) {
        std::cerr << "Unable to create file" << std::endl;
        return;
    }

    // Write data to the file
    outfile <<
        R"(
            Dear Julia,
            You are the most beautiful girl that I have ever seen. I was wondering
            if you would like to come and visit me. My mother will make us
            pancakes with ice cream. My dog, Bella, just had three beautiful puppies.
            Mom says I may only keep one of them. I would like you to help me
            choose one, because they are all so cute and adorable. And just
            because you are my special friend, you may also have one if you want.
            Your friend,
            Hector
        )";
    outfile.close(); // Close the file
}

string replaceCharWithString(string str, char ch, const string& newStr) {
    string newStr2;
    for (char c : str) {
        if (c == ch) {
            newStr2 += newStr;
        } else {
            newStr2 += c;
        }
    }
    return newStr2;
}

void encode_letter () {
    ifstream infile; // Open the file for reading
    infile.open("letter.txt");
    if (!infile) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }

    string line;

    while (getline(infile, line)) {
        content += line + "\n";
    }
    cout << content;
    encoded_content = replaceCharWithString(content, 't' || 'T', "1Y");
    encoded_content = replaceCharWithString(encoded_content,'h' || ('H', "1O");
    cout << encoded_content;
    infile.close(); // Close the file
}

int main () {
    create_file();
    encode_letter();
    return 0;
}
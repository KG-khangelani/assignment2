//
// Created by Khangelani Mgoqi on 2024/07/01.
//
/*
Write a program that reads an input file with the letter character by character.
*/

#include <iostream>
#include <fstream>
#include <string>
//#include <valarray>
#include <algorithm>
using namespace std;

string content, encoded_content;

void create_file() {
    ofstream outfile("letter.txt"); // Open the file for writing
    if (!outfile) {
        std::cerr << "Unable to create file" << std::endl;
        return;
    }

    // Write data to the file
    outfile <<
        R"(
    Dear Julia T,
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

string replaceCharWithString(const string& str, const string& ch, const string& newStr) {
    string result = str;
    size_t pos = str.find(ch);
    while ((pos = result.find(ch, pos)) != string::npos) {
        result.replace(pos, ch.length(), newStr);
        pos += newStr.length();
    }
    size_t posUpper = str.find(toupper(ch[0]));
    while ((posUpper = result.find(toupper(ch[0]), posUpper)) != string::npos) {
        result.replace(posUpper, ch.length(), newStr);
        posUpper += newStr.length();
    }
    return result;
}

void encode_letter () {
    ifstream infile; // Open the file for reading
    infile.open("letter.txt");
    if (!infile) {
        cerr << "Unable to open file" << endl;
        return;
    }

    string line;

    while (getline(infile, line)) {
        content += line + "\n";
    }

    cout << content;
    cout << "    ===============================\n";
    encoded_content = replaceCharWithString(content, "t", "1Y");
    encoded_content = replaceCharWithString(encoded_content, "h", "1O");
    encoded_content = replaceCharWithString(encoded_content, "j", "1X");
    encoded_content = replaceCharWithString(encoded_content, "d", "1B");
    encoded_content = replaceCharWithString(encoded_content, "a", "1S");
    encoded_content = replaceCharWithString(encoded_content, "p", "1M");
    encoded_content = replaceCharWithString(encoded_content, "i", "1Q");
    cout << encoded_content;
    infile.close(); // Close the file
}

int main () {
    create_file();
    encode_letter();
    return 0;
}
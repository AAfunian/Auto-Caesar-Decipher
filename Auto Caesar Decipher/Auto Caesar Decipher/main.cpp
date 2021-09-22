//
//  main.cpp
//  Auto Caesar Decipher
//
//  Created by Amir on 9/20/21.
//

#include <iostream>
#include <ctype.h>

using namespace std;

// processes caesar shift on string x by y letters
string caesar(const string& a, const int& y);

// deciphers caesar shift cipher created by user
void decipher(string& x);

int main() {
    string input;
    string cipher;
    int shift;
    cout << "Enter a sentence to caesar shift: ";
    getline(cin, input);
    cout << "Enter the amount to caesar shift by: ";
    cin >> shift;
    cipher = caesar(input, shift);
    cout << "Cipher: " << cipher << '\n';
    decipher(cipher);
        
    return 0;
}

string caesar(const string& a, const int& y) {
    // x is a copy of original string a
    string x = a;
    //cout << "x: " << x << '\n';
    for (int i = 0; i < x.size(); ++i) {
        // ignores non-alpha characters (whitespace, punctuation, ...)
        if (isalpha(x[i])) {
            // check for lowercase
            if (int(x[i]) >= int('a')) {
                if (int(x[i] + y) > int('z')) {
                    x[i] = char(int(x[i] + y) - 26);
                }
                else {
                    x[i] = char(int(x[i] + y));
                }
            }
            // uppercase swap
            else {
                if (int(x[i] + y) > int('Z')) {
                    x[i] = char(int(x[i] + y) - 26);
                }
                else {
                    x[i] = char(int(x[i] + y));
                }
            }
        }
    }
    return x;
}

void decipher(string& x) {
    char arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int freq[26] = {3,-1,1,1,4,0,0,2,2,-5,-2,1,0,2,3,0,-6,2,2,3,1,-1,0,-5,0,-7};
    int sum;
    int max = 0;
    int maxCtr = 0;
    string s;
    for (int g = 0; g < 26; ++g) {
        sum = 0;
        s = caesar(x, g);
        int index = 0;
        // for each char in the current cipher mapped from 0 to 25, find frequency value, add to sum
        for (char a : s) {
            // find the index and use to find freq value
            for (int i = 0; i < 26; ++i) {
                if (tolower(a) == arr[i]) index = i;
            }
            sum += freq[index];
        }
        if (sum > max) {
            max = sum;
            maxCtr = g;
        }
    }
    cout << "Deciphered sentence: " << caesar(x, maxCtr) << '\n';
}

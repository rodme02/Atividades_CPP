#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    return str == reversedStr;
}

int main() {
    string input;
    cout << "Digite uma string: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << "A string eh um palindromo." << endl;
    } else {
        cout << "A string nao eh um palindromo." << endl;
    }

    return 0;
}
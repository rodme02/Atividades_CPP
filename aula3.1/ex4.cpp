#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int count = input.length();
    cout << "Number of characters: " << count << endl;

    return 0;
}
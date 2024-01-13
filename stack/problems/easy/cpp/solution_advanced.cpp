// This code is not repetitive and uses map; thus, it is considered advanced
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    // Getting input string
    string input;
    cin >> input;

    // Creating new empty stack that accepts only character elements
    stack<char> characters;

    unordered_map<char, char> charactersMapping = { {')', '('}, {']', '['}, {'}', '{'} };

    // Creating a boolean to check whether our input is valid or not
    bool isValid = true;

    // Looping through every character in our input string (Note: c++ 11th version +)
    // Alternative:
    //  for (int i = 0; i < input.size(); i++) {
    //      char ch = input[i];
    
    for (char ch : input) {
        char currentChar = charactersMapping[ch];
        // Checking if current character is a closing one: 
        // Maps receive a key within '[]' and return the key's value
        // charactersMapping[')'] with ')' key returns value '('
        // charactersMapping['('] with '(' key returns undefined, which is false boolean
        if (currentChar) { 
            // If stack is empty or top element of it is an opening bracket, we run the condition
            // Note: if we don't check !characters.empty(), then characters.top() will give error in compilation
            if (characters.empty() || !characters.empty() && characters.top() != currentChar) {
                // Switch isValid boolean to false if our condition works
                isValid = false;

                // Stop the loop and go directly to output
                break;
            }
        }
        // Pushing the character into the stack
        characters.push(ch);
    }

    // Condition: if our string is valid - print "true", if it is not - print "false"
    if (isValid) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
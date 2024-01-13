#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Getting input string
    string input;
    cin >> input;

    // Creating new empty stack that accepts only character elements
    stack<char> characters;

    // Creating a boolean to check whether our input is valid or not
    bool isValid = true;

    // Looping through every character in our input string
    for (char ch : input) {
        if (ch == ')') {
            // If stack is empty or top element of it is an opening bracket, we run the condition
            // Note: if we don't check !characters.empty(), then characters.top() will give error in compilation
            if (characters.empty() || !characters.empty() && characters.top() != '(') {
                // Switch isValid boolean to false if our condition works
                isValid = false;

                // Stop the loop and go directly to output
                break;
            }
        }
        if (ch == ']') {
            if (characters.empty() || !characters.empty() && characters.top() != '[') {
                isValid = false;
                break;
            }
        }
        if (ch == '}') {
            if (characters.empty() || !characters.empty() && characters.top() != '{') {
                isValid = false;
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
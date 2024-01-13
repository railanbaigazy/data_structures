#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to evaluate Reverse Polish Notation expression
int evaluate(const string expression[], int size) {
    stack<int> operands;

    for (int i = 0; i < size; i++) {
        string token = expression[i];
        
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Operator encountered, pop operands from stack
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            // Perform the operation and push the result back to the stack
            if (token == "+") {
                operands.push(operand1 + operand2);
            } else if (token == "-") {
                operands.push(operand1 - operand2);
            } else if (token == "*") {
                operands.push(operand1 * operand2);
            } else if (token == "/") {
                operands.push(operand1 / operand2);
            }
        } else {
            // Operand encountered, push it into the stack after converting to integer with 'stoi()' function
            operands.push(stoi(token));
        }
    }

    // The final result is on the top of the stack
    return operands.top();
}

int main() {
    // Example expressions as arrays of strings
    string expression1[5] = {"2", "1", "+", "3", "*"};
    string expression2[5] = {"4", "13", "5", "/", "+"};

    // Evaluate and print the results
    // Note: we are passing '5' into the function as the size of our array
    cout << "Result 1: " << evaluate(expression1, 5) << endl;
    cout << "Result 2: " << evaluate(expression2, 5) << endl;

    return 0;
}

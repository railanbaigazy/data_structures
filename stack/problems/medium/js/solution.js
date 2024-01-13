class Stack {
    constructor() {
        this.items = []; // Array to store stack elements
    }

    push(element) {
        this.items.push(element); // Add element to the top of the stack
    }

    pop() {
        this.items.pop(); // Remove the element from the top of the stack
    }

    size() {
        return this.items.length; // Get the number of elements in the stack
    }

    top() {
        const stackSize = this.size();

        // Return the element at the top of the stack, or undefined if the stack is empty
        return stackSize > 0 ? this.items[stackSize - 1] : undefined;
    }

    empty() {
        return this.size() <= 0; // Check if the stack is empty
    }
}

// Function to evaluate Reverse Polish Notation expression
function evaluate(expression) {
    const operands = new Stack();

    for (let i = 0; i < expression.length; i++) {
        const token = expression[i];

        if (token === "+" || token === "-" || token === "*" || token === "/") {
            // Operator encountered, pop operands from stack
            const operand2 = operands.top();
            operands.pop();
            const operand1 = operands.top();
            operands.pop();

            // Perform the operation and push the result back to the stack
            if (token === "+") {
                operands.push(operand1 + operand2);
            } else if (token === "-") {
                operands.push(operand1 - operand2);
            } else if (token === "*") {
                operands.push(operand1 * operand2);
            } else if (token === "/") {
                operands.push(Math.floor(operand1 / operand2));
            }
        } else {
            // Operand encountered, push it into the stack after converting to integer with 'parseInt()' function
            operands.push(parseInt(token, 10));
        }
    }

    // The final result is on the top of the stack
    return operands.top();
}

// Example expressions as arrays of strings
const expression1 = ["2", "1", "+", "3", "*"];
const expression2 = ["4", "13", "5", "/", "+"];

// Evaluate and print the results
alert(`Result 1: ${evaluate(expression1)}`);
alert(`Result 2: ${evaluate(expression2)}`);

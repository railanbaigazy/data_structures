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

// Getting input string
const input = prompt("Enter the input string:"); // You can use any method to get user input in the browser

// Creating new empty stack that accepts only character elements
const characters = new Stack();

const charactersMapping = {')': '(', ']': '[', '}': '{'};

// Creating a boolean to check whether our input is valid or not
let isValid = true;

// Looping through every character in our input string
for (const ch of input) {
    const currentChar = charactersMapping[ch];

    // Checking if the current character is a closing one
    if (currentChar) {
        // If the stack is empty or the top element of it is an opening bracket, we run the condition
        if (characters.empty() || !characters.empty() && characters.top() !== currentChar) {
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
    alert("true");
} else {
    alert("false");
}

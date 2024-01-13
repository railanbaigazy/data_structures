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

// Function to find the largest rectangle area in a histogram
function largestArea(heights) {
    const indices = new Stack(); // Stack to store indices of bars
    let maxArea = 0;

    for (let i = 0; i <= heights.length; i++) {
        // Push the current index into the stack if it's empty or the current height is greater than the height at the top of the stack
        while (!indices.empty() && (i === heights.length || heights[i] < heights[indices.top()])) {
            const height = heights[indices.top()];
            indices.pop();

            // Calculate the width of the rectangle
            const width = indices.empty() ? i : i - indices.top() - 1;

            // Update the maximum area
            maxArea = Math.max(maxArea, height * width);
        }

        // Push the current index into the stack
        indices.push(i);
    }

    return maxArea;
}

// Example histogram represented by an array
const heights = [2, 1, 5, 6, 2, 3];

// Find and print the largest rectangle area
const result = largestArea(heights);
alert(`Largest Rectangle Area: ${result}`);

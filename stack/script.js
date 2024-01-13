class Stack {
    constructor() {
        this.items = [] // Array to store stack elements
    }

    push(element) {
        this.items.push(element) // Add element to the top of the stack
    }

    pop() {
        this.items.pop() // Remove the element from the top of the stack
    }

    size() {
        return this.items.length // Get the number of elements in the stack
    }

    top() {
        const stackSize = this.size()

        // Return the element at the top of the stack, or undefined if the stack is empty
        return stackSize > 0 ? this.items[stackSize - 1] : undefined
    }

    empty() {
        return this.size() <= 0 // Check if the stack is empty
    }
}

const friends = new Stack() // Create a new stack instance

friends.push("Blue")
friends.push("Red")
friends.push("Green")

while (!friends.empty()) {
    console.log(friends.top()) // Print the top element of the stack
    friends.pop() // Remove the top element of the stack
}

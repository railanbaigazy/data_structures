#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to find the largest rectangle area in a histogram
int largestArea(int heights[], int size) {
    stack<int> indices; // Stack to store indices of bars
    int maxArea = 0;

    for (int i = 0; i <= size; i++) {
        // Push the current index into the stack if it's empty or the current height is greater than the height at the top of the stack
        while (!indices.empty() && (i == size || heights[i] < heights[indices.top()])) {
            int height = heights[indices.top()];
            indices.pop();

            // Calculate the width of the rectangle
            int width = indices.empty() ? i : i - indices.top() - 1;

            // Update the maximum area
            maxArea = max(maxArea, height * width);
        }

        // Push the current index into the stack
        indices.push(i);
    }

    return maxArea;
}

int main() {
    // Example histogram represented by an array
    int heights[6] = {2, 1, 5, 6, 2, 3};

    // Find and print the largest rectangle area
    int result = largestArea(heights, 6);
    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}

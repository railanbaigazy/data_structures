#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Commented part:
    //
    // //Create a new empty stack
    // stack<string> friends;

    // //Push
    // friends.push("Blue");
    // friends.push("Red");

    // //Pop
    // // friends.pop();

    // //Top
    // // string output = friends.top();
    // // cout << output << endl;

    // //Empty
    // bool isEmpty = friends.empty();

    // if (isEmpty) {
    //     cout << "Empty" << endl;
    // } else {
    //     string output = friends.top();
    //     cout << output << endl;
    //     cout << "Is not empty" << endl;
    // }

    // //Size
    // int stackSize = friends.size();
    // cout << stackSize << endl;

    stack<string> friends; // Create a new stack instance

    friends.push("Blue"); 
    friends.push("Red");
    friends.push("Green");

    //Output
    while (!friends.empty()) {
        cout << friends.top() << endl; // Print the top element of the stack

        friends.pop(); // Remove the top element of the stack
    }

    return 0;
}
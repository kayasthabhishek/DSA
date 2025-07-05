#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        cout << "Deleting stack nodes..." << endl;
        while (top != nullptr) {
            cout << "Deleting node: " << top->data << endl;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cerr << "Stack is empty" << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() {
        if (top == nullptr) {
            cerr << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main()
{
    Stack stack;

    do 
    {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check if empty\n5. Exit\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2: {
                int poppedValue = stack.pop();
                if (poppedValue != -1) {
                    cout << "Popped value: " << poppedValue << endl;
                }
                break;
            }
            case 3: {
                int topValue = stack.peek();
                if (topValue != -1) {
                    cout << "Top value: " << topValue << endl;
                }
                break;
            }
            case 4: {
                cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            }
            case 5:
                return 0; // Exit the program
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (true);
}
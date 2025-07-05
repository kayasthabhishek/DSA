#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* TOS;
public:
    Stack() { this->TOS = nullptr; }
    
    ~Stack() {
        cout << "DELETING STACK NODES..." << endl;
        while (TOS != nullptr) {
            cout << "RELEASING NODE: " << TOS->data << endl;
            Node* temp = TOS;
            TOS = TOS->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return TOS == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        if (!newNode) {
            cout << "\nSTACK OVERFLOW" << endl;
        }
        newNode->next = TOS;
        TOS = newNode;
    }

    int pop() {
        if (this->isEmpty()) {
            cout << "\nSTACK UNDERFLOW" << endl;
            return -1;
        } else {
            int poppedValue = TOS->data;
            Node* temp = TOS;
            TOS = TOS->next;
            delete temp;
            return poppedValue;
        }
    }

    int peek() {
        if (this->isEmpty()) {
            cerr << "STACK IS EMPTY" << endl;
            return -1;
        }
        return TOS->data;
    }

    void display() {
        if (this->isEmpty()) {
            cout << "STACK IS EMPTY." << endl;
            return;
        }
        Node* current = TOS;
        cout << "STACK ELEMENTS: ";
        while (current != nullptr) {
            cout << current->data << " <- ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

};

int main()
{
    Stack stack;
    int choice;

    do 
    {
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. PEEK\n";
        cout << "4. CHECK IF EMPTY\n";
        cout << "5. DISPLAY STACK\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: {
                int value;
                cout << "ENTER VALUE TO PUSH: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2: {
                int poppedValue = stack.pop();
                if (poppedValue != -1) {
                    cout << "POPPED VALUE: " << poppedValue << endl;
                }
                break;
            }
            case 3: {
                int topValue = stack.peek();
                if (topValue != -1) {
                    cout << "TOP VALUE: " << topValue << endl;
                }
                break;
            }
            case 4: {
                cout << (stack.isEmpty() ? "STACK IS EMPTY" : "STACK IS NOT EMPTY") << endl;
                break;
            }
            case 5: {
                stack.display();
                break;
            }
            case 6: {
                break;
            }
            default: {
                cout << "INVALID CHOICE!!!" << endl;
            }
        }
        cout << "PRESS ENTER...";
        cin.ignore(); cin.get();
        if (system("clear") != 0)
            system("cls");
        
    } while (choice != 6);

    return 0;
}
#include "SLL.hpp"

using namespace std;

int main()
{
    SLL list;
    int choice, data, pos;
    if (system("clear") != 0)
        system("cls");

    do {
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete at Beginning" << endl;
        cout << "5. Delete at End" << endl;
        cout << "6. Delete at Position" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Search Element" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                list.insertAtBeg(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data and position to insert: ";
                cin >> data >> pos;
                list.insertAtPos(data, pos);
                break;
            case 4:
                list.deleteAtBeg();
                break;
            case 5:
                list.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deleteAtPos(pos);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Enter element to search: ";
                cin >> data;
                list.search(data);
                break;
            case 9:
                // list.~SLL();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        cout << "Press Enter...";
        cin.ignore(); cin.get();
        if (system("clear") != 0)
            system("cls");

    } while (choice != 9);

    return 0;
}
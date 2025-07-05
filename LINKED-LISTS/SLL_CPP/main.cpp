#include "SLL.hpp"

using namespace std;

int main()
{
    SLL list;
    int choice, data, pos;
    if (system("clear") != 0)
        system("cls");

    do {
        cout << "1. INSERT AT BEGINNING" << endl;
        cout << "2. INSERT AT END" << endl;
        cout << "3. INSERT AT POSITION" << endl;
        cout << "4. DELETE AT BEGINNING" << endl;
        cout << "5. DELETE AT END" << endl;
        cout << "6. DELETE AT POSITION" << endl;
        cout << "7. DISPLAY LIST" << endl;
        cout << "8. SEARCH ELEMENT" << endl;
        cout << "9. EXIT" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "ENTER DATA TO INSERT AT BEGINNING: ";
                cin >> data;
                list.insertAtBeg(data);
                break;
            case 2:
                cout << "ENTER DATA TO INSERT AT END: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "ENTER DATA AND POSITION TO INSERT: ";
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
                cout << "ENTER POSITION TO DELETE: ";
                cin >> pos;
                list.deleteAtPos(pos);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "ENTER ELEMENT TO SEARCH: ";
                cin >> data;
                list.search(data);
                break;
            case 9:
                // list.~SLL();
                break;
            default:
                cout << "INVALID CHOICE! PLEASE TRY AGAIN." << endl;
        }
        cout << "PRESS ENTER...";
        cin.ignore(); cin.get();
        if (system("clear") != 0)
            system("cls");

    } while (choice != 9);

    return 0;
}
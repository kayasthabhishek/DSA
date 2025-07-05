#include "DLL.h"

int main()
{
    int choice, value, pos;
    if (system("clear") != 0)
        system("cls");
    printf("DOUBLY LINKED LIST IMPLEMENTATION\n");
    printf("DLL created successfully!\n");
    
    do
    {
        printf("\n1. INSERT AT BEGINNING\n");
        printf("2. INSERT AT END\n");
        printf("3. INSERT AT POSITION\n");
        printf("4. DELETE NODE FROM BEGINNING\n");
        printf("5. DELETE NODE FROM END\n");
        printf("6. DELETE NODE FROM POSITION\n");
        printf("7. LENGTH OF LIST\n");
        printf("8. LINEAR SEARCH\n");
        printf("9. DISPLAY LIST\n");
        printf("10. DISPLAY LIST IN REVERSE ORDER\n");
        printf("11. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("ENTER VALUE: ");
                scanf("%d", &value);
                insert_at_beg(value);
                break;
            case 2:
                printf("ENTER VALUE: ");
                scanf("%d", &value);
                insert_at_end(value);
                break;
            case 3:
                printf("ENTER VALUE AND POSITION (SEPARATE WITH SPACE): ");
                scanf("%d %d", &value, &pos);
                insert_at_pos(value, pos);
                break;
            case 4:
                delete_node_from_beg();
                break;
            case 5:
                delete_node_from_end();
                break;
            case 6:
                printf("ENTER POSITION TO DELETE: ");
                scanf("%d", &pos);
                delete_node_from_pos(pos);
                break;
            case 7:
                printf("LENGTH OF LIST: %d\n", getlen());
                break;
            case 8:
                printf("ENTER ELEMENT TO SEARCH: ");
                scanf("%d", &value);
                linear_search(value);
                break;
            case 9:
                display();
                break;
            case 10:
                display_reversed();
                break;
            case 11:
                release_memory();
                exit(0);
            default:
                printf("INVALID CHOICE! TRY AGAIN.\n");
        }
        printf("PRESS ENTER...\n");
        getchar(); getchar();
        if (system("clear") != 0)
            system("cls");

    } while (choice != 11);

    return 0;
}
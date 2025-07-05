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
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete node from beginning\n");
        printf("5. Delete node from end\n");
        printf("6. Delete node from position\n");
        printf("7. Length of List\n");
        printf("8. Linear search\n");
        printf("9. Display list\n");
        printf("10. Display list in reverse order\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_at_beg(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_at_end(value);
                break;
            case 3:
                printf("Enter value and position (separate with space): ");
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
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_node_from_pos(pos);
                break;
            case 7:
                printf("Length of List: %d\n", getlen());
                break;
            case 8:
                printf("Enter element to search: ");
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
        printf("Press Enter...\n");
        getchar(); getchar();
        if (system("clear") != 0)
            system("cls");

    } while (choice != 11);

    return 0;
}
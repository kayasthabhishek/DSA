#include "SLL.h"
#ifdef _WIN32
#define SYS_CLEAR "cls"
#else
#define SYS_CLEAR "clear"
#endif


int main()
{
    SLL list = {NULL, NULL};
    int choice, data, pos;
    system(SYS_CLEAR);
    printf("SINGLY LINKED LIST IMPLEMENTATION\n");
    printf("SLL created successfully!\n");
    do
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Search element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        
        switch (choice)
        {
            case 1:
            printf("Enter data: ");
            scanf("%d", &data);
                insertAtBeg(&list, data);
                break;
                case 2:
                printf("Enter Data: ");
                scanf("%d", &data);
                insertAtEnd(&list, data);
                break;
                case 3:
                printf("Enter data and position (separate with space): ");
                scanf("%d %d", &data, &pos);
                insertAtPos(&list, data, pos);
                break;
                case 4:
                deleteAtBeg(&list);
                break;
            case 5:
                deleteAtEnd(&list);
                break;
                case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(&list, pos);
                break;
                case 7:
                display(&list);
                break;
                case 8:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(&list, data);
                break;
                case 9:
                release(&list);
                printf("Exiting...\n");
                break;
                default:
                printf("Invalid choice! Please try again.\n");
            }
        printf("Press Enter...\n");
        getchar();
        getchar();
        system(SYS_CLEAR);
    } while (choice != 9);
    
    return 0;
}
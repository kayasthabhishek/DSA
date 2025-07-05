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
    printf("SLL CREATED SUCCESSFULLY.\n");
    do
    {
        printf("\n1. INSERT AT BEGINNING\n");
        printf("2. INSERT AT END\n");
        printf("3. INSERT AT POSITION\n");
        printf("4. DELETE AT BEGINNING\n");
        printf("5. DELETE AT END\n");
        printf("6. DELETE AT POSITION\n");
        printf("7. DISPLAY LIST\n");
        printf("8. SEARCH ELEMENT\n");
        printf("9. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        
        switch (choice)
        {
            case 1:
                printf("ENTER DATA: ");
                scanf("%d", &data);
                insertAtBeg(&list, data);
                break;
            case 2:
                printf("ENTER DATA: ");
                scanf("%d", &data);
                insertAtEnd(&list, data);
                break;
            case 3:
                printf("ENTER DATA AND POSITION (SEPARATE WITH SPACE): ");
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
                printf("ENTER POSITION TO DELETE: ");
                scanf("%d", &pos);
                deleteAtPos(&list, pos);
                break;
            case 7:
                display(&list);
                break;
            case 8:
                printf("ENTER ELEMENT TO SEARCH: ");
                scanf("%d", &data);
                search(&list, data);
                break;
            case 9:
                release(&list);
                break;
            default:
                printf("INVALID CHOICE! PLEASE TRY AGAIN.\n");
            }
        printf("PRESS ENTER...\n");
        getchar();
        getchar();
        system(SYS_CLEAR);
    } while (choice != 9);
    
    return 0;
}
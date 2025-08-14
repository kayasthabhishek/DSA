#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void selection_sort(int A[], int len)
{
    int i, j, least, pos, temp;
    for (i = 0; i < len; i++) {
        least = A[i];
        pos = i;

        for (j = i + 1; j < len; j++) {
            if (A[j] < least) {
                least = A[j];
                pos = j;
            }
        }

        if (i != pos) {
            temp = A[i];
            A[i] = A[pos];
            A[pos] = temp;
        }
    }
}

void display(int A[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}


int main()
{
    int A[MAX];
    int len, i;
    time_t t1, t2;
    double diff;
    
    do {
        printf("ENTER NUMBER OF ELEMENTS: ");
        scanf("%d", &len);
        if (len > MAX || len <= 0) 
            printf("LENGTH EXCEEDS MAXIMUM LIMIT");
    } while (len > MAX || len <= 0);

    srand(time(NULL));
    for (i = 0; i < len; i++) {
        A[i] = rand() % (MAX*2);
    }

    printf("UNSORTED ARRAY: ");
    display(A, len);

    t1 = time(NULL);
    selection_sort(A, len);
    t2 = time(NULL);

    diff = difftime(t2, t1);
    printf("SORTED ARRAY USING SELECTION-SORT: ");
    display(A, len);
    printf("TIME: %.6f seconds", diff);

    return 0;
}
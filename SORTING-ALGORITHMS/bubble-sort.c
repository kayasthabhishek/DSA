#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void bubble_sort(int A[], int len)
{
    int i, j, temp;

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
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
    clock_t t1, t2;
    double diff;

    printf("BUBBLE SORT IMPLEMENTATION\n");
    do {
        printf("ENTER NUMBER OF ELEMENTS: ");
        scanf("%d", &len);
        if (len > MAX || len <= 0) 
            printf("LENGTH EXCEEDS MAXIMUM LIMIT\n");
    } while (len > MAX || len <= 0);

    srand(time(NULL));
    for (i = 0; i < len; i++) {
        A[i] = rand() % (MAX*2);
    }

    printf("UNSORTED ARRAY: ");
    display(A, len);

    t1 = clock();
    bubble_sort(A, len);
    t2 = clock();

    diff = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("SORTED ARRAY USING BUBBLE-SORT: ");
    display(A, len);
    printf("TIME: %.6f seconds", diff);

    return 0;
}
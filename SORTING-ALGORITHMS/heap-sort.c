#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 500001

void max_heapify(int A[], int i, int len)
{
    int left = 2*i;
    int right = 2*i+1;
    int large = i;
    int temp;

    if (left <= len && A[left] > A[large])
    large = left;
    
    if (right <= len && A[right] > A[large])
    large = right;
    
    if (large != i) {
        temp = A[i];
        A[i] = A[large];
        A[large] = temp;

        max_heapify(A, large, len);
    }
}

void BuildHeap(int A[], int len)
{
    int i;
    for (i = len / 2; i >= 1; i--) {
        max_heapify(A, i, len);
    }
}

void HeapSort(int A[], int len)
{
    int i, temp;

    BuildHeap(A, len);

    for (i = len; i >= 2; i--) {
        temp = A[1];
        A[1] = A[len];
        A[len] = temp;

        len = len-1;

        max_heapify(A, 1, len);
    } 
}

void display(int A[], int len)
{
    for (int i = 1; i <= len; i++) {
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
    
    do {
        printf("ENTER NUMBER OF ELEMENTS: ");
        scanf("%d", &len);
        if (len > MAX || len <= 0) 
            printf("LENGTH EXCEEDS MAXIMUM LIMIT");
    } while (len > MAX || len <= 0);

    srand(time(NULL));
    for (i = 1; i <= len; i++) {
        A[i] = rand() % (len*3);
    }

    printf("UNSORTED ARRAY: ");
    display(A, len);

    t1 = clock();
    HeapSort(A, len);
    t2 = clock();

    diff = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
    printf("SORTED ARRAY USING HEAP-SORT: ");
    display(A, len);
    printf("TIME: %.6f seconds", diff);

    return 0;
}
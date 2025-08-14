# SORTING
> Arrangement of data in some systematic order is called sorting

> ***Sorting can be done in following orders:***
    - Ascending order
    - Descending order

## COMPILE THE C FILE:
```bash
gcc bubble-sort.c -o bubble-sort -O0
```

```bash
gcc insertion-sort.c -o insertion-sort -O0
```

```bash
gcc selection-sort.c -o selection-sort -O0
```

```bash
gcc merge-sort.c -o merge-sort -O0
```

```bash
gcc heap-sort.c -o heap-sort -O0
```

```bash
gcc shell-sort.c -o shell-sort -O0
```

```bash
gcc radix-sort.c -o radix-sort -O0
```

# Types of Sorting: 
> Sorting can be categorized into different categories:
- ***Internal and External Sorting:***
    - ***Internal Sorting:*** The sorting done within the computer main memory is called internal sorting. It is performed on data items small enough to easily fit within the main memory.
    - ***External Sorting:*** The sorting of data that is too large to fit into the main memory, the sorting is done in external file disk, i.e. secondary memory. It involves dividing the data into smaller chunks, sorting them individually, and then merging the sorted chunks.

- ***Stable and Unstable Sorting:***
    - ***Stable Sorting:*** A sorting algorithm is said to be stable if it preserves the relative order of records with equal keys (i.e., values). In other words, if two elements are equal, a stable sort will ensure that they remain in the same order in the sorted output as they were in the input.
    - ***Unstable Sorting:*** An unstable sorting algorithm does not guarantee to preserve the relative order of records with equal keys. This means that equal elements may appear in a different order in the sorted output compared to the input.

- ***In-place and Out-of-place Sorting:***
    - ***In-place Sorting:*** An in-place sorting algorithm is one that does not requires additional storage space to sort the data. It sorts the data by modifying the input data structure directly.
    - ***Out-of-place Sorting:*** An out-of-place sorting algorithm requires additional storage space proportional to the size of the input data.

- ***Adaptive vs Non-adaptive Sorting:***
    - ***Adaptive Sorting:*** An adaptive sorting algorithm takes advantage of existing order in its input. If the input is partially sorted, an adaptive sort can run faster than a non-adaptive sort.
    Example: Insertion sort, Bubble sort, Selection sort, etc.
    - ***Non-adaptive Sorting:*** A non-adaptive sorting algorithm does not take advantage of any existing order in its input. It always runs in the same time regardless of the input's initial order.
    Example: Merge-sort, Quick-sort, Heap-sort, etc.


# EFFICIENCY
> Efficiency of the algorithms depend upon mainly two factors
1. Time Complexity
2. Space Complexity

# SORTING ALGORITHMS
1. ***Bubble Sort***:
    - Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. 
    - The pass through the list is repeated until the list is sorted.
    - It is called Bubble Sort because the data gradually bubbles up in its proper position. In each pass at least one data is bubbled up in its proper position

2. ***Insertion Sort:***
    - Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. 
    - Any unsorted data item is kept on swapping with its previous data items until its proper position is not found. Once the new data item is inserted, the next data item after it is chosen for next insertion. The process continues until all data items are sorted
    - It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

3. ***Selection Sort:***
    - Selection sort is a simple comparison-based sorting algorithm. It works by dividing the input list into two parts: the sorted part and the unsorted part. The algorithm repeatedly selects the smallest (or largest) element from the unsorted part and moves it to the end of the sorted part.
    - A list of n elements requires n-1 passes to completely rearrange the data. The last pass requires only one comparison between the last two elements remaining

4. ***Merge Sort:***    
    - Merge sort is an efficient, stable, comparison-based, divide-and-conquer sorting algorithm. 
    - It works by recursively dividing the input array into two halves the process is repeated until each sub-list contain exactly 1 item, then sorting each half, and then merging the sorted halves back together.
    - Conquer part:
        - A list with a single element is considered sorted automatically
        - Pair of list is sorted and merged into one (i.e. approx. n/2 sublists of size 2)
        - The sort and merge is keep on repeated until a single list of size n is found
    - The overall dividing and conquering is done recursively.

5. ***Quick Sort:***
    - Also called partition-exchange sort
    - Quick sort is an efficient, in-place sorting algorithm that uses a divide-and-conquer approach to sort elements. 
    - It works by selecting a "pivot" element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. All values less than the pivot are placed on left side of pivot. All greater values are placed on right side of the pivot. The pivot is then placed in its final position, and the process is repeated for the left and right sub-arrays.

6. ***Heap Sort:***
    - Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. 
    - It is an in-place algorithm • It is not a stable sort • Heap sort algorithm is divided into two-parts
        • Building of heap
        • Sorting of data in an array from the heap
    - Heaps are almost complete binary tree, where
        - Content of each node is less than or equal to that of its father
        - All levels are full except the lowest level
        - If lowest level is not full, then nodes must be packed to left
        - The operations performed in a heap tree are: insertion and deletion
        - Insertion always occurs in empty left child node
        - Deletion occurs from root node
    - It works by first building a max heap (or min heap) from the input data, and then repeatedly extracting the maximum (or minimum) element from the heap and rebuilding the heap until all elements are sorted.

7. ***Shell Sort:***
    - Also called diminishing increment sort
    - Shell sort is an optimization of insertion sort that allows the exchange of items that are far apart. 
    - The idea is to arrange the list of elements so that, starting anywhere, taking every h-th element produces a sorted list. This is done by using a gap sequence to determine which elements to compare and swap. The process is repeated until gap value is less than 1; the list is sorted by the end of this pass

8. ***Radix Sort:***
    - Radix sort is a non-comparison-based sorting algorithm that sorts integers by processing individual digits. 
    - Queues are made for representing different key values. In each queue sub-lists from the original list are formed depending on the key values
    - It works by grouping numbers by their individual digits, starting from the least significant digit to the most significant digit, and using a stable sorting algorithm (like counting sort) as a subroutine.
    - The data to be sorted in the given list is checked starting from any of the position(LSD/MSD) in data
        - If the starting position is LSD – Least Significant Digit, then the sorting is called LSD Radix Sort
        - If the starting position is MSD – Most Significant Digit, then the sorting is called MSD Radix Sort
    - All the values are made of same length by adding 0s as MSDs if any of the values is shorter than others
    - Sub-lists are now gathered into main list in order of the key values in queues
    - If LSD is being used, one’s position are checked first and sub-lists are formed
    - Thus formed list is now again checked for ten’s place and sub-lists are formed on queues
    - The gathering and forming of sub-lists is continued for other higher placed digit until every queue contains at most one data items
    - Now the final gathering results with the sorted list
    - LSD Radix Sort is mainly used for sorting Numeral values
    - MSD Radix Sort is mainly used for sorting Alphabetical values
    - Its main advantage is that the computers represent data in binary form which can be sorted easily by using radix sort
    - Its main disadvantage is that it requires more space than other sorting algorithms

<!-- 
### TIME AND SPACE COMPLEXITIES

| ***SORTING ALGORITHMS*** | ***TIME COMPLEXITY*** | ***SPACE COMPLEXITY***
|--------------------------|-----------------------|-----------------------
| Bubble Sort              | O(n^2)                | O(n)
| Selection Sort           | O(n^2)                | O(n)
| Insertion Sort           | O(n^2)                | O(n)
| Merge Sort               | O(n log n) / O(n^2)   | O(n)
| Quick Sort               | O(n log n)            | O(log n)
| Heap Sort                | O(n log n)            | O(1)
| Shell Sort               | O(n log n)            | O(1)
| Radix Sort               | O(nk)                 | O(n + k) -->


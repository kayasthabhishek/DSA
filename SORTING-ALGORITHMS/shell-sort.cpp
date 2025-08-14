#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void display(int arr[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << "]\n";
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap = static_cast<int>(floor(gap / 2)))
    {
        for (int j = gap; j < n; j++) 
        {
            for (int i = j - gap; i >= 0; i -= gap)
            {
                display(arr, n);
                if (arr[i] > arr[i + gap])
                {
                    swap(arr[i], arr[i + gap]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {23, 29, 15, 19, 31, 7, 9, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t t1, t2;
    double diff;

    t1 = clock();
    shellSort(arr, n);
    t2 = clock();

    diff = (double)(t2 - t1) / CLOCKS_PER_SEC;
    cout << "SORTED ARRAY: \n";
    display(arr, n);
    cout << "TIME TAKEN: " << diff << " seconds\n";

    return 0;
}
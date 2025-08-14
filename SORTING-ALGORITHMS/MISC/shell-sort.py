def shellSort2(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        print(f"Gap: {gap}")
        for i in range(gap, n):
            temp = arr[i]
            j = i

            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
                print(f"Swapping {arr[j + gap]} and {arr[j]} -> {arr}")

            arr[j] = temp
        gap //= 2

    return arr


def shellSort1(arr):
    gap = n = len(arr)
    
    while gap := gap // 2:
        for j in range(gap, n):
            for i in range(j-gap, -1, -gap):
                if arr[i] > arr[i + gap]:
                    arr[i], arr[i + gap] = arr[i + gap], arr[i]
                else:
                    break
                print(arr)



a = [23, 29, 15, 19, 31, 7, 9, 5, 2]
shellSort1(a)
print("Sorted List: ", a)
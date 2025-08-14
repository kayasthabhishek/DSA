def quick_sort(arr, left, right):
    if left >= right:
        return

    pivot_index = partition(arr, left, right)
    
    # Recursive calls
    quick_sort(arr, left, pivot_index - 1)
    quick_sort(arr, pivot_index + 1, right)

def partition(arr, left, right):
    pivot = arr[right]
    i = left - 1

    print(f"\n=== Partitioning from {left} to {right} ===")
    print(f"Initial array: {arr[left:right+1]}, pivot = {pivot}")

    for j in range(left, right):
        print(f"Comparing arr[{j}] = {arr[j]} with pivot = {pivot}")
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            print(f"  Swapped arr[{i}] and arr[{j}], new array: {arr}")
            print(f"  -> i pointer moved to {i}")
        else:
            print(f"  No swap needed")

    arr[i + 1], arr[right] = arr[right], arr[i + 1]
    print(f"Placing pivot in position {i+1}, final array for this partition: {arr}")
    return i + 1

# 🧪 Test
arr = [8, 4, 7, 3, 10, 1, 9, 5]
quick_sort(arr, 0, len(arr) - 1)
print("\n🎉 Sorted array:", arr)

def bubble_sort(arr):
	for i in range(len(arr) - 1, 0, -1):
		for j in range(i):
			if arr[j] > arr[j + 1]:
				
				temp = arr[j + 1]
				arr[j + 1] = arr[j]
				arr[j] = temp

	return arr

# Example usage
if __name__ == "__main__":
    liss = [12, 10, 0, 7, 9, 6, 11, 3]
    sorted_list = bubble_sort(liss)
    print(sorted_list)
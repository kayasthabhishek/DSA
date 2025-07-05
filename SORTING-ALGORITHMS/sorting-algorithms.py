class SORTS:
	def __init__(self, arr):
		self.arr = arr

	def bubble_sort(self):
		return bubble_sort(self.arr)
	
	def quick_sort(self):
		return quick_sort(self.arr)


def bubble_sort(items):
	for i in range(len(items) - 1, 0, -1):
		for j in range(i):
			if items[j] > items[j + 1]:
				
				temp = items[j + 1]
				items[j + 1] = items[j]
				items[j] = temp
		print(f"After pass {len(items) - i}: {items}")
	return items

def quick_sort(items, left=None, right=None):
	if left == None:
		left = 0
	if right == None:
		right = len(items) - 1

	if right <= left:
		return
	
	i = left
	pivot = items[right]
	for j in range(left, right):
		# i will track first greater than pivot
		if items[j] <= pivot:
			items[i], items[j] = items[j], items[i]
			i += 1
	
	items[i], items[right] = items[right], items[i]

	print(f"Pivot: {pivot}, List: {items}")

	quick_sort(items, left, i - 1)
	# i is now at the pivot position
	quick_sort(items, i + 1, right)


if __name__ == "__main__":
	arr = [5, 2, 9, 1, 5, 6]
	sorts = SORTS(arr)

	print("Original array:", arr)
	sorts.quick_sort()
	print("Sorted array:", arr)

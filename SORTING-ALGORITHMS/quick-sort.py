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
        if items[j] <= pivot:
            items[i], items[j] = items[j], items[i]
            i += 1

    items[i], items[right] = items[right], items[i]
    

    quick_sort(items, left, i - 1)
    quick_sort(items, i + 1, right)


liss = [12, 10, 0, 7, 9, 6, 11, 3]
quick_sort(liss)
print(liss)
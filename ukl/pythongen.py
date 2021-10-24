# Sorting algorithm pseudocode:
# if is sorted:
# return
# else:
# move item a to pos i[a]
from itertools import permutations


def sortBajt(arr):
    time = 0
    arrSorted = sorted(arr)
    print(arrSorted)
    while arr != arrSorted:
        if arr[0] == 1:
            time += len(arr)-1
            arr.insert(0, arr.pop(-1))
        else:
            time += arr[0]-1
            a = arr.pop(arr[0]-1)
            arr.insert(0, a)
        # print(arr)
    return time


print()

x = int(input("Biggest num: "))

for i in range(x):
    iTime = 0
    arr = [j+1 for j in range(i+1)]
    perms = permutations(arr, i+1)
    for perm in perms:
        print(perm, end=' ')
        iTime += sortBajt(list(perm))
    print(f" Time = {iTime} ")

    # print(arr)

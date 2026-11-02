# BINARY SEARCH

## AIM
    To implement Binary Search using Iterative and Recursive approaches to find a given element in a sorted array.
    
## ALGORITHM

### ITERATIVE
1. Start.
2. Set two pointes.
    - low = 0
    - high = n - 1
3. While low <= high.
    - Calculate mid = (low + high) / 2
    - If arr[mid] == key then return mid
    - Else if key < arr[mid], set high = mid - 1
    - Else set low = mid + 1
4. If low > high then output "Element not found"
5. Stop

### RECURSIVE

1. Start
2. Inititialize two pointers:
    - low = 0
    - high = n - 1
3. If low > high return -1 (Element not found).
4. Calculate mid = (low + high) / 2.
5. If arr[mid] == key, return mid.
6. Else If key < arr[mid]:
    - Recursively call the function with low and mid - 1
7. Else:
    - Recursively call the function with mid + 1 and high
8. Return the result of recursive call.
9. Stop
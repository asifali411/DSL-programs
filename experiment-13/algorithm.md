# SORTING ALGORITHMS

## AIM
    To implement Bubble Sort, Insertion Sort, Radix Sort, Quick Sort and Merge Sort and compare the number of steps involved in each.

## ALGORITHM

### BUBBLE SORT

1. Start.
2. Read n elements into the array arr.
3. For i = 0 to n - 2:
    - For j = 0 to n - i - 2:
        - Compare arr[j] and arr[j + 1] and increment number_of_steps.
        - If arr[j + 1] < arr[j], swap arr[j] and arr[j + 1].
4. Display the sorted array and number_of_steps.
5. Stop.

### INSERTION SORT

1. Start.
2. Read n elements into the array arr.
3. If n <= 1, go to step 5.
4. For i = 1 to n - 1:
    - Set temp = arr[i] and j = i - 1.
    - While j >= 0:
        - Increment number_of_steps.
        - If arr[j] <= temp, stop the loop.
        - Else shift arr[j] to arr[j + 1] and decrement j.
    - Place temp at arr[j + 1].
5. Display the sorted array and number_of_steps.
6. Stop.

### RADIX SORT

1. Start.
2. Read n elements into the array arr.
3. If n <= 1, go to step 6.
4. Find the largest element max in arr.
5. For exp = 1 while max / exp > 0, with exp = exp * 10:
    - Initialize the count array of size 10 to 0.
    - Create a bucket array of size 10 x MAX.
    - For each element arr[i]:
        - Find the digit index = (arr[i] / exp) % 10.
        - Place arr[i] into bucket[index][count[index]].
        - Increment count[index].
        - Increment number_of_steps.
    - Collect the elements from bucket 0 to bucket 9 back into arr in order.
6. Display the sorted array and number_of_steps.
7. Stop.

### QUICK SORT

1. Start.
2. Read n elements into the array arr.
3. Call sort(arr, 0, n - 1).
4. In sort(arr, low, high):
    - If low >= high, return.
    - Set index = pivot_idx(arr, low, high).
    - Recursively sort arr[low] to arr[index - 1].
    - Recursively sort arr[index + 1] to arr[high].
5. In pivot_idx(arr, low, high):
    - Set pivot = arr[low], i = low + 1 and j = high.
    - Repeat:
        - While i <= high:
            - Increment number_of_steps.
            - If arr[i] > pivot, stop the loop.
            - Increment i.
        - While j > low:
            - Increment number_of_steps.
            - If arr[j] <= pivot, stop the loop.
            - Decrement j.
        - If i < j, swap arr[i] and arr[j]; otherwise stop the loop.
    - Swap arr[low] and arr[j].
    - Return j.
6. Display the sorted array and number_of_steps.
7. Stop.

### MERGE SORT

1. Start.
2. Read n elements into the array arr.
3. Call sort(arr, 0, n - 1).
4. In sort(arr, low, high):
    - If low >= high, return.
    - Set mid = (low + high) / 2.
    - Recursively sort arr[low] to arr[mid].
    - Recursively sort arr[mid + 1] to arr[high].
    - Merge the two sorted halves.
5. In merge(arr, low, mid, high):
    - Create a temporary array temp.
    - Set i = low, j = mid + 1 and k = low.
    - While i <= mid and j <= high:
        - Increment number_of_steps.
        - If arr[i] <= arr[j], copy arr[i] into temp[k] and increment i.
        - Else copy arr[j] into temp[k] and increment j.
        - Increment k.
    - Copy any remaining elements of the left half into temp.
    - Copy any remaining elements of the right half into temp.
    - Copy temp[low ... high] back into arr.
6. Display the sorted array and number_of_steps.
7. Stop.

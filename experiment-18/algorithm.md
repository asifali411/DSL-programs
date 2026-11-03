# MERGE K SORTED LISTS USING A MIN-HEAP

## AIM
    To merge K sorted lists into a single sorted list using a min-heap that keeps track of the smallest element from each list.

## ALGORITHM

1. Start.
2. Read the number of lists K.
3. Read the elements of each list; every list is sorted in ascending order.
4. Create a min-heap where each entry stores:
    - value -> the first (smallest) element of a list.
    - list_index -> the list from which the element came.
5. Insert the first element of every non-empty list into the min-heap.
6. While the min-heap is not empty:
    - Extract the entry with the smallest value from the heap.
    - Append that value to the merged list.
    - If the list at list_index still has elements, insert its next element into the min-heap.
7. Display the merged list.
8. Stop.

### HEAP OPERATIONS

#### INSERT (SIFT-UP)

1. Place the new entry at the end of the heap and increment the heap size.
2. While the entry is not at the root:
    - Find the parent index = (current index - 1) / 2.
    - If the parent value is greater than the current value, swap them and continue from the parent index.
    - Otherwise stop.

#### EXTRACT MINIMUM (SIFT-DOWN)

1. The root holds the minimum entry.
2. Replace the root with the last entry and decrement the heap size.
3. While the current index has a child:
    - Find the left child index = 2 * current index + 1 and the right child index = 2 * current index + 2.
    - Select the smallest of the current entry, the left child and the right child.
    - If the current entry is the smallest, stop.
    - Otherwise swap it with the smallest child and continue from that child's index.
4. Return the removed minimum entry.

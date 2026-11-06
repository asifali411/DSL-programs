# MERGE K SORTED LISTS USING A MIN-HEAP

## AIM
To merge K sorted linked lists into a single sorted list using a min-heap that holds a pointer to the current front node of each list.

## ALGORITHM

1. Start.
2. Read the number of lists K.
3. For each list, read the number of elements and then the elements, which are in ascending order. Store each list as a linked list, appending every new element at the tail in O(1) using a tail pointer.
4. Create a min-heap (an array of node pointers). Each heap entry is a pointer to the current front node of one list. The key is `node->data`, and the node's `next` pointer leads to the rest of its list, so no separate list index is needed.
5. Build the heap: for every non-empty list, place its head node at the end of the heap, increment the heap size, and sift it up. Skip empty lists.
6. Create an empty result list with a head pointer and a tail pointer.
7. While the heap is not empty:
    - Take the root node, which holds the smallest value, and append its value to the result list.
    - Replace the root with the root's `next` node (advance that list by one).
    - If `next` is NULL, that list is exhausted. Replace the root with the last heap entry and decrement the heap size.
    - Sift the root down to restore the heap property.
8. Display each input list and the merged result list.
9. Free all the lists and the result list.
10. Stop.

### HEAP OPERATIONS

#### BUILD HEAP (SIFT-UP)

1. For each non-empty list, place its head node at index `heap_size` and set `idx = heap_size`, then increment the heap size.
2. While `idx > 0`:
    - Find the parent index = (idx - 1) / 2.
    - If the node's value is smaller than the parent's value, swap them and continue from the parent index.
    - Otherwise stop.

#### REPLACE ROOT (SIFT-DOWN)

Used after the root has been consumed and replaced, either by its `next` node or by the last heap entry.

1. Start at `idx = 0`.
2. While the current index has a child inside the heap:
    - Find the left child index = 2 * idx + 1 and the right child index = 2 * idx + 2.
    - Select the smallest of the current node, the left child and the right child, considering only children with index < heap size.
    - If the current node is the smallest, stop.
    - Otherwise swap it with the smallest child and continue from that child's index.

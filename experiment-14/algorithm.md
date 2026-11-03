# GENERAL POST OFFICE PRIORITY QUEUE

## AIM
    To simulate the preferential treatment of customers at the General Post Office using a max-heap, so that customers are served in the order Differently abled, Senior citizen, Defence personnel and Ordinary.

## ALGORITHM

1. Start.
2. Define a Customer structure containing:
    - name -> name of the customer.
    - priority -> preference value of the customer.
3. Initialize an empty max-heap of customers and set size = 0.
4. Add Customer:
    - If the heap is full, display "Customer list is full" and return.
    - Create a new customer with the given name and priority.
    - Insert the customer at the end of the heap and increment size.
    - While the customer is not at the root:
        - Find the parent index = (current index - 1) / 2.
        - If the parent has lower priority than the customer, swap them and continue from the parent index.
        - Otherwise stop.
5. Serve Customer:
    - If the heap is empty, display "No customer left to serve" and return.
    - The customer at the root has the highest priority.
    - Swap the root with the last customer.
    - Decrement size and display the served customer.
    - Restore the max-heap property from the root:
        - Find the left child index = 2 * current index + 1 and the right child index = 2 * current index + 2.
        - Select the largest of the current node, the left child and the right child.
        - If the current node is the largest, stop.
        - Otherwise swap it with the largest child and continue from that child's index.
6. Display Customers:
    - For i = 0 to size - 1, display the name and priority of heap[i].
7. Display the menu and repeat steps 4 to 6 according to the user's choice until Exit is selected.
8. Stop.

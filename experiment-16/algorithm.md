# MEMORY ALLOCATOR AND GARBAGE COLLECTOR

## AIM
    To simulate a basic memory allocator and garbage collector using a doubly linked list.

## ALGORITHM

1. Start.
2. Define the constants and the Block structure:
    - FREE = 1, USED = 0, START_ADDRESS = 1000.
    - Block contains:
        - start_address -> the starting address of the block.
        - size -> the size of the block.
        - is_free -> FREE if the block is unused, USED otherwise.
        - prev -> pointer to the previous block.
        - next -> pointer to the next block.
3. Initialize the global pointer head = NULL.
4. Create Block (start_address, size, is_free):
    - Allocate memory for a new block.
    - Set its start_address, size and is_free.
    - Set next and prev to NULL.
    - Return the new block.
5. Add Block (start_address, size, is_free):
    - Create a block with the given start address, size and status.
    - Compute next_address = start_address + size.
    - If the list is empty, set head to the new block and return next_address.
    - Otherwise traverse to the last block, set last->next to the new block and new block->prev to the last block.
    - Return next_address as the next available address.
6. Display Blocks:
    - Traverse the list from head using next.
    - Display the start address, size and status (FREE / USED) of every block.
7. Delete Block (block):
    - If block is NULL, return.
    - Let prev_block = block->prev and next_block = block->next.
    - If prev_block exists, set prev_block->next = next_block. Otherwise set head = next_block.
    - If next_block exists, set next_block->prev = prev_block.
    - Free the block.
8. Garbage Collection:
    - If the list is empty (head == NULL), return.
    - Set current = head.
    - Repeat while current and current->next are not NULL:
        - If both current and current->next are free:
            - Add the size of current->next to current->size.
            - Delete current->next using Delete Block.
            - Do not advance current, so that several consecutive free blocks are merged into one.
        - Otherwise, move current to current->next.
9. Compaction:
    - If the list is empty (head == NULL), return.
    - Initialize new_head = NULL, tail = NULL, current_start_address = START_ADDRESS and total_free_space = 0.
    - Traverse the old list from head:
        - If the block is free, add its size to total_free_space.
        - If the block is used:
            - Create a new USED block with start address current_start_address and the same size.
            - Append it to the end of the new list (set new_head if the new list is empty, otherwise link it after tail and update tail).
            - Advance current_start_address by the block size.
    - After the traversal, if total_free_space > 0:
        - Create one FREE block of size total_free_space at current_start_address.
        - Append it to the end of the new list (it becomes new_head if there were no used blocks).
    - Free all blocks of the old list using Free Memory Blocks.
    - Set head = new_head.
10. Free Memory Blocks:
    - Traverse from head, saving each block in a temporary pointer, moving head to head->next and freeing the saved block.
    - Continue until head becomes NULL.
11. Main Program:
    - Set next_address = START_ADDRESS and add the following blocks in order, each starting at the address returned by the previous call:
        - 100 FREE, 200 USED, 300 FREE, 100 USED, 300 FREE, 100 FREE.
    - Display the blocks (before garbage collection and compaction).
    - Perform Garbage Collection and display the blocks.
    - Perform Compaction and display the blocks.
    - Free all remaining blocks before exiting.
12. Stop.
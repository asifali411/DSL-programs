# MEMORY ALLOCATOR AND GARBAGE COLLECTOR

## AIM
    To simulate a basic memory allocator and garbage collector using a doubly linked list.

## ALGORITHM

1. Start.
2. Define a Block structure containing:
    - start_address -> the starting address of the block.
    - size -> the size of the block.
    - is_free -> FREE if the block is unused, USED otherwise.
    - next -> pointer to the next block.
3. Initialize head = NULL and set the starting address to START_ADDRESS (1000).
4. Create Block:
    - Allocate a new block and set its start_address, size and is_free.
    - Set next and prev to NULL.
5. Add Block:
    - Create a block with the given start address, size and status.
    - If the list is empty, set head to the new block.
    - Otherwise traverse to the last block, link it to the new block and set the new block's prev to the last block.
    - Return start_address + size as the next available address.
6. Display Blocks:
    - Traverse the list from head using next.
    - Display the start address, size and status of every block.
7. Garbage Collection:
    - If the list has fewer than two blocks, return.
    - Start from head and examine each pair of adjacent blocks.
    - If both the current block and the next block are free:
        - Add the size of the next block to the current block.
        - Link the current block to the block after the next block.
        - Update the prev pointer of the following block, if it exists.
        - Free the removed block.
    - Otherwise move to the next block.
8. Compaction:
    - Initialize a new empty list, current_start_address = START_ADDRESS and total_free_space = 0.
    - Traverse the old list:
        - If the block is free, add its size to total_free_space.
        - If the block is used, create a new used block with current_start_address and the same size, append it to the new list, and advance current_start_address by the block size.
    - After the traversal, if total_free_space > 0, create one free block of that size at current_start_address and append it to the end of the new list.
    - Free all blocks of the old list and set head to the new list.
9. Stop.

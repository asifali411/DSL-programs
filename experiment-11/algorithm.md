# FIND AND REPLACE

## AIM
    To write a C program to find and replace a specific word in a sentence using a singly linked list.

## ALGORITHM
1. Start.
2. Read a sentence from the user.
3. Split the sentence into individual words using strtok().
4. Create a singly linked list:
    - Each node stores:
        - One word.
        - A pointer to the next node.
5. Traverse the linked list:
    - Compare each word with the target word.
    - If a match is found, replace it with the replacement word.
6. Display the modified sentence.
7. Free the allocated memory.
8. Stop.
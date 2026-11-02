# DICTIONARY IMPLEMENTATION USING BST

## AIM
    To implement a dictionary that stores word-meaning pairs using a binary search tree (BST).

## ALGORITHM

1. Start
2. Create a Node structure:
    - word -> the keyword (string)
    - meaning -> its respective meaning string
    - left, right -> pointers representing BST links
3. Insert Operation
    - If the tree is empty, create a new node and set it as the root.
    - If the new word is alphabetically smaller than the word at the root, insert it into the left subtree.
    - If the new word is alphabetically greater than the word at the root, insert it into the right subtree.
    - If the word already exists, display a message that the word already exists in the dictionary.
    - Repeat recursively until the correct position is found.
4. Search Operation
    - Compare the given word with the current node's word:
        - If they match, display its meaning.
        - If the target word is smaller, move to the left subtree.
        - If the target word is larger, move to the right subtree.
        - If the node is NULL, print "word not found".
5. Display Operation
    - Traverse the tree in inorder:
        - Traverse the left subtree.
        - Display the current node's word and meaning.
        - Traverse the right subtree.
6. Stop
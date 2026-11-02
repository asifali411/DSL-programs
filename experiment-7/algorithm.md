# BINARY TREE FOR AN ARITHMETIC EXPRESSION

## AIM
    To implement a binary tree for a simple arithmetic expression and find its prefix and postfix equivalents.

## ALGORITHM

1. Start
2. Create an empty stack.
3. For each symbol in the postfix expression:
    - If the symbol is an operand:
        - Create a node and push it onto the stack.
    - Else if the symbol is an operator:
        - Pop two nodes from the stack.
        - Create a new node with the operator.
        - Set the first popped node as the right child and the second popped node as the left child.
        - Push the new node onto the stack.
4. Set the root to the top of the stack.
5. To find the prefix equivalent, traverse the tree in preorder:
    - Visit the root.
    - Traverse the left subtree.
    - Traverse the right subtree.
6. To find the postfix equivalent, traverse the tree in postorder:
    - Traverse the left subtree.
    - Traverse the right subtree.
    - Visit the root.
7. Stop
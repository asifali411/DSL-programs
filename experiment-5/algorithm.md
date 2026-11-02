# NAVIGATION SIMULATION USING DOUBLY LINKED LIST

## AIM
    To simulate browser navigation using a doubly linked list.

## ALGORITHM

1. Start
2. Initialize
    - Struct Node containing:
      - url - stores the webpages URL.
      - prev - points to the previous node.
      - next - points to the next node.
    - Initialize head = current = NULL.
3. Create Home page
    - Create a new node containing the home page URL.
    - Set head = current = newNode.
4. Visit Page
    - Read url from user
    - Create a new node.
    - Free all the nodes after the current node (forward history).
    - Set current->next = newNode.
    - Set newNode->prev = current.
    - Update current = newNode.
5. Go Forward
    - Check whether current->next == NULL.
    - If null display "No Forward page" and exit.
    - Else current = current->next.
    - Display current webpages URL.
6. Go Back
    - Check whether current->prev == NULL.
    - If null display "No previous page" and exit.
    - Else current = current->prev.
    - Display current webpages URL.
7. Stop
  
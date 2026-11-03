# SPELL CHECKER USING HASH TABLE

## AIM
    To implement a spell checker that stores a dictionary of words in a hash table for fast lookup and suggests corrections for misspelled words.

## ALGORITHM

1. Start.
2. Define a Node structure containing:
    - word -> the dictionary word.
    - next -> pointer to the next node in the same hash bucket.
3. Create a hash table of TABLE_SIZE buckets and initialize every bucket to NULL.
4. Hash Function:
    - Set hash = 0.
    - For every character in the word:
        - hash = (hash * 31 + lowercase(character)) % TABLE_SIZE.
    - Return hash as the bucket index.
5. Insert Word:
    - Compute the bucket index using the hash function.
    - Create a new node with the given word.
    - Insert the node at the beginning of that bucket's linked list.
6. Check Word:
    - Compute the bucket index using the hash function.
    - Traverse the linked list of that bucket.
    - If a node matches the word (ignoring case), the word is valid; display that it exists and stop.
    - If the end of the list is reached without a match, the word is invalid; display that it was not found and call Suggest Word.
7. Suggest Word:
    - For every bucket in the hash table:
        - For every node in the bucket:
            - Compute the edit distance between the misspelled word and the node's word.
            - If the distance is less than or equal to 2, display the node's word as a suggestion.
    - If no suggestion was found, display "No suggestions found".
8. Edit Distance (between two strings):
    - Let m and n be the lengths of the two strings.
    - Initialize a matrix grid where grid[i][0] = i and grid[0][j] = j.
    - For i = 1 to m and j = 1 to n:
        - cost = 0 if the characters match (ignoring case), otherwise 1.
        - grid[i][j] = minimum of:
            - grid[i - 1][j] + 1 (deletion).
            - grid[i][j - 1] + 1 (insertion).
            - grid[i - 1][j - 1] + cost (substitution).
    - Return grid[m][n] as the edit distance.
9. Display the menu and repeat steps 5 to 7 according to the user's choice until Exit is selected.
10. Stop.

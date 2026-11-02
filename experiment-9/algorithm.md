# LAND MINES INSIDE A MAZE

## AIM
    To find the shortest distance from any traversable cell to its nearest land mine inside a maze using BFS.

## ALGORITHM

1. Start
2. Create a distance matrix and initialize the matrix with INF (Infinity).
3. Create a queue for BFS.
4. For every cell that is a mine, set its distance to 0, mark it visited, and enqueue it.
5. While the queue is not empty:
    - Dequeue a cell (x, y)
    - For each of its 4 neighbours:
        - A neighbour is traversable if it is inside the maze and is not a wall.
        - If the neighbour is traversable and not visited:
            - Update its distance = distance of (x, y) + 1
            - Mark it visited
            - Enqueue the neighbour
6. Stop
# WATER POURING PROBLEM

## AIM
    To find a sequence of pours that leaves exactly 2 litres in the 7-litre container, using a 10-litre, a 7-litre and a 4-litre container, where the 7-litre and 4-litre containers start full and the 10-litre container starts empty.

## ALGORITHM

1. Start.
2. Define a state (a, b, c) where
    - a -> litres of water in the 10-litre container.
    - b -> litres of water in the 7-litre container.
    - c -> litres of water in the 4-litre container.
   The capacities are A = 10, B = 7, C = 4, so a valid state satisfies 0 <= a <= 10, 0 <= b <= 7 and 0 <= c <= 4.
3. Initialize the start state as (0, 7, 4), mark it visited, and enqueue it with no parent.
4. While the queue is not empty:
    - Dequeue the front state as the current state.
    - If b == 2, a solution is found:
        - Follow the parent pointers from the current state back to the start and print the states in order.
        - Stop.
    - Otherwise, generate the next states by pouring from one container into another.
5. For every ordered pair of different containers (X, Y):
    - The amount poured is the smaller of the water in X and the free space in Y: amount = min(X, capacity of Y - Y).
    - If amount > 0:
        - Form the new state by reducing X by amount and increasing Y by amount.
        - If the new state has not been visited:
            - Mark it visited.
            - Set its parent to the current state.
            - Enqueue it.
6. If the queue becomes empty without reaching a state with b == 2, display "No solution found".
7. Stop.

# MAXIMUM ACTIVITY POINTS

## AIM
    To find the maximum activity points that can be earned by participating in at most k events, given the activity points awarded by each event.

## ALGORITHM

1. Start.
2. Read the total number of events n.
3. If n < 0 or n > MAX, display "Invalid number of events" and stop.
4. Read the activity points A[0] to A[n - 1] for the n events.
5. Read the maximum number of events k that can be participated in.
6. If k < 0, set k = 0.
7. If k > n, set k = n, since participation is limited to the available events.
8. Sort the array A in descending order using Bubble Sort:
    - For i = 0 to n - 2:
        - For j = 0 to n - i - 2:
            - If A[j] < A[j + 1], swap A[j] and A[j + 1].
9. Set max_activity_points = 0.
10. For i = 0 to k - 1:
    - Display A[i] as a selected event.
    - Add A[i] to max_activity_points.
11. Display max_activity_points as the maximum total activity points.
12. Stop.

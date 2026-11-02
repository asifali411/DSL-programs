# QUEUE, CIRCULAR QUEUE AND DEQUE

## AIM
To implement Queue, Circular Queue and Deque (Double-Ended Queue) using arrays.

## ALGORITHM

### QUEUE

#### ENQUEUE
```
1. Start
2. If rear == MAX - 1:
  - Output "Queue overflow"
  - Exit
3. Else:
  - If front == -1:
    - front = 0
  - rear = rear + 1
  - queue[rear] = item
4. Stop
```

#### DEQUEUE
```
1. Start
2. If front > rear || front == -1:
  - Output "Queue underflow"
  - Exit
3. Else:
  - item = queue[front]
  - front = front + 1
  - Return item
4. Stop
```

#### PEEK
```
1. Start
2. If front > rear || front == -1:
  - Output "Queue is empty"
3. Else:
  - Return queue[front]
4. Stop
```

#### DISPLAY
```
1. Start
2. If front > rear || front == -1:
  - Output "Queue is empty"
  - Exit
3. Else:
  - For i = front to rear:
    - Output queue[i]
4. Stop
```

---

### CIRCULAR QUEUE

#### ENQUEUE
```
1. Start
2. If (rear + 1) % MAX == front:
  - Output "Queue overflow"
  - Exit
3. Else:
  - If front == -1:
    - front = 0
    - rear = 0
  - Else:
    - rear = (rear + 1) % MAX
  - queue[rear] = item
4. Stop
```

#### DEQUEUE
```
1. Start
2. If front == -1:
  - Output "Queue underflow"
  - Exit
3. Else:
  - item = queue[front]
  - If front == rear:
    - front = -1
    - rear = -1
  - Else:
    - front = (front + 1) % MAX
  - Return item
4. Stop
```

#### PEEK
```
1. Start
2. If front == -1:
  - Output "Queue is empty"
3. Else:
  - Return queue[front]
4. Stop
```

#### DISPLAY
```
1. Start
2. If front == -1:
  - Output "Queue is empty"
  - Exit
3. Else:
  - i = front
  - While i != rear:
    - Output queue[i]
    - i = (i + 1) % MAX
  - Output queue[rear]
4. Stop
```

---

### DEQUE (DOUBLE-ENDED QUEUE)

#### INSERT AT FRONT
```
1. Start
2. If (front == 0 && rear == MAX - 1) || front == rear + 1:
  - Output "Deque overflow"
  - Exit
3. Else:
  - If front == -1:
    - front = 0
    - rear = 0
  - Else if front == 0:
    - front = MAX - 1
  - Else:
    - front = front - 1
  - deque[front] = item
4. Stop
```

#### INSERT AT REAR
```
1. Start
2. If (front == 0 && rear == MAX - 1) || front == rear + 1:
  - Output "Deque overflow"
  - Exit
3. Else:
  - If front == -1:
    - front = 0
    - rear = 0
  - Else if rear == MAX - 1:
    - rear = 0
  - Else:
    - rear = rear + 1
  - deque[rear] = item
4. Stop
```

#### DELETE FROM FRONT
```
1. Start
2. If front == -1:
  - Output "Deque underflow"
  - Exit
3. Else:
  - item = deque[front]
  - If front == rear:
    - front = -1
    - rear = -1
  - Else if front == MAX - 1:
    - front = 0
  - Else:
    - front = front + 1
  - Return item
4. Stop
```

#### DELETE FROM REAR
```
1. Start
2. If front == -1:
  - Output "Deque underflow"
  - Exit
3. Else:
  - item = deque[rear]
  - If front == rear:
    - front = -1
    - rear = -1
  - Else if rear == 0:
    - rear = MAX - 1
  - Else:
    - rear = rear - 1
  - Return item
4. Stop
```

#### DISPLAY
```
1. Start
2. If front == -1:
  - Output "Deque is empty"
  - Exit
3. Else:
  - i = front
  - While i != rear:
    - Output deque[i]
    - i = (i + 1) % MAX
  - Output deque[rear]
4. Stop
```
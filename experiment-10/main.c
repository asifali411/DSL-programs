#include <stdio.h>
#include <stdlib.h>

#define MAX 500

#define VISITED 1
#define NOT_VISITED 0

#define MAX_A 10
#define MAX_B 7
#define MAX_C 4

typedef struct State {
  int a, b, c;
  struct State *parent;
} State;

int visited[MAX][MAX][MAX];

State *queue[MAX];
int front = -1, rear = -1;

// helper variable, to free memory
State *allocated[MAX];
int allocated_count = 0;

State *create_state(int a, int b, int c, State *parent) {
  State *state = (State *)malloc(sizeof(State));

  state->a = a;
  state->b = b;
  state->c = c;

  state->parent = parent;

  allocated[allocated_count++] = state;

  return state;
}

int is_empty() { return front == -1 || front > rear; }

void enqueue(State *state) {
  if (rear == MAX - 1)
    return;

  if (front == -1)
    front = 0;
  rear++;
  queue[rear] = state;
}

State *dequeue() {
  if (is_empty())
    return NULL;

  State *val = queue[front];
  front++;

  if (front > rear)
    front = rear = -1;

  return val;
}

void display_solution(State *state) {
  if (state == NULL)
    return;

  display_solution(state->parent);
  printf("(A = %2d, B = %2d, C = %2d)\n", state->a, state->b, state->c);
}

void add_state(State *state) {
  if (!visited[state->a][state->b][state->c]) {
    visited[state->a][state->b][state->c] = VISITED;
    enqueue(state);
  }
}

void pour(State *current) {
  int a = current->a;
  int b = current->b;
  int c = current->c;

  int na = 0;
  int nb = 0;
  int nc = 0;

  int pourAmt = 0;

  State *next;

  // A -> B
  pourAmt = (a + b > MAX_B) ? MAX_B - b : a;

  if (pourAmt > 0) {
    na = a - pourAmt;
    nb = b + pourAmt;
    nc = c;

    next = create_state(na, nb, nc, current);
    add_state(next);
  }

  // A -> C
  pourAmt = (a + c > MAX_C) ? MAX_C - c : a;

  if (pourAmt > 0) {
    na = a - pourAmt;
    nb = b;
    nc = c + pourAmt;

    next = create_state(na, nb, nc, current);
    add_state(next);
  }

  // B -> A
  pourAmt = (b + a > MAX_A) ? MAX_A - a : b;

  if (pourAmt > 0) {
    na = a + pourAmt;
    nb = b - pourAmt;
    nc = c;

    next = create_state(na, nb, nc, current);
    add_state(next);
  }

  // B -> C
  pourAmt = (b + c > MAX_C) ? MAX_C - c : b;

  if (pourAmt > 0) {
    na = a;
    nb = b - pourAmt;
    nc = c + pourAmt;

    next = create_state(na, nb, nc, current);
    add_state(next);
  }

  // C -> A
  pourAmt = (c + a > MAX_A) ? MAX_A - a : c;

  if (pourAmt > 0) {
    na = a + pourAmt;
    nb = b;
    nc = c - pourAmt;

    next = create_state(na, nb, nc, current);
    add_state(next);
  }

  // C -> B
  pourAmt = (c + b > MAX_B) ? MAX_B - b : c;

  if (pourAmt > 0) {
    na = a;
    nb = b + pourAmt;
    nc = c - pourAmt;

    next = create_state(na, nb, nc, current);
    add_state(next);
  }
}

int main() {

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      for (int k = 0; k < MAX; k++) {
        visited[i][j][k] = NOT_VISITED;
      }
    }
  }

  State *initial_state = create_state(0, 7, 4, NULL);
  enqueue(initial_state);
  visited[0][7][4] = VISITED;

  while (!is_empty()) {
    State *current = dequeue();

    if (current->b == 2 || current->c == 2) {
      printf("Solution: \n");
      display_solution(current);

      for (int i = 0; i < allocated_count; i++) {
        free(allocated[i]);
      }
      return 0;
    }

    pour(current);
  }

  printf("No solution found!\n");
  for (int i = 0; i < allocated_count; i++) {
    free(allocated[i]);
  }
  return 0;
}

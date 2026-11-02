#include <stdio.h>

#define MAX 100
#define INF 9999

#define VISITED 1
#define NOT_VISITED 0

typedef struct {
  int x;
  int y;
} Cell;

int maze[MAX][MAX];
int dist[MAX][MAX];
int visited[MAX][MAX];

int rows = 0, cols = 0;

Cell queue[MAX * MAX];
int front = -1, rear = -1;

int neighbour_idx[2][4] = {
    {0, 0, 1, -1},
    {1, -1, 0, 0},
};

int is_empty() { return front == -1 || front > rear; }

void enqueue(int x, int y) {
  if (rear == (MAX * MAX) - 1)
    return;

  if (front == -1)
    front = 0;
  rear++;
  queue[rear] = (Cell){
      .x = x,
      .y = y,
  };
}

Cell dequeue() {
  if (is_empty())
    return (Cell){.x = -1, .y = -1};

  Cell val = queue[front];
  front++;

  if (front > rear)
    front = rear = -1;

  return val;
}

void display_maze() {

  printf("\nMAZE: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (maze[i][j] > 0)
        printf("   #");
      else
        printf("%4d", maze[i][j]);
    }
    printf("\n");
  }
}

void display_dist() {
  printf("DIST: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (maze[i][j] > 0)
        printf("   #");
      else if (dist[i][j] == INF)
        printf(" INF");
      else
        printf("%4d", dist[i][j]);
    }
    printf("\n");
  }
}

int is_valid_cell(int i, int j) {
  if (i < 0 || j < 0)
    return 0;
  if (i >= rows || j >= cols)
    return 0;
  return 1;
}

void bfs() {
  while (!is_empty()) {
    Cell current = dequeue();

    for (int i = 0; i < 4; i++) {
      int newX = current.x + neighbour_idx[0][i];
      int newY = current.y + neighbour_idx[1][i];

      if (is_valid_cell(newX, newY) && !visited[newX][newY] &&
          maze[newX][newY] <= 0) {
        enqueue(newX, newY);

        visited[newX][newY] = VISITED;
        dist[newX][newY] = dist[current.x][current.y] + 1;
      }
    }
  }
}

int main() {

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      visited[i][j] = NOT_VISITED;
    }
  }

  printf("Enter the number of rows and columns in maze: ");
  scanf("%d %d", &rows, &cols);

  printf("Enter the maze (0 = path, >0 = obstacle, -1 = mine)\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &maze[i][j]);

      if (maze[i][j] == -1) {
        dist[i][j] = 0;
        enqueue(i, j);
        visited[i][j] = VISITED;
      } else {
        dist[i][j] = INF;
      }
    }
  }

  bfs();

  display_maze();
  display_dist();

  return 0;
}

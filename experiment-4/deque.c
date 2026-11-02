#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int is_empty() {
  return front == -1;
}

int is_full() {
  return (rear + 1) % MAX == front;
}

void enqueue_front(int elem) {
  if (is_full()) {
    printf("Queue overflow\n");
    return;
  }

  if (front == -1) front = rear = 0;
  else front = (front - 1 + MAX) % MAX; // add MAX to prevent negative values

  queue[front] = elem;
}

void enqueue_rear(int elem) {
  if (is_full()) {
    printf("Queue overflow\n");
    return;
  }

  if (front == -1) front = 0;

  rear = (rear + 1) % MAX;
  queue[rear] = elem;
}

void dequeue_front() {
  if (is_empty()) {
    printf("Queue underflow\n");
    return;
  }

  int val = queue[front];

  if (front == rear) front = rear = -1;
  else front = (front + 1) % MAX;

  printf("%d\n", val);
}

void dequeue_rear() {
  if (is_empty()) {
    printf("Queue underflow\n");
    return;
  }

  int val = queue[rear];

  if (front == rear) front = rear = -1;
  else rear = (rear - 1 + MAX) % MAX; // add MAX to prevent negative values

  printf("%d\n", val);
}

void display() {
  if (is_empty()) {
    printf("Queue is empty\n");
    return;
  }
  int i = front;
  while(i != rear) {
    printf("%d ", queue[i]);
    i = (i + 1) % MAX;
  }
  printf("%d\n", queue[rear]);
}

int main() {

  printf("1. Enqueue front\n");
  printf("2. Enqueue rear\n");
  printf("3. Dequeue front\n");
  printf("4. Dequeue rear\n");
  printf("5. Display\n");
  printf("6. Exit\n");

  int is_running = 1;
  int choice, element;

  do {

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the number to enqueue: ");
        scanf("%d", &element);

        enqueue_front(element);
        break;

      case 2:
        printf("Enter the number to enqueue: ");
        scanf("%d", &element);

        enqueue_rear(element);
        break;

      case 3:
        dequeue_front();
        break;

      case 4:
        dequeue_rear();
        break;

      case 5:
        display();
        break;

      case 6:
        is_running = 0;
        break;
  
      default:
        printf("Invalid choice\n");
    }

  } while(is_running);

  return 0;
}
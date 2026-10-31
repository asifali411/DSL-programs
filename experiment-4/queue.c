#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int is_empty() {
  return front > rear || front == -1;
}

int is_full() {
  return rear == MAX - 1;
}

void enqueue(int elem) {
  if (is_full()) {
    printf("Queue overflow\n");
    return;
  }

  if (front == -1) front = 0;

  rear++;
  queue[rear] = elem;
}

void dequeue() {
  if (is_empty()) {
    printf("Queue underflow\n");
    return;
  }

  int val = queue[front];
  front++;

  if (front > rear) {
    front = -1;
    rear = -1;
  }

  printf("%d\n", val);
}

void peek() {
  if (is_empty()) {
    printf("Queue is empty\n");
    return;
  }
  
  printf("%d\n", queue[front]);
}

void display() {
  if (is_empty()) {
    printf("Queue is empty\n");
    return;
  }
  
  for(int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  
  printf("\n");
}

int main() {
  
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. Peek\n");
  printf("4. Diplay\n");
  printf("5. Exit\n");

  int is_running = 1;
  int choice;
  int element;

  do {

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {  
      case 1:
        printf("Enter the number to enqueue: ");
        scanf("%d", &element);
        enqueue(element);
        break;

      case 2:
        dequeue();
        break;
      
      case 3:
        peek();
        break;
      
      case 4:
        display();
        break;
  
      case 5:
        is_running = 0;
        break;
      
      default:
        printf("Invalid choice\n");
    }
  } while(is_running);
  
  return 0;
}
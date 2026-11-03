#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  char name[100];
  int priority;
} Customer;

Customer *heap[MAX];
int size = 0;

void swap(int i, int j) {
  Customer *temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

Customer *create_customer(char name[], int priority) {
  Customer *customer = (Customer *)malloc(sizeof(Customer));

  strcpy(customer->name, name);
  customer->priority = priority;

  return customer;
}

void add_customer(char name[], int priority) {
  if (size == MAX) {
    printf("Customer list is full\n");
    return;
  }

  Customer *customer = create_customer(name, priority);

  heap[size] = customer;
  size++;

  int current_idx = size - 1;
  int parent_idx;
  
  while(current_idx > 0) {
    parent_idx = (current_idx - 1) / 2;

    if (heap[parent_idx]->priority < heap[current_idx]->priority) {
      swap(current_idx, parent_idx);
    } else break;

    current_idx = parent_idx;
  }
}

void serve_customer() {
  if (size == 0) {
    printf("No customer left to serve\n");
    return;
  }
  
  Customer *temp;
  temp = heap[0];

  heap[0] = heap[size - 1];
  heap[size - 1] = temp;

  Customer *customer = heap[--size];
  printf("name: %s, priority: %d\n", customer->name, customer->priority);
  free(customer);

  int current_idx = 0;
  int left, right, largest;

  while(1) {
    left = current_idx * 2 + 1;
    right = current_idx * 2 + 2;

    largest = current_idx;

    if (left < size && heap[left]->priority > heap[largest]->priority) {
      largest = left;
    }

    if (right < size && heap[right]->priority > heap[largest]->priority) {
      largest = right;
    }

    if (largest == current_idx) {
      break;
    }

    swap(current_idx, largest);
    current_idx = largest;
  }
}

void display_customers() {
  for(int i = 0; i < size; i++) {
    printf("name: %s, priority: %d\n", heap[i]->name, heap[i]->priority);
  }
  printf("\n");
}

int main() {

  printf("1. Add Customer\n");
  printf("2. Serve Customer\n");
  printf("3. Display all customers\n");
  printf("4. Exit");

  int choice, priority, is_running = 1;
  char name[100];

  do {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the name of the customer: ");
        scanf(" %[^\n]", name);
        printf("Enter their priority: ");
        scanf("%d", &priority);
        
        add_customer(name, priority);
        break;  
    
      case 2:
        serve_customer();
        break;
    
      case 3:
        display_customers();
        break;
   
      case 4:
        is_running = 0;
        break;
      
      default:
        printf("Invalid choice\n");
    }
  } while(is_running);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *lists[MAX];
Node *heap[MAX];
int heap_size = 0;

void swap(int i, int j) {
  Node *temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

void append(Node **head, Node **tail, int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  if (*head == NULL) *head = node;
  else (*tail)->next = node;
  *tail = node;
}

void heapify_up(int idx) {
  while (idx > 0) {
    int parent = (idx - 1) / 2;
    if (heap[idx]->data >= heap[parent]->data) break;
    swap(idx, parent);
    idx = parent;
  }
}

void heapify_down(int idx) {
  while (1) {
    int left = 2 * idx + 1, right = left + 1, smallest = idx;

    if (left < heap_size && heap[left]->data < heap[smallest]->data) smallest = left;
    if (right < heap_size && heap[right]->data < heap[smallest]->data) smallest = right;
    if (smallest == idx) break;

    swap(idx, smallest);
    idx = smallest;
  }
}

void construct_min_heap(int no_of_lists) {
  for (int i = 0; i < no_of_lists; i++) {
    if (lists[i] == NULL) continue;
    heap[heap_size] = lists[i];
    heapify_up(heap_size++);
  }
}

Node *merge(void) {
  Node *result = NULL, *tail = NULL;

  while (heap_size > 0) {
    Node *top = heap[0];
    append(&result, &tail, top->data);

    heap[0] = top->next;
    if (heap[0] == NULL) heap[0] = heap[--heap_size];
    heapify_down(0);
  }
  return result;
}

void display_list(Node *head) {
  for (; head != NULL; head = head->next) printf("%d ", head->data);
  printf("\n");
}

void free_list(Node *head) {
  while (head != NULL) {
    Node *temp = head;
    head = head->next;
    free(temp);
  }
}

int main(void) {
  int no_of_lists;

  printf("Enter the number of lists: ");
  scanf("%d", &no_of_lists);

  for (int i = 0; i < no_of_lists; i++) {
    int no_of_elements, num;
    Node *tail = NULL;

    printf("Enter the number of elements in list %d: ", i + 1);
    scanf("%d", &no_of_elements);

    printf("Enter the elements: ");
    for (int j = 0; j < no_of_elements; j++) {
      scanf("%d", &num);
      append(&lists[i], &tail, num);
    }
  }

  construct_min_heap(no_of_lists);
  Node *result = merge();

  for (int i = 0; i < no_of_lists; i++) {
    display_list(lists[i]);
    free_list(lists[i]);
  }

  printf("Result: ");
  display_list(result);
  free_list(result);

  return 0;
}
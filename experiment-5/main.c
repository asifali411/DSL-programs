#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
  char url[MAX];
  struct Node *prev;
  struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

Node *createNode(char url[]) {
  Node *node = (Node *)malloc(sizeof(Node));

  strcpy(node->url, url);
  node->next = NULL;
  node->prev = NULL;

  return node;
}

void free_nodes(Node *start) {
  Node *temp, *current = start;

  while(current != NULL) {
    temp = current;
    current = current->next;

    free(temp);
  }
}

void visit_page(char url[]) {
  Node *node = createNode(url);

  free_nodes(current->next);
  current->next = node;
  node->prev = current;

  current = node;

  printf("visited: %s", url);
}

void go_back() {
  if (current->prev == NULL) {
    printf("No previous page\n");
    return;
  }

  current = current->prev;
  printf("url: %s\n", current->url);
}

void go_forward() {
  if (current->next == NULL) {
    printf("No forward page\n");
    return;
  }

  current = current->next;
  printf("url: %s\n", current->url);
}

int main() {

  char home_url[MAX] = "app://home.com";
  current = head = createNode(home_url);

  printf("1. visit page\n");
  printf("2. go forward\n");
  printf("3. go back\n");
  printf("4. current page\n");
  printf("5. exit");

  int is_running = 1;
  int choice;
  char url[MAX];

  do {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the url of the webpage: ");
        scanf("%99s", url);
        visit_page(url);
        break;
      
      case 2:
        go_forward();
        break;
      
      case 3:
        go_back();
        break;

      case 4:
        printf("url: %s", current->url);
        break;

      case 5:
        is_running = 0;
        break;

      default:
        printf("Invalid choice\n");
    }
  } while(is_running);

  free_nodes(head);
  return 0;
}
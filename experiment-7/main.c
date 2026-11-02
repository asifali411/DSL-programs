#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct Node {
  char data;
  struct Node *left, *right;
} Node;

char expr[MAX];
Node *stack[MAX];
int top = -1;

void push(Node *n) {
  if (top == MAX -1) return;

  top++;
  stack[top] = n;
}

Node *pop() {
  if (top == -1) return NULL;
  return stack[top--];
}

Node *create_node(char c) {
  Node *node = (Node *)malloc(sizeof(Node));

  node->data = c;
  node->left = NULL;
  node->right = NULL;

  return node;
}

int is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

void infix(Node *root) {
  if (root == NULL) return;

  infix(root->left);
  printf("%c", root->data);
  infix(root->right);
}

void postfix(Node *root) {
  if (root == NULL) return;

  postfix(root->left);
  postfix(root->right);
  printf("%c", root->data);
}

void prefix(Node *root) {
  if (root == NULL) return;

  printf("%c", root->data);
  prefix(root->left);
  prefix(root->right);
}

void free_tree(Node *root) {
  if (root == NULL) return;

  free_tree(root->left);
  free_tree(root->right);

  free(root);
}

int main() {

  printf("Enter the postfix expression: ");
  scanf("%99s", expr);

  for(int i = 0; expr[i] != '\0'; i++) {
    char c = expr[i];

    if (isalnum(c)) {
      Node *newNode = create_node(c);
      push(newNode);
    }

    else if (is_operator(c)) {
      Node *opNode = create_node(c);

      Node *right = pop();
      Node *left = pop();

      opNode->left = left;
      opNode->right = right;

      push(opNode);
    }
  }

  printf("\nInfix: ");
  infix(stack[0]);

  printf("\nPrefix: ");
  prefix(stack[0]);

  printf("\nPostfix: ");
  postfix(stack[0]);

  free_tree(stack[0]);
  return 0;
}
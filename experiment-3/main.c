#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
  if (top == MAX - 1) return;
  stack[++top] = ch;
}

char peek() {
  if (top == -1) return '\0';
  return stack[top];
}

char pop() {
  if (top == -1) return '\0';
  return stack[top--];
}

int is_operator(char ch) {
  return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
}

int precedence(char ch) {
  switch (ch) {
    case '*': case '/': return 2;
    case '+': case '-': return 1;
    default: return 0;
  }
}

void to_postfix(char infix[], char postfix[]) {
  int k = 0;
  top = -1; // reset stack

  for(int i = 0; infix[i] != '\0'; i++) {
    char ch = infix[i];

    if (isspace(ch)) continue;

    if (isalnum(ch)) {
      postfix[k] = ch;
      k++;
    } else if (ch == '(') {
      push(ch);
    } else if (ch == ')') {
      while (top >= 0 && peek() != '(') {
        postfix[k] = pop();
        k++;
      }

      if (top < 0) {
        printf("Unbalanced parentheses\n");
        exit(1);
      }

      pop();
    } else if (is_operator(ch)) {
      while(top >= 0 && peek() != '(') {
        int top_prec = precedence(peek());
        int op_prec = precedence(ch);

        if (top_prec > op_prec) {
          postfix[k] = pop();
          k++;
        } else break;
      }

      push(ch);
    } else {
      printf("Invalid character '%c'\n", ch);
      exit(1);
    }
  }

  while(top >= 0) {
    char ch = pop();

    if (ch == '(') {
      printf("Unbalanced parentheses\n");
      exit(1);
    }

    postfix[k] = ch;
    k++;
  }

  postfix[k] = '\0';
}

void reverse(char str[]) {
  int len = strlen(str);

  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}

void to_prefix(char infix[], char prefix[]) {
  
  char rev[MAX];
  strcpy(rev, infix);
  reverse(rev);

  for(int i = 0; rev[i] != '\0'; i++) {
    if (rev[i] == '(') {
      rev[i] = ')';
    } else if (rev[i] == ')') {
      rev[i] = '(';
    }
  }

  to_postfix(rev, prefix);
  reverse(prefix);
}

int main() {

  char infix[MAX], postfix[MAX], prefix[MAX];

  printf("Enter the infix expression: ");
  scanf("%[^\n]", infix);

  to_postfix(infix, postfix);
  to_prefix(infix, prefix);

  printf("Infix: %s\n", infix);
  printf("Postfix: %s\n", postfix);
  printf("Prefix: %s\n", prefix);

  return 0;
}
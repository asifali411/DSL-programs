#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50
#define TABLE_SIZE 100

typedef struct Node {
  char word[MAX];
  struct Node *next;
} Node;

Node *table[TABLE_SIZE];

int hash_function(char *word) {
  int hash = 0;

  while(*word) {
    hash = (hash * 31 + tolower(*word)) % TABLE_SIZE;
    word++;
  }

  return hash;
}

void insert_word(char *word) {
  int index = hash_function(word);

  Node *node = (Node *)malloc(sizeof(Node));

  strcpy(node->word, word);
  node->next = table[index];
  table[index] = node;
}


int minimum(int a, int b, int c) {
  int min = a;
  if (b < min) min = b;
  if (c < min) min = c;
  return min;
}

int distance(char *s1, char *s2) {
  int m = strlen(s1);
  int n = strlen(s2);

  int grid[MAX][MAX];

  for (int i = 0; i <= m; i++) grid[i][0] = i;
  for (int j = 0; j <= n; j++) grid[0][j] = j;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {

    int cost = (tolower(s1[i - 1]) == tolower(s2[j - 1])) ? 0 : 1;

      grid[i][j] = minimum(
        grid[i - 1][j] + 1,       // Deletion
        grid[i][j - 1] + 1,       // Insertion
        grid[i - 1][j - 1] + cost // Substitution
      );
    }
  }

  return grid[m][n];
}

void suggest_word(char *word) {
  int found = 0;
  for(int i = 0; i < TABLE_SIZE; i++) {
    Node *current = table[i];

    while(current != NULL) {
      int dist = distance(word, current->word);
      if (dist <= 2) {
        printf("Suggested word: %s\n", current->word);
        found = 1;
      }

      current = current->next;
    }
  }

  if (!found) {
    printf("No suggestions found\n");
  }
}

int same_word(char *a, char *b) {
  while(*a && *b) {
    if (tolower(*a) != tolower(*b)) return 0;
    a++;
    b++;
  }

  return *a == *b;
}

void search_word(char *word) {
  int index = hash_function(word);

  Node *current = table[index];
  while(current != NULL) {
    if (same_word(current->word, word)) {
      printf("Word '%s' exists.\n", word);
      return;
    }
  
    current = current->next;
  }

  printf("The word '%s' was not found.\n", word);
  suggest_word(word);
}

int main() {

  for(int i = 0; i < TABLE_SIZE; i++) {
    table[i] = NULL;
  }

  printf("1. Insert word\n");
  printf("2. Search word\n");
  printf("3. Exit\n");

  int choice, is_running = 1;
  char word[MAX];

  do {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the word: ");
        scanf("%49s", word);
        insert_word(word);
        break;

      case 2:
        printf("Enter the word to search: ");
        scanf("%49s", word);
        search_word(word);
        break;

      case 3:
        is_running = 0;
        break;
      
      default:
        printf("Invalid choice\n");
    }
  } while(is_running);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
  char word[MAX];
  struct Node *next;
} Node;

Node *head = NULL;

Node *create_node(char word[MAX]) {
  Node *node = (Node *)malloc(sizeof(Node));

  strcpy(node->word, word);
  node->next = NULL;

  return node;
}

void add_word(char word[MAX]) {
  Node *node = create_node(word);

  if (head == NULL) {
    head = node;
    return;
  }

  Node *current = head;
  while(current->next != NULL) {
    current = current->next;
  }

  current->next = node;
}

void display_sentence() {
  Node *current = head;
  while(current != NULL) {
    printf("%s ", current->word);
    current = current->next;
  }
  printf("\n");
}

void free_sentence() {
  Node *temp;

  while(head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

void replace(char word[MAX], char replacement[MAX]) {
  Node *current = head;
  while(current != NULL) {

    if(strcmp(current->word, word) == 0) {
      strcpy(current->word, replacement);
      return;
    }

    current = current->next;
  }

  printf("The word '%s' was not found in the sentence.\n", word);
}

int main() {

  char sentence[1000];
  char target_word[MAX], replacement_word[MAX];

  printf("Enter the sentence: ");
  scanf("%[^\n]", sentence);

  char *word = strtok(sentence, " ");
  while(word != NULL) {
    add_word(word);
    word = strtok(NULL, " ");
  }

  printf("Enter the word you want to replace: ");
  scanf("%s", target_word);

  printf("Enter the new word: ");
  scanf("%s", replacement_word);

  printf("Original sentence: ");
  display_sentence();

  replace(target_word, replacement_word);

  printf("Updated sentence: ");
  display_sentence();

  free_sentence();
  return 0;
}
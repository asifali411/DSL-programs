#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX 50
#define MEANING_MAX 200

typedef struct Node {
  char word[WORD_MAX];
  char meaning[MEANING_MAX];

  struct Node *left;
  struct Node *right;
} Node;

Node *tree_root = NULL;

Node *create_node(char word[], char meaning[]) {
  Node *node = (Node *)malloc(sizeof(Node));

  strcpy(node->word, word);
  strcpy(node->meaning, meaning);

  node->left = node->right = NULL;

  return node;
}

Node *insert_word(Node *root, char word[], char meaning[]) {
  if (root == NULL) {
    return create_node(word, meaning);
  }

  int cmp = strcmp(word, root->word);

  if (cmp < 0) {
    root->left = insert_word(root->left, word, meaning);
  } else if (cmp > 0) {
    root->right = insert_word(root->right, word, meaning);
  } else {
    printf("'%s' already exists in dictionary.\n", word);
  }

  return root;
}

void search_word(Node *root, char word[]) {
  if (root == NULL) {
    printf("word '%s' not found.\n", word);
    return;
  }

  int cmp = strcmp(word, root->word);
  
  if (cmp < 0) {
    search_word(root->left, word);
  } else if (cmp > 0) {
    search_word(root->right, word);
  } else {
    printf("%s\n", root->meaning);
  }
}

void display_words(Node *root) {
  if (root == NULL) return;

  display_words(root->left);
  printf("%s: %s\n", root->word, root->meaning);
  display_words(root->right);
}

void free_tree(Node *root) {
  if (root == NULL) return;

  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main() {

  printf("1. Insert word\n");
  printf("2. Search word\n");
  printf("3. Display all words\n");
  printf("4. Exit\n");

  int choice, is_running = 1;
  char word[WORD_MAX], meaning[MEANING_MAX];

  do {

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the word: ");
        scanf(" %[^\n]", word);
        
        printf("Enter the meaning: ");
        scanf(" %[^\n]", meaning);

        tree_root = insert_word(tree_root, word, meaning);
        break;
    
      case 2:
        printf("Enter the word: ");
        scanf("%s", word);

        search_word(tree_root, word);
        break;
      
      case 3:
        display_words(tree_root);
        break;
      
      case 4:
        is_running = 0;
        break;

      default:
        printf("Invalid choice\n");
    }

  } while(is_running);

  free_tree(tree_root);
  return 0;
}
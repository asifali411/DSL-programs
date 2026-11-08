#include <stdio.h>
#include <stdlib.h>

#define FREE 1
#define USED 0

#define START_ADDRESS 1000

typedef struct Block {
  int start_address;
  int size;
  int is_free;
  struct Block *prev;
  struct Block *next;
} Block;

Block *head = NULL;

Block *create_block(int start_address, int size, int is_free) {
  Block *block = malloc(sizeof(Block));

  block->start_address = start_address;
  block->size = size;
  block->is_free = is_free;
  block->next = NULL;
  block->prev = NULL;

  return block;
}

void free_memory_blocks() {
  Block *temp;
  while(head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int add_block(int start_address, int size, int is_free) {
  Block *block = create_block(start_address, size, is_free);
  int next_address = start_address + size;

  if (head == NULL) {
    head = block;
    return next_address;
  }

  Block *current = head;
  while(current->next != NULL) {
    current = current->next;
  }

  current->next = block;
  block->prev = current;

  return next_address;
}

void display_memory_blocks() {
  Block *current = head;

  while(current != NULL) {
    printf("(START: %4d, SIZE: %4d, %s)\n", 
      current->start_address,
      current->size,
      current->is_free ? "FREE" : "USED"
    );

    current = current->next;
  }
}

void delete_block(Block *block) {
  if (block == NULL)
    return;

  Block *next_block = block->next;
  Block *prev_block = block->prev;

  if (prev_block != NULL) {
    prev_block->next = next_block;
  } else {
    head = next_block;
  }

  if (next_block != NULL) {
    next_block->prev = prev_block;
  }

  free(block);
}

void garbage_collect() {
  if (head == NULL) return;

  Block *current = head;

  while(current != NULL && current->next != NULL) {

    if (current->is_free && current->next->is_free) {

      Block *next_block = current->next;

      current->size += next_block->size;

      delete_block(next_block);
    } else {
      current = current->next;
    }
  }
}

void compact() {
  if (head == NULL) return;

  Block *new_head = NULL;
  Block *tail = NULL; // tail points to last element of new list

  int current_start_address = START_ADDRESS;
  int total_free_space = 0;

  Block *current = head;
  while(current != NULL) {
    if (current->is_free) {
      total_free_space += current->size;
    } else {
      Block *new_block = create_block(current_start_address, current->size, USED);
      current_start_address += current->size;

      if (new_head == NULL) {
        new_head = new_block;
        tail = new_block;
      } else {
        tail->next = new_block;
        new_block->prev = tail;
        tail = new_block;
      }
    }
    current = current->next;
  }

  if (total_free_space > 0) {
    Block *free_block = create_block(current_start_address, total_free_space, FREE);

    if (new_head == NULL) {
      new_head = free_block;
    } else {
      tail->next = free_block;
      free_block->prev = tail;
    }
  }

  free_memory_blocks();

  head = new_head;
}

int main() {

  int next_address;

  next_address = add_block(START_ADDRESS, 100, FREE);
  next_address = add_block(next_address, 200, USED);
  next_address = add_block(next_address, 300, FREE);
  next_address = add_block(next_address, 100, USED);
  next_address = add_block(next_address, 300, FREE);
  next_address = add_block(next_address, 100, FREE);

  printf("Before garbage collection and compaction:\n");
  display_memory_blocks();
  
  garbage_collect();

  printf("\nAfter garbage collection:\n");
  display_memory_blocks();

  compact();

  printf("\nAfter compacting:\n");
  display_memory_blocks();

  free_memory_blocks();

  return 0;
}

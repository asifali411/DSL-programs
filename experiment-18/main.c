#include <stdio.h>

#define MAX 10

int heaps[MAX][MAX];
int sizes[MAX];
int number_of_lists = 0;

void swap(int list_idx, int i, int j) {
  int temp = heaps[list_idx][i];
  heaps[list_idx][i] = heaps[list_idx][j];
  heaps[list_idx][j] = temp;
}

void add_to_heap(int list_idx, int elem) {
  int size = sizes[list_idx];
  heaps[list_idx][size] = elem;

  int current_idx = size;
  int parent_idx;

  while (current_idx > 0) {
    parent_idx = (current_idx - 1) / 2;

    if (heaps[list_idx][parent_idx] > heaps[list_idx][current_idx]) {
      swap(list_idx, current_idx, parent_idx);
    } else
      break;

    current_idx = parent_idx;
  }

  sizes[list_idx]++;
}

int remove_min(int list_idx) {
  int min = heaps[list_idx][0];

  sizes[list_idx]--;

  heaps[list_idx][0] = heaps[list_idx][sizes[list_idx]];

  int current_idx = 0;

  while (1) {
    int left = 2 * current_idx + 1;
    int right = 2 * current_idx + 2;
    int smallest = current_idx;

    if (left < sizes[list_idx] &&
        heaps[list_idx][left] < heaps[list_idx][smallest]) {
      smallest = left;
    }

    if (right < sizes[list_idx] &&
        heaps[list_idx][right] < heaps[list_idx][smallest]) {
      smallest = right;
    }

    if (smallest == current_idx)
      break;

    swap(list_idx, current_idx, smallest);
    current_idx = smallest;
  }

  return min;
}

void merge(int merged[]) {
  int k = 0;

  while (1) {
    int min = 999999;
    int min_idx = -1;

    for (int i = 0; i < number_of_lists; i++) {
      if (sizes[i] > 0 && heaps[i][0] < min) {
        min = heaps[i][0];
        min_idx = i;
      }
    }

    if (min_idx == -1)
      break;

    merged[k++] = remove_min(min_idx);
  }

  printf("\nMerged list: ");
  for (int i = 0; i < k; i++) {
    printf("%d ", merged[i]);
  }
  printf("\n");
}

int main() {
  int elem, size;

  int merged[MAX];

  for (int i = 0; i < MAX; i++) {
    sizes[i] = 0;
  }

  printf("Enter the number of lists: ");
  scanf("%d", &number_of_lists);

  for (int i = 0; i < number_of_lists; i++) {
    printf("Enter the number of elements in list %d: ", i + 1);
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (int j = 0; j < size; j++) {
      scanf("%d", &elem);
      add_to_heap(i, elem);
    }
  }

  merge(merged);
}

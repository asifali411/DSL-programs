#include <stdio.h>

#define MAX 100

int number_of_steps = 0;

int max_elem(int arr[], int size) {
  int max = arr[0];

  for(int i = 0; i < size; i++) {
    if (arr[i] > max) max = arr[i];
  }

  return max;
}

void sort(int arr[], int size) {
  if (size <= 1) return;

  int max = max_elem(arr, size);

  for(int exp = 1; max / exp > 0; exp *= 10) {
    int count[10] = {0};
    int bucket[10][MAX];
    
    for(int i = 0; i < size; i++) {
      int idx = (arr[i] / exp) % 10;

      bucket[idx][count[idx]] = arr[i];
      count[idx]++;
      
      number_of_steps++;
    }

    int k = 0;
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < count[i]; j++) {
        arr[k++] = bucket[i][j];
      }
    }
  }
}

int main() {

  int size, arr[MAX];

  printf("Enter the number of elements: ");
  scanf("%d", &size);

  printf("Enter the numbers: ");
  for(int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\n");
  printf("Unsorted array: ");
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  sort(arr, size);

  printf("Sorted array: ");
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("\nNumber of steps: %d\n", number_of_steps);

  return 0;
}
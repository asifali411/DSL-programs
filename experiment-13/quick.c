#include <stdio.h>

#define MAX 100

int number_of_steps = 0;

int pivot_idx(int arr[], int low, int high) {
  int pivot = arr[low];
  int i = low + 1;
  int j = high;

  int temp;

  while(1) {
    while(i <= high) {
      number_of_steps++;

      if (arr[i] > pivot) break;

      i++;
    }

    while(j > low) {
      number_of_steps++;

      if (arr[j] <= pivot) break;

      j--;
    }

    if (i < j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    } else break;
  }

  temp = arr[low];
  arr[low] = arr[j];
  arr[j] = temp;

  return j;
}

void sort(int arr[], int low, int high) {
  if (low >= high) return;

  int index = pivot_idx(arr, low, high);

  sort(arr, low, index - 1);
  sort(arr, index + 1, high);
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

  sort(arr, 0, size - 1);

  printf("Sorted array: ");
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("\nNumber of steps: %d\n", number_of_steps);

  return 0;
}
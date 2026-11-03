#include <stdio.h>

#define MAX 100

int number_of_steps = 0;

void sort(int arr[], int size) {
  int temp;

  if (size <= 1) return;

  for(int i = 1; i < size; i++) {
    int j = i - 1;
    temp = arr[i];

    while(j >= 0) {
      number_of_steps++;

      if (arr[j] <= temp) break;

      arr[j+1] = arr[j];
      j--;
    }

    arr[j+1] = temp;
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
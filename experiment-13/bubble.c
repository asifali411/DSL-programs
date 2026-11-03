#include <stdio.h>

#define MAX 100

int number_of_steps = 0;

void sort(int arr[], int size) {
  
  int temp;
  for(int i = 0; i < size - 1; i++) {
    for(int j = 0; j < size - i - 1; j++) {
      if (arr[j+1] < arr[j]) {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
      
      number_of_steps++;
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
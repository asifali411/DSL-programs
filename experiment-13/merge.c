#include <stdio.h>

#define MAX 100

int number_of_steps = 0;

void merge(int arr[], int low, int mid, int high) {

  int i = low;
  int j = mid + 1;
  int k = low;

  int temp[MAX];

  while(i <= mid && j <= high) {
    number_of_steps++;

    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }

    k++;
  }

  while(i <= mid) {
    temp[k] = arr[i];
    k++; i++;
  }

  while(j <= high) {
    temp[k] = arr[j];
    k++; j++;
  }

  for (i = low; i <= high; i++) {
    arr[i] = temp[i];
  }
}

void sort(int arr[], int low, int high) {

  if (low >= high) return; 

  int mid = (high + low) / 2;

  sort(arr, low, mid);
  sort(arr, mid + 1, high);

  merge(arr, low, mid, high);
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
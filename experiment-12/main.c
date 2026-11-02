#include <stdio.h>

#define MAX 100

int binary_search_iterative(int arr[], int size, int key) {
  int low = 0;
  int high = size - 1;
  int mid;

  while(low <= high) {
    mid = (high + low) / 2;

    if (arr[mid] > key) {
      high = mid - 1;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int binary_search_recursive(int arr[], int key, int low, int high) {
  if (low > high) return -1;

  int mid = (high + low) / 2;

  if (arr[mid] > key) {
    return binary_search_recursive(arr, key, low, mid - 1);
  } else if (arr[mid] < key) {
    return binary_search_recursive(arr, key, mid + 1, high);
  }

  return mid;
}

int main() {

  int size, key, idx;
  int array[MAX];

  printf("Enter the number of elements: ");
  scanf("%d", &size);

  printf("Enter the numbers in sorted order: ");
  for(int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }

  printf("Enter the element to search: ");
  scanf("%d", &key);

  idx = binary_search_iterative(array, size, key);
  if (idx == -1) {
    printf("Element not found\n");
    return 0;
  }
  printf("(Iterative approach) Element found at index: %d\n", idx);

  idx = binary_search_recursive(array, key, 0, size - 1);
  printf("(Recursive approach) Element found at index: %d\n", idx);
  
  return 0;
}
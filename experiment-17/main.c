#include <stdio.h>

#define MAX 100

void sort(int arr[], int size) {
  int temp;
  for(int i = 0; i < size - 1; i++) {
    for(int j = 0; j < size - i - 1; j++) {
      if (arr[j] < arr[j+1]) {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {

  int number_of_events;
  int activity_points[MAX];
  int max_number_of_events;
  int max_activity_points = 0;

  printf("Enter the total number of events: ");
  scanf("%d", &number_of_events);

  if (number_of_events < 0 || number_of_events > MAX) {
    printf("Invalid number of events\n");
    return 1;
  }

  printf("Enter the activity points for each event: ");
  for(int i = 0; i < number_of_events; i++) {
    scanf("%d", &activity_points[i]);
  }

  printf("Enter the maximum number of events you can participate in: ");
  scanf("%d", &max_number_of_events);

  if (max_number_of_events < 0) max_number_of_events = 0;
  if (max_number_of_events > number_of_events) max_number_of_events = number_of_events;

  sort(activity_points, number_of_events);

  printf("Selected events (activity points): ");
  for(int i = 0; i < max_number_of_events; i++) {
    printf("%d ", activity_points[i]);
    max_activity_points += activity_points[i];
  }
  printf("\n");

  printf("Maximum total activity points: %d\n", max_activity_points);

  return 0;
}
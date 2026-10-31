#include <stdio.h>

#define MAX 100

typedef struct {
  int row;
  int col;
  int val;
} Field;

void read_sparce(Field matrix[MAX]) {

  int row, col, val;

  printf("Enter the number of rows, cols and non-zero values: ");
  scanf("%d %d %d", &row, &col, &val);

  matrix[0] = (Field){
      .row = row,
      .col = col,
      .val = val,
  };

  printf("Enter the (row, col, value) pairs\n");
  for (int i = 1; i <= matrix[0].val; i++) {
    scanf("%d %d %d", &row, &col, &val);
    matrix[i] = (Field){
        .row = row,
        .col = col,
        .val = val,
    };
  }
}

void display_sparce(Field matrix[MAX]) {
  for (int i = 0; i <= matrix[0].val; i++) {
    printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].val);
  }
}

void add(Field firstMatrix[], Field secondMatrix[], Field sumMatrix[]) {
  if ((firstMatrix[0].row != secondMatrix[0].row) ||
      (firstMatrix[0].col != secondMatrix[0].col)) {
    printf("Dimension of both sparce matrix must be same for addition.");
    return;
  }

  int i = 1;
  int j = 1;
  int k = 1;

  sumMatrix[0] = firstMatrix[0];

  while (i <= firstMatrix[0].val && j <= secondMatrix[0].val) {

    // case 1: row same, col same
    if (firstMatrix[i].row == secondMatrix[j].row &&
        firstMatrix[i].col == secondMatrix[j].col) {
      sumMatrix[k] = (Field){
          .row = firstMatrix[i].row,
          .col = firstMatrix[i].col,
          .val = firstMatrix[i].val + secondMatrix[i].val,
      };

      k++;
      j++;
      i++;
    }

    // case 2: row same, col different
    if (firstMatrix[i].row == secondMatrix[j].row &&
        firstMatrix[i].col != secondMatrix[j].col) {
      // first col < second col
      if (firstMatrix[i].col < secondMatrix[j].col) {
        sumMatrix[k] = firstMatrix[i];

        k++;
        i++;
      }

      // first col >= second col
      else {
        sumMatrix[k] = secondMatrix[j];

        k++;
        j++;
      }
    }

    // case 3: row different
    if (firstMatrix[i].row != secondMatrix[j].row) {
      // first row < second row
      if (firstMatrix[i].row < secondMatrix[j].row) {
        sumMatrix[k] = firstMatrix[i];

        k++;
        i++;
      }

      // first row >= second row
      else {
        sumMatrix[k] = secondMatrix[j];

        k++;
        j++;
      }
    }
  }

  while (i <= firstMatrix[0].val) {
    sumMatrix[k] = firstMatrix[i];
    k++;
    i++;
  }

  while (j <= secondMatrix[0].val) {
    sumMatrix[k] = secondMatrix[j];
    k++;
    j++;
  }

  sumMatrix[0].val = k - 1;
}

void transpose(Field matrix[MAX], Field transpose[MAX]) {
  
  transpose[0] = (Field) {
    .row = matrix[0].col,
    .col = matrix[0].row,
    .val = matrix[0].val,
  };

  int k = 1;
  int col = 0;
  int i = 1;
  
  for(col = 0; col < matrix[0].col; col++) {
    for(i = 1; i <= matrix[0].val; i++) {
      if (matrix[i].col == col) {
        transpose[k] = (Field) {
          .row = matrix[i].col,
          .col = matrix[i].row,
          .val = matrix[i].val,
        };

        k++;
      }
    }
  }
}

int main() {

  Field firstMatrix[MAX], secondMatrix[MAX], sumMatrix[MAX],
      transposeMatrix[MAX];

  printf("Enter the first sparce matrix\n");
  read_sparce(firstMatrix);

  printf("Enter the second sparce matrix\n");
  read_sparce(secondMatrix);

  printf("\nA:\n");
  display_sparce(firstMatrix);
  printf("\nB:\n");
  display_sparce(secondMatrix);

  add(firstMatrix, secondMatrix, sumMatrix);
  printf("\nSum:\n");
  display_sparce(sumMatrix);

  transpose(firstMatrix, transposeMatrix);
  printf("\nTranspose of A:\n");
  display_sparce(transposeMatrix);

  return 0;
}

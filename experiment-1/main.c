#include <stddef.h>
#include <stdio.h>

#define MAX 100

typedef struct {
  int coeff;
  int exp;
} Term;

// ---------------------------------------------------------------------------------

void display_poly(Term p[MAX], int size) {
  for (int i = 0; i < size; i++) {
    printf("%dx^%d", p[i].coeff, p[i].exp);

    if (i != size - 1) printf(" + ");
  }
  printf("\n");
}

void read_poly(Term p[MAX], int size) {
 
  int coeff, exp;

  printf("Enter the (coeff, exp) pairs\n");
  for (int i = 0; i < size; i++) {
    scanf("%d %d", &coeff, &exp);
    p[i] = (Term){.coeff = coeff, .exp = exp};
  }
}

int add(
    Term firstPoly[MAX], int firstSize,
    Term secondPoly[MAX], int secondSize,
    Term sumPoly[MAX]
) {
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < firstSize && j < secondSize) {
    if (firstPoly[i].exp == secondPoly[j].exp) {
      sumPoly[k] = (Term) {
        .coeff = firstPoly[i].coeff + secondPoly[j].coeff,
        .exp = firstPoly[i].exp
      };

      k++; j++; i++;
    } else if (firstPoly[i].exp < secondPoly[j].exp) {
      sumPoly[k] = firstPoly[i];

      k++; i++;
    } else {
      sumPoly[k] = secondPoly[j];

      k++; j++;
    }
  }

  while (i < firstSize) sumPoly[k++] = firstPoly[i++];
  while (j < secondSize) sumPoly[k++] = secondPoly[j++];

  return k;
}

// ---------------------------------------------------------------------------------

int main() {

  Term firstPoly[MAX], secondPoly[MAX], sumPoly[MAX];
  int coeff, exp;
  int firstSize, secondSize, sumSize;

  printf("Enter the number of terms in first polynomial: ");
  scanf("%d", &firstSize);

  read_poly(firstPoly, firstSize);

  printf("Enter the number of terms in second polynomial: ");
  scanf("%d", &secondSize);

  read_poly(secondPoly, secondSize);

  sumSize = add(firstPoly, firstSize, secondPoly, secondSize, sumPoly);
  
  printf("\n");
  display_poly(firstPoly, firstSize);
  display_poly(secondPoly, secondSize);
  display_poly(sumPoly, sumSize);
  return 0;
}

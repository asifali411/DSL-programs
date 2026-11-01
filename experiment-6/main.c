#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
  int coeff;
  int exp;
  struct Term *next;
} Term;

Term *firstPoly = NULL;
Term *secondPoly = NULL;
Term *sumPoly = NULL;
Term *productPoly = NULL;

Term *create_term(int coeff, int exp) {
  Term *term = (Term *)malloc(sizeof(Term));

  term->coeff = coeff;
  term->exp = exp;
  term->next = NULL;

  return term;
}

Term *add_term(Term *poly, int coeff, int exp) {
  if (coeff == 0) return poly;

  Term *current = poly;

  while (current != NULL) {
    if (current->exp == exp) {
      current->coeff += coeff;
      return poly;
     }
    current = current->next;
  }

  Term *term = create_term(coeff, exp);

  if (poly == NULL) {
    return term;
  }

  current = poly;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = term;
  return poly;
}

void free_poly(Term *poly) {
  while (poly != NULL) {
    Term *temp = poly;
    poly = poly->next;
    free(temp);
  }
}

void display(Term *poly) {
  while(poly != NULL) {
    printf("%dx^%d", poly->coeff, poly->exp);
    if (poly->next != NULL) printf(" + ");
    poly = poly->next;
  }
  printf("\n");
}

void add() {
  Term *current = firstPoly;
  while (current != NULL) {
    sumPoly = add_term(sumPoly, current->coeff, current->exp);
    current = current->next;
  }

  current = secondPoly;
  while (current != NULL) {
    sumPoly = add_term(sumPoly, current->coeff, current->exp);
    current = current->next;
  }
}

void multiply() {
  Term *firstPtr = firstPoly;
  while(firstPtr != NULL) {
    Term *secondPtr = secondPoly;

    while(secondPtr != NULL) {
      productPoly = add_term(
        productPoly, 
        firstPtr->coeff * secondPtr->coeff, 
        firstPtr->exp + secondPtr->exp
      );
      secondPtr = secondPtr->next;
    }

    firstPtr = firstPtr->next;
  }
}

int main() {
  int firstSize, secondSize;
  int coeff, exp;

  printf("Enter the number of terms in first polynomial: ");
  scanf("%d", &firstSize);

  printf("Enter the (coeff, exp) pairs\n");
  for(int i = 0; i < firstSize; i++) {
    scanf("%d %d", &coeff, &exp);
    firstPoly = add_term(firstPoly, coeff, exp);
  }

  printf("Enter the number of terms in second polynomial: ");
  scanf("%d", &secondSize);
  
  printf("Enter the (coeff, exp) pairs\n");
  for(int i = 0; i < secondSize; i++) {
    scanf("%d %d", &coeff, &exp);
    secondPoly = add_term(secondPoly, coeff, exp);
  }

  display(firstPoly);
  display(secondPoly);

  add();
  multiply();

  display(sumPoly);
  display(productPoly);
 
  free_poly(firstPoly);
  free_poly(secondPoly);
  free_poly(sumPoly);
  free_poly(productPoly);
  return 0;
}
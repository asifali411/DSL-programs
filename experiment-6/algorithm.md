# POLYNOMIAL ADDITION AND MULTIPLICATION USING SINGLY LINKED LIST

## AIM
    To add and multiply two polynomials using a singly linkedlist.

## ALGORITHM

1. Start
2. Define a struct Term containing:
    - coeff -> coefficient of the term.
    - exp -> exponent of the term.
    - next -> pointer to the next node.
3. Initialize the pointer firstPoly, secondPoly, sumPoly and productPoly.
4. Create a function create_term(coeff, exp)
    - Allocate memory for a new node
    - Store coefficient and exponent.
    - Set next to NULL.
    - Return new node.
5. Create a function add_term(poly, coeff, exp)
    - If coeff is 0, return the polynomial.
    - Traverse the linked list.
    - If a node with same exponent exists, add the given coefficient to its coefficient.
    - Else, create a new node and insert it at the end of the linked list.
    - Return the updated polynomial.
6. Polynomial Addition
    - Traverse the first polynomial
    - Insert each term into sumPoly using add_term()
    - Traverse the second polynomial
    - Insert each term into sumPoly using add_term()
7. Polynomial Multiplication
    - Tranverse each tearm of the first polynomial using firstPtr.
    - For each term of the first polynomial, traverse all terms of the second polynomial using secondPtr.
    - Multiply their coefficients.
    - Add their exponents.
    - Insert the resulting term into productPoly using add_term().
    - Repeat until all combinations of terms are processed.
8. Stop
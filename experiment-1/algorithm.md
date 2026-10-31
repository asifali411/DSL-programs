# SUM OF SPARSE POLYNOMIALS USING ARRAYS

## AIM
    To find the sum of two sparse polynomials using arrays.

## ALGORITHM
1. Start.
2. Read the two polynomials to be added (poly1 and poly2).
3. Initialize three index variables:
    i = 0 → For the first polynomial.
    j = 0 → For the second polynomial.
    k = 0 → For the resultant polynomial.
3. Repeat while i is less than the size of the first polynomial and j is less than the size of the second polynomial:
    - If the exponents of both terms are equal:
        - Add their coefficients.
        - Store the resulting coefficient and the common exponent in the resultant polynomial (if the coefficient is non-zero).
        - Increment i, j, and k (increment k only if a term is stored).
    - Else if poly1[i].exp < poly2[j].exp:
        - Copy poly1[i] to the resultant polynomial.
        - Increment i and k.
    - Else:
        - Copy poly2[j] to the resultant polynomial.
        - Increment j and k.
4. Copy the remaining terms of the first polynomial, if any, to the resultant polynomial.
5. Copy the remaining terms of the second polynomial, if any, to the resultant polynomial.
6. Stop.
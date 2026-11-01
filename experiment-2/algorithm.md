# SPARSE MATRIX ADDITION AND TRANSPOSE

## AIM
    To perform addition and transpose of sparse matrices.

## ALGORITHM

### TRANSPOSE

1. Start.
2. Read the sparse matrix.
3. Initialize the transpose matrix.
    - Number of rows = Number of columns in original matrix.
    - Number of cols = Number of rows in original matrix.
    - Number of non-zero elements = Number of non-zero elements in original matrix.
4. Initialize k = 1 to store the elements in the transpose matrix.
5. Repeat for each column of the original matrix, starting from column 0:
    - Traverse all non-zero elements of the original matrix.
    - If the column of the current element matches the current column:
        - Interchange its row and column positions.
        - Copy the value into the transpose matrix.
        - Increment k.
6. Stop.

### ADDITION

1. Start.
2. Read the two sparse matrices.
3. Check whether the dimensions of both matrices are equal.
    - If the dimensions are not equal, display an error message and stop the addition.
4. Initialize three index variables:
    - i = 1 -> for first matrix.
    - j = 1 -> for second matrix.
    - k = 1 -> for resultant matrix.
5. Store the dimensions of the first matrix in the resultant matrix.
6. Repeat while i <= firstMatrix[0].val and j <= secondMatrix[0].val:
    - if the row and col are both equal:
        - add their values.
        - store the resulting value with the common row and column position in the resultant matrix.
        - increment i, j and k.
    - else if row is equal
        - if firstMatrix[i].col < secondMatrix[j].col:
            - copy element of first matrix to the resultant matrix.
            - increment i and k.
        - else
            - copy element of second matrix to the resultant matrix.
            - increment j and k.
    - else if row positions are different:
        - if firstMatrix[i].row < secondMatrix[j].row:
            - copy element of first matrix to the resultant matrix.
            - increment i and k.
        - else
            - copy element of second matrix to the resultant matrix.
            - increment j and k.
7. Copy the remaining elements of the first and second matrices to resultant matrix.
8. Update the number of non-zero elements in the resultant matrix.
9. Stop.


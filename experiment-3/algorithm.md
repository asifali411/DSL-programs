# Infix to Postfix and Prefix Conversion and Evaluation Using a Stack

## AIM
    To implement a program that converts an infix expression to its equivalent postfix and prefix expressions, and evaluates the expression using a stack.

## ALGORITHM

### INFIX TO POSTFIX

1. Start.
2. Initialize an empty stack and an empty output string.
3. Scan the infix expression from left to right.
4. If the symbol is an operand, append it to the output.
5. If the symbol is `(`, push it onto the stack.
6. If the symbol is `)`, pop operators from the stack and append them to the output until `(` is encountered. Pop and discard the `(`.
7. If the symbol is an operator:
   - While the stack is not empty, the top of the stack is not `(`, and the precedence of the top operator is **greater than or equal to** the precedence of the scanned operator, pop the top operator and append it to the output.
   - Push the scanned operator onto the stack.
8. After scanning is complete, pop all remaining operators from the stack and append them to the output.
9. Stop.

### INFIX TO PREFIX

1. Start.
2. Reverse the infix expression.
3. While reversing, swap every `(` with `)` and every `)` with `(`.
4. Convert the modified expression to postfix using the algorithm above, with one change in step 7: pop only while the top operator has **strictly greater** precedence than the scanned operator (not equal).
5. Reverse the resulting postfix expression. This is the prefix expression.
6. Stop.

### EVALUATION OF POSTFIX EXPRESSION

1. Start.
2. Initialize an empty operand stack.
3. Scan the postfix expression from left to right.
4. If the symbol is an operand, push its value onto the stack.
5. If the symbol is an operator:
   - Pop the top element as `op2`.
   - Pop the next element as `op1`.
   - Compute `result = op1 (operator) op2`.
   - Push `result` onto the stack.
6. After scanning, the single value left on the stack is the answer.
7. Stop.

### EVALUATION OF PREFIX EXPRESSION

1. Start.
2. Initialize an empty operand stack.
3. Scan the prefix expression from **right to left**.
4. If the symbol is an operand, push its value onto the stack.
5. If the symbol is an operator:
   - Pop the top element as `op1`.
   - Pop the next element as `op2`.
   - Compute `result = op1 (operator) op2`.
   - Push `result` onto the stack.
6. After scanning, the single value left on the stack is the answer.
7. Stop.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/* stack and the top pointer */
double data[MAX_SIZE];
int top = -1;

/* check is stack empty */
int isEmpty() {
    return top == -1;
}

/* check is stack full */
int isFull() {
    return top == MAX_SIZE - 1;
}

/* Add  new value to the top of the stack */
void push(double value) {
    if (isFull()) {
        printf("Error: Stack is full!\n");
        return;
    }
    top++;
    data[top] = value;
}

/* Remove and returns the value from the top of the stack */
double pop() {
    if (isEmpty()) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    double value = data[top];
    top--;
    return value;
}

/* Returns the top value */
double peek() {
    if (isEmpty()) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    return data[top];
}

int main() {
    char command[20];

    printf("=== Reverse Polish Calculator ===\n");
    printf("Commands: ? (input), +, -, *, /, = (result), q (quit)\n");


}

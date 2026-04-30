#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/* stack and the top pointer */
double data[MAX_SIZE];
int top = -1;

/* ================check is stack empty=============== */
int isEmpty() {
    return top == -1;
}

/*====================== check is stack full================================== */
int isFull() {
    return top == MAX_SIZE - 1;
}

/* ==========Add  new value to the top of the stack =====================*/
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

/* ===============================================main function=========================================== */
int main() {
    char command[20];

    printf("=== Reverse Polish Calculator ===\n");
    printf("Commands: ? (input), +, -, *, /, = (result), q (quit)\n");
    while (1) {
        printf("> ");
        scanf("%s", command);

        /* Exit condition */
        if (strcmp(command, "q") == 0 || strcmp(command, "quit") == 0) {
            printf("Exiting calculator.\n");
            break;
        }

        /* Command to input a number */
        else if (strcmp(command, "?") == 0) {
            double num;
            printf("  Enter number: ");
            scanf("%lf", &num);
            push(num);
            printf("  Pushed: %.2f\n", num);
        }

        /* Command to display the current top value */
        else if (strcmp(command, "=") == 0) {
            printf("  Result = %.2f\n", peek());
        }

        /* ========================Basic Arithmetic Operations =====================*/
        else if (strcmp(command, "+") == 0) {
            double b = pop();
            double a = pop();
            push(a + b);
            printf("  %.2f + %.2f = %.2f\n", a, b, a + b);
        }
        else if (strcmp(command, "-") == 0) {
            double b = pop();
            double a = pop();
            push(a - b);
            printf("  %.2f - %.2f = %.2f\n", a, b, a - b);
        }
        else if (strcmp(command, "*") == 0) {
            double b = pop();
            double a = pop();
            push(a * b);
            printf("  %.2f * %.2f = %.2f\n", a, b, a * b);
        }
        /*================================Zero Division error checking=========================*/
        else if (strcmp(command, "/") == 0) {
            double b = pop();
            double a = pop();
            if (b == 0) {
                printf("  Error: Cannot divide by zero!\n");
                push(a);
                push(b);
            } else {
                push(a / b);
                printf("  %.2f / %.2f = %.2f\n", a, b, a / b);
            }
        }

        /* ==================Error handling for invalid commands======================= */
        else {
            printf("  Unknown command: %s\n", command);
        }
    }

    return 0;


}

#include <math.h>
#include <stdio.h>

#include "stack.c"
#include "taylor_sine.c"
// I include .c-file, because with .h-file is dont wark

void print_stack(stack s) {
    node* p = s.head;
    for (int i = 0; p != NULL; i++) {
        printf("%d, %d\n", i, p->data);

        p = p->next;
    }
}

void test_taylor_sine(double x, int n) {
    printf("TEST, x = %.1lf, n = %d \n", x, n);
    double taylor = taylor_sine(x, n);
    double ANSI = sin(x);

    int close = (abs(taylor - ANSI) < 0.01) ? 1 : 0;

    printf("Taylor: %.8lf, ANSI: %.8lf, close: %d \n\n", taylor, ANSI, close);

    return;
}

void test_function_sine(void) {
    // Test range of function
    test_taylor_sine(1, 5);  // Calculates good
    test_taylor_sine(3, 5);
    test_taylor_sine(5, 5);
    // Here x are to great for the precission,
    // For a precision of 5, an x-value greater than 5
    // cant be calculated accuretly.
    // The interval in which the taylor sine is accurate, depends on the
    // precition (n)

    // Test precision of function
    test_taylor_sine(5, 5);
    test_taylor_sine(5, 7);
    test_taylor_sine(5, 10);
    // The first test, cant calculte sin(5) accuretly.
    // The second test is closer, but not quite.
    // The last test is passed.
    // Incresing the precision makes the function calculate values futher from
    // 0. The further from 0 the value is, the more terms the function need to
    // be calculated.
    return;
}

void test_stack() {
    printf("----- STACK LIST -----\n");

    stack s;
    initialize(&s);
    // Condition A:
    printf("Condition (A): %d\n", empty(&s));

    // Condition B:
    int x = 3;
    push(x, &s);
    int y = pop(&s);
    printf("Condition (B): %d\n", x == y);

    // Condition C:
    int x0 = 1;
    int x1 = 2;
    push(x0, &s);
    push(x1, &s);
    int y0 = pop(&s);
    int y1 = pop(&s);
    printf("Condition (C): %d\n", x0 == y1 && x1 == y0);

    return;
}

// Add your test cases for Exercise 1 (b,c) here
int main(int argc, char** argv) {
    test_function_sine();
    test_stack();
    return 0;
}
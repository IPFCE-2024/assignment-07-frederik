#include <assert.h>
#include "./include/stack.h"

int main()
{
    stack s;
    initialize(&s);

    // (1) After initialize(s), stack must be empty
    assert(empty(&s));
    printf("Law (1) passed\n");

    // (2) push(x, s); y = pop(s); stack unchanged; x == y
    push(42, &s);
    int y = pop(&s);
    assert(empty(&s));
    assert(y == 42);
    printf("Law (2) passed\n");

    // (3) push(x0, s); push(x1, s); y0 = pop(s); y1 = pop(s);
    // Stack should be the same as before, and LIFO holds
    push(10, &s);
    push(20, &s);
    int y0 = pop(&s);
    int y1 = pop(&s);
    assert(empty(&s));
    assert(y0 == 20 && y1 == 10);
    printf("Law (3) passed\n");

    printf("\nAll stack laws verified successfully!\n\n");


    return 0;
}
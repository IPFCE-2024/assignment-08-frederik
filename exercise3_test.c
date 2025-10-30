#include "exercise3.h"

int main(void) {
    queue q;
    int x0 = 10, x1 = 20;
    int y0, y1;

    // Law 1
    initialize(&q);
    assert(empty(&q));

    // Law 2
    enqueue(&q, x0);
    y0 = dequeue(&q);
    assert(empty(&q));
    assert(x0 == y0);

    // Law 3
    enqueue(&q, x0);
    enqueue(&q, x1);
    y0 = dequeue(&q);
    y1 = dequeue(&q);
    assert(empty(&q));
    assert(x0 == y0);
    assert(x1 == y1);

    printf("All queue tests passed.\n");
    return 0;
}
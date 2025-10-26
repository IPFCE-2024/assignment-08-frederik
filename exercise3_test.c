#include "./include/exercise3.h"



int main(void) {
    queue q;
    initialize(&q);

    // --- Law 1 ---
    // After initialization queue must be empty
    assert(q.front == NULL && q.rear == NULL);
    printf("Law 1 passed: Queue is empty after initialization.\n");

    // --- Law 2 ---
    // enqueue then dequeue returns same element - queue unchanged
    int x = 42;
    enqueue(&q, x);
    int y = dequeue(&q);
    assert(x == y);
    assert(q.front == NULL && q.rear == NULL);
    printf("Law 2 passed: Queue restored and x == y.\n");

    // --- Law 3 ---
    // enqueue x0, enqueue x1, dequeue y0, dequeue y1
    int x0 = 1;
    int x1 = 2;
    enqueue(&q, x0);
    enqueue(&q, x1);

    int y0 = dequeue(&q);
    int y1 = dequeue(&q);

    assert(x0 == y0 && x1 == y1);
    assert(q.front == NULL && q.rear == NULL);
    printf("Law 3 passed: Queue restored and FIFO order preserved.\n");

    printf("\nAll queue tests passed successfully!\n");
    return 0;
}
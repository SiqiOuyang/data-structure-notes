#include <stdio.h>
#define MAX 100000   // 开大，保证不溢出

typedef struct {
    int data[MAX];
    int front;   // 队头下标
    int rear;    // 队尾下标（指向下一个可插入位置）
} Queue;

// 初始化
void InitQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// 判空
int IsEmpty(Queue *q) {
    return q->front == q->rear;
}

// 判满（循环队列，牺牲一个单元区分空和满）
int IsFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// 入队
int EnQueue(Queue *q, int x) {
    if (IsFull(q)) return 0;      // 队满，入队失败
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX;
    return 1;
}

// 出队
int DeQueue(Queue *q, int *x) {
    if (IsEmpty(q)) return 0;      // 队空，出队失败
    *x = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    return 1;
}
//添加main 函数

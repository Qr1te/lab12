//
// Created by Asus Tuf on 15.04.2025.
//

#ifndef LAB12_QUEUE_H
#define LAB12_QUEUE_H

#endif //LAB12_QUEUE_H
typedef struct QueueNode {
    struct QueueNode* next;
    int num;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
    int capacity;
} Queue;

typedef struct DequeNode {
    struct DequeNode* next;
    struct DequeNode* prev;
    int num;
} DequeNode;

typedef struct {
    DequeNode* front;
    DequeNode* rear;
    int size;
    int capacity;
} Deque;


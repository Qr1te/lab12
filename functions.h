//
// Created by Asus Tuf on 15.04.2025.
//

#ifndef LAB12_FUNCTIONS_H
#define LAB12_FUNCTIONS_H

#endif //LAB12_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "queue.h"

void setNumber(int *number);
int isDigit(char symbol);
void initQueue(Queue* q, int capacity);
int isQueueFull(Queue* q);
int isQueueEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void printQueue(Queue* q);
void inputQueue(Queue* q);
void freeQueue(Queue* q);
DequeNode* createNode(int num);
void initializeDeque(Deque* deque, int capacity);
int isEmpty(Deque* deque);
int isFull(Deque* deque);
void addFront(Deque* deque, int num);
void addRear(Deque* deque, int num);
int removeFront(Deque* deque);
int removeRear(Deque* deque);
void printDeque(Deque* deque);
void processInput(Deque* deque, int num);
int areQueuesEqual(Queue* q1, Queue* q2);

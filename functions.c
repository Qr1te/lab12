//
// Created by Asus Tuf on 15.04.2025.
//

#include "functions.h"

void setNumber(int* number)
{
    int isInvalid = 0;
    do {
        isInvalid = 0;
        int i = 0;
        *number = 0;
        char digits[10];
        scanf("%s", digits);
        int negative = 1;
        if(digits[0] == '-'){negative = -1;i++;}
        do {
            if (digits[i] < '0' || digits[i] > '9') {
                printf("Enter a valid number\n");
                isInvalid = 1;
                while(getchar()!='\n');
                break;
            }
            else {*number = *number * 10 + digits[i] - '0'; }
        } while(digits[++i] != 0);
        *number *= negative;
    }while(isInvalid == 1);
    rewind(stdin);
}
int isDigit(char symbol) {
    return (symbol >= '0' && symbol <= '9');;
}


void initQueue(Queue* q, int capacity) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    q->capacity = capacity;
}

int isQueueFull(Queue* q) {
    return q->size >= q->capacity;
}


int isQueueEmpty(Queue* q) {
    return q->size == 0;
}


void enqueue(Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("\nQueue is full %d\n", value);
        return;
    }

    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("Error allocation memory\n");
        return;
    }

    newNode->num = value;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return INT_MIN;
    }

    QueueNode* temp = q->front;
    int value = temp->num;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return value;
}

void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    QueueNode* current = q->front;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}


void inputQueue(Queue* q) {
    char str[12];
    int ind = 0;
    int num;
    printf("Enter queue. Press enter to stop\n");
    printf("Max size: %d\n", q->capacity);
    while (1) {
        str[ind] = _getch();

        if (str[ind] == 13) {
            if (ind > 0 && str[0] != '-') {
                num = atoi(str);
                if (!isQueueFull(q)) {
                    enqueue(q, num);
                    printf("\n");
                    break;
                } else {
                    printf("\nQueue is empty.\n");
                    break;
                }
            } else {
                printf("\nError.\n");
                ind = 0;
                continue;
            }
        }

        if (str[ind] == '\b') {
            if (ind > 0) {
                ind--;
                printf("\b \b");
            }
            continue;
        }

        if (isDigit(str[ind]) || (ind == 0 && str[ind] == '-')) {
            printf("%c", str[ind]);
            ind++;
        }

        if (str[ind] == ' ' && ind > 0 && str[ind - 1] != '-') {
            str[ind] = '\0';
            num = atoi(str);
            if (!isQueueFull(q)) {
                enqueue(q, num);
                printf(" ");
                ind = 0;
            } else {
                printf("\nQueue is full.\n");
                break;
            }
        }
    }
}
void freeQueue(Queue* q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
}



DequeNode* createNode(int num) {
    DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->num = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void initializeDeque(Deque* deque, int capacity) {
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    deque->capacity = capacity;
}

int isEmpty(Deque* deque) {
    return deque->size == 0;
}


int isFull(Deque* deque) {
    return deque->size == deque->capacity;
}


void addRear(Deque* deque, int num) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }

    DequeNode* newNode = createNode(num);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    deque->size++;
}


int removeFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }

    DequeNode* temp = deque->front;
    int num = temp->num;

    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(temp);
    deque->size--;
    return num;
}


void printDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque (front to rear): ");
    DequeNode* current = deque->front;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}


void processInput(Deque* deque, int num) {
    if (!isFull(deque)) {

        addRear(deque, num);
        printf("Added %d to rear (normal mode)\n", num);
    } else {
        int removed = removeFront(deque);
        printf("Removed %d from front (special mode)\n", removed);

        if (removed != num) {
            addRear(deque, num);
            printf("Added %d to rear (special mode)\n", num);
        } else {
            printf("%d equals removed element, not added\n", num);
        }
    }
}

int areQueuesEqual(Queue* q1, Queue* q2) {
    if (q1->size != q2->size) return 0;

    QueueNode* node1 = q1->front;
    QueueNode* node2 = q2->front;

    while (node1 != NULL && node2 != NULL) {
        if (node1->num != node2->num) return 0;
        node1 = node1->next;
        node2 = node2->next;
    }

    return 1;
}

//
// Created by Asus Tuf on 24.04.2025.
//

#include "tasks.h"
#include "functions.h"
void performTask1(){
    int capacity;
    printf("Enter max size of queue: ");
    scanf_s("%d", &capacity);

    Queue q;
    initQueue(&q, capacity);
    inputQueue(&q);


    printf("\nProcessing mode:\n");
    printf("When you enter a number, the first element of the queue will be deleted.\n");
    printf("If it matches the number entered, the number is added to the queue..\n");
    printf("Press -1 to exit.\n\n");

    int num;
    while (1) {
        printQueue(&q);

        printf("Enter number: ");
        setNumber(&num);

        if (num == -1) {
            break;
        }

        if (!isQueueEmpty(&q)) {
            int first = dequeue(&q);
            if (first == num) {
                enqueue(&q, num);
                printf("Element %d matched and was added back to the queue.\n", num);
            } else {
                printf("Element %d did not match the first element of the queue %d.\n", num, first);
            }
        } else {
            printf("Queue is empty.\n");
            break;
        }
    }

    freeQueue(&q);
    puts("Press any key to return..."), _getch();
}

void performTask2(){
    Deque deque;
    int capacity;

    printf("Enter the maximum size of the deque: ");
    scanf("%d", &capacity);

    initializeDeque(&deque, capacity);

    int choice, num;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a number to the deque\n");
        printf("2. Print the deque\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to add: ");
                scanf("%d", &num);
                processInput(&deque, num);
                break;
            case 2:
                printDeque(&deque);
                break;
            case 3:

                while (!isEmpty(&deque)) {
                    removeFront(&deque);
                }
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        puts("Press any key to return..."), _getch();
    }

}

void performTask3(){
    int capacity, capacity1;
    printf("Enter max size of first queue: \n");
    setNumber(&capacity);

    Queue q1, q2;
    initQueue(&q1, capacity);
    printf("Enter max size of the second queue: \n");
    setNumber(&capacity1);
    initQueue(&q2, capacity1);


    inputQueue(&q1);


    inputQueue(&q2);

    if (areQueuesEqual(&q1, &q2)) {
        printf("\nQueues are equal\n");
    } else {
        printf("\nQueues are not equal\n");
    }

    printf("\nFirst queue:\n");
    printQueue(&q1);
    printf("Second queue:\n");
    printQueue(&q2);

    freeQueue(&q1);
    freeQueue(&q2);
    puts("Press any key to return..."), _getch();
}
void menu(){

    int answer;
    do {
        system("cls");
        answer = 0;
        printf("Choose what u want to do\n");
        printf("1. perform task 1.\n2. perform task 2\n3. perform task 3\n4.Exit.\n");

        while (answer < '1' || answer > '4') answer = _getch();
        if (answer == '1'){
            performTask1();
        }
        else if (answer == '2') {
            performTask2();
        }
        else if (answer == '3') {
            performTask3();
        }
    } while (answer != '4');
}
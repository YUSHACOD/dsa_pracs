#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
typedef struct {
    char job_name[50];
} PrintJob;
typedef struct {
    PrintJob items[MAX_QUEUE_SIZE];
    int front, rear;
} PrintQueue;
void initQueue(PrintQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isQueueEmpty(PrintQueue *queue) {
    return (queue->front == -1);
}
int isQueueFull(PrintQueue *queue) {
    return (queue->rear == MAX_QUEUE_SIZE - 1);
}
void enqueue(PrintQueue *queue, char *job_name) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot add more print jobs.\n");
    } else {
        if (isQueueEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        strcpy(queue->items[queue->rear].job_name, job_name);
        printf("Print job '%s' added to the queue.\n", job_name);
    }
}
void dequeue(PrintQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. No print jobs to print.\n");
    } else {
        printf("Printing: %s\n", queue->items[queue->front].job_name);
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
    }
}
int main() {
    PrintQueue queue;
    initQueue(&queue);

    while (1) {
        printf("\nPrint Spooler Menu:\n");
        printf("1. Add Print Job\n");
        printf("2. Print Next Job\n");
        printf("3. Quit\n");
        int choice;
        char job_name[50];
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the print job name: ");
                scanf("%s", job_name);
                enqueue(&queue, job_name);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printf("Exiting the print spooler.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

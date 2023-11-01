#include <stdio.h>
#include <stdlib.h>
struct QueueNode{
    int data;
    struct QueueNode* next;
};
struct Queue {
    struct QueueNode* front;
     struct QueueNode* rear;
};
struct Queue* createQueue() {
struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
if (!queue) {
printf("Memory allocation failed\n");
exit(1);
}
queue->front = queue->rear = NULL;
return queue;
}
int isEmpty(struct Queue* queue) {
return (queue->front == NULL);
}
void enqueue(struct Queue* queue, int data) {
struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct
QueueNode));
if (!newNode) {
printf("Memory allocation failed\n");
exit(1);
}

newNode->data = data;
newNode->next = NULL;

if (isEmpty(queue)) {
queue->front = queue->rear = newNode;
} else {

queue->rear->next = newNode;
queue->rear = newNode;
}
}
int dequeue(struct Queue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty. Dequeue operation failed\n");
exit(1);
}
int data = queue->front->data;
struct QueueNode* temp = queue->front;
queue->front = queue->front->next;
if (queue->front == NULL) {
queue->rear = NULL;
}
free(temp);
return data;
}
void displayQueue(struct Queue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty.\n");
return;
}
struct QueueNode* current = queue->front;
while (current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}
int main() {
struct Queue* queue = createQueue();
int choice, data;
while (1) {
printf("Queue Menu:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Display Queue\n");
printf("4. Quit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to enqueue: ");
scanf("%d", &data);
enqueue(queue, data);
break;
case 2:
if (!isEmpty(queue)) {
printf("Dequeued element: %d\n", dequeue(queue));
} else {
printf("Queue is empty. Dequeue operation failed\n");
}
break;
case 3:
printf("Queue elements: ");
displayQueue(queue);
break;
case 4:
printf("Exiting program\n");
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node *front, *rear;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        q->rear->next = q->front;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }
}
int deQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    int value;
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    } 
    else
    {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    return value;
}

int Front(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

int Rear(struct Queue* q) {
    if (q->rear == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->rear->data;
}
int main() {
    struct Queue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    printf("Front: %d\n", Front(q));  
    printf("Rear: %d\n", Rear(q));    
    printf("Dequeued: %d\n", deQueue(q));  
    printf("Front: %d\n", Front(q));  
    printf("Rear: %d\n", Rear(q));    
    return 0;
}


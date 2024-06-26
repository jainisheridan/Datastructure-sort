#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ARRAY_SIZE 100

// Queue node structure
typedef struct node {
    int value;
    struct node *next;
} Node;

// Queue ADT structure
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Function prototypes
void generateArray(int array[], int size);
int findBiggest(int array[], int size);
int getNumberOfRuns(int number);
void radixSort(int array[], int size);
void display(int array[], int size);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
bool isEmpty(Queue *q);
void initQueue(Queue *q);

// Queue Operations
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    Node *temp = q->front;
    int value = temp->value;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

// Radix Sort functions
void generateArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 900 + 100; // Generate 3-digit random numbers
    }
}

int findBiggest(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int getNumberOfRuns(int number) {
    int runs = 0;
    while (number != 0) {
        runs++;
        number /= 10;
    }
    return runs;
}

void radixSort(int array[], int size) {
    int max = findBiggest(array, size);
    int runs = getNumberOfRuns(max);
    Queue bins[10]; // Queues for each digit

    for (int i = 0; i < 10; i++) {
        initQueue(&bins[i]);
    }

    for (int i = 0, factor = 1; i < runs; i++, factor *= 10) {
        for (int j = 0; j < size; j++) {
            int binIndex = (array[j] / factor) % 10;
            enqueue(&bins[binIndex], array[j]);
        }

        int arrayIndex = 0;
        for (int k = 0; k < 10; k++) {
            while (!isEmpty(&bins[k])) {
                array[arrayIndex++] = dequeue(&bins[k]);
            }
        }
    }
}

void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int array[ARRAY_SIZE];
    generateArray(array, ARRAY_SIZE);
    
    printf("Original array:\n");
    display(array, ARRAY_SIZE);
    
    radixSort(array, ARRAY_SIZE);
    
    printf("Sorted array:\n");
    display(array, ARRAY_SIZE);
    
    return 0;
}


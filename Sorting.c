#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGE_SIZE 1000000
#define MEDIUM_SIZE 500000
#define SMALL_SIZE 100000
#define TINY_SIZE 5000

void generateRandomArray(int *array, int size);
void bubbleSort(int *array, int size);
void selectionSort(int *array, int size);
void insertionSort(int *array, int size);
void quickSort(int *array, int low, int high);
int partition(int *array, int low, int high);
void radixSort(int *array, int size);
void countSort(int *array, int size, int exp);
int getMax(int *array, int size);
long long currentTimeMillis();


int main() {

    srand((unsigned int)time(NULL));

 
    int *array = (int *)malloc(LARGE_SIZE * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    generateRandomArray(array, LARGE_SIZE);

    long long startMillis, endMillis;

    startMillis = currentTimeMillis();
    bubbleSort(array, TINY_SIZE);
    endMillis = currentTimeMillis();
    printf("Bubble sort time: %lld ms\n", (endMillis - startMillis));

    startMillis = currentTimeMillis();
    selectionSort(array, SMALL_SIZE); 
    endMillis = currentTimeMillis();
    printf("Selection sort time: %lld ms\n", (endMillis - startMillis));

    startMillis = currentTimeMillis();
    insertionSort(array, SMALL_SIZE); 
    endMillis = currentTimeMillis();
    printf("Insertion sort time: %lld ms\n", (endMillis - startMillis));

    startMillis = currentTimeMillis();
    quickSort(array, 0, MEDIUM_SIZE - 1); 
    endMillis = currentTimeMillis();
    printf("QuickSort time: %lld ms\n", (endMillis - startMillis));

    startMillis = currentTimeMillis();
    radixSort(array, MEDIUM_SIZE); 
    endMillis = currentTimeMillis();
    printf("Radix sort time: %lld ms\n", (endMillis - startMillis));

    free(array);
    return 0;
}


long long currentTimeMillis() {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return now.tv_sec * 1000LL + now.tv_nsec / 1000000LL;
}


void generateRandomArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100000; 
    }
}

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int *array, int size) {
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

void insertionSort(int *array, int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int getMax(int *array, int n) {
    int mx = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > mx)
            mx = array[i];
    return mx;
}

void countSort(int *array, int size, int exp) {
    int output[size];
    int i, count[10] = {0};

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];
}

void radixSort(int *array, int size) {
    int m = getMax(array, size);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(array, size, exp);
}


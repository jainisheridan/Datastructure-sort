#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
   int i, j;
   for (i = 0; i < n-1; i++)     
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

int* arrayGenerator(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n; 
    }
    return arr;
}

void markTime(clock_t *timer) {
    *timer = clock();
}

void clockTickToTime(clock_t timer) {
    long total_seconds = timer / CLOCKS_PER_SEC;
    int hours = total_seconds / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;
    
    if (timer > 0 && total_seconds == 0) {
        seconds = 1;
    }

    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}



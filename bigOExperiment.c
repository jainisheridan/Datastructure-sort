#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
        
    srand(time(NULL)); 
    int n = 1000000; 
    int* arr = arrayGenerator(n);

    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    clock_t start, end;
    markTime(&start);

    bubbleSort(arr, n);

    end = clock();
    clock_t elapsed = end - start;
    printf("Time taken for bubble sort on array of size %d: ", n);
    clockTickToTime(elapsed);

    free(arr); 
    return 0;
}


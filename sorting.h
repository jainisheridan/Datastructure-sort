#ifndef __sorting_h__
#define __sorting_h__

#include <time.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void swap(int *xp, int *yp);
int* arrayGenerator(int n);
void markTime(clock_t *timer);
void clockTickToTime(clock_t timer);

#endif


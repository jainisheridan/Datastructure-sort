#include <stdio.h>

void printArray(int arr[], int size, int index);
void sortAscending(int arr[], int size, int index);
int findSmallest(int arr[], int size, int index);
void swap(int arr[], int firstIndex, int secondIndex);

int main()
{
	int array[] = {32, 10, 90, 6, 20};
	int size = sizeof(array) / sizeof(array[0]);

	sortAscending(array, size, 0);
	printArray(array, size, 0);

	return 0;
}

void printArray(int arr[], int size, int index)
{
	if (index < size) {
		printf("%d", arr[index]);
		if (index < size - 1){
			printf(", ");
		}
		printArray(arr, size, index + 1);
	} else {
		printf("\n");
	}
}

void sortAscending(int arr[], int size, int index)
{
	if (index < size -1){
		int smallestIndex = findSmallest(arr, size, index);
		if (smallestIndex != index){
			swap(arr, index, smallestIndex);
		}
		sortAscending(arr, size, index + 1);
	}
}	

int findSmallest(int arr[], int size, int index)
{
	if (index == size - 1){
		return index;
	}
	int smallestIndex = findSmallest(arr, size, index + 1);
	return (arr[index] < arr[smallestIndex]) ? index : smallestIndex;
}

void swap(int arr[], int firstIndex, int secondIndex)
{
	int temp = arr[firstIndex];
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = temp;
}

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int numbers[], int low, int high, int value) {
	if (low > high) {
		return -1; // Base case: value not found
	}

	int mid = low + (high - low) / 2; // Calculate the middle index

	if (numbers[mid] == value) {
		return mid; // Base case: value found at mid index
	} else if (numbers[mid] > value) {
		// Recursive case: value may be in the left half
		return binarySearch(numbers, low, mid - 1, value);
	} else {
		// Recursive case: value may be in the right half
		return binarySearch(numbers, mid + 1, high, value);
	}
}

int search(int numbers[], int low, int high, int value) {
	return binarySearch(numbers, low, high, value);
}

void printArray(int numbers[], int sz) {
	int i;
	printf("Number array: ");
	for (i = 0; i < sz; ++i) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
}

int main(void) {
	int i, numInputs;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt", "r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0) {
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int*)malloc(countOfNums * sizeof(int));
		for (i = 0; i < countOfNums; i++) {
			fscanf(inFile, " %d", &value);
			numArray[i] = value;
		}

		printArray(numArray, countOfNums);
		value = numArray[countOfNums / 2]; // Choose a value from the array for searching
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0) {
			printf("Item %d exists in the number array at index %d!\n", value, index);
		} else {
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
	return 0;
}

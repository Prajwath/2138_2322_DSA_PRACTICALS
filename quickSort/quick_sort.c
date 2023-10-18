// quick_sort.c
#include "quick_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(WordEntry* a, WordEntry* b) {
    WordEntry temp = *a;
    *a = *b;
    *b = temp;
}

int partition(WordEntry arr[], int left, int right) {
    int pivot = arr[right].key;
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (arr[j].key < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quickSort(WordEntry arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

void readInputFile(const char* filename, WordEntry arr[], int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%d%*1[, ] %49s", &arr[i].key, arr[i].word) != EOF) {
        i++;
    }

    *size = i;
    fclose(file);
}

void writeOutputFile(const char* filename, WordEntry arr[], int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d %s\n", arr[i].key, arr[i].word);
    }

    fclose(file);
}

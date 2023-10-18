// main.c
#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

int main() {
    const char* inputFile = "inputQS.csv";
    const char* outputFile = "outputQS.csv";

    WordEntry arr[1000];
    int size;

    readInputFile(inputFile, arr, &size);
    quickSort(arr, 0, size - 1);
    writeOutputFile(outputFile, arr, size);

    printf("Sorting complete. Output written to %s\n", outputFile);

    return 0;
}

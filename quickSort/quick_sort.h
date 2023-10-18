// quick_sort.h
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

typedef struct {
    char word[50];
    int key;
} WordEntry;

void quickSort(WordEntry arr[], int left, int right);
void readInputFile(const char* filename, WordEntry arr[], int* size);
void writeOutputFile(const char* filename, WordEntry arr[], int size);

#endif // QUICK_SORT_H

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

struct Data {
    int count;
    char word[50];
};

void merge_sort(struct Data arr[], int left, int right);

#endif
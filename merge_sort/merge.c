#include "merge.h"

void merge(struct Data arr[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    struct Data left_subarray[left_size];
    struct Data right_subarray[right_size];

    for (int i = 0; i < left_size; i++)
        left_subarray[i] = arr[left + i];
    for (int j = 0; j < right_size; j++)
        right_subarray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < left_size && j < right_size) {
        if (left_subarray[i].count <= right_subarray[j].count) {
            arr[k] = left_subarray[i];
            i++;
        } else {
            arr[k] = right_subarray[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left_subarray[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right_subarray[j];
        j++;
        k++;
    }
}

void merge_sort(struct Data arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
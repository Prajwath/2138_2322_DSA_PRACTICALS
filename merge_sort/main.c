#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

int main() {
    FILE *inputFile = fopen("inputQS.csv", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    struct Data input_data[1000];
    int count = 0;
    char line[100];

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        sscanf(line, "%d,%s", &input_data[count].count, input_data[count].word);
        count++;
    }
    fclose(inputFile);

    merge_sort(input_data, 0, count - 1);

    FILE *outputFile = fopen("output.csv", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d,%s\n", input_data[i].count, input_data[i].word);
    }
    fclose(outputFile);

    printf("Data has been sorted and written to 'output.csv'.\n");

    return 0;
}
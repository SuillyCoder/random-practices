/*
self-imposed rules:
allowed external references
disabled copilot completions

v1
start: 13:38

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct coord {
    int x;
    int y;
} COORD;

int main() {
    COORD dims;
    char* input = calloc(250, sizeof(char));
    int maxElements;

    printf("START!\n");
    scanf("%[^\n]249s", input);

    dims.x = atoi(strtok(input, " "));
    dims.y = atoi(strtok(NULL, " "));
    unsigned int totalElements = dims.x * dims.y;
    printf("%d\n", totalElements);

    int* raw = calloc(totalElements, sizeof(int));

    for(int i = 0; i < totalElements; i++){
        raw[i] = atoi(strtok(NULL, " "));
    }

    for(int i = 0; i < totalElements; i++){
        printf("%d ", raw[i]);
    }

    printf("\n\nDone!\n");

}
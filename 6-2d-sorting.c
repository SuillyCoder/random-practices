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
    int row;
    int col;
} COORD;

void arrayDisp(int** arr, COORD dims){
    for (int i = 0; i < dims.row; i++){
        for(int j = 0; j < dims.col; j++){
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    COORD dims;
    char* input = calloc(250, sizeof(char));

    // user prompt
    printf("START!\n");
    scanf("%[^\n]249s", input);

    // dimensions of array: x by y grid
    dims.col = atoi(strtok(input, " "));
    dims.row = atoi(strtok(NULL, " "));
    int totalElements = dims.row * dims.col;
    // printf("%d\n", totalElements);

    // solution array
    int** solution = calloc(dims.row, sizeof(int*));
    for(int i = 0; i < dims.row; i++)
        solution[i] = calloc(dims.col, sizeof(int));

    // filling the array with user values
    for(int i = 0, x = 0, y = 0; i < totalElements; i++){
        
        if(x >= dims.col){
            x = 0;
            y++;
        }

        solution[y][x++] = atoi(strtok(NULL, " "));
    }

    // int* raw = calloc(totalElements, sizeof(int));

    // for(int i = 0; i < totalElements; i++){
    //     raw[i] = atoi(strtok(NULL, " "));
    // }

    // for(int i = 0; i < totalElements; i++){
    //     printf("%d ", raw[i]);
    // }

    // printf("\n\n I/O done!\n");

    arrayDisp(solution, dims);

    printf("\n\n display done!\n");
    

}
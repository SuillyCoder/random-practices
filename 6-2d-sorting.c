/*
self-imposed rules:
allowed external references
disabled copilot completions

v1
start:  13:38
break:  15:29
resume: 19:27
finish: 20:46 (3hr 10min)
polish: 21:12 (+26min)

limitations: no error handling

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// value of point Q at (x, y) -> foo[y][x]
typedef struct coord {
    int x, y;
} COORD;

// prints an x by y array
void arrayDisp(int** arr, COORD dims){
    for (int i = 0; i < dims.y; i++){
        for(int j = 0; j < dims.x; j++)
            printf("%2d ", arr[i][j]);

        printf("\n");
    }
    printf("\n");
}

// determines the next antidiagonal coordinate from the given coordinate
void nextCoord(COORD* curr, COORD dims){
    STEP:;
    curr->y++;
    curr->x--;

    WRAP:;
    // if x goes out of bounds, then step forward
    if(curr->x >= dims.x)
        goto STEP;

    // if y goes out of bounds or if x underflows to negative value, then wrap around
    else if((curr->y >= dims.y) || (curr->x < 0)){
        curr->x = curr->x + curr->y + 1;
        curr->y = 0;
        goto WRAP;
    }
}

// swaps addresses
void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    char* input = calloc(250, sizeof(char));
    COORD dims;

    // user prompt and input
    printf("Enter size of grid and values, separated by spaces\n");
    printf("Format:  x y n_1 n_2 ... n_(x * y)\n");
    printf("Example: 3 3 9 5 1 6 2 8 4 3 7\n");
    scanf("%[^\n]249s", input);
    printf("\n");

    // dimensions of array: x by y grid
    dims.x = atoi(strtok(input, " "));
    dims.y = atoi(strtok(NULL, " "));
    int totalElements = dims.x * dims.y;

    // declaration of solution array
    int** solution = calloc(dims.y, sizeof(int*));
    for(int i = 0; i < dims.y; i++)
        solution[i] = calloc(dims.x, sizeof(int));

    // filling the array with user values
    for(int i = 0, x = 0, y = 0; i < totalElements; i++){
        // if x goes out of bounds, then wrap
        if(x >= dims.x){
            x = 0;
            y++;
        }

        solution[y][x++] = atoi(strtok(NULL, " "));
    }

    // printing of unsorted array
    printf("Size of array: %d by %d\n", dims.x, dims.y);
    printf("Input array:\n");
    arrayDisp(solution, dims);

    // antidiagonal sorting, via selection sort
    COORD curr = {0, 0}; // current tail of sorted array
    for(int i = 0; i < totalElements - 2; i++){ // -2 because of min and item
        COORD min = {curr.x, curr.y}; // smallest in unsorted array
        COORD item = {curr.x, curr.y}; // for consideration

        // logs smallest in unsorted array
        for(int j = i + 1; j < totalElements ; j++){
            nextCoord(&item, dims);
            if (solution[min.y][min.x] > solution[item.y][item.x]){
                min.x = item.x;
                min.y = item.y;
            }
        }

        // swap smallest from tail of sorted array
        swap(&(solution[min.y][min.x]), &(solution[curr.y][curr.x]));

        // proceed to next tail
        nextCoord(&curr, dims);
    }

    // printing of sorted array
    printf("Output array:\n");
    arrayDisp(solution, dims);
}
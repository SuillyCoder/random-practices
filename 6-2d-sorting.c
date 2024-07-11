/*
self-imposed rules:
allowed external references
disabled copilot completions

v1
start:  13:38
break:  15:29
resume: 19:27
finish: 20:46
polish: 

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
        for(int j = 0; j < dims.x; j++){
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

// determines the next antidiagonal coordinate from the given coordinate
// returns and modifies the original
COORD nextCoord(COORD* curr, COORD dims){
    curr->y++;
    curr->x--;

    do {
        // if x goes out of bounds, then step forward
        if(curr->x >= dims.x){
            curr->y++;
            curr->x--;
            continue;
        }

        // if y goes out of bounds, then wrap around
        else if(curr->y >= dims.y){
            curr->x = curr->x + curr->y + 1;
            curr->y = 0;
            continue;
        }

        // if x underflows to negative value, then wrap around
        else if(curr->x < 0){
            curr->x = curr->y;
            curr->y = 0;
            continue;
        }

        // otherwise
        else return *curr;

    } while (1);
}

// swaps addresses
void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    COORD dims;
    char* input = calloc(250, sizeof(char));

    // user prompt
    printf("Enter size of grid and values, separated by spaces\n");
    printf("Format:  x y n_1 n_2 ... n_(x * y)\n");
    printf("Example: 3 3 9 5 1 6 2 8 4 3 7\n");
    scanf("%[^\n]249s", input);

    // dimensions of array: x by y grid
    dims.x = atoi(strtok(input, " "));
    dims.y = atoi(strtok(NULL, " "));
    int totalElements = dims.x * dims.y;

    // solution array
    int** solution = calloc(dims.y, sizeof(int*));
    for(int i = 0; i < dims.y; i++)
        solution[i] = calloc(dims.x, sizeof(int));

    // filling the array with user values
    for(int i = 0, x = 0, y = 0; i < totalElements; i++){
        if(x >= dims.x){
            x = 0;
            y++;
        }
    solution[y][x++] = atoi(strtok(NULL, " "));
    }

    arrayDisp(solution, dims);

    printf("\n\n display done!\n\n");

    // antidiagonal sorting, via selection sort
    COORD curr = {0, 0};
    for(int i = 0; i < totalElements - 2; i++){ // - 2 because of min and item
        COORD min = {curr.x, curr.y};
        COORD item = {curr.x, curr.y};

        for(int j = i + 1; j < totalElements ; j++){
            nextCoord(&item, dims);
            if (solution[min.y][min.x] > solution[item.y][item.x]){
                min.x = item.x;
                min.y = item.y;
            }
        }

        swap(&(solution[min.y][min.x]), &(solution[curr.y][curr.x]));
        nextCoord(&curr, dims);
    }

    arrayDisp(solution, dims);
    printf("\n\n Finished output!\n\n");
}
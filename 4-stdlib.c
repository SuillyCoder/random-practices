// started at 8:21PM
// finished at 9:21PM

// limitations:
// no error handling

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (){
    char *name = calloc(100, sizeof(char));
    int size;

    printf("Enter name: ");
    scanf("%[^\n]s", name);

    size = strlen(name);
    name = realloc(name, (size + 1) * sizeof(char));
    //printf("%s %d\n", full, strlen(full));
    
    char *full = calloc((size + 9), sizeof(char));
    char *single = calloc((size + 9), sizeof(char));
    char *middle = calloc((size + 9), sizeof(char));

    memset(full, '*', size + 8);
    //printf("%s %d\n", full, strlen(full));

    memset(single, '*', size + 8);
    memset(single + 1, ' ', size + 6);
    //printf("%s %d\n", single, strlen(single));

    memset(middle, '*', size + 8);
    memset(middle + 1, ' ', size + 6);
    strncpy(middle + 4, name, size);
    //printf("%s %d\n", middle, strlen(middle));

    puts(full);
    puts(single);
    puts(middle);
    puts(single);
    puts(full);
}
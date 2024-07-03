#include <stdio.h>
#include <math.h>

void main(){

    int num;
    printf("\e[38;2;255;0;0mEnter (positive) number: \e[m");
    scanf("%d", &num);
    printf("\n\n");

    int width = floor(log10(num) + 1);

    for (int i = num*-1; i <= num; i++){
        if (i == 0){
            i++;
            continue;
        }

        for (int j = num * -1; j <= num; j++){
            if (j == 0){
                j++;
                continue;
            }

            int x = abs(i) > abs(j) ? abs(i) : abs(j);
            printf("\e[1;%dm%*d\e[1;0m ", 31+(x%6), width, x);
        }

        printf("\n");
    }
}
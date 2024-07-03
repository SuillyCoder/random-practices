//prac 2 in c
//started at around 3:30 PM
//finished at around 5:20 PM

#include <stdio.h>

void main(){

    int numMonth, date, days;
    // word[] is x+1 as so the longest entries not overwrite '\0'
    char memMonth[] = "JanuaryFebruaryMarchAprilMayJuneJulyAugustSeptemberOctoberNovemberDecember", wordMonth[10];
    char memZodiac[] = "CapricornAquariusPiscesAriesTaurusGeminiCancerLeoVirgoLibraScorpioSagittarius", wordZodiac[12];

    // setting all values in word[] to \0
    for(int i = 0; i != 10; i++)
        wordMonth[i] = '\0';

    for(int i = 0; i != 12; i++)
        wordZodiac[i] = '\0';

    // gets input from user
    printf("Enter month: ");
    scanf("%d", &numMonth);
    printf("Enter day: ");
    scanf("%d", &date);

    // converts numeric month into the phrase month
    switch (numMonth){
        case 1: // January, length = 7, index from memMonth[] starts at 0
            for(int i = 0; i != 7; i++)
                wordMonth[i] = memMonth[i];
            break;

        case 2: // February, length = 8, index from memMonth[] starts at 7
            for(int i = 0; i != 8; i++)
                wordMonth[i] = memMonth[i + 7];
            break;

        case 3: // March, length = 5, index from memMonth[] starts at 15
            for(int i = 0; i != 5; i++)
                wordMonth[i] = memMonth[i + 15];
            break;

        case 4: // April, length = 5, index from memMonth[] starts at 20
            for(int i = 0; i != 5; i++)
                wordMonth[i] = memMonth[i + 20];
            break;

        case 5: // May, length = 3, index from memMonth[] starts at 25
            for(int i = 0; i != 3; i++)
                wordMonth[i] = memMonth[i + 25];
            break;

        case 6: // June, length = 4, index from memMonth[] starts at 28
            for(int i = 0; i != 4; i++)
                wordMonth[i] = memMonth[i + 28];
            break;

        case 7: // July, length = 5, index from memMonth[] starts at 32
            for(int i = 0; i != 5; i++)
                wordMonth[i] = memMonth[i + 32];
            break;

        case 8: // August, length = 6, index from memMonth[] starts at 36
            for(int i = 0; i != 6; i++)
                wordMonth[i] = memMonth[i + 36];
            break;

        case 9: // September, length = 9, index from memMonth[] starts at 42
            for(int i = 0; i != 9; i++)
                wordMonth[i] = memMonth[i + 42];
            break;

        case 10: // October, length = 7, index from memMonth[] starts at 51
            for(int i = 0; i != 7; i++)
                wordMonth[i] = memMonth[i + 51];
            break;

        case 11: // November, length = 8, index from memMonth[] starts at 58
            for(int i = 0; i != 8; i++)
                wordMonth[i] = memMonth[i + 58];
            break;

        default: // December, length = 8, index from memMonth[] starts at 66
            for(int i = 0; i != 8; i++)
                wordMonth[i] = memMonth[i + 66];
            break;
    }

    // converts MM/DD into a day on the year
    // Dec 22 = 374
    days = ((numMonth - 1) * 32 + date) % 374;

    // calculates the zodiac sign from the ranges provided
    if (days <= 19)                     // Jan 19 = 19
        for(int i = 0; i != 9; i++)     // Capricorn, length = 9, index from memZodiac[] starts at 0
            wordZodiac[i] = memZodiac[i];
    
    else if (days <= 50)                // Feb 18 = 50
        for(int i = 0; i != 8; i++)     // Aquarius, length = 8, index from memZodiac[] starts at 9
            wordZodiac[i] = memZodiac[i + 9];
    
    else if (days <= 84)                // Mar 20 = 84
        for(int i = 0; i != 6; i++)     // Pisces, length = 6, index from memZodiac[] starts at 17
            wordZodiac[i] = memZodiac[i + 17];
    
    else if (days <= 115)               // Apr 19 = 115
        for(int i = 0; i != 5; i++)     // Aries, length = 5, index from memZodiac[] starts at 23
            wordZodiac[i] = memZodiac[i + 23];

    else if (days <= 148)               // May 20 = 148
        for(int i = 0; i != 6; i++)     // Taurus, length = 6, index from memZodiac[] starts at 28
            wordZodiac[i] = memZodiac[i + 28];
    
    else if (days <= 180)               // Jun 20 = 180
        for(int i = 0; i != 6; i++)     // Gemini, length = 6, index from memZodiac[] starts at 34
            wordZodiac[i] = memZodiac[i + 34];

    else if (days <= 214)               // Jul 22 = 214
        for(int i = 0; i != 6; i++)     // Cancer, length = 6, index from memZodiac[] starts at 40
            wordZodiac[i] = memZodiac[i + 40];

    else if (days <= 246)               // Aug 22 = 246
        for(int i = 0; i != 3; i++)     // Leo, length = 3, index from memZodiac[] starts at 46
            wordZodiac[i] = memZodiac[i + 46];

    else if (days <= 278)               // Sep 22 = 278
        for(int i = 0; i != 5; i++)     // Virgo, length = 5, index from memZodiac[] starts at 49
            wordZodiac[i] = memZodiac[i + 49];

    else if (days <= 310)               // Oct 22 = 310
        for(int i = 0; i != 5; i++)     // Libra, length = 5, index from memZodiac[] starts at 54
            wordZodiac[i] = memZodiac[i + 54];

    else if (days <= 341)               // Nov 21 = 341
        for(int i = 0; i != 7; i++)     // Scorpio, length = 7, index from memZodiac[] starts at 59
            wordZodiac[i] = memZodiac[i + 59];

    else                                // Nov 22 to Dec 21, Dec 22 to Dec 31 is handled by % 374
        for(int i = 0; i != 11; i++)     // Sagittarius, length = 11, index from memZodiac[] starts at 66
            wordZodiac[i] = memZodiac[i + 66];

    // prints the horoscope information
    printf("Zodiac sign for %s %d is %s\n", wordMonth, date, wordZodiac);

}


#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char entry;
    int value;
} Dict;

Dict HexTable[] = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15},
};

int getValue(char entry){
    int i;

    for (i = 0; i < sizeof(HexTable) / sizeof(HexTable[0]); i++) {
        if (HexTable[i].entry == toupper(entry)) {
            return HexTable[i].value;
        }
    }
    // If the entry is not found, you might want to return some default value.
    return -1;
}

int main(int argc, char *argv[]){
    int i;
    int total = 0;
    if(argc < 2){
        printf("\n\n[✗] Missing hex string: %s <hex_value>\n\n\n", argv[0]);
        return -1;
    }

    // Check if the first 2 letters are 0x
    if(argv[1][0] == '0' && toupper(argv[1][1]) == 'X'){
        argv[1]+= 2;
        printf("arg %s", argv[1]);
    }

    // Check if last char is h
    if (argv[1][strlen(argv[1]) - 1] == 'h'){
        argv[1][strlen(argv[1]) - 1 ] = '\0';
    }

    // We loop throught each char of the param
    int size = strlen(argv[1]);

    for (i = 0; i < size ; i ++){
        if(getValue(argv[1][i]) == -1){
            printf("\n\n[✗] Invalid hexadecimal character: %c \n\n\n", argv[1][i]);
            return -2;
        }
        total += getValue(argv[1][i]) * pow(16, (size - i - 1));
    }

    printf("\n\n\nDecimal value: %d\n\n\n", total);

    return 0;
}
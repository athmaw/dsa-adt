#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//write the code of the function that will display the bit-pattern
//of a given integer. 
//Note: 
// 1. use bit manipulation operators if applicable. 
// 2. the code should be platform independent. [hint: use sizeof 
//operator to determine the no of bits representing the integer variable. 
// 3. no array should be used in this function.]

void displayBitPattern(int num) {
    int i, numBits = sizeof(num) * 8;

    for(i = numBits - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;

        printf("%d", bit);
    }
    printf("\n");
}

int main() {

    int num = ~65;
    displayBitPattern(num);

    return 0;
}

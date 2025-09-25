#include <stdio.h>

//write the code of the function findFourth that
//will return 1 if the 4th bit from the right is 1,
//otherwise, return 0

// 0 0 0 0 1 0 0 0 = 8 -> findFourth returns 1
// 0 0 0 0 0 1 0 0 = 4 -> findFourth returns 0
int findFourth(char val) {
    return (val >> 3) & 1;
}

//write the function displayBit that will display
//the bit pattern of the given value
void displayBit(char val) {
    int bits = sizeof(char) * 8;
    unsigned int mask = 1 << (bits - 1);

    while (mask != 0) {
        printf("%d ", (val & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
}

int main() {
    
    printf("%d\n", findFourth(8));
    printf("%d\n", findFourth(4));
    displayBit(8);
    displayBit(4);
    
    return 0;
}
#include <stdio.h>

int main() {

    int x = 10;
    int y = -16;
    int a = 127;
    int b = -20;
    int c = 100;
    int d = 3;
    
    int result = c >> d; // result = 12
    //int result = b >> 2; // result = -5
    //int result = a << 1; // result = 254
    //int result = y >> 3; // result = -2
    //int result = x << 2; // result = 40

    printf("result: %d", result);

    return 0;
}
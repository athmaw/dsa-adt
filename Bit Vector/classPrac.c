//1. using a char element holding
//an int value
//2. using bit fields inside struct
#include <stdio.h>
#define MAX 20

typedef struct {
    unsigned int : MAX;
} Set;

//3. using an enum
typedef enum {true, false} Boolean;
typedef Boolean Set[MAX];
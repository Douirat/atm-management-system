#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include "header.h"


int HashedValue(char* Key) {
    unsigned long int hashVal = 0;
    int i = 0;
    while(hashVal < LONG_MAX && i < strlen(Key)) {
        hashVal += Key[i] << 8;
        i++;
    }
    return (int)(hashVal % SIZE);
}
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

// Instantiate a new user:
User* NewUser() {
    User *user = (User*)malloc(sizeof(User));
    if (!user) {
        printf("The memmory allocation for a new user has failed\n");
        exit(1);
    }
    return user;
}

// Instantiate a new Record:
Record* NewRecord() {
    Record* record = (Record*)malloc(sizeof(Record));
    if(!record) {
        printf("The memmory allocation for a new record has failed!!!\n");
        exit(1);
    }
    return record;
}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "header.h"
#define MAX 20

// Instantiate a new user:
User *NewUser() {
    User* user = (User*)malloc(sizeof(User));
    if (!user){
        printf("The memmory allocation for a new user has failed!\n"); 
        exit(1);
    }
    printf("Enter your id:\n");
    scanf("Your id: %d",&user->Id);
    // user->Id = id;
    printf("Your user name");
    char userName[MAX];
    scanf("Enter you user name:", &userName);
    strcpy(user->UserName, userName);

    printf("Enter your password: \n");
    char password[MAX];
    scanf("Enter your passsword her:", &password);
    strcpy(user->Password, password);
    
    return user;
}

// Instantiate a new record:
Record* NewRecord(int id, int userId, char userName[50], int acountId, char date[10], char country[60], int phone, float balance, char accountType[10]) {
    Record* record = (Record*) malloc(sizeof(Record));
    if (!record) {
        printf("The memory allocation for a new record has failed\n");
        exit(1);
    }
    record->Id = id;
    record->UserId = userId;
    strcpy(record->UserName, userName);
    record->acountId = acountId;
    strcpy(record->DateOfCreation, date);
    strcpy(record->Country, country);
    record->Phone = phone;
    record->Balance = balance;
    strcpy(record->AcountType, accountType);
    return record;
}


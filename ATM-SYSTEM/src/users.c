#include <stdio.h>
#include "header.h"

// Instantiate a new user:
User *NewUser(int id, char *userName, char *password)
{
    User *user = (User *)malloc(sizeof(User));
    if (!user)
    {
        printf("The memmory allocation for a new user has failed\n");
        exit(1);
    }
    user->Id = id;
    strcpy(user->UserName, userName);
    strcpy(user->Password, password);
    user->next = user->Previous = NULL;
    return user;
}
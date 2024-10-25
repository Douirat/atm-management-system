#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

// Instantiate a new user:
User *NewUser(int id, char *userName, char *password)
{
    User *user = (User *)malloc(sizeof(User));
    if (!user)
    {
        printf("The memmory allocation for a new user has failed!!!");
        exit(1);
    }
    user->Id = id;
    strcpy(user->UserName, userName);
    strcpy(user->Password, password);
    user->Acounts = NULL;
    user->Next = NULL;
    return user;
}

// Instantiate my hash table:
Users *NewUsersTable()
{
    Users *table = (Users *)malloc(sizeof(Users));
    if (!table)
    {
        printf("The memmory allocation for a new hash table has failed!!!");
        exit(1);
    }
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->HashedUsers[i] = NULL;
    }
    return table;
}

// Function to simulate user authentication
int HashedIndex(char *key)
{
    unsigned long int val = 0;
    int i = 0;
    while (val < LONG_MAX, i < strlen(key))
    {
        val += key[i] << 8;
        i++;
    }
    printf("The index is: %ld\n", val % TABLE_SIZE);
    return val % TABLE_SIZE;
}

// Insert a new user in the hah table:
void InsertNewUser(User **Node, User *user)
{
    if ((*Node) != NULL && UserExists((*Node)->UserName, user->UserName))
    {
        printf("Oops user already exists\n");
        exit(1);
    }
    if ((*Node) == NULL)
    {
        *Node = user;
        return;
    }
    else if ((*Node)->Next == NULL)
    {
        (*Node)->Next = user;
        return;
    }
    InsertNewUser(&(*Node)->Next, user);
}

// Check if the user already exists:
bool UserExists(char *input, char *userName)
{
    for (int i = 0; i < strlen(userName); i++)
    {
        if (userName[i] != input[i])
        {
            return false;
        }
    }
    return true;
}

// => Here i will apply all the CRUD operations:
// Apply the insertion:
void Insertion(Users *table, int id, char *userName, char *password)
{
    User *user = NewUser(id, userName, password);
    InsertNewUser(&table->HashedUsers[HashedIndex(userName)], user);
}

// Create a new acount:
void AcountCreation(Users *table, char *userName, int acountId, char *date, char *country, int acountNumber, float balance, char *acountType)
{
    Acount *acount = NewAcount(acountId, date, country, acountNumber, balance, acountType);
    CreateAcount(&table->HashedUsers[HashedIndex(userName)]->Acounts, acount);
}

// Display All the acounts that are :
void DisplayUserAcounts(Users *table, char *userName)
{
    DisplayAcounts(table->HashedUsers[HashedIndex(userName)]->Acounts);
}

// Delete a specific acount based on its id:
void AcountDeletion(Users* table, char *userName, int acountId)
{
    DeleteAcount(&table->HashedUsers[HashedIndex(userName)]->Acounts, acountId);
}

// A check function to display all users:
void DisplayUsers(User* Node) {
    if(Node == NULL) {
        return;
    }
     printf("The user id is: %d, his user name is %s and his password is: %s \n", Node->Id, Node->UserName, Node->Password);
     DisplayUsers(Node->Next);
}
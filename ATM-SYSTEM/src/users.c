#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"
#include <unistd.h>
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
    user->UserName = malloc(strlen(userName) + 1);
    strcpy(user->UserName, userName);
    user->Password = malloc(strlen(password) + 1);
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
    return val % TABLE_SIZE;
}

// Insert a new user in the hah table:
void InsertNewUser(User **Node, User *user)
{
    if ((*Node) == NULL)
    {
        *Node = user;
        return;
    }

    User *Prev = NULL;
    User *Current = (*Node);
    while (Current != NULL)
    {
        if (strcmp(user->UserName, Current->UserName) == 0)
        {
            printf("The user %s is the same as user %s\n", user->UserName, Current->UserName);
            printf("Oops user already exists or \n");
            exit(1);
        }
        Prev = Current;
        Current = Current->Next;
    }
    Prev->Next = user;
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
void AcountCreation(Users *table, char *userName, int acountId, char *date, char *country, char* phone, int acountNumber, float balance, char *acountType)
{
    User *logedIn = LogedUser(table->HashedUsers[HashedIndex(userName)], userName);
     printf("The user name is%s\n", logedIn->UserName);
    Acount *acount = NewAcount(acountId, date, country, phone, acountNumber, balance, acountType);
    // CreateAcount(&table->HashedUsers[HashedIndex(userName)]->Acounts, acount);
    if (logedIn->Acounts == NULL) {
        logedIn->Acounts = acount;
        return;
    }
    Acount* Temp = logedIn->Acounts;
    while(Temp->Next != NULL) {
        Temp = Temp->Next;
    }
    Temp->Next = acount;
}

// Display All the acounts that are :
void DisplayUserAcounts(Users *table, char *userName)
{
    printf("\n\n      ------------------->> [[ ... Here is a list of all your acounts mrs %s ... ]] <-------------------\n\n", userName);
    DisplayAcounts(table->HashedUsers[HashedIndex(userName)]->Acounts);
}

// Delete a specific acount based on its id:
void AcountDeletion(Users *table, char *userName, int acountId)
{
    DeleteAcount(&table->HashedUsers[HashedIndex(userName)]->Acounts, acountId);
}

// A check function to display all users:
void DisplayUsers(User *Node)
{
    if (Node == NULL)
    {
        return;
    }
    printf("The user id is: %d, his user name is %s and his password is: %s \n", Node->Id, Node->UserName, Node->Password);
    DisplayAcounts(Node->Acounts);
    DisplayUsers(Node->Next);
}

// Bring a pointer to the loged user:
User *LogedUser(User *Node, char *userName)
{
    if (Node == NULL)
    {
        return NULL;
    }
    if (strcmp(Node->UserName, userName) == 0)
    {
        return Node;
    }
    return LogedUser(Node->Next, userName);
}

// Search for a users in an other form login:
void Login(Users *table)
{
    system("clear");
    char userName[50];
    char password[20];
    printf("\n\n------------------------------> [ ... Login ... ] <------------------------------\n\n");
    printf("Enter your user name: ");
    scanf("%s", userName);

    printf("your user name is: %s\n", userName);
    User *logedUser = LogedUser(table->HashedUsers[HashedIndex(userName)], userName);
    if (logedUser == NULL)
    {
        printf("             ---------------> User does'nt exist!!!! <---------------\n\n");
        exit(1);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Enter your password: ");
        scanf("%s", password);
        printf("Your password is: %s\n", password);
        if (strcmp(logedUser->Password, password) == 0)
        {
            printf("Connecting...\n");
            sleep(3);
            ProfileMenu(table, logedUser);
            break;
        }
        printf("You only have three chances!!!\n");
        sleep(3);
    }
}

// Search for a user:
User *SearchUser(User *Node, char *pattern)
{
    if (Node == NULL)
    {
        printf("User does'nt exist!!!\n");
        exit(1);
    }
    if (strcmp(Node->UserName, pattern) == 0)
    {
        return Node;
    }
    return SearchUser(Node->Next, pattern);
}
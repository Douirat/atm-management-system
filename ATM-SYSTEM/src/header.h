#include <stdbool.h>
#ifndef ATM
#define ATM

// Declare a global variable to hold the siof my table
#define TABLE_SIZE 20

// Declare the acount object:
typedef struct Acount
{
    int AcountId;
    char CreationDate[11];
    char Country[50];
    int AcountNumber;
    float Balance;
    char AcountType[11];
    struct Acount* Next;
} Acount;

// Declare a user struct:
typedef struct User
{
    int Id;
    char UserName[50];
    char Password[20];
    Acount* Acounts;
    struct User *Next;
} User;

// Daclare the users hash table to make efficient operations on memmory:
typedef struct Users
{
    // unsigned int Edges; // The number ofelements inserted in the hash table to keep track of the load factor:
    User *HashedUsers[TABLE_SIZE];
} Users;

// Invite the logic related to the user to the scope:
Users *NewUsersTable();
User *NewUser();
int HashedIndex(char *key);
void InsertNewUser(User **Node, User *user);
void Insertion(Users *table, int id, char *userName, char *password);
bool UserExists(char *input, char *userName);
void DisplayUserAcounts(Users* table, char* userName);
void AcountDeletion(Users* table, char *userName, int acountId);


// Invite the logic related to the acount to the scope:
Acount *NewAcount(int acountId, char *date, char *country, int acountNumber, float balance, char *acountType);
void CreateAcount(Acount** Node, Acount* newAcount);
void AcountCreation(Users* table, char* userName, int acountId, char *date, char *country, int acountNumber, float balance, char *acountType);
void DisplayAcounts(Acount* Node);
void DeleteAcount(Acount **Node, int id);
void CreateNewAcount(Users *table, User* Profile);

// Clling the system functionalies to the scope:
void InitialMenu();
void ProfileMenu(Users* table, User *Profile);
#endif // !ATM
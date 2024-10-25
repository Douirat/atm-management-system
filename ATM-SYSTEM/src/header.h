#include <stdbool.h>
#ifndef ATM
#define ATM

// Declare a global variable to hold the siof my table
#define TABLE_SIZE 100
// Declare filePointer as an extern variable. This tells the compiler that the variable exists but will be defined in one of the source files
extern FILE *filePointer;

// Declare the acount object:
typedef struct Acount
{
    int AcountId;
    char CreationDate[11];
    char Country[50];
    int AcountNumber;
    float Balance;
    char AcountType[11];
    struct Acount *Next;
} Acount;

// Declare a user struct:
typedef struct User
{
    int Id;
    char UserName[50];
    char Password[20];
    Acount *Acounts;
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
void DisplayUserAcounts(Users *table, char *userName);
void AcountDeletion(Users *table, char *userName, int acountId);
void DisplayUsers(User* Node);


// Invite the logic related to the acount to the scope:
Acount *NewAcount(int acountId, char *date, char *country, int acountNumber, float balance, char *acountType);
void CreateAcount(Acount **Node, Acount *newAcount);
void AcountCreation(Users *table, char *userName, int acountId, char *date, char *country, int acountNumber, float balance, char *acountType);
void DisplayAcounts(Acount *Node);
void DeleteAcount(Acount **Node, int id);
void CreateNewAcount(Users *table, User *Profile);
void AcountsWriter(Users *table, User *Profile);

// Calling the system functionalies to the scope:
void InitialMenu();
void ProfileMenu(Users *table, User *Profile);
void UserRegistration(Users* table);

// The logic related to the file out/in=>puts:
void WritingToFile(const char *filePath,const char *mode, const char *string);
char* ReadFile(const char *filePath);
void AppendAcount(User *user, Acount *Node);
void AppendNewUser(User *user);
Users * ExtractUsers();
void ExtractAcounts();

// Authentification and validation and helper methods:
int Atoi(const char *str);
char *Itoa(int num);
float Atof(char *str);
char* Ftoa(float fl);

#endif // !ATM
#include <stdbool.h>
#ifndef ATM
#define ATM

// Declare a global variable to hold the siof my table
#define TABLE_SIZE 20
// Declare filePointer as an extern variable. This tells the compiler that the variable exists but will be defined in one of the source files
extern FILE *filePointer;

// Declare the acount object:
typedef struct Acount
{
    int AcountId;
    char *CreationDate;
    char *Country;
    char *Phone;
    int AcountNumber;
    float Balance;
    char *AcountType;
    struct Acount *Next;
} Acount;

// Declare a user struct:
typedef struct User
{
    int Id;
    char *UserName;
    char *Password;
    Acount *Acounts;
    struct User *Next;
} User;

// Daclare the users hash table to make efficient operations on memmory:
typedef struct Users
{
    // unsigned int Edges; // The number ofelements inserted in the hash table to keep track of the load factor:
    User *HashedUsers[TABLE_SIZE];
} Users;


// The main function:
int main();

// Invite the logic related to the user to the scope:
Users *NewUsersTable();
User *NewUser();
int HashedIndex(char *key);
void InsertNewUser(User **Node, User *user);
void Insertion(Users *table, int id, char *userName, char *password);
bool UserExists(char *input, char *userName);
void AcountDeletion(Users *table, char *userName, int acountId);
void DisplayUsers(User *Node);
void Login(Users *table);
User *LogedUser(User *Node, char *userName);
User *SearchUser(User *Node, char *pattern);

// Invite the logic related to the acount to the scope:
Acount *NewAcount(int acountId, char *date, char *country, char *phone, int acountNumber, float balance, char *acountType);
void CreateAcount(Acount **Node, Acount *newAcount);
void AcountCreation(Users *table, char *userName, int acountId, char *date, char *country, char *phone, int acountNumber, float balance, char *acountType);
void DisplayAcounts(Acount *Node);
bool DeleteAcount(Acount **Node, int id); // This is the function helper for deletinh an acount:
void CreateNewAcount(Users *table, User *Profile);
void CheckUserAcounts(Users *table, User *Profile);
void DeleteAcountById(Users *table, User* Profile);
void UpdateAcount(Users *table, User* Profile);
void MakeTransaction(Users* table, User* Profile);
Acount *ChosenAcount(Acount **Node, int number);
void CheckAcountDetails(Users* table, User* Profile);
void TransferOwnership(Users* table, User* Profile);

// Calling the system functionalies to the scope:
void InitialMenu(Users *table);
void ProfileMenu(Users *table, User *Profile);
void UserRegistration(Users *table);

// The logic related to the file out/in=>puts:
void WritingToFile(const char *filePath, const char *mode, const char *string);
char *ReadFile(const char *filePath);
void AppendAcount(User *user, Acount *Node);
void AppendNewUser(User *user, char* userName);
Users *ExtractUsers();
Users *ExtractAcounts(Users **table);

// Authentification and validation and helper methods:
int Atoi(const char *str);
char *Itoa(int num);
float Atof(char *str);
char *Ftoa(float fl);
bool ValidCredentials(Users *table, int id, char* userName);
bool ValidAccountId(Acount* account, int id);
bool ValidAccountDate(Acount *account, char *date);
bool ValidPhone(Acount *account, char *phone);
bool ValidAccountNumber(Acount *account, int number);
bool ValidType(char *type);

#endif // !ATM
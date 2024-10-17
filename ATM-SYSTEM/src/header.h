#ifndef ATM
#define ATM

// Declare a global instance of the file:


//Declare a user struct:
typedef struct {
int Id;
char UserName[50];
char Password[20];
}User;

// Declare a Record object:
typedef struct 
{
    int Id;
    int UserId;
    char UserName[50];
    int acountId;
    char DateOfCreation[10];
    char Country[60];
    int Phone;
    float Balance;
    char AcountType;
}Record;

// Authentification functions:
User* NewUser();


// System functions:
void FileWriter();

#endif // !ATM

#ifndef ATM
#define ATM

// Declare a global variable and assign it the size of the hash table:
#define SIZE 20

// Declare the 
typedef struct User {
    int Id;
    char UserName[20];  // Fixed-length character array for the username
    char Password[20];  // Fixed-length character array for the password
    struct User* next;  // Correct forward declaration for pointers to the same type
    struct User* Previous;
} User;


// invite my the functions related the user structure to the scope:
User *NewUser(int id, char *userName, char *password);
int HashedValue(char* Key);
#endif
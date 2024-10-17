#include <stdio.h>
#include "header.h"



int main() {
    User *newUser = NewUser();
    printf("The user'id is %d and his full name is %s and the passwrd is: %s\n", newUser->Id, newUser->UserName, newUser->Password);

    // FileWriter("Test the availability of my func!!!\n");
    return 0;
}
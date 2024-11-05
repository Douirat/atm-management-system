#include <stdio.h>
#include "header.h" // Include the header file



int main()
{
    Users *usersTable = ExtractUsers(usersTable);
    usersTable = ExtractAcounts(&usersTable);
    InitialMenu(usersTable);
    return 0;
}

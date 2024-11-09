#include <stdio.h>
#include "header.h" // Include the header file



int main()
{
    Users *usersTable = ExtractUsers(usersTable);
    usersTable = ExtractAcounts(&usersTable);
    InitialMenu(usersTable);
    // char *date = "31/13/1111";
    // ValidAccountDate(usersTable->HashedUsers[12]->Acounts, date);
    return 0;
}

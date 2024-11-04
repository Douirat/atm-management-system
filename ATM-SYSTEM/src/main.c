#include <stdio.h>
#include "header.h" // Include the header file



int main()
{
    Users *usersTable = ExtractUsers(usersTable);
    usersTable = ExtractAcounts(&usersTable);
    // InitialMenu(usersTable);
    User * U = LogedUser(usersTable->HashedUsers[HashedIndex("JackRack")], "JackRack");
    CheckAcountDetails(usersTable, U);
    return 0;
}

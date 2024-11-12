#include <stdio.h>
#include "header.h" // Include the header file



int main()
{
    Users *usersTable = ExtractUsers(usersTable);
    usersTable = ExtractAcounts(&usersTable);
    // InitialMenu(usersTable);
    User* u = LogedUser(usersTable->HashedUsers[HashedIndex("AnnaBella")], "AnnaBella");
    DeleteAcount(&u->Acounts, 11);
    return 0;
}

#include <stdio.h>
#include "header.h" // Include the header file

int main()
{
    Users *usersTable = ExtractUsers(usersTable);
    usersTable = ExtractAcounts(&usersTable);
    // InitialMenu(usersTable);

    UpdateAcount(usersTable, SearchUser(usersTable->HashedUsers[HashedIndex("BenDoe")], "BenDoe"));
    for(int i=0; i<TABLE_SIZE; i++ ){
        DisplayUsers(usersTable->HashedUsers[i]);
    }
    return 0;
}
 
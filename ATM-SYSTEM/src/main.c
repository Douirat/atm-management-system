#include <stdio.h>
// #include <stdbool.h>
#include "header.h" // Include the header file

int main()
{

    Users *usersTable = ExtractUsers(usersTable);
    usersTable = ExtractAcounts(&usersTable);


    // for (int i = 0; i < TABLE_SIZE; i++)
    // {
    //     if (usersTable->HashedUsers[i] != NULL)
    //     {
    //         printf("\nThe users at index %d is: \n", i);
    //          DisplayUserAcounts(usersTable, usersTable->HashedUsers[i]->UserName);
    //     }
    // }



    // printf("The user id is: %d, his user name is %s and his password is: %s\n", usersTable->HashedUsers[8]->Id, usersTable->HashedUsers[8]->UserName, usersTable->HashedUsers[8]->Password);
    // printf("The user id is: %d, his user name is %s and his password is: %s\n", usersTable->HashedUsers[12]->Id, usersTable->HashedUsers[12]->UserName, usersTable->HashedUsers[12]->Password);
    // printf("The user id is: %d, his user name is %s and his password is: %s\n", usersTable->HashedUsers[4]->Id, usersTable->HashedUsers[4]->UserName, usersTable->HashedUsers[4]->Password);
    // Acount *acount = NewAcount(1, "01/02/2023", "Morroco", 123456789, 356456.568, "Saving");
    // printf("The acount id is %d, %s, %s, %d, %f, %s\n",acount->AcountId, acount->CreationDate, acount->Country, acount->AcountNumber, acount->Balance, acount->AcountType);
    // bool check = UserExists("Ben", "Ben");


    // printf("%d", check);
    // AcountDeletion(usersTable, "BenDoe", 789);
    // InitialMenu();
    // ProfileMenu(usersTable, usersTable->HashedUsers[HashedIndex("BenDoe")]);
    // UserRegistration(usersTable);


    InitialMenu(usersTable);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <syscall.h>
#include "header.h"

// Declare the home page menu function:
void InitialMenu()
{
    int Option;
    system("clear");
    printf("\n\n    =================================== << >> {{ ATM }} << >> =================================== \n");
    printf("    --------->> Wellcome in your Bank please log in or register if you are a new User <<---------\n");
    printf("\n\t\t[1]- login\n");
    printf("\n\t\t[2]- register\n");
    printf("\n\t\t[3]- exit\n\n");
    printf("    --------->> Please enter your choise 1, 2 or 3 here: ");
    scanf("%d", &Option);

    switch (Option)
    {
    case 1:
        printf("The user want to login\n");
        //  ProfileMenu(usersTable, usersTable->HashedUsers[HashedIndex("BenDoe")]);
        break;
    case 2:
        printf("The user wants to register\n");

        break;
    case 3:
        printf("The user want to exit\n");

        break;
    default:
        printf("Please enter a valid choice!\n");
        return;
    }
}

// Declare the profile menu:
void ProfileMenu(Users *table, User *Profile)
{
    system("clear");
    int Option;
    printf("\n\n    =================================== << >> {{ ATM }} << >> =================================== \n");
    printf("\n   -------------------->> Hello again mr %s How can we assist you today <<--------------------\n", Profile->UserName);
    printf("\n\t\t[1]- Create a new account\n");
    printf("\n\t\t[2]- Update account information\n");
    printf("\n\t\t[3]- Check existing accounts\n");
    printf("\n\t\t[4]- Make Transaction\n");
    printf("\n\t\t[5]- Remove existing account\n");
    printf("\n\t\t[6]- Transfer ownership\n");
    printf("\n\t\t[7]- Exit\n\n");
    printf("Pleaser enter your choice here: \n");
    scanf("%d", &Option);

    switch (Option)
    {
    case 1:
        printf("The user wants to create a new acount\n");
        CreateNewAcount(table, Profile);
        return;
    case 2:
        printf("The user wants to update his acounts\n");
        return;
    case 3:
        printf("The user wants to all his acounts:\n");
        return;
    case 4:
        printf("The user wants to make a transaction:\n");
        return;
    case 5:
        printf("The user wants to Delete an acount\n");
        return;
    case 6:
        printf("The user wants to transfer ownership\n");
        return;
    case 7:
        printf("The user wants to delete his acount\n");
        return;
    }
}
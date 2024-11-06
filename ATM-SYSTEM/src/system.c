#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <syscall.h>
#include <unistd.h>
#include "header.h"

// Declare the home page menu function:
void InitialMenu(Users *table)
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
        Login(table);
        break;
    case 2:
        printf("The user wants to register\n");
        UserRegistration(table);
        break;
    case 3:
        printf("Loging out....\n");
        sleep(3);
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
    printf("\n\t\t[4]- Check the details of owned accounts:\n");
    printf("\n\t\t[5]- Make Transaction\n");
    printf("\n\t\t[6]- Remove existing account\n");
    printf("\n\t\t[7]- Transfer ownership\n");
    printf("\n\t\t[8]- Exit\n\n");
    printf("-------------> Pleaser enter your choice: \n        --------> Here: ");
    scanf("%d", &Option);

    switch (Option)
    {
    case 1:
        CreateNewAcount(table, Profile);
        return;
    case 2:
        UpdateAcount(table, Profile);
        return;
    case 3:
        CheckUserAcounts(table, Profile);
        return;
    case 4:
        CheckAcountDetails(table, Profile);
        return;
    case 5:
        MakeTransaction(table, Profile);
        return;
    case 6:
        DeleteAcountById(table, Profile);
        return;
    case 7:
        TransferOwnership(table, Profile);
        return;
    case 8:
        printf("The user wants to log out!!!\n");
        return;
    }
}

// Handle a new user registration:
void UserRegistration(Users *table)
{
    int id;
    char userName[50];
    char password[20];
    system("clear");
    printf("\n\n-------------------------> [ ... Registration ... ] <-------------------------\n\n");
    printf("Enter a valid id: ");
    scanf("%d", &id);
    printf("Enter your user name: ");
    scanf("%s", userName);
    printf("Enter your password: ");
    scanf("%s", password);
    Insertion(table, id, userName, password);
    AppendNewUser(table->HashedUsers[HashedIndex(userName)], userName);
    Login(table);
}

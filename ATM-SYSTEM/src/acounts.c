#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

// Instantiate a new Acount:
Acount *NewAcount(int acountId, char *date, char *country, int acountNumber, float balance, char *acountType)
{
    Acount *acount = (Acount *)malloc(sizeof(Acount));
    if (!acount)
    {
        printf("The memmory allocation for a new acount has failed!!!");
        exit(1);
    }
    acount->AcountId = acountId;
    acount->CreationDate = malloc(strlen(date));
    strcpy(acount->CreationDate, date);
    acount->Country = malloc(strlen(country));
    strcpy(acount->Country, country);
    acount->AcountNumber = acountNumber;
    acount->Balance = balance;
    acount->AcountType = malloc(strlen(acountType));
    strcpy(acount->AcountType, acountType);
    acount->Next = NULL;
    return acount;
}

// When the User Creates an acount an insertion happens:
void CreateAcount(Acount **Node, Acount *newAcount)
{
    if ((*Node) == NULL)
    {
        (*Node) = newAcount;
        return;
    }
    else if ((*Node)->Next == NULL)
    {
        (*Node)->Next = newAcount;
        return;
    }
    CreateAcount(&(*Node)->Next, newAcount);
}

// Display all the acounts of a specific user:
void DisplayAcounts(Acount *Node)
{
    if (Node == NULL)
    {
        printf("No acounts to show!!");
        return;
    }

    printf("                  ----------------------->> ... <<-----------------------\n\n");
    printf("                     -----> Acount id: %d\n", Node->AcountId);
    printf("                     -----> Creation Date: %s\n", Node->CreationDate);
    printf("                     -----> The country: %s\n", Node->Country);
    printf("                     -----> Acount Number: %d\n", Node->AcountNumber);
    printf("                     -----> Balance: $%f\n", Node->Balance);
    printf("                     -----> Acount type: %s\n\n", Node->AcountType);
    DisplayAcounts(Node->Next);
}

// Deleting a specific acount based on its id:
void DeleteAcount(Acount **Node, int id)
{
    if ((*Node) == NULL)
    {
        printf("Acount not found!!!");
        return;
    }
    else if ((*Node)->AcountId == id)
    {
        (*Node) = (*Node)->Next;
        return;
    }
    else if ((*Node)->Next->AcountId == id && (*Node)->Next != NULL)
    {
        (*Node)->Next = (*Node)->Next->Next;
        return;
    }
    else if ((*Node)->Next == NULL)
    {
        printf("Acount not found!!!");
        return;
    }
    DeleteAcount(&(*Node)->Next, id);
}

void CreateNewAcount(Users *table, User *Profile)
{
    int acountId;
    char date[11];
    char country[50];
    int acountNumber;
    float balance;
    char acountType[10];

    printf("\nEnter the acount id:");
    scanf("%d", &acountId);
    printf("\nEnter creation data in this form: 11/11/1111: ");
    scanf("%s", date);
    printf("\nEnter your country name: ");
    scanf("%s", country);
    printf("\nEnter your acount number:");
    scanf("%d", &acountNumber);
    printf("\nEnter your the amount you want to deposit:");
    scanf("%f", &balance);
    printf("\n         ------> Choose a type: ");
    printf("\n              -> Saving:");
    printf("\n              -> Current:");
    printf("\n              -> Fixed01: (for 1 year)");
    printf("\n              -> Fixed02: (for 2 year)");
    printf("\n              -> Fixed03: (for 3 year)");
    printf("\n         ------> Enter the acount type: ");
    scanf("%s", acountType);

    AcountCreation(table, Profile->UserName, acountId, date, country, acountNumber, balance, acountType);
    AcountsWriter(table, "a", Profile);
}

// The handler of inserting a new acount in the file:
void AcountsWriter(Users *table, char *mode, User *Profile)
{
    WritingToFile("data/records.txt", mode, "");
    AppendAcount(table->HashedUsers[HashedIndex(Profile->UserName)], table->HashedUsers[HashedIndex(Profile->UserName)]->Acounts);
}

// Display all the acounts of the logged in user:
void CheckUserAcounts(Users *table, User *Profile)
{
    system("clear");
    DisplayUserAcounts(table, Profile->UserName);
    int choice;
    printf("\n\n----------->>Enter [1] to go to the Home page and [0] to Logout\n\n");
    scanf("%d", &choice);                  // Use &choice to pass the address
    printf("The choice is: %d\n", choice); // Print the value of choice

    if (choice == 1)
    {
        // Call ProfileMenu function with appropriate arguments
        ProfileMenu(table, Profile); // Uncomment this when using ProfileMenu
    }
    else if (choice == 0)
    {
        printf("Logging out...\n");
        sleep(3);
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

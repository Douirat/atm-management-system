#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

// Instantiate a new Acount:
Acount *NewAcount(int acountId, char *date, char *country, char *phone, int acountNumber, float balance, char *acountType)
{
    Acount *acount = (Acount *)malloc(sizeof(Acount));
    if (!acount)
    {
        printf("The memmory allocation for a new acount has failed!!!");
        exit(1);
    }
    acount->AcountId = acountId;
    acount->CreationDate = malloc(strlen(date) + 1);
    strcpy(acount->CreationDate, date);
    acount->Country = malloc(strlen(country) + 1);
    strcpy(acount->Country, country);
    acount->Phone = malloc(strlen(phone) + 1);
    strcpy(acount->Phone, country);
    acount->AcountNumber = acountNumber;
    acount->Balance = balance;
    acount->AcountType = malloc(strlen(acountType) + 1);
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
    printf("                     -----> The Phone: %s\n", Node->Phone);
    printf("                     -----> Acount Number: %d\n", Node->AcountNumber);
    printf("                     -----> Balance: $%f\n", Node->Balance);
    printf("                     -----> Acount type: %s\n\n", Node->AcountType);
    if (Node->Next == NULL)
    {
        return;
    }
    DisplayAcounts(Node->Next);
}

// Deleting a specific acount based on its id:
bool DeleteAcount(Acount **Node, int id)
{
    if ((*Node) == NULL)
    {
        return false;
    }
    else if ((*Node)->AcountId == id)
    {
        (*Node) = (*Node)->Next;
        return true;
    }
    else if ((*Node)->Next != NULL && (*Node)->Next->AcountId == id)
    {
        (*Node)->Next = (*Node)->Next->Next;
        sleep(2);
        return true;
    }
    else if ((*Node)->Next == NULL)
    {
        return false;
    }
    return DeleteAcount(&(*Node)->Next, id);
}

void CreateNewAcount(Users *table, User *Profile)
{
    int acountId;
    char date[11];
    char country[50];
    char phone[11];
    int acountNumber;
    float balance;
    char acountType[10];
    printf("\n\n-------------------------> [ ... Create a new account ... ] <-------------------------\n\n");
    printf("\nEnter the acount id:");
    scanf("%d", &acountId);
    printf("\nEnter creation data in this form: 11/11/1111: ");
    scanf("%s", date);
    printf("\nEnter your country name: ");
    scanf("%s", country);
    printf("\nEnter your phone number: ");
    scanf("%s", phone);
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

    AcountCreation(table, Profile->UserName, acountId, date, country, phone, acountNumber, balance, acountType);
    AcountsWriter(table, "a", Profile);
    ProfileMenu(table, Profile);
}

// The handler of inserting a new acount in the file:
void AcountsWriter(Users *table, char *mode, User *Profile)
{
    AppendAcount(table->HashedUsers[HashedIndex(Profile->UserName)], table->HashedUsers[HashedIndex(Profile->UserName)]->Acounts);
}

// Display all the acounts of the logged in user:
void CheckUserAcounts(Users *table, User *Profile)
{
    system("clear");
    DisplayUserAcounts(table, Profile->UserName);
    int choice;
    printf("\n\n    ----------->> Enter [1] to go to the Home page and [0] to Logout\n\n");
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

// Delete an acount based on the id:
void DeleteAcountById(Users *table, User *Profile)
{
    int choice;
    printf("\n\n--------> Enter the edentification [ID] of the acount you want to delete <--------\n\n");
    printf("Acount id: ");
    scanf("%d", &choice);
    bool Deleted = DeleteAcount(&table->HashedUsers[HashedIndex(Profile->UserName)]->Acounts, choice);
    if (Deleted)
    {
        printf("Acount was deleted successfully\n");
        sleep(2);
        WritingToFile("data/records.txt", "w", "");
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            User *Temp = table->HashedUsers[i];
            while (Temp != NULL)
            {
                AppendAcount(Temp, Temp->Acounts);
                Temp = Temp->Next;
            }
        }
        ProfileMenu(table, Profile);
    }
    else
    {
        printf("Acount not found!!!\n");
        sleep(1);
    }
}

// Update an ccount based on id:
void UpdateAcount(Users *table, User *Profile)
{
    int choice;
    int chosen;
    printf("\n\n      -------------------------> [ ... Update ... ] <-------------------------\n\n");
    printf("      ------------> Enter the [ID] of the acount you want to update: ");
    scanf("%d", &choice);
    printf("\n      ----> Which information you want to update?\n\n");
    printf("         -> [1] Phone number\n");
    printf("         -> [2] Country\n\n");
    scanf("%d", &chosen);
    char input[11];
    Acount *Temp = Profile->Acounts;
    while (Temp != NULL)
    {
        if (Temp->AcountId == choice)
        {
            if (chosen == 1)
            {
                printf("\n      ----> Enter the new phone number: ");
                scanf("%s", input);
                strcpy(Temp->Phone, input);
                printf("Your phone number is updated successfully\n");
                break;
            }
            else
            {
                printf("\n      ----> Enter the new country: ");
                scanf("%s", input);
                strcpy(Temp->Country, input);
                printf("Your phone number is updated successfully\n");
                break;
            }
        }
        Temp = Temp->Next;
    }
}
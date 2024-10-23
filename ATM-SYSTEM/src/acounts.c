#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    strcpy(acount->CreationDate, date);
    strcpy(acount->Country, country);
    acount->AcountNumber = acountNumber;
    acount->Balance = balance;
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
        return;
    }
    printf("The acount id is %d, %s, %s, %d, %f, %s\n", Node->AcountId, Node->CreationDate, Node->Country, Node->AcountNumber, Node->Balance, Node->AcountType);
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
    printf("\nEnter the acount type: ");
    scanf("%s", acountType);

    AcountCreation(table, Profile->UserName, acountId, date, country, acountNumber, balance, acountType);
    
    DisplayUserAcounts(table, "BenDoe");
}

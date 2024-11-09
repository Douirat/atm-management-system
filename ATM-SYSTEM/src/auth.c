#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Create an atoi to convert a string to an integer:
int Atoi(const char *str)
{
    int x = 0;
    int y = 1;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
        {
            y = -1;
        }
        *str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        x = x * 10 + *str - '0';
        str++;
    }
    return x * y;
}

// Create and Itoa to convert a number to a string:
char *Itoa(int num)
{
    char *str = (char *)malloc(20 * sizeof(char));
    if (!str)
    {
        printf("Memmory allocation for a string has failed");
        exit(1);
    }

    int ind = 0;
    if (num < 0)
    {
        str[ind++] = '-';
        num *= -1;
    }

    while (num != 0)
    {
        str[ind++] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}

// Create an atof to convert a string to a float:
float Atof(char *str)
{
    float x = 0.0f;
    float y = 1.0f;
    float factor = 1.0f;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
        {
            y = -1.0f;
        }
        *str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        x = x * 10.0f + *str - '0';
        str++;
    }
    if (*str == '.')
    {
        *str++;
        while (*str >= '0' && *str <= '9')
        {
            x = x * 10.0f + *str - '0';
            str++;
            factor *= 10.0f;
        }
    }
    return y * (x / factor);
}

// Create an Ftoa function:
char *Ftoa(float fl)
{
    char *str = (char *)malloc(20 * sizeof(char));
    if (!str)
    {
        printf("Memmory allocation for a string has failed");
        exit(1);
    }
    int whole = (int)fl;
    float fraction = fl - whole;
    int decimal = 0;
    while (whole != 0)
    {
        decimal++;
        whole /= 10;
    }
    printf("the number of decimals is: %d and the float is %f\n", decimal, fraction);
    snprintf(str, 20, "%.*f", decimal, fl);
    return str;
}

// Is the the new use id valid:
bool ValidCredentials(Users *table, int id, char *userName)
{
    User *Temp = table->HashedUsers[HashedIndex(userName)];
    while (Temp != NULL)
    {
        if (Temp->Id == id || (strcmp(Temp->UserName, userName) == 0))
        {
            return false;
        }
        Temp = Temp->Next;
    }
    return true;
}

// Validate acounts data:
bool ValidAccountId(Acount *account, int id)
{
    if (account == NULL)
    {
        return true;
    }
    if (account->AcountId == id)
    {
        return false;
    }
    return ValidAccountId(account->Next, id);
}

// Validate the date:
bool ValidAccountDate(Acount *account, char *date)
{
    if (strlen(date) != 10)
    {
        return false;
    }
    int helper = 0;
    for (int i = 0; i < strlen(date); i++)
    {
        if (i == 2 || i == 5)
        {
            if (i == 2 && helper > 31 || i == 2 && helper < 0)
            {
                return false;
            }
            else if (i == 5 && helper > 12 || i == 5 && helper < 0)
            {
                return false;
            }
            helper = 0;
            if (date[i] != 47)
            {
                return false;
            }

            continue;
        }
        helper = helper * 10 + date[i] - 48;
        if (date[i] < 48 || date[i] > 57)
        {
            return false;
        }
    }
    return true;
}

// Validate the account number:

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
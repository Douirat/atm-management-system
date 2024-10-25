#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

FILE *filePointer = NULL; // Definition of the global variable

// Write data to a file:
void WritingToFile(const char *filePath, const char *mode, const char *string)
{
    // Open the file in append mode
    filePointer = fopen(filePath, mode); // for example data/users.txt"
    // Check if the file was opened successfully
    if (filePointer == NULL)
    {
        perror("Error opening file"); // Use perror for detailed error message
        return;
    }
    // Append the string to the file
    fputs(string, filePointer);

    // Close the file
    fclose(filePointer);

    printf("Data appended to file successfully.\n");
}

// Read data from a file:
char *ReadFile(const char *filePath)
{
    system("clear");
    filePointer = fopen(filePath, "r");
    if (filePointer == NULL)
    {
        printf("Error opening file: %s\n", filePath);
        exit(1);
    }

    size_t bufferSize = 1000;
    char *result;
    result = (char *)malloc(bufferSize * sizeof(char));
    if (!result)
    {
        printf("Memmory allocation for the result string has failed!");
        exit(1);
    }
    result[0] = '\0';
    char str[100];
    // Read lines from the file and display
    while (fgets(str, sizeof(str), filePointer) != NULL)
    {
        strcat(result, str);
        //    strcat(result, "\n");
    }
    fclose(filePointer);
    return result;
}

// Insret the updated or new added acounts to my file:
void AppendAcount(User *user, Acount *Node)
{
    if (Node == NULL)
    {
        return;
    }

    // Estimate buffer size more carefully based on typical field lengths.
    size_t bufferSize = 255; // Adjust this based on your expected input size.
    char *str = (char *)malloc(bufferSize * sizeof(char));
    if (!str)
    {
        printf("Error allocating memory for a new buffer\n");
        exit(1);
    }

    // Ensure the buffer is initialized as an empty string.
    str[0] = '\0';

    // Safely concatenate account data into the buffer
    int err = snprintf(str, bufferSize, "%d %d %s %s %s %.2f %s\n",
                       Node->AcountId,
                       user->Id,
                       user->UserName,
                       Node->CreationDate,
                       Node->Country,
                       Node->Balance,
                       Node->AcountType);
    if (err == 1)
    {
        printf("Error converting data\n");
        exit(1);
    }
    // Call the function to write the string to the file
    WritingToFile("data/records.txt", "a", str);
    free(str);
    // Recursively process the next account node
    AppendAcount(user, Node->Next);
}

// Insert data related to a new user to the file:
void AppendNewUser(User *user)
{
    if (user == NULL)
    {
        printf("User doesn't exist\n");
        exit(1);
    }
    size_t buffuerSize = 255;
    char *str = (char *)malloc(buffuerSize * sizeof(char));
    if (!str)
    {
        printf("Memmory allocation for the user data buffer has failed!!!\n");
        exit(10);
    }
    // Concatenate the user data to the baffer:
    snprintf(str, buffuerSize, "%d %s %s\n", user->Id, user->UserName, user->Password);
    // write data to the file:
    WritingToFile("data/users.txt", "a", str);
}

// Extract users from the file:
Users *ExtractUsers()
{
    Users *table = NewUsersTable();
    char *data = ReadFile("data/users.txt");
    if (!data || strlen(data) == 0)
    {
        printf("Lack of data in the file!!!");
        exit(1);
    }

    int Id;
    char userName[50];
    char password[20];
    int ind = 1;       // Field indicator: 1 = Id, 2 = userName, 3 = password
    char str[50] = ""; // Temporary buffer for each field

    for (int i = 0, len = strlen(data); i < len; i++)
    {
        if (data[i] == ' ' || data[i] == '\n')
        {
            // Process the current field based on the value of `ind`
            switch (ind)
            {
            case 1:
                Id = Atoi(str);
                break;
            case 2:
                strcpy(userName, str);
                break;
            case 3:
                strcpy(password, str);
                break;
            }
            str[0] = '\0'; // Clear the buffer after copying

            if (data[i] == '\n')
            {
                // End of line, insert record
                Insertion(table, Id, userName, password);
                ind = 1; // Reset field indicator for the next user
            }
            else
            {
                ind++; // Move to the next field
            }
        }
        else
        {
            // Append the current character to `str`
            strncat(str, &data[i], 1);
        }
    }

    free(data); // Free allocated memory for data if ReadFile uses dynamic allocation
    ExtractAcounts(table);
    return table;
}

// Extract acounts from the file:
void ExtractAcounts(Users *table)
{
    char *data = ReadFile("data/records.txt");
    printf("%s", data);
    if (!data || strlen(data) == 0)
    {
        printf("Lack of data in the file!!!");
        exit(1);
    }
    int acountId;
    char creationDate[11];
    char country[50];
    int acountNumber;
    float balance;
    char acountType[11];
    int ind = 1;
    char UserName[50];

    size_t bufferSize = 55;
    char *str;
    str = (char*) malloc(bufferSize * sizeof(char));
    if(!str) {
        printf("Memmory allocation for a buffer has failed!!!");
        exit(1);
    }
    for (int i = 0; i < strlen(data); i++)
    {
        if(data[i] == ' ' || data[i] == '\n') {
            switch(ind) {
                case 1:
                    acountId = Atoi(str);
                case 2:
                    strcpy(UserName, str);
                case 3:
                    strcpy(creationDate, str);
                case 4:
                    strcpy(country, str);
                case 5:
                    acountNumber = Atoi(str);
                case 6:
                    balance = Atof(str);
                case 7:
                    strcpy(acountType, str);
            } 
            str[0] = '\0';
            if(data[i] == '\n') {
                printf("The id is : %d the user name is %s the date %s the country is %s balance %lf the type %s");
                // AcountCreation(table,  UserName,acountId, creationDate, country, acountNumber, balance, acountType);
                ind = 1;
            } else {
                ind ++;
            }
        } else {
            strncat(str, &data[i], 1);
        }
    }
}
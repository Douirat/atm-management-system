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

    printf("String appended to file successfully.\n");
}

// Read data from a file:
void ReadFile(const char *filePath)
{
    FILE *filePointer = fopen(filePath, "r");
    if (filePointer == NULL)
    {
        printf("Error opening file: %s\n", filePath);
        return;
    }

    char str[100];
    // Read lines from the file and display
    while (fgets(str, sizeof(str), filePointer) != NULL)
    {
        printf("%s", str); // Display the line read from the file
    }

    fclose(filePointer);
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
    snprintf(str, bufferSize, "%d %d %s %s %s %.2f %s\n",
        Node->AcountId,               // Integer account ID
        user->Id,                     // Integer user ID
        user->UserName,               // String (make sure it's properly null-terminated)
        Node->CreationDate,           // String date
        Node->Country,                // String country
        Node->Balance,                // Floating point balance
        Node->AcountType              // String account type
    );

    // Call the function to write the string to the file
    WritingToFile("data/records.txt", "a", str);

    free(str);

    // Recursively process the next account node
    AppendAcount(user, Node->Next);
}



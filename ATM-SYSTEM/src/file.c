#include <stdio.h>
#include "header.h"

FILE *filePointer = NULL;  // Definition of the global variable

// Write data to a file:
void WritingToFile(const char *filePath, const char *string)
{
    // Open the file in append mode
   filePointer = fopen(filePath, "w");  // for example data/users.txt" 
    // Check if the file was opened successfully
    if (filePointer == NULL)
    {
        perror("Error opening file");  // Use perror for detailed error message
        return;
    }
    // Append the string to the file
    fputs(string, filePointer);
    
    // Close the file
    fclose(filePointer);

    printf("String appended to file successfully.\n");
}

// Read data from a file:
void ReadFile(const char *filePath) {
    FILE *filePointer = fopen(filePath, "r");
    if (filePointer == NULL) {
        printf("Error opening file: %s\n", filePath);
        return;
    }

    char str[100];
    // Read lines from the file and display
    while (fgets(str, sizeof(str), filePointer) != NULL) {
        printf("%s", str); // Display the line read from the file
    }

    fclose(filePointer);
}


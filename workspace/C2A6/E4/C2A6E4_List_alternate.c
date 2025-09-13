#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "C2A6E4_List-Driver.h"

#define BUFFER 256
#define DELIM " \n"

// Function to print the list
List *PrintList(const List *head)
{
    for (const List *table = head; table != NULL; table = table->next)
    {
        printf("%-15s%4d ea\n", table->str, table->count);
    }
    return (List *)head;
}

// Function to free the list
void FreeList(List *head)
{
    while (head != NULL)
    {
        List *temp = head;
        head = head->next;
        free(temp->str);  // Free the dynamically allocated string
        free(temp);       // Free the node memory
    }
}

// Function to create the list from a file using fgets
List *CreateList(FILE *fp)
{
    char buffer[BUFFER];
    List *head = NULL;
    bool foundMatch = false;

    // Read one line at a time using fgets
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove the newline character at the end, if any
        buffer[strcspn(buffer, "\n")] = 0;

        // Trim leading and trailing spaces from the buffer
        char *start = buffer;
        while (isspace(*start)) start++;  // Skip leading spaces
        if (*start == '\0') continue; // Skip empty lines
        char *end = start + strlen(start) - 1;
        while (end > start && isspace(*end)) end--;  // Trim trailing spaces
        *(end + 1) = '\0'; // Null-terminate the trimmed string

        // Tokenize the line into words using strtok
        for (char *token = strtok(start, DELIM); token != NULL; token = strtok(NULL, DELIM))
        {
            // Ensure that the token is cleaned up from any leading spaces
            while (isspace(*token)) token++;  // Skip leading spaces

            if (*token != '\0') // Make sure token is not empty
            {
                foundMatch = false;

                // Search through the linked list to check if the word already exists
                for (List *nodePtr = head; nodePtr != NULL; nodePtr = nodePtr->next)
                {
                    if (strcmp(token, nodePtr->str) == 0)
                    {
                        // Increment the count for the existing word
                        nodePtr->count++;
                        foundMatch = true;
                        break;
                    }
                }

                // If the word was not found, create a new node
                if (!foundMatch)
                {
                    List *newNode = (List *)malloc(sizeof(List));
                    if (newNode == NULL)
                    {
                        fprintf(stderr, "Memory allocation failed!\n");
                        exit(EXIT_FAILURE);
                    }

                    // Allocate space for the word and store it in the new node
                    size_t length = strlen(token) + 1; // +1 for null terminator
                    newNode->str = (char *)malloc(length * sizeof(char));
                    if (newNode->str == NULL)
                    {
                        fprintf(stderr, "String memory allocation failed!\n");
                        exit(EXIT_FAILURE);
                    }

                    // Copy the token into the new node's string
                    memcpy(newNode->str, token, length);

                    // Initialize count to 1 for the new word
                    newNode->count = 1;

                    // Add the new node to the front of the list
                    newNode->next = head;
                    head = newNode;

                    // Debug: Print the new node added
                    // printf("Added new node: [%s] with count = %d\n", newNode->str, newNode->count);
                }
            }
        }
    }

    return head;
}



#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "C2A6E4_List-Driver.h"

#define BUFFER 256
#define DELIM " \n"
List *PrintList(const List *head)
{
    for (const List *table = head; table != NULL; table = table->next)
       {
           printf("%-15s%4d ea\n", table->str, table->count);
       }
       return((List *)head);
}
void FreeList(List *head)
{
    // while head isn't null
 while(head)
    {
        List * temp = head;
        head = head ->next;
        free(temp->str);
        free(temp);
    }
}
// copied

List *CreateList(FILE *fp)
{
    char buffer[BUFFER];
    char *temp;
    List * head = NULL;
    bool foundMatch = false;
    // this for loop keeps getting lines until there are no more lines to get
    // this simple while loop works
// while loop works perfectly as is: please see other solution for alternative
while (fscanf(fp, "%255s", buffer) != EOF)
    //for(temp = fgets(buffer,sizeof(buffer),fp); temp != NULL; temp = fgets(buffer,sizeof(buffer),fp))
    //while (fgets(buffer, sizeof(buffer), fp) != NULL) // attempt 3
    {
        //buffer[strcspn(buffer, "\n")] = 0;// attemp3
        //printf("read: %s\n",buffer);
        // this breaks each item into a token or "word". call strtok
        foundMatch = false;
        for(char * token = strtok(buffer,DELIM); token != NULL; token = strtok(NULL,DELIM))
        {
            //printf("%s..", token);
            
            foundMatch = false;
            // Ensure that the current Token is not a space!
            
            while (isspace(*token)) {
                ++token;  // Move the pointer to the next non-whitespace character
            }
             
            if(*token != '\0' )
            {
                for(List * nodePtr = head; nodePtr != NULL; nodePtr=nodePtr->next)
                {
                    
                    // printf("looping thru the L.L\n");
                    //printf("%s. ",nodePtr->str);
                    //foundMatch = true;
                    if(!strcmp(token,nodePtr->str))
                    {
                        // printf("**");
                        nodePtr->count = nodePtr->count+1;
                        foundMatch = true;
                        break;
                        // i think i can do this too:
                        // nodePtr->count++;
                    }
                }
                if(foundMatch == false)
                {
                    // dynamically allocate the new node
                    List * newNode = (List *)malloc(sizeof(List));
                    if(newNode==NULL)
                    {
                        fprintf(stderr, "MALLOC FAIL");
                        exit(EXIT_FAILURE);
                    }
                    // take into account the null character
                    size_t length = strlen(token) + 1;
                    newNode->count=newNode->count+1;
                    // dynamically allocate the string space within the node
                    newNode->str = (char *)malloc(length * sizeof(char));
                    if(newNode->str==NULL)
                    {
                        fprintf(stderr, "String MALLOC FAIL");
                        exit(EXIT_FAILURE);
                    }
                    memcpy(newNode->str,token,length);
                    // push the node to front of list
                    newNode->next = head;
                    head = newNode;
                }
                
            }
        }
    }
   
    return head;
}




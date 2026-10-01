#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

// Display all lines
void displayDocument(char lines[MAX_LINES][MAX_LENGTH], int lineCount)
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s", i + 1, lines[i]);
    }

    printf("--------------------\n");
}


// Insert a new line
void insertLine(char lines[MAX_LINES][MAX_LENGTH], int *lineCount)
{
    if (*lineCount >= MAX_LINES)
    {
        printf("Error: Document is full.\n");
        return;
    }

    int lineNumber;

    printf("Enter line number: ");
    scanf("%d", &lineNumber);

    getchar();

    if (lineNumber < 1 || lineNumber > *lineCount + 1)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    // Shift existing lines down
    for (int i = *lineCount; i >= lineNumber; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter text: ");
    fgets(lines[lineNumber - 1], MAX_LENGTH, stdin);

    (*lineCount)++;

    printf("Line inserted successfully.\n");
}


// Delete a line
void deleteLine(char lines[MAX_LINES][MAX_LENGTH], int *lineCount)
{
    if (*lineCount == 0)
    {
        printf("Error: Document is empty.\n");
        return;
    }

    int lineNumber;

    printf("Enter line number to delete: ");
    scanf("%d", &lineNumber);

    if (lineNumber < 1 || lineNumber > *lineCount)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    // Shift lines up
    for (int i = lineNumber - 1; i < *lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    (*lineCount)--;

    printf("Line deleted successfully.\n");
}


// Save document to a file
void saveFile(char lines[MAX_LINES][MAX_LENGTH], int lineCount)
{
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error: Could not save file.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s", lines[i]);
    }

    fclose(file);

    printf("File saved successfully.\n");
}


// Load document from a file
void loadFile(char lines[MAX_LINES][MAX_LENGTH], int *lineCount)
{
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Could not open file.\n");
        return;
    }

    *lineCount = 0;

    while (*lineCount < MAX_LINES &&
           fgets(lines[*lineCount], MAX_LENGTH, file) != NULL)
    {
        (*lineCount)++;
    }

    fclose(file);

    printf("File loaded successfully.\n");
}


// Search for a word or phrase
void searchText(char lines[MAX_LINES][MAX_LENGTH], int lineCount)
{
    char search[100];
    int found = 0;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    getchar();

    printf("Enter word or phrase to search: ");
    fgets(search, sizeof(search), stdin);

    search[strcspn(search, "\n")] = '\0';

    if (strlen(search) == 0)
    {
        printf("Error: Search text cannot be empty.\n");
        return;
    }

    printf("\n----- SEARCH RESULTS -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], search) != NULL)
        {
            printf("Found on line %d: %s", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found.\n");
    }

    printf("--------------------------\n");
}


// Main function
int main()
{
    char lines[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;
    char command[20];

    printf("===== SIMPLE LINE EDITOR =====\n");

    while (1)
    {
        printf("\n> ");
        scanf("%s", command);

        if (strcmp(command, "insert") == 0)
        {
            insertLine(lines, &lineCount);
        }

        else if (strcmp(command, "delete") == 0)
        {
            deleteLine(lines, &lineCount);
        }

        else if (strcmp(command, "display") == 0)
        {
            displayDocument(lines, lineCount);
        }

        else if (strcmp(command, "save") == 0)
        {
            saveFile(lines, lineCount);
        }

        else if (strcmp(command, "load") == 0)
        {
            loadFile(lines, &lineCount);
        }

        else if (strcmp(command, "search") == 0)
        {
            searchText(lines, lineCount);
        }

        else if (strcmp(command, "help") == 0)
        {
            printf("\n===== AVAILABLE COMMANDS =====\n");
            printf("insert  - Insert a new line\n");
            printf("delete  - Delete a line\n");
            printf("display - Display the document\n");
            printf("save    - Save document to a file\n");
            printf("load    - Load document from a file\n");
            printf("search  - Search for a word or phrase\n");
            printf("help    - Show available commands\n");
            printf("exit    - Exit the editor\n");
            printf("==============================\n");
        }

        else if (strcmp(command, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        else
        {
            printf("Unknown command. Type 'help' for available commands.\n");
        }
    }

    return 0;
}

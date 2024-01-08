#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"
#include "note_manager.h"

void createNote()
{
    char title[100];
    char content[1000];

    printf("Enter note title: ");
    getchar(); // Consume the newline character left in the buffer
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove the trailing newline

    printf("Enter note content: ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = '\0'; // Remove the trailing newline

    // Generate a unique filename based on the current timestamp
    char filename[20];
    int timestamp = (int)time(NULL);
    sprintf(filename, "note_%d.txt", timestamp);

    // Create and write to the file
    FILE *file = fopen(filename, "w");
    if (file != NULL)
    {
        fprintf(file, "Title: %s\n", title);
        fprintf(file, "Content: %s\n", content);
        fclose(file);

        printf("\n" ANSI_COLOR_GREEN "Note created successfully!" ANSI_COLOR_RESET "\n");

        // Store timestamp and filename in the array
        for (int i = 0; i < MAX_NOTES; i++)
        {
            if (noteInfo[i].timestamp == 0)
            {
                noteInfo[i].timestamp = timestamp;
                noteInfo[i].filename = strdup(filename);
                break;
            }
        }
    }
    else
    {
        printf("\n" ANSI_COLOR_RED "Error creating note file." ANSI_COLOR_RESET "\n");
    }
}

void viewNotes()
{
    printf("-------- Note List --------\n");

    // Iterate through the array and print notes
    for (int i = 0; i < MAX_NOTES; i++)
    {
        if (noteInfo[i].timestamp != 0)
        {
            printf("Timestamp: %d\n", noteInfo[i].timestamp);

            FILE *file = fopen(noteInfo[i].filename, "r");
            if (file != NULL)
            {
                char line[256];
                while (fgets(line, sizeof(line), file) != NULL)
                {
                    printf("%s", line);
                }

                fclose(file);
            }
        }
    }

    printf("-------- End of Note List --------\n");
}

void printNoteIntegrationMenu()
{
    printf("\n" ANSI_COLOR_RED "╔═════════════════════ Note Integration Menu ═══════════════════╗\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "║ " ANSI_COLOR_RESET "1. Create Note                                                " ANSI_COLOR_RED "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "║ " ANSI_COLOR_RESET "2. View Notes                                                 " ANSI_COLOR_RED "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "║ " ANSI_COLOR_RESET "3. Back to Main Menu                                          " ANSI_COLOR_RED "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "╚═══════════════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void noteIntegration()
{
    int option;

    do
    {
        printNoteIntegrationMenu();

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            createNote();
            break;
        case 2:
            viewNotes();
            break;
        case 3:
            printf("\nReturning to the Main Menu...\n");
            break;
        default:
            printf("\n" ANSI_COLOR_RED "\nInvalid choice. Please try again." ANSI_COLOR_RESET "\n");
        }

    } while (option != 3);
}
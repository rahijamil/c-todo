#include <stdio.h>
#include "main.h"
#include "task_manager.h"
#include "note_manager.h"

void printMainMenu()
{
    printf("\n" ANSI_COLOR_GREEN "╔═══════════════════════ C-Todo Main Menu ══════════════════════╗\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "║ " ANSI_COLOR_RESET "1. Task Management                                            " ANSI_COLOR_GREEN "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "║ " ANSI_COLOR_RESET "2. Note Integration                                           " ANSI_COLOR_GREEN "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "║ " ANSI_COLOR_RESET "3. Exit                                                       " ANSI_COLOR_GREEN "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

int main()
{
    int choice;

    do
    {
        printMainMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            taskManagement(); // Function from task_manager.c
            break;
        case 2:
            noteIntegration(); // Function from note_manager.c
            break;
        case 3:
            printf("\nExiting C-Todo. " ANSI_COLOR_GREEN "Goodbye!" ANSI_COLOR_RESET "\n\n");
            break;
        default:
            printf("\n" ANSI_COLOR_RED "Invalid choice. Please try again." ANSI_COLOR_RESET "\n\n");
        }

    } while (choice != 3);

    return 0;
}
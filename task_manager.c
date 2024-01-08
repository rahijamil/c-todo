#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "task_manager.h"

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask(Task tasks[], int *taskCount, const char *title, const char *description)
{
    if (*taskCount < MAX_TASKS)
    {
        tasks[*taskCount].id = *taskCount + 1;

        // Allocate memory for title and description
        tasks[*taskCount].title = strdup(title);
        tasks[*taskCount].description = strdup(description);

        (*taskCount)++;

        printf("\n" ANSI_COLOR_GREEN "Task added successfully!" ANSI_COLOR_RESET "\n");
    }
}

void removeTask(Task tasks[], int *taskCount, int taskId)
{
    if (*taskCount > 0)
    {
        int foundIndex = -1;

        // Search for the task with the specified ID
        for (int i = 0; i < *taskCount; i++)
        {
            if (tasks[i].id == taskId)
            {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1)
        {
            // Free memory for title and description
            free(tasks[foundIndex].title);
            free(tasks[foundIndex].description);

            // Shift tasks to fill the gap
            for (int i = foundIndex; i < *taskCount - 1; i++)
            {
                tasks[i] = tasks[i + 1];
            }

            (*taskCount)--; // Decrement taskCount
            printf("\n" ANSI_COLOR_GREEN "Task removed successfully!" ANSI_COLOR_RESET "\n");
        }
        else
        {
            printf("\n" ANSI_COLOR_RED "Task not found with ID %d" ANSI_COLOR_RESET "\n", taskId);
        }
    }
    else
    {
        printf("\n" ANSI_COLOR_YELLOW "No tasks to remove." ANSI_COLOR_RESET "\n");
    }
}

void editTask(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int taskId;
        printf("Enter the ID of the task to edit: ");
        scanf("%d", &taskId);

        int foundIndex = -1;

        // Search for the task with the specified ID
        for (int i = 0; i < taskCount; i++)
        {
            if (tasks[i].id == taskId)
            {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1)
        {
            printf("Enter new task title: ");
            getchar(); // Consume the newline character left in the buffer
            fgets(tasks[foundIndex].title, sizeof(tasks[foundIndex].title), stdin);
            tasks[foundIndex].title[strcspn(tasks[foundIndex].title, "\n")] = '\0'; // Remove the trailing newline

            printf("Enter new task description: ");
            fgets(tasks[foundIndex].description, sizeof(tasks[foundIndex].description), stdin);
            tasks[foundIndex].description[strcspn(tasks[foundIndex].description, "\n")] = '\0'; // Remove the trailing newline

            printf("\n" ANSI_COLOR_GREEN "Task edited successfully!" ANSI_COLOR_RESET "\n");
        }
        else
        {
            printf("\n" ANSI_COLOR_RED "Task not found with ID %d" ANSI_COLOR_RESET "\n", taskId);
        }
    }
    else
    {
        printf("\n" ANSI_COLOR_YELLOW "No tasks to edit." ANSI_COLOR_RESET "\n");
    }
}

void printTaskManagementMenu()
{
    printf("\n" ANSI_COLOR_YELLOW "╔══════════════════════ Task Management Menu ═══════════════════╗\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "║ " ANSI_COLOR_RESET "1. Add Task                                                   " ANSI_COLOR_YELLOW "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "║ " ANSI_COLOR_RESET "2. Remove Task                                                " ANSI_COLOR_YELLOW "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "║ " ANSI_COLOR_RESET "3. Edit Task                                                  " ANSI_COLOR_YELLOW "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "║ " ANSI_COLOR_RESET "4. View Tasks                                                 " ANSI_COLOR_YELLOW "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "║ " ANSI_COLOR_RESET "5. Back to Main Menu                                          " ANSI_COLOR_YELLOW "║\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "╚═══════════════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}

void taskManagement()
{
    int choice;

    do
    {
        printTaskManagementMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char title[100];
            char description[500];
            printf("Enter task title: ");
            getchar();
            
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0'; // Remove the trailing newline

            printf("Enter task description: ");

            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0'; // Remove the trailing newline

            addTask(tasks, &taskCount, title, description);
        }
        break;
        case 2:
        {
            int taskId;
            printf("Enter the ID of the task to remove: ");
            scanf("%d", &taskId);
            removeTask(tasks, &taskCount, taskId);
        }
        break;
        case 3:
            editTask(tasks, taskCount);
            break;
        case 4:
            viewTask(tasks, taskCount);
            break;
        case 5:
            printf("Returning to the Main Menu...\n");
            break;
        default:
            printf("\n" ANSI_COLOR_RED "\nInvalid choice. Please try again." ANSI_COLOR_RESET "\n");
        }

    } while (choice != 5);
}

void viewTask(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        printf("-------- Task List --------\n");
        printf("ID\tTitle\t\tDescription\n");

        for (int i = 0; i < taskCount; i++)
        {
            printf("%d\t%s\t\t%s\n", tasks[i].id, tasks[i].title, tasks[i].description);
        }
    }
    else
    {
        printf("\n" ANSI_COLOR_YELLOW "No tasks to view." ANSI_COLOR_RESET "\n");
    }
}
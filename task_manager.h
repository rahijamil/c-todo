#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

// Define the Task structure using typedef
typedef struct
{
    int id;
    char *title;
    char *description;
} Task;

// Define the maximum number of tasks
#define MAX_TASKS 100

extern Task tasks[MAX_TASKS];
extern int taskCount;

// Function declarations
void addTask(Task tasks[], int *taskCount, const char *title, const char *description);
void removeTask(Task tasks[], int *taskCount, int taskId);
void editTask(Task tasks[], int taskCount);
void viewTask(Task tasks[], int taskCount);

void printTaskManagementMenu();
void taskManagement();

#endif

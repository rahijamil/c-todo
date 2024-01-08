#ifndef NOTE_MANAGER_H
#define NOTE_MANAGER_H

// Define the maximum number of notes
#define MAX_NOTES 100

typedef struct
{
    int timestamp;
    char *filename;
} NoteInfo;

NoteInfo noteInfo[MAX_NOTES]; // Array to store timestamp and filename

// Function declarations for note manager
void createNote();
void viewNotes();

void printNoteIntegrationMenu();
void noteIntegration();

#endif

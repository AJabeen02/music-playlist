#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a song node
struct Song {
    char title[50];
    struct Song* next;
};

struct Song* head = NULL;

// Function to print line
void printLine() {
    printf("=====================================\n");
}

// Function to add a song
void addSong() {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));

    printLine();
    printf("        ADD NEW SONG\n");
    printLine();

    printf("Enter song title: ");
    scanf(" %[^\n]", newSong->title);

    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        struct Song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }

    printf("\n Song added successfully!\n");
    printLine();
}

// Function to display playlist
void displayPlaylist() {
    printLine();
    printf("        PLAYLIST\n");
    printLine();

    if (head == NULL) {
        printf(" Playlist is empty.\n");
        printLine();
        return;
    }

    struct Song* temp = head;
    int i = 1;

    while (temp != NULL) {
        printf("%d. %s\n", i, temp->title);
        temp = temp->next;
        i++;
    }

    printLine();
}

// Function to delete a song
void deleteSong() {
    char name[50];

    printLine();
    printf("        DELETE SONG\n");
    printLine();

    printf("Enter song title: ");
    scanf(" %[^\n]", name);

    struct Song *temp = head, *prev = NULL;

    if (temp != NULL && strcmp(temp->title, name) == 0) {
        head = temp->next;
        free(temp);
        printf("\n Song deleted successfully!\n");
        printLine();
        return;
    }

    while (temp != NULL && strcmp(temp->title, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\n Song not found!\n");
        printLine();
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\n Song deleted successfully!\n");
    printLine();
}

// Function to search a song
void searchSong() {
    char name[50];

    printLine();
    printf("        SEARCH SONG\n");
    printLine();

    printf("Enter song title: ");
    scanf(" %[^\n]", name);

    struct Song* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (strcmp(temp->title, name) == 0) {
            printf("\n Found at position %d\n", pos);
            printLine();
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("\n Song not found!\n");
    printLine();
}

// Main menu
int main() {
    int choice;

    while (1) {
        printLine();
        printf("      * MUSIC PLAYLIST MENU * \n");
        printLine();

        printf(" 1. Add Song\n");
        printf(" 2. Delete Song\n");
        printf(" 3. Display Playlist\n");
        printf(" 4. Search Song\n");
        printf(" 5. Exit\n");

        printLine();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSong(); break;
            case 2: deleteSong(); break;
            case 3: displayPlaylist(); break;
            case 4: searchSong(); break;
            case 5:
                printLine();
                printf("Exiting... Thank you!\n");
                printLine();
                exit(0);
            default:
                printf("\n✖ Invalid choice!\n");
        }
    }
}
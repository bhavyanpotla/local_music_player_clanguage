#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SONG_FILE "songs.dat"
#define ID_FILE   "song_id.dat"

struct Song {
    int id;               // AUTO-INCREMENT ID
    char title[50];
    char artist[50];
    char path[300];
};

int nextID = 1;

// Function declarations
void loadNextID();
void saveNextID();
void addSong();
void displaySongs();
void searchSong();
void updateSong();
void deleteSong();
void playSong();

// Load the last used ID from file
void loadNextID() {
    FILE *fp = fopen(ID_FILE, "rb");
    if (fp) {
        fread(&nextID, sizeof(int), 1, fp);
        fclose(fp);
    }
}

// Save updated nextID to file
void saveNextID() {
    FILE *fp = fopen(ID_FILE, "wb");
    fwrite(&nextID, sizeof(int), 1, fp);
    fclose(fp);
}

int main() {
    loadNextID();  // Load last used ID when program starts

    int choice;

    while (1) {
        printf("\n================ MUSIC PLAYLIST MANAGEMENT ================\n");
        printf("1. Add Song\n");
        printf("2. Display All Songs\n");
        printf("3. Search Song by ID\n");
        printf("4. Update Song by ID\n");
        printf("5. Delete Song by ID\n");
        printf("6. Play Song by ID\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSong(); break;
            case 2: displaySongs(); break;
            case 3: searchSong(); break;
            case 4: updateSong(); break;
            case 5: deleteSong(); break;
            case 6: playSong(); break;
            case 7: saveNextID(); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// =========================== ADD SONG ================================
void addSong() {
    struct Song s;
    FILE *fp = fopen(SONG_FILE, "ab");

    s.id = nextID++;
    saveNextID();

    printf("Enter Song Title: ");
    fflush(stdin);
    gets(s.title);

    printf("Enter Artist: ");
    gets(s.artist);

    printf("Enter FULL file path (example: C:\\Users\\Bhavyan\\Downloads\\song.mp3):\n");
    gets(s.path);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("\nSong added successfully with ID: %d\n", s.id);
}

// =========================== DISPLAY SONGS ===========================
void displaySongs() {
    struct Song s;
    FILE *fp = fopen(SONG_FILE, "rb");

    if (!fp) {
        printf("No songs found!\n");
        return;
    }

    printf("\n=========== SONG LIST ===========\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("ID     : %d\n", s.id);
        printf("Title  : %s\n", s.title);
        printf("Artist : %s\n", s.artist);
        printf("Path   : %s\n", s.path);
        printf("---------------------------------\n");
    }

    fclose(fp);
}

// =========================== SEARCH SONG ===========================
void searchSong() {
    int id;
    struct Song s;
    int found = 0;

    printf("Enter Song ID to search: ");
    scanf("%d", &id);

    FILE *fp = fopen(SONG_FILE, "rb");
    if (!fp) {
        printf("No file found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("\nSong Found!\n");
            printf("ID     : %d\n", s.id);
            printf("Title  : %s\n", s.title);
            printf("Artist : %s\n", s.artist);
            printf("Path   : %s\n", s.path);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Song not found!\n");
}

// =========================== UPDATE SONG ===========================
void updateSong() {
    int id;
    struct Song s;
    int found = 0;

    printf("Enter Song ID to update: ");
    scanf("%d", &id);

    FILE *fp = fopen(SONG_FILE, "rb+");
    if (!fp) {
        printf("No songs present.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {

            printf("Enter new title: ");
            fflush(stdin);
            gets(s.title);

            printf("Enter new artist: ");
            gets(s.artist);

            printf("Enter new path: ");
            gets(s.path);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            printf("\nSong updated successfully!\n");
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Song not found!\n");
}

// =========================== DELETE SONG ===========================
void deleteSong() {
    int id;
    struct Song s;
    int found = 0;

    printf("Enter Song ID to delete: ");
    scanf("%d", &id);

    FILE *fp = fopen(SONG_FILE, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(SONG_FILE);
    rename("temp.dat", SONG_FILE);

    if (found)
        printf("Song deleted successfully!\n");
    else
        printf("Song not found!\n");
}

// =========================== PLAY SONG ===========================
void playSong() {
    int id;
    struct Song s;
    int found = 0;

    printf("Enter Song ID to play: ");
    scanf("%d", &id);

    FILE *fp = fopen(SONG_FILE, "rb");
    if (!fp) {
        printf("No file exists.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {

            char command[400];
            sprintf(command, "start \"\" \"%s\"", s.path);
            system(command);

            printf("\nPlaying song: %s\n", s.title);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Song not found!\n");
}


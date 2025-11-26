# Abstract
NaaSongs — Naa Istam is a CLI-based music management system built in C for organizing and playing local songs using ID-based indexing. It demonstrates practical C concepts such as file handling, structs, and terminal interaction. The project is lightweight, efficient, and maintains a persistent music database across runs.
#  {NaaSongs — Naa Istam}  
### A Terminal-Based Music Database & Player in C  

NaaSongs — Naa Istam is a command-line music management system implemented in C, designed to simulate a playlist controller similar to a simplified Spotify/Media Manager. It supports interactive song management and playback control directly from the terminal interface using a unique ID-based system.

---

##  Key Features

- **Add songs with title, artist & file path**
- **Auto-increment unique ID for every song**
- **View complete music list**
- **Search specific song by ID**
- **Modify song data**
- **Delete songs from library**
- **Play songs directly via terminal**
- **Fast & lightweight execution**
- **Persistent database across runs**

---

##  System Architecture

This project demonstrates core software engineering concepts:

- `struct Song` data modeling  
- binary file handling  
- persistent local storage  
- ID-based indexing  
- modularized C programming  
- command-driven interaction  
- safe string input  
- Windows-based `system()` execution  

---
## Functional Requirements
### User Requirements

User must provide:

song title

artist name

full file path for the song file

User interacts through numeric terminal menu

User must store songs locally on the system

Windows OS required for song playback using start command

### Technical Requirements

C compiler (GCC / Clang / MSVC)

## Windows terminal or VS Code terminal

songs.dat file auto-created by the program

song_id.dat stores next unique ID

Execution environment supports system() call


## How It Works (Internal Workflow)

### 1. Program Starts

loads previous last ID value from song_id.dat

if file doesn't exist → first ID starts at 1

### 2. Menu Loop begins
User selects one of the operations:

1 Add Song → writes Song struct record to songs.dat

2 Display All → sequential read from file & print

3 Search → scans file & matches ID

4 Update → modifies record in-place

5 Delete → copies all except deleted one to temp.dat

6 Play → launches file externally using Windows command

7 Exit → saves current ID for next session

### 3. Binary File Records
Each song stored in songs.dat as a struct:

| ID | Title | Artist | Path |


### 4. ID Handling

nextID global variable increments after each addition

saved and restored even between system boots
Running the Project in VS Code
##  Install Required Tools

✔ VS Code
✔ C/C++ extension
✔ MinGW or GCC compiler
✔ Windows OS

2. Create Project Folder
NaaSongs/
   main.c

3. Open Folder in VS Code

File → Open Folder → select NaaSongs
## Security & Stability Notes

### Advantages

 Data never erased unless user deletes manually
Low memory usage
✔ Fast sequential I/O
✔ Clean modular functions

### Limitations

✖ Works only on Windows (due to start "")
✖ gets() unsafe for production
✖ No duplicate file prevention
✖ No space validation for extremely long paths
✖ Playback depends on Windows file associations
 




 




 

# Abstract
This project is a CLI-based music management system built in C for organizing and playing local songs using ID-based indexing. It demonstrates practical C concepts such as file handling, structs, and terminal interaction. The project is lightweight, efficient, and maintains a persistent music database across runs.
#  [LOCAL MUSIC PLAYER]
### A Terminal-Based Music Database & Player in C  

It's a command-line music management system implemented in C, designed to simulate a playlist controller similar to a simplified Spotify/Media Manager. It supports interactive song management and playback control directly from the terminal interface using a unique ID-based system.

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

 VS Code
 C/C++ extension
 MinGW or GCC compiler
 Windows OS
 
 Windows (MinGW / GCC):
#### gcc main.c -o music.exe

#### music.exe

If you have multiple C files (example):
gcc *.c -o music

⚠️ Important Notes

Ensure songs.dat and song_id.dat are in the same folder as your program.

On Windows, songs must be stored with full path, for example:

C:\Users\Teja\Downloads\song.mp3

 
 
## Security & Stability Notes

### Advantages

 Data never erased unless user deletes manually
 
 Low memory usage
 
 Fast sequential I/O
 
 Clean modular functions

### Limitations

 Works only on Windows (due to start "")
 
 gets() unsafe for production
 
 No duplicate file prevention
 
 No space validation for extremely long paths
 
 Playback depends on Windows file associations

 ## OUTPUT PHOTOS
 ### 1.add song
 <img width="1002" height="417" alt="image" src="https://github.com/user-attachments/assets/2e740015-ec7e-4465-b471-c8e54724b658" />

 ### 2.display songs
 <img width="1011" height="869" alt="image" src="https://github.com/user-attachments/assets/25a1b9fe-9c8a-48a4-9112-dd9cbe8a0195" />

 ### 3.search song
 <img width="669" height="257" alt="image" src="https://github.com/user-attachments/assets/29dc0ac7-e4a4-444c-ab74-f1430290af7f" />

 ### 4.update song
 <img width="720" height="232" alt="image" src="https://github.com/user-attachments/assets/bc80d5e8-b4e4-4183-9a7d-8a6c5dd26591" />

 ### 5.delete song
 <img width="444" height="126" alt="image" src="https://github.com/user-attachments/assets/2e80dd7e-41b9-44b9-a4c0-1f78372af5ad" />

 ### 6.play song
 <img width="1888" height="963" alt="image" src="https://github.com/user-attachments/assets/60703159-1c3c-44be-a045-b939266eea1e" />






 





 




 

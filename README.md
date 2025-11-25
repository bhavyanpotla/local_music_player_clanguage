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

##  Installation & Compilation

### Compile:
```bash
-----------------------
gcc main.c -o naasongs
./naasongs
naasongs.exe
-----------------------


### Advantages (Pros)

Simple & lightweight

Fast execution due to C efficiency

Structured storage using Song records

Easy to use — intuitive UI

Good real world use-case demonstration

Teaches file handling & persistent storage

ID-based fast lookup

Extremely small program size

Clean modular functions


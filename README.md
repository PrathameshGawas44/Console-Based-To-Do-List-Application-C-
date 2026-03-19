# Console-Based To-Do List Application (C++)

## Project Description

This project is a menu-driven, console-based To-Do List application developed using C++.  
It allows users to create, manage, and persist tasks through a structured switch-case menu system.

The application uses binary file handling for persistent storage and incorporates exception handling to ensure safe and reliable file operations.  
The primary goal of this project is to demonstrate strong fundamentals in C++, file handling, and structured program design.

---

## Tech Stack

Language: C++  

Header Files Used:
- iostream  
- conio.h  
- string  
- iomanip  
- fstream  

Interface: Command Line / Terminal  

Data Storage: Binary file handling using file streams  

---

## Menu Options and Functionalities

The application is controlled using a switch-case based menu with the following options:

1. Add Task  
2. Show Tasks  
3. Delete Task  
4. Sort Tasks  
5. Task Suggestions  
6. Show Additional Notes of a Task  
7. Delete All Tasks  
8. Exit  

---

## Features

- Menu-driven interface using switch-case statements  
- Add, view, and manage multiple tasks  
- Persistent storage using binary files  
- Display all stored tasks in a formatted manner  
- Delete individual tasks  
- Delete all tasks at once  
- Sort tasks based on defined criteria  
- Task suggestion functionality  
- Support for additional notes for each task  
- Exception handling for file operations  
- Structured and modular code design  

---

## Concepts Demonstrated

- Object-oriented and structured programming in C++  
- Switch-case based control flow  
- Binary file handling using fstream  
- Reading and writing structured data to files  
- Exception handling for file safety and error handling  
- Sorting techniques on stored records  
- Input validation and formatted output using iomanip  
- Modular function-based program design  

---

## Data Storage Approach

All tasks are stored in a binary file using file stream objects.  
Each task is written and read as a structured record, allowing data to persist across multiple executions of the program.

Exception handling is used to manage file access errors and ensure reliable read and write operations.

---

## What I Learned

- Implementing persistent storage using binary files in C++  
- Handling file operations safely using exception handling  
- Managing structured data with file streams  
- Designing a complete menu-driven console application  
- Applying sorting and data management logic  
- Writing clean, readable, and modular C++ code  

---

## Future Improvements

- GUI-based extension using C++ Qt  
  (Implemented and available in a different repository)

- GUI-based extension using JavaFX, with file-based storage replaced by a MySQL database using JDBC  
  (Implemented and available in a different repository)

---

## Author

Prathamesh Gawas

---

## Repository Description

Menu-driven console-based To-Do list application in C++ using binary file storage and exception handling.

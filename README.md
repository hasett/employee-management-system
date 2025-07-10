Employee Management System 

Introduction

This Employee Management System is a simple C++ console application designed to help small businesses or students manage basic employee records easily.It allows you to add employee details (ID, name, and salary), view all stored employees, search for a specific employee by ID, and delete an employee if needed — all from the command line. The program stores data in a plain text file (employees.txt), so the employee records remain saved even after the program is closed and reopened.

Key Features
·	Add Employee: Enter a new employee’s ID, name, and salary to a file.
·	View All Employees: Display a list of all employees currently saved.
·	Search by ID: Quickly find an employee’s information by entering their ID.
·	Delete by ID: Remove an employee’s record permanently by ID.
·	Persistent Storage: Uses file I/O to keep records between sessions.


How It Works

The Employee Management System runs in the command line and uses text file storage to keep employee data between program runs. Here’s a step‑by‑step overview of how the program works:
1 Starting the ProgramWhen you run the program, it shows a simple menu with five options:
·	Add Employee
·	View All Employees
·	Search Employee by ID
·	Delete Employee by ID
·	Exit
You pick an option by entering the corresponding number.

2️ Adding an EmployeeIf you choose Add Employee, the program asks you to:
·	Enter the employee’s ID
·	Enter the employee’s name
·	Enter the employee’s salary
These details are stored in a simple text file (employees.txt). Each employee’s record is saved on a new line in the format.
3️ Viewing All Employees when you select View All Employees, the program opens the text file and reads each line one by one.It splits each line into ID, name, and salary, then displays them neatly on the screen.
4️ Searching for an Employee by ID. If you choose Search Employee by ID, the program asks for an ID.It then scans the text file line by line, looking for a matching ID.If it finds a match, it displays the employee’s full details.If not, it tells you the employee was not found.
5 Deleting an Employee by ID. If you choose Delete Employee by ID, the program asks for an ID to delete.It then copies every record except the one with the matching ID into a temporary file.After copying, it deletes the old file and renames the temporary file to employees.txt.This effectively removes the selected employee from the system.
6️ Exiting the Program. Choosing Exit stops the program safely.

Why Use It

This program is a great practice project for C++ beginners. It covers:
·	Object-oriented programming (classes and objects)
·	File handling (ifstream and ofstream)
·	String operations
·	Loops and conditional logic
·	Basic console input/output


References

·	Learn C++ File Handling – YouTube
·	C++ File I/O – W3Schools
·	GeeksforGeeks: File Handling in C++(https://www.geeksforgeeks.org/file-handling-c-classes/)


      
    Group Members 			      		ID
1.	Amira Mehdi  …………………….…....... RCD/0894/2017
2.	Ananya Alemayehu ............. RCD/0895/2017
3.	Edom Tsegaye…………………….….....……. RCD/0906/2017
4.	Hasset Tefera ……………………………..... RCD/0915/2017
5.	Hermela  Melaku ………………………..... RCD/0918/2017
6.	Hiwot Adane …………………………..…......RCD/0920/2017
7.	Ikram nesro ……………………………….......RCD/1648/2017



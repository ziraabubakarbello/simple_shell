PROJECT TITLE
===============
SIMPLE-SHELL

PROJECT OBJECTIVE
==================
Creating and implementing the shell command-line interface using a C-program.

PROJECT DESCRIPTION
====================
A shell is a type of computer program called a command-line interpreter that lets Linux and Unix users control their operating systems with command-line interfaces. Shells allow users to communicate efficiently and directly with their operating systems. A shell has two categories, command-line shell and graphical shell. Command-line shells are accessed using command-line interfaces where systems receive input in human-readable commands and then use the command-line interfaces to display the output. Graphical shells use a graphical user interface (GUI) to perform interactions and essential operations such as opening, closing, and saving files. 
There are various types of shell programs which includes the Korn shell (kh), Bourne shell (sh), Bourne Again shell (bash), e.t.c but for this project we are going to the working with the simplest type which is the Bourne(sh) shell. 
In this Simple-shell project we are going to be building our own version of the Bourne shell program which can basically accept any command entered by the user, execute and print out the result to the standard output which in this case is the ubuntu terminal.

From the definition of a shell program described above In other to create our own we have to be able to write a program that can perform at least four basic operations;
*Prompt: Create a prompt for the user to type in whatever commands they wish to
*Read-line: Reads whatever command that is entered from the standard input.
*Parse-line: Break the command into individual strings. For instance if someone types cat main.c into the terminal. we want to grab that and break it into two strings cat and main.c. (This process is also referred to as tokenization).
*Execute: Execute the commands using fork() and the execve() command in the child process to replace the running program with the program we actually want to run.

REQUIREMENTS
=============
Header files(stdio.h, stdlib.h,unistd.h, string.h, <sys/wait.h>)
function prototypes: (man 3 files and man 2 files)
Enviroment variables: getenv, setenv, unsetenv.
Builtin commands: cd, exits, ls, errors.

COLLABORATORS
==============
Akinbowale Kehinde
Zira Abubakar Bello
 

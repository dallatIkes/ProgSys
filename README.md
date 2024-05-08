# System Programming

Welcome, thanks for using my system programming repository. Here I try to document every practival hands-on computer sessions. It may not be up to date, but I'm working on it...

## Table of contents
1. [How does it work ?](#how-does-it-work)  
2. [Headers](#headers)
   1. [colors.h](#colorsh)
   2. [prog_sys.h](#prog_sysh)
   3. [std.h](#stdh)
3. [Makefile Makefile Makefile](#makefile-makefile-makefile)
   1. [Makefile](#makefile)
   2. [TP_Makefile](#tp_makefile)

## How does it work ?
I create a new directory for each new session we have with the same structure :
```
./TP_n/
├── .gitignore
├── bin/
├── doc/
│   ├── .gitignore
│   └── notes.md
├── src/
└── Makefile
```
Generally what you're looking for are the source code in ``src/`` and the report in ``doc/``.  

## Headers
In system programming, many libraries are necessary, and we always need to include the same header files. Thus, I created 3 header files regrouping them to simplify things : ``colors.h``, ``prog_sys.h`` and ``std.h``. Including them in your source file is like including any standard library, the Makefile will take care of finding them in the ``utils`` directory during the compilation.
```C
#include <colors.h>
#include <prog_sys.h>
#include <std.h>

// make sure to use <> and not ""
// refer to the Makefile for further explanation
```
### colors.h
This file is just here to define some color codes. I use it to differenciate the outputs of different processes.
```C
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
``` 
### prog_sys.h
This file includes all the libraries needed by the functions and procedures we study in system programming.
```C
#include <unistd.h>   /* sleep */
#include <signal.h>   /* signal */
#include <unistd.h>   /* sleep, alarm, fork */
#include <sys/wait.h> /* wait */
#include <sys/types.h> /* open */
#include <sys/stat.h> /* open */
#include <fcntl.h> /* O_WRONLY, O_RDONLY */
```
### std.h
This file includes all the standard libraries usually used in C
```C
#include <stdio.h>  /* printf */
#include <stdlib.h> /* fopen, srand, rand*/
#include <string.h> /* strlen, strsignal */
```

## Makefile Makefile Makefile
In the main directory are two Makefiles : ``Makefile`` and ``TP_Makefile``. The first one is for creating a new session directory and the second one is to automate the compilation.
### Makefile
In this file, there is only one command : ``newTP : $(TP)``. As you can see, it requires a parameter which is the name of the directory you wich to create and it will automatically create the directory and all of ots sub-directories while alos importing the usefule files from ``utils/``.
#### Example :
```bash
make newTP TP=TP_test

# Ouput :

# === Création du répertoire TP_test
# === Création des sous-répertoires src bin et doc
# === Création du fichier Markdown
# === Création du fichier Makefile
# === Création du fichier .gitignore
```
### TP_Makefile
This file a simple automation of the compilation process. I just added two parameters : ``$(src)`` and ``$(bin)`` because many source files and binaries are used during a single session. Please refer to the following example for better understanding. Don't bother copying it in your directory the first Makefile automatically does it at its creation.
#### Example :
```bash
make bin=binName src=srcFile 
# Warning : do not add the .c suffix to the source file name
```

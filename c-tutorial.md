
Sunday, 2026-01-04

**Prerequisite**
Install the tools for C language, two main sets of C/C++ compilers that are widely used includes:

- `gcc` : GNU's C compiler, older but widely used. Installing it also gives `g++`, compiler for C++
- `clang` : newer C compiler, slightly faster, and comes with error messages are easier to understand. Installing it also adds `clang++`, compiler for C++

Installing command for ubuntu:
```
sudo apt install clang 
sudo apt install gcc
```

**A. Folder Structure**
It is recommended to have basic folder structure for a C project, even when learning.  Example can be seen as below:

- Project root
	- `source/` : where the source files are (.c, .cpp)
	- `include/` : contains header files (.h, .hpp)
	- `build/` : holds the intermediate files (.o)
	- `bin`/ : where it contains final executable(s) (.exe) of the program

**B. Single File C Program**
Create a file named `main.c` inside the `source/` folder, and write codes below:

```
#include <stdio.h>

int main() {
	puts("hello world");
	return 0; 
}
```

to build the program, run commands below
```
clang --std=c23 source/main.c -c -o build/main.o

clang build/main.o -o bin/program.exe
```

the commands above will compile an executable file `bin/program.exe`. Compiled executables also known as **binary**, not to be confused with the numeral system. 

To run the program on linux, simply open a terminal on the root project, and run `./bin/program.exe`. The program example above is a command line program, so it should be run from the terminal, opening it by clicking will result in window that starts up and close immediately.

**Explanation for the compiling process:**
CPU does not execute .C file, or any text file. It only operates on bytecode, data that made up entirely of bytes for example: `0x01 0x04 0xF3 0xFC`.  To make the bytecode the .C file needs to be compiled into an object file; a file that stores the bytecode of a .C program. 

```
clang --std=c23 source/main.c -c -o build/main.o
```

Command above uses the `-c` flag to signal that clang should compile into an object file, and uses `-o` to signify `<output>` to output the compilation into the object file `build/main.o`, also `--std=c23` is used to tell clang to use latest version of C for this tutorial, the C23. Compiler defaults to a slightly older version of C, as such explicitly setting the version is needed. 

Now, even if the `.c` file is compiled into an object file, the object files are not executables. **They are "raw" compiled codes**. The computer does not know what to do with it, in essence these raw codes need to be "built" so it can be executed. As such the final step is required to create the executable:

```
clang build/main.o -o bin/program.exe
```

Command above uses a component of the compiler called "linker" to link the newly created object file(s) into a single binary, and the `-o` signify the output where the result will be generated, in this case `bin.program.exe`. Linking binary like this also automatically adds  runtime into it.

In short, writing any C program will involves :
- compiling source into object files
- linking object files into an executable

It is important to know both compile and link are distict steps, as there will be a lot of times where errors are from compilers, while others are from linkers.

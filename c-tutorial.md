
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

**Explanation for the codes**
```
#include <stdio.h>
```
`#include` is not a function but a **preprocessor directive**, which used to include one of C's built in files, in this case it's **stdio.h**, into the current file, which stands for **standard input/output** functions that can be used inside the code, like `puts()` and such. This **stdio.h** is required to include in order to use `printf()` and `puts()`. 

```
int main() { 

}
```
All C/C++ program needs function named `main()`. This is the main thing that executed when the program starts, as such without it there will be error when a program is linked. The lines above define the function `main()`. 


```
puts("hello world");
```
The line above  calls one of C's built in function `puts()`, which outputs the string to terminal. 

```
return 0;
```
Every program of C returns a number, so that the OS knows how the process ended. If a process ended safely, a 0 is returned. On error, `-1` is returned. Other values depend on the system. This number is referred to as exit status. Because `main()` is a function that returns an integer/int, hence the `int main()`, the exit code of the program is whatever it returns 

**Introduction to printing**
`puts()` is only for printing strings and nothing more, for variables use `printf()` instead.

```
printf("hello world\n");
```
The `\n` at the end is a control character, specifically called newline character. It used to tell the terminal to shift the cursor to line below.

Without it, the cursor does not move and instead continues from the same line. For example:
```
printf("hello");
printf("world");
printf("!");
```
the lines above will prints:
```
helloworld!
```
instead of:
```
hello
world 
!
```
because the cursor did not move below.

**Basics**
1. Comments
```c
// comments that look like this span a single line.
/* On the other hand, if you really need to be writing longer blocks of notes,
multi-line comments can be written like this. */
```

2. Variables
To **declare** something is to make it known. To **define** something is to assign it's data to value, also sometimes called **assignment**. To create a variable can be done by either declare and define it, or just declare it. 

```c
// to declare a variable, write it's type, then the name. 
int number1; 

// you can then later assign the variable to whatever you want. 
number1 = 4;

// variables can be defined and declared in the same line. 
int number2 = 7;
```

Not defining variable when declaring it causes the variable staying uninitialized, unknown value. In C these valuable don't get assigned automatically, as such always initialize the variable to prevent using uninitialized data.

Do not re-define a variable, as it would cause error. Instead re-assign it to change the value.
```c
// why are you setting number's type twice in a row? this would error!
int number = 3;
int number = 7;

// OK, this would set number to 3, then re-assign it as 7.
int number = 3;
number = 7;
```

Variables in C are block scoped, only accessible to the block they declared in.  Curly braces can be used to create a scope
```c
int main() {
	int number1 = 4;

	// note: curly braces on their own can be used to create a new scope.
	{
		int number2 = number1 + 2;
	}

	int number3 = number1 + number2; // error! number2 is in a diferent scope.
}
```

Variables with a value that won't change is called `constants`. In C it is denoted with `const` before the variable's type and name:
```c
const int MAX_VALUE = 40;
MAX_VALUE = 3; // this line would error! you can't modify a constant
```

3. Printing variables

For printing numbers to terminal, `puts()` cannot be used as it's only for strings. The alternative would be `printf()` (*print formatted*). This function also supports **variadic arguments**, meaning that accept various kind of arguments instead of just printing single variable at a time.

Unlike `puts()`, `printf()` needs two main things to pass into it: a **format**, which describes the layout and what kind of data each argument will be interpreted as, and the arguments themselves:

```c
#include <stdio.h>

int main() {
	// Our variables that we will be printing.
	int num1 = 5;
	int num2 = 3;
	int num3 = 12;

	printf(
		"three numbers: %d, %d, and 0x%02X\n",
		num1,num2,num3
	);

	return 0;
}
```

This would print:
```
three numbers: 5, 3, and 0x0C
```

Notice that newline `\n` need to be added just like when using `puts()`.
As for how the format works, take a look on this string for the formatting:

```
"three numbers: %d, %d, and 0x%02X\n"

```

`%d` here is a **format specifier**. All of them starts with `%`, followed by characters for additional options. After each format specifier is processed, `printf` then proceeds to the next argument in its list of arguments. So the first `%d` will be replaced with `num1`, second `%d` replaced by `num2`, and third will be replaced with `num3`, third specifier uses `%02X` format specifier which can be explained below:

- `0`, so empty spaces are filled with zeroes.
- `2`, so the text will have empty space added until it's `2` characters long.
- `X`, so the text will have hexadecimal representation, rather than hexadecimal representation. Since this is `X` and not `x`, the text will also be capitalized.

Notice that the `0x` part isn't actually part of the format specifier at all, it's just normal text. For a list of format specifiers, [see the documentation for printf](https://en.cppreference.com/w/c/io/fprintf.html)

 **Another important thing to add is that the number of arguments must always match the number of format specifiers.** `printf` is not smart: it will blindly attempt to use more than its able to use. If you were to attempt to do:

```c
printf("numbers: %d, %d\n",1)
```
crashes could end up occuring, as a result of the second format specifier having no argument to use.


**The Preprocessor**

In the previous code examples, notice that some lines started with `#` character. As explained before, the computer splits the compilation process into several steps, and one of the earliest ones is preprocessing. 

Before any of the code is properly compiled, the preprocessor, which is a very advanced text replacement program, scans through each lines and process any `#includes`, `#defines`, and such. To see this in practice take a look on main concept in C language: the header files. Put the example file below into `include/player.h` and `source/main.c`

`include/player.h`:
```c
#define PLAYER_MAXHEALTH (30)
#define PLAYER_DAMAGEVAL (PLAYER_MAXHEALTH-3)

// a small note: the "extern" keyword is usually used for undefined variables
// that get declared later on in a different file. It's not *needed*, so it's
// usually just there for clarification.
extern int gPlayerHP;
```

`source/main.c`
```c
// another note: for #include, <> is usually used for builtin header files. ""
// is the one that's commonly used for user-made headers.

#include <stdio.h>
#include "player.h"

int gPlayerHP = PLAYER_MAXHEALTH;

int main() {
	gPlayerHP -= PLAYER_DAMAGEVAL;

	printf("player HP: %d\n",gPlayerHP);
	return 0;
}
```

To compile, add the path of the header files, since the compiler does not know where to find it. Use the `-I<includepath>`. Since the header files are in `include/` folder, it's written as `-Iinclude`

```
clang --std=c23 -Iinclude source/main.c -c -o build/main.o clang build/main.o -o bin/program.exe
```

1. Macros
from the `include/player.h` file, notice that it has 2 defines, and the value of these can be used directly as shown above:

```c
int gPlayerHP = PLAYER_MAXHEALTH;
```
this way, `gPlayerHP`'s value would become `PLAYER_MAXHEALTH`, that is 30.

These are known as Macros. Macros are used to hold value as constant. Do note however, that when defining macros values with operation, the MDAS rule apply:

```c
#define DAMAGEVAL 30 - 3
#define DAMAGEMUL 2

int number = DAMAGEVAL * DAMAGEMUL;
```

The expression above would evaluate to:
```c
int number = 30 - 3 * 2;
```
In other words, 24. Remember, Multiplication and Division first, then Addition and Subtraction.

As such wrapping the macros's definition inside parentheses could change it:
```c
#define DAMAGEVAL (30 - 3)
#define DAMAGEMUL (2)

// number would be 54,
int number = DAMAGEVAL * DAMAGEMUL;
```


2. Including headers
To explain more in detail, `#include` is a basic preprocessor directive that includes a file in the current file it's in. It preprocesses that file's text, then includes all of that onto the actual file. To demonstrate this is how it would look like in `main.c` where player.h header is included.

```c

// <stdio.h is a long file, but imagine it's here...>
#define PLAYER_MAXHEALTH 30
#define PLAYER_DAMAGEVAL PLAYER_MAXHEALTH-3
extern int gPlayerHP;

int gPlayerHP = PLAYER_MAXHEALTH;

int main() {
	gPlayerHP -= PLAYER_DAMAGEVAL;

	printf("player HP: %d\n",gPlayerHP);
	return 0;
}
```

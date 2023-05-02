<br/>
<p align="center">
  <a href="https://github.com/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf">
    <img src="https://www.iconpacks.net/icons/1/free-printer-icon-1434-thumb.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Flexible Output Formatting with C <em>ft_printf</em></h3>

  <p align="center">
    An Awesome ReadME Generator To Jumpstart Your Projects!
    <br/>
    <br/>
    <a href="https://github.com/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf">View Demo</a>
    .
    <a href="https://github.com/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf/issues">Report Bug</a>
    .
    <a href="https://github.com/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf/issues">Request Feature</a>
  </p>
</p>

<div  style="display: flex; justify-content: center;">
<a  href="https://twitter.com/i_am_amine" target="_blank">
  <img  alt="Twitter Follow"  src="https://img.shields.io/twitter/follow/i_am_amine?style=social">
</a>
<img  src="https://img.shields.io/github/repo-size/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf"  alt="Repo Size">
<img  src="https://img.shields.io/github/last-commit/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf"  alt="Last Commit">
<img  src="https://img.shields.io/github/license/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf" alt="License" >
</div>

## Table Of Contents

- [Table Of Contents](#table-of-contents)
- [About The Project](#about-the-project)
- [Built With](#built-with)
- [Explanations](#explanations)
  - [The syntax for a format placeholder](#the-syntax-for-a-format-placeholder)
  - [Parameter field](#parameter-field)
  - [Flags field](#flags-field)
    - [The `-` flag](#the---flag)
    - [The `+` flag](#the--flag)
    - [The ' ' _(space character)_ flag](#the--space-character-flag)
    - [The `0` flag](#the-0-flag)
    - [The `#` flag](#the--flag-1)
    - [Width field](#width-field)
    - [Precision field](#precision-field)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
  - [Creating A Pull Request](#creating-a-pull-request)
- [Sources](#sources)
- [License](#license)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)

## About The Project

The ft_printf project is a custom implementation of the printf function in the C programming language. It aims to replicate the functionality and behavior of the standard printf function while providing additional features and customization options.

The project focuses on formatting and outputting data to the standard output stream, allowing developers to print formatted text with various data types, such as strings, characters, integers, floats, and pointers. It supports a wide range of format specifiers, modifiers, and flags, allowing precise control over the formatting and alignment of the output.

The ft_printf project serves as a valuable exercise in parsing input, processing format strings, and generating formatted output. It challenges developers to consider edge cases, handle error conditions, and ensure compatibility with different platforms and compilers.


## Built With

The ft_printf project is implemented using the following technologies and tools:

- C Programming Language: The project is written in the C programming language, taking advantage of its low-level capabilities and efficient memory management.

- Standard Library: The project utilizes various functions from the standard C library, such as string manipulation functions (e.g., strlen, strcpy), memory management functions (e.g., malloc, free), and input/output functions (e.g., putchar, putstr).

- Variable Arguments: The project leverages the variable arguments feature in C, allowing for the handling of a variable number of arguments passed to the printf-like function.

- String Formatting: The project implements custom string formatting logic, parsing format specifiers and converting corresponding arguments into formatted strings.

- Data Type Conversion: The project includes functionality for converting different data types (e.g., integers, floats, strings) into their formatted string representations.

- Format Specifiers and Modifiers: The project supports a wide range of format specifiers and modifiers, allowing for precise control over the formatting and alignment of the output.

- Memory Allocation: The project utilizes dynamic memory allocation functions (e.g., malloc) to manage memory for formatted strings and other data structures.

- Error Handling: The project includes error handling mechanisms to handle invalid format strings, memory allocation failures, and other error conditions.

- Integrated Development Environment (IDE): Developers may use an IDE of their choice, such as Visual Studio Code, CLion, or Xcode, for writing, debugging, and testing the ft_printf project. The one used in this project is Visual Studio Code

By leveraging these technologies and tools, the ft_printf project provides a robust and customizable implementation of the printf function, enabling developers to format and print data in a flexible and controlled manner.
## Explanations

### The syntax for a format placeholder

```text
%[parameter][flags][width][.precision][length]type
```

### Parameter field

_**Note** This is a POSIX extension and not in C99_

The Parameter field takes as input the index of the parameter _aka_ the `n`th parameter _(or 'the `n`th **argument**', whatever you want to call it)_ followed by a `$` Dollar sign. After that we can apply some flags just as we would do normally.

_**Note** that the index should always start from `1` and not `0`_.

Once you specify a parameter field for one parameter, you should do the same with all the other parameters, i.e. you can't just have 5 parameters, apply the "Parameter field" _(aka `n$`)_ to, e.g., the _4th_ element, leave the others without indexing, and expect `printf()` to just magically figure out which flag should point to which parameter, it's either **All of them** or **None of them**.

- **Example** of a good use-case

```c
#include <stdio.h>

int main(void)
{
    printf("%3$d; %1$d; %4$d; %2$d",16, 17, 18, 19)
    return (0);
}
```

```text
Output:

18; 16; 19; 17
```

- **Example** that'll produce an error

```c
#include <stdio.h>

int main(void)
{
    printf("%3$d; %1$d; %d; %2$d",16, 17, 18, 19)
    return (0);
}
```

```text
Output:

file.c:5:26: error: missing $ operand number in format
5   |     printf("%3$d; %1$d; %d; %2$d", 16, 17, 18, 19)
    |            ^~~~~~~~~~~~~~~~~~~~
```

### Flags field

#### The `-` flag

When used, the content becomes Left-Justified _(instead of the default Right-Justification)_.

- **_Example:_**

```c
#include <stdio.h>

int main(void)
{
    printf("Without the '-' flag:\n");
    printf("\"%12s\"\n\n", "Hello");
    printf("Without the '-' flag:\n");
    printf("\"%-12s\"\n", "Hello");
    return (0);
}
```

```text
Output:

Without the '-' flag:
"       Hello"

With the '-' flag:
"Hello       "
```

_We will later see what the number `12` means in this case._

#### The `+` flag

When used _(with signed-numeric types)_, it'll prepend a `+` sign if the integer is positive, or a `-` sign if it's negative; As oppose to the default behaviour where the `+` sign is omitted in case the integer is positive.

- **_Example:_**

```c
#include <stdio.h>

int main(void)
{
    printf("Without the '+' flag:\n");
    printf("%d\n", 69);
    printf("%d\n\n", -69);
    printf("With the '+' flag:\n");
    printf("%+d\n", 69);
    printf("%+d\n", -69);
    return (0);
}
```

```text
Output:

Without the '+' flag:
69
-69

With the '+' flag:
+69
-69
```

#### The '&emsp;' _(space character)_ flag

When used _(with signed-numeric types)_, it'll prepend a '&emsp;' *(space character)* if the integer is positive, or a `-` sign if it's negative. It's behaviour is quite similar to the `+` flag, exept that it prepends a '&emsp;' instead of a `+`.

- **_Example:_**

```c
#include <stdio.h>

int main(void)
{
    printf("Without the ' ' (space character) flag:\n");
    printf("%d\n", 420);
    printf("%d\n\n", -420);
    printf("With the ' ' (space character) flag:\n");
    printf("% d\n", 420);
    printf("% d\n", -420);
    return (0);
}
```

```text
Output:

Without the ' ' (space character) flag:
420
-420

With the ' ' (space character) flag:
 420
-420
```

_**Remember:** this flag is ignored if the `+` flag exists._

#### The `0` flag

When used with the `%d` _or_ `%i` _or_ `%x` _or_ `%X`, and with the **Width** flag _(we'll get to that later on)_, it replaces the default blank spaces for numeric types with _`0`'s_.

- **_Example:_**

```c
#include <stdio.h>

int main(void)
{
 printf("Without the '0' flag:\n");
    printf("\"%5d\"\n\n", 1);
    printf("With the '0' flag:\n");
    printf("\"%05d\"\n", 1);
    return (0);
}
```

```text
Output:

Without the '0' flag:
"    1"

With the '0' flag:
"00001"
```

_**Remember** the `0` flag is ignored if precision is specified for an integer or if the `-` flag is specified._

#### The `#` flag

When used with the `%x` _or_ `%X` formats, it prefixes the output with a `0x` _or a_ `0X` respectively, i.e. it adds either a `0x` at the beginning of the output given by the `%x` formats, or a `0X` at the beginning of the output given by the `%X`.

- **_Example:_**

```c
#include <stdio.h>

int main(void)
{
 printf("Without the '#' flag:\n");
    printf("%x\n", 180);
    printf("%X\n\n", 180);
    printf("With the '#' flag:\n");
    printf("%#x\n", 180);
    printf("%#X\n", 180);
    return (0);
}
```

```text
Output:

Without the '#' flag:
b4
B4

With the '#' flag:
0xb4
0XB4
```

_The `#` flag should not be used with `c` or `d` or `i` or `u` or `s` types._

#### Width field

It's basicaly a non-negative decimal number that represents the minimum number of bytes to be printed. If the number of bytes in the output value is less than the specified width, blanks are added on the _Right_ _(or to the Left if the `-` flag is specified)_.

Width never causes a value to be truncated; if the number of bytes in the output value is greater than the specified width, or width is not given, all characters of the value are printed.

The width specification can be an asterisk `*`, in which case an argument —from the argument list— supplies the value. The width argument must precede the value being formatted in the argument list.

- **Example:**

```c
int main(void)
{
 printf("|00| Without the Width:\n");
    printf("\"%d\"\n\n", 69420);
    printf("|01| With the Width:\n");
    printf("\"%10d\"\n\n", 69420);
    printf("|02| With the Width:\n");
    printf("\"%-10d\"\n\n", 69420);
    printf("|03| With the Width:\n");
    printf("\"%5d\"\n\n", 69420);
    printf("|04| With the Width:\n");
    printf("\"%2d\"\n\n", 69420);
    printf("|05| With the Width:\n");
    printf("\"%*d\"\n", 15, 69420);
    return (0);
}
```

```text
Output:

|00| Without the Width:
"69420"

|01| With the Width:
"     69420"

|02| With the Width:
"69420     "

|03| With the Width:
"69420"

|04| With the Width:
"69420"

|05| With the Width:
"          69420"
```

#### Precision field

The **Precision field** can be described as the opposite of what the _Width field_ does, while the latter specifies the minimum number of bytes to be printed, the _Precision field_ specifies the maximum number of bytes to be printed; another thing is that  the _Width field_ doesn't truncate the output in any case, the _Precision field_ does in case the original length of the output exceeds the maximum specified length in the _Precision field_.

The Precision specification can be an asterisk `*`, in which case an argument —from the argument list— supplies the value. The Precision argument must precede the value being formatted in the argument list.

In our case, the precision will only be applied to `%s`, `%d` and `%i`. If the specified width exceeds the total length of the string, the string gets printed, and that's all, no spaces, and no `0`'s. If it's applied to a digit _(`%d` or `%i`)_, and the specified length exceeds the total length of the digits in the given number, the rest is filled with `0`'s, but if it's the opposite, and the specified length is smaller than the total length of the number, it doesn't get truncated.

_**Note** that the precision field doesn't work with `%c`, and outputs a warning —but does work— when used with `%p`, and_

- **Example:**

```c
int main(void)
{
    printf("Without the Precision:\t%%s\n");
    printf("\"%s\"\n\n", "Hello, world!");
    printf("With the Precision:\t%%.10s\n");
    printf("\"%.10s\"\n\n", "Hello, world!");
    printf("With the Precision:\t%%.15s\n");
    printf("\"%.15s\"\n\n", "Hello, world!");
    printf("With the Precision:\t%%-15.10s\n");
    printf("\"%-15.10s\"\n\n", "Hello, world!");
    printf("With the Precision:\t%%15.10s\n");
    printf("\"%15.10s\"\n\n", "Hello, world!");
    return (0);
}
```

```text
Output:

Without the Precision:  %s
"Hello, world!"

With the Precision:     %.10s
"Hello, wor"

With the Precision:     %.15s
"Hello, world!"

With the Precision:     %-15.10s
"Hello, wor     "

With the Precision:     %15.10s
"     Hello, wor"
```

## Getting Started

To get started with the ft_printf project, follow the steps below:

### Prerequisites

Before you can use the ft_printf project, ensure that you have the following prerequisites in place:

- C Compiler:

  - Ensure that you have a C compiler installed on your system. The ft_printf project is written in C and requires a compatible C compiler to compile and execute the code. Commonly used C compilers include GCC and Clang.

- Operating System:

  - The ft_printf project is designed to work on Unix-like operating systems such as Linux and macOS. Ensure that you have a supported operating system installed on your machine.

- Dependencies:

  - The ft_printf project does not have any external dependencies. It is a standalone project that only requires the standard C library.

- Makefile:

  - The ft_printf project provides a Makefile to simplify the build process. Ensure that you have the make utility installed on your system. This tool will read the Makefile and automatically compile the project for you. You can check if make is installed by running the make --version command in your terminal.

- Text Editor or IDE:

  - You'll need a text editor or integrated development environment (IDE) to view and edit the source code. Choose a text editor or IDE that you are comfortable with, such as Visual Studio Code, Atom, or Sublime Text.

By fulfilling these prerequisites, you'll be ready to proceed with using the ft_printf project. Ensure that you have the necessary tools and environment set up before diving into the codebase.

### Installation

To install and use the ft_printf project, follow these steps:

1. Clone the Repository: Start by cloning the ft_printf repository to your local machine. Open a terminal and navigate to the directory where you want to store the project files. Then, run the following command:

```bash
git clone <repository_url>
```

2. Compile the Project: Once you have cloned the repository, navigate to the project directory using the terminal. Inside the project directory, you will find a Makefile. Run the following command to compile the project:

```bash
make bonus
```

This command will read the Makefile and compile the necessary source files to generate the executable.

3. Executable: After the compilation process is complete, you will find an executable file generated in the project directory. The name of the executable is typically ft_printf or similar. This is the binary file that you can run to execute the ft_printf program.

## Usage

To use the ft_printf library in your own projects, follow these steps:

1. Include the Header File: In the source file where you want to use the ft_printf function, include the ft_printf header file by adding the following line at the top:

```c
#include "ft_printf.h"
```

2. Format and Print: To print formatted output using ft_printf, you can use the function in a similar way as the standard printf function. The syntax is as follows:

```c
int ft_printf(const char *format, ...);
```

  - The format parameter is a string that specifies the format of the output. It can include format specifiers, such as %d, %s, %c, etc., similar to the standard printf function.

  - For example, you can use the following code to print a formatted string with ft_printf:

```c
ft_printf("Hello, %s! The value of x is %d.", "John", x);
```

3. Compile and Run: After writing your code, compile the source file(s) that include the ft_printf function along with the ft_printf library. Make sure to link the library during the compilation process. For example:

```bash
gcc -o my_program my_program.c -L<path_to_ft_printf_library> -lft_printf
```

Replace <path_to_ft_printf_library> with the actual path where the ft_printf library is located.

4. Execute: Once the compilation process is complete, run the generated executable to see the output. For example:

```bash
./my_program
```

  - The program will execute, and the output will be displayed based on the format string and provided arguments.

By following these usage steps, you can integrate and use the ft_printf library in your own projects, allowing you to print formatted output with ease.

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
* If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf/issues/new) to discuss it, or directly create a pull request after you edit the *README.md* file with necessary changes.
* Please make sure you check your spelling and grammar.
* Create individual PR for each suggestion.
* Please also read through the [Code Of Conduct](https://github.com/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf/blob/main/CODE_OF_CONDUCT.md) before posting your first idea as well.

### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Sources

- Wikipedia: [https://en.wikipedia.org/wiki/Printf_format_string](https://en.wikipedia.org/wiki/Printf_format_string)

- IBM's Docs: [https://www.ibm.com/docs/en/i/7.4?topic=functions-printf-print-formatted-characters](https://www.ibm.com/docs/en/i/7.4?topic=functions-printf-print-formatted-characters)

- Other random websites:

  - [https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html)

  - [https://flylib.com/books/en/2.254.1/using_flags_in_the_printf_format_string.html](https://flylib.com/books/en/2.254.1/using_flags_in_the_printf_format_string.html)

  - [https://www.codingunit.com/printf-format-specifiers-format-conversions-and-formatted-output](https://www.codingunit.com/printf-format-specifiers-format-conversions-and-formatted-output)

  - [https://alvinalexander.com/programming/printf-format-cheat-sheet/](https://alvinalexander.com/programming/printf-format-cheat-sheet/)

## License

Distributed under the MIT License. See [LICENSE](https://github.com/The-Intruder/Flexible-Output-Formatting-with-C-aka-ft_printf/blob/main/LICENSE.md) for more information.

## Authors

* **Mohamed Amine Naimi** - *Computer Science Student* - [Mohamed Amine Naimi](https://github.com/The-Intruder/) - *Built the ft_printf project*

## Acknowledgements

* [The-Intruder](https://github.com/The-Intruder/)

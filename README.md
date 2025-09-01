# AccelC
AccelC is a lightweight domain-specific compiler prototype in C that translates a custom high-level toy syntax into equivalent C code, performs conditional branching, arithmetic expansion, and code generation, then invokes gcc for compilation and execution—simulating end-to-end compilation workflow.

AccelC is a lightweight toy compiler written in C. It takes a simplified custom syntax and translates it into valid C code, which is then compiled and executed automatically. This project demonstrates the fundamentals of lexical scanning, parsing, code generation, and conditional execution in a compact form.

✨ Features

Custom Commands Supported

PRINT <text> → Prints text to the console

SET <var> <value> → Declares and assigns integer variables

ADD <var1> <var2> → Prints the sum of two variables

MUL <var1> <var2> → Prints the product of two variables

IF <var> > <num> PRINT <text> → Simple conditional check with print

Generates C code (output.c)

Automatically compiles using gcc

Runs the generated executable instantly

🖥 Example Usage
Input (AccelC language):
SET x 20  
SET y 10  
ADD x y  
MUL x y  
IF x > 15 PRINT x is large  
PRINT Hello World  
END  

Generated C Code (output.c):
#include <stdio.h>

int main() {
    int x = 20;
    int y = 10;
    printf("%d\n", (x + y));
    printf("%d\n", (x * y));
    if (x > 15) printf("x is large\n");
    printf("Hello World\n");
    return 0;
}

Output after compilation:
30
200
x is large
Hello World

⚙️ How It Works

User writes code in a simple toy syntax.

AccelC parses input line-by-line.

Corresponding C statements are generated into output.c.

The program invokes gcc to compile the file.

Executable is automatically run to display the result.

🚀 Getting Started
Prerequisites

GCC installed (sudo apt install gcc on Linux)

Standard C compiler

Build & Run
gcc accelC.c -o accelC
./accelC

🔮 Future Enhancements

Support for ELSE and nested conditionals

Loops (FOR, WHILE)

Function definitions and calls

String and array operations

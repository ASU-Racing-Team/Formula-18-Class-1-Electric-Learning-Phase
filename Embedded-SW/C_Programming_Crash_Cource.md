# C Programming Crash Course
## Syntax
___
### Variables, Constants and built-in data types
   Variables and constants are the basic data objects manipulated in a program.  
   Declarations list the variables to be used, and state what type they have and perhaps what their initial values are.  
   The C programming language has some built in data types.
```C
// Old data types and declaration

char c0 = 'a' ; // single byte (8 bits) can be signed or unsigned 
short s0 = 52; // size architecture dependant but always less than or equal to int
int i0 = 42; // size is architecture dependant
long l0 = 65 // size is architecture dependant but always more or equal to int
float f0 = 3.1415; // single-precision floating point number, IEEE 754 standard
double d0 = 2.718; // double-precision floating point number, IEEE 754 standard
unsigned char c1 = 'b'; 
unsigned int i1 = 43;

// new fixed size int data types

int8_t i8; // always 1 bytes
int16_t i16; // always 2 bytes
int32_t i32; // always 4 bytes
int64_t i64; // always 8 bytes
uint8_t u8; // always 1 bytes
uint16_t u16; // always 2 bytes
uint32_t u32; // always 4 bytes
uint64_t u64; // always 8 bytes
size_t size; // same as the architecture's program counter width

// boolean 

bool x = false;

```
___
### Type Conversions and casting
You can convert one type to another using type casting, note that type casting behavior is sometimes very weird and unpredictable.
```C
uint8_t x = 10;
// x is here automatically cast to a larger type so no problems.
uint32_t y = x;
// x must be manually cast because the expression on the left will be evaluated first
float z = (float)x / 3;
```
___
### Operators
 Operators specify what is to be done to them.
 ```C
    // Arithmatic Operators
        // unary ( acts on one number )
        x++; // post increment, a statment.
        ++x; // pre increment, a statment;
        -x; // negative, an expression
        // binary ( acts on two numbers) all are expressions
        x + y // binary addition
        x - y // binary addition with the 2's complement of y
        x * y // hardware or software multiply (to be explained more)
        x / y // hardware or software division (to be explained more)
        x % y // module operator, returns the reminder of division
    // Bit-Wise Operators
        // unary
        ~x; // binary not, flips all bits, expression
        // 000111 -> 111000
        // binary, all are expressions
        x >> y // shift right
        // 1011 >> 2 == 0010
        x << x // shift left
        // 1011 << 2 ==  101100
        x | y // x OR y
        // 1010 | 1100 = 1110
        x & y // x AND y
        // 1010 | 1100 = 1000
        x ^ y // x XOR y
        // 1010 | 1100 = 0110 
    // Comparison operators
        x == y // equaltiy
        x != y // non equality
        x > y // x larger than y
        x < y // x less than y
        x >= y // x larger than or equal y
        x <= y // x less than or equal y
    // Comparison composition operators, all are expressions
        cond1 && cond2 // cond1 is true and cond2 is true
        cond1 || cond2 // cond1 is true or cond2 is true
        !cond1 // not cond1
    // assignment operator "="
        x = 1 + 1; // takes a variable name of the left and an expression of the write and composes a statment.
 ```
 ___
### Expressions
Expressions combine variables and constants to produce new values.
___
### Statments
The consist of one or more expression and operator but has no new value of it's own.
___
### User Defined Types and Aliases
#### Aliases
Giving an existing types a new **aliased** name
```C
#include <stdio.h>

typedef int whatever_t;
int main(){
    // x is still an int
    whatever_t x = 42;
    // prints 42
    printf("%d\n",x); 
}
```
#### Structs
Structs are composed container datatypes, used to combine multiple values into a signle container.  
The memory layout of structs is simple, elements are layed out one after another with the address of the first byte being the address of the whole struct.  
Each element inside the struct can be accessed using the "." operators
```C
#include <stdio.h>

int main(){
    // declares a variable named var with the type struct{int x;int y;}
    struct {int x; int y;} var; 
    // accessing the element x inside the instance var of type struct{int x;int y;}
    var.x = 5; 
    // accessing the element y inside the instance var of type struct{int x;int y;}
    var.y = 77;
    // prints 5 77
    printf("%d %d\n", var.x, var.y);
}
```
To avoid retyping the long type name you can also do
```C
#include <stdio.h>

struct point {
    int x;
    int y;
}; 

int main(){
    // declares a variable named var with the type struct{int x;int y;}
    struct point var; 
    // accessing the element x inside the instance var of type struct{int x;int y;}
    var.x = 5; 
    // accessing the element y inside the instance var of type struct{int x;int y;}
    var.y = 77;
    // prints 5 77
    printf("%d %d\n", var.x, var.y);
}
```
Another common way to avoid typing the word struct in every declaration is aliasing it.
```C
#include <stdio.h>

// defines an alias for the type struct{int x;int y;}
typedef struct{
    int x;
    int y;
} point_t;

int main(){
    // initilization 
    point_t p0 = {.x = 5, .y = 77};
    // prints 5 77
    printf("%d %d\n", p0.x , p0.y);
}
```
#### Enums
Enums define a set of values that of variable of that type can only have, but has an underlying int type.  
Think of the boolean data type that it can only take a value of true of false, but underlying those are values of 0 and 1.
By default values are assigned 0 through N where N-1 is the number of possible values.
```C
#include <stdio.h>

enum color { RED, GREEN, BLUE};

int main(){

    enum color r0 = RED;
    enum color r1 = GREEN;
    enum color r2 = BLUE;
    // prints 0, 1, 2
    printf("%d %d %d", r0, r1, r2);
}
```
Same as struct to avoid typing the word enum
```C


typedef enum { RED, GREEN, BLUE} color_t;

int main(){

    color_t r0 = RED;
    color_t r1 = GREEN;
    color_t r2 = BLUE;
    // prints 0, 1, 2
    printf("%d %d %d", r0, r1, r2);
}
```
___
### Pointers
A pointers are special data types that holds the memory address of other data types.  
all pointer have the size of the program counter of the architecture.  
to access the address of a non pointer type we use the operator **&**  
to access the data in the address pointed to by a pointer we use the operator \*  
to access an element inside a struct pointed at by a pointer we use the operator **->**
```C
#include <stdio.h>

typedef enum {
    RED, 
    GREEN, 
    BLUE
} color_t;

typedef struct{
    int x;
    int y;
} point_t;

int main(){
    int i = 42;
    color_t r = RED;
    point_t p = {.x = 5, .y = 77};
    
    int *i_p = &i; // pointer to int, holds the address of i
    color_t *r_p = &r; // pointer to color_t, holds the address of r
    point_t *p_p = &p; // pointer to point_t, holds the address of p

    // prints 42 42
    printf("%d %d\n", i, *i_p);
    *i_p = 50;
    // prints 50 50
    printf("%d %d\n", i, *i_p);
    // prints 0 0
    printf("%d %d\n", r, *r_p);
    r = GREEN;
    // prints 1 1
    printf("%d %d\n", r, *r_p);
    // prints 5 77 5 77
    printf("%d %d %d %d\n", p.x, p.y, p_p->x, p_p->y);
    p.x = 66;
    p_p->y = 105;
    // prints 66 105 66 105
    printf("%d %d %d %d\n", p.x, p.y, p_p->x, p_p->y);

}
```
___
### Functions, Scope and visibility
A function is a named block of code that has sort of isolation from the rest of the program,   
variables defined inside a function are not visible to the rest of the program,   
this is called **lexical scoping**  
functions can take arguments or any known type and return only one value.
```C
uint64_t square(uint32_t n){
    return (uint64_t)n * n;
}
```
___
### Control Flow
#### If Conditions
```C
if(cond1){
    // do something
}else if(cond2){
    // do something
}else{
    // do something
}
```
#### Switch Case
```C
switch(value){
    case v1:
        // do something
        break;
    case v2:
        // do something
        break;
    default:
        // do something
}
```
#### While Loop
```C
while(cond){
    // do something until cond is false
}
```
#### For Loop
```C
for(init; cond; update){
    // do something until cond is false
}
```
____
### Keywords
These are some keywords that have a somewhat complicated meaning

#### volatile
volatile signals to the compiler that a variable has a non obvious hardware related meaning, so that the compiler doesn't do weird things to that variable (this will get clear in the future)
```C
volatile int x = 5;
```
#### extern
extern tells the compiler that a certain identifer (variable of function) is not defined in this file but will be available after linking with a library or the rest of the program
```C
extern int getnumber();
extern char c;
```
#### static
A static variable inside a function keeps its value between invocations.  
A static global variable or a function is "seen" only in the file it's declared in
```C
#include <stdio.h>

// this variable is global but only visible with the file
static int x = 0;

int addone(){
    // this variable holds it's value between different calls
    static int i = 0;
    i++;
    return i;
}

int main(){
    
    // prints 1
    printf("%d\n", addone());
    // prints 2
    printf("%d\n", addone());
    // prints 3
    printf("%d\n", addone());
    // prints 4
    printf("%d\n", addone());
    // prints 5
    printf("%d\n", addone());
}

```
___
## Program Structure
___
### Single file Programs
1. Perprocessor Directives

    Directives that will be excuted during compilation by the preprocessor and will never make it to the final binary output.

2. Global Variables

    Variables that have a global scope, which means all functions inside this file can **see** it.  
    If not initialized to a value by the user the memory will be initialized to zero.  
    Has a special allocated place in memory called .data for initialized variables, and .bss for uninitialized variables.

3. Functions Prototype/Implementation

    Function Prototypes can go here and their implementation can go in section 5 after main  
    or you can write just the implementation here

4. main function

    Your application's entry point where code starts executing (no always the case as we will see soon)

5. Functions Implementation

    If you have a function Prototype in section 4 then your implementation goes here
5
```C
// Preprocessor Directives

#include <stdio.h>
#pragma whatever
#define hello 5

// Global Variables

int universe = 42;
double pi = 3.14159265359;

// Functions Prototype

double piplusone();

// Functions Implementation

double piplustwo(){
    return pi + 2;
}

// main function

int main(){
 
    int w;
    printf("hello world\n");
    w = piplusone() + piplustwo();
    return 0;
}

// Function Implementation

double piplusone(){
    return pi + 1;
}
```
### Multiple files program
There are two types of C source code files, a C source file and C header file, source files end a .c and header files end in .h  
header files contain prototypes of functions, new type definitions and preprocessor directives and are included at the top of source files   
source files contain actual executable code, implementation of functions
___
### Compilation steps

![](http://blog.techveda.org/wp-content/uploads/2012/10/Compilation-Process.png)

## Reference 
The C Programming Language 2n Edition by Brian W, Kernighan and Dennis M.Ritchie

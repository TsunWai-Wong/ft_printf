# Custom printf() function in C

### Description
This project aims to replicate the behavior of the C function printf().
The following datatype can be handled:
- %c: Character
- %d: Decimal Integer
- %i: Integer
- %p: Pointer
- %s: String
- %u: Unsigned Integer
- %x: Hexadecimal Integer (in lowercase)
- %X: Hexadecimal Integer (in UPPERCASE)
- %%: Percentage Sign

### Getting Started
1. Compile the functions and turn them into a static c library
```
make
```
2. To use the library in your project, include the header file in your own project
```
#include "ft_printf.h"
```
3. Compile your project with the static library. For example:
```
cc main.c libftprintf.a
```

# Beej's Guide to C Programming Notes


05/31/25
## Ch.20 - Structs II
- structs have padding bytes (sizeOf parts =/= sizeOf struct)
  - can measure how many extra bytes with offsetof()
- bit packing allows you to define the size of each type, overwriting their default
  compiler assigned size
  - must be adjacent for this to work, can't alternate normal and packed types
  - can also insert zero width type like //unsigned int :0 || instead of normal int a:2 or whatever
- union allows you to declare a bunch of variables but only reserve memory space of the largest type
  - can then only use one of the fields at a time since they take the same memory
  - "type punning" might be something to google
  - can make a union of structs, if they have the same initial space (ie first stuff declared) they will share memory!
    - this can be used to share info between structs since they share the memory!


## Ch.21 - Characters & Strings II
- Trigraphs
  - triplets of 3 characters that the compiler encodes into special characters, mostly you can ignore
  - this is second point
- unicode can be encoded with escapes beforehand like \u1234




06/02/25
## Ch.22 - Enumerated Types
- Constant int values by name
- can only be integer type whereas #define can do anything
- enums show up as their identifier in the debugger whereas #define just shows the raw number
- enums increment up starting at zero for lists automatically


## Ch.23 - Pointers III - Pointers to Pointers and More
- int** (int-pointer-pointer) just points to the address of the other pointer
- You can make a pointer to anything with *
- you can get the thing a pointer points to with &
  - inverse of eachother * &
- can convert pointer to intptr_t type and back without losing data with <stdint.h>
- **Strict Aliasing** means you can only access an object via pointers ot compatible types of the object
- can subtract one pointer from another in the same array to get the difference between their
  positions in the array
  - the type of that difference is up to implementation
  - can store result in ptrdiff_t to be more portable via <stddef.h>
- can call function via pointer of the same type as the return type of the function
  - looks like a func prototype
    - so something like int (*p)(int, int) just points to the function
      - this is always a pointer to a function! "(*p) ("


## Ch.24 - Bitwise Operations
- bitwise shift causes integer promotion on each operand before it's executed
- generally the same as java




06/03/25
## Ch. 25 - Variadic Functions
- **Variadic Functions** are functions that can take in an arbitrary number of args
  - All variadic functions must have at least one argument
- must have args first followed by ...
  - ex: void func(int a, ...)
- must include <stdarg.h>
- special variable type **va_list**
  - start capturing list with **va_start** which is the last named parameter (before the ...)
  - process each additional arg with **va_arg** (takes in all the args)
  - end with **va_end**




06/04/25
## Ch. 26 - Locale and Internationalization
- include <locale.h>
- use **set_locale(AC_ALL, "")**
  - basically says use this env locale for everything
  - you can specify in the second arg what locale if you want
  - can call struct lconv *x = localeconv(); for special symbols like currency
  - see page 206 for list



## Ch. 27 - Unicode & Wide Characters
- a **code point** is a numeric value representing a character
- the **encoding** is how the character is represented in memory
- bytes can be in little endian or big endian order. default is technically big but windows default is little
- UTF-8 is reverse compatible with ASCII
- Generally uses one byte until it can't and then adds the encoding in a seperate byte
- use \u1234 for smaller than 8 bits and \U0001D4D1 for 16 bits
- a normal char* string is actually a multibyte string
- a **Wide character** is an array of characters NOT an array of bytes like multibyte strings
  - wide characters have the wchar_t type with #include <wchar.h>
  - can convert between wchar_t and multibyte with conversion functions ie mbtowc(), wctomb(), etc
  - wcslen() is the equivalent of strlen() for wide character strings
  - don't use byte oriented functs with wide characters
    - don't use fprinf() with wide chars instead use fwprintf()
  - mbstate_t should be initilized with memset() to zero
- UTF
  - can prefix a string to convert
    - char *s = u8"Hello World!";
  - can convert to multibyte and back withs funcs like mbrtoc16()
- 3rd party libs for converting
  - icon, ICU, etc




06/05/2025
## Ch. 28 - Exiting a Program
- main func has implicit 'return 0' when it exits
- calling exit() ends the program
- **Exit Handlers**
  - functions to be called when the program exits
  - **atexit()** will call the arg before closing
  - **quick_exit** exits fast but doesn't flush temp files and doesn't call atexit() funcs
    - **at_quick_exit()** will still call handlers
  - **_Exit()** immediately exits and nothing else
  - **assert()** must be true for the program to run
  - **abort()** signal something went wrong and exit



## Ch. 29 - Signal Handling
>[!NOTE]
ignore this chapter and default to the OS' signal handling instead
- function that is auomatically called when an external event occures
- can pause a program until signal is handled
  - can be ignored, handled, or allow the default action
    - ex program that ignores exit signal
- only portable thing you can do is SIG_IGN and SIG_DFL



06/06/2025
## Ch. 30 - Variable-Length Arrays (VLAs)
- an array whose size is determined at runtime
  - dont need to free() memory after
- Not commonly used eg banned in linux kernal because they can cause problems
- __STDC_NO_VLA__ macro is set to 1 if VLAs are not present
- **sizeof()** is executed at runtime whereas non VLAs is computed at compile time



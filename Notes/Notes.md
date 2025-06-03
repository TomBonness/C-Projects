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


## Ch. 25 - Variadic Functions
- 

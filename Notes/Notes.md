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
- **typedef** makes a new type with values as they existed when typedef was executed
  - fixed size array of the length of the VLA at time of execution
- VLAs are generally slower




06/08/2025
## Ch. 31 - Goto
- Sends execution to jump forward/backwards to specified label skipping inbetween
- function scope - can goto them anywhere inside the function they're used in
  - cannot goto other function's labels
- can be used for nested loops instead of **continue**
  - used to break out of loops/do/while
- Tail call optimization for recursive functions



## Ch.32 - Types Part V: Compound Literals and Generic Selections
- **Compound Literals**
  - create object without assigning it to a variable
    - ex unnamed array of ints: (int []){1,2,3,4} can be a func arg instead of like 'int a'
  - unnamed object only exists in its scope
    - pointer to unnamed object out of scope will point to dead object so undefined behavior
- **Generic Selections**
  - select piece of code based on type of the first argument to the expression
  - processed at compile time not runtime
  - declared like _Generic(i, int: "whatever", float: "stuff");
    - the type of i picks the corresponding case



06/09/2025
## Ch. 33 - Arrays Part II
 - C always fills empty array slots with 0
  - even in multi dimentional arrays



## Ch. 34 - Long Jumps
- rarely used but allows you to jump back to the original function call
- **setjmp()** sets where to jump to and **longjmp()** goes to the setjmp
  - need to include <setjmp.h>
- keeps execution point stored in jmp_buf and just uses that to jump back so kinda weird
- can't jump to setjmp() in another thread



## Ch. 35 - Incomplete Types
- an **incomplete type** is a type where the sizeof() is unknown
  - a type that hasn't finished declaring
- only used in forward references to structs with self referential structures
- can declare pointer to something that doesnt exist yet like a linked list inside a struct!
  - basically you could never make a pair of structs that reference eachother if this didnt exist



## Ch. 36 - Complex Types
- #INCLUDE <complex.h>
- types: **complex** and **imaginary**
  - macro: **I** ex: double complex x = 5 + 2I
- can grab with **creal()** and **cimag()**
- C has trig functions too!



## Ch. 37 - Fixed Width Integer Types
- can define types of an exact length ie 32bits
- three main classes of these types
  - **intN_t** for ints of exactly a certain size
  - **int_leastN_t** for ints of at least a certain size
  - **int_fastN_t** for ints of at least a certain size but as fast as possible


## Ch. 38 - Date and Time Functionaliy
- types: **time_t** and **struct tm**
  - time_t represents number of seconds since epoch
  - struct has calendar + time broken down into components like tm_sec and tm_year etc
- **ctime()** is the only portable way to get the local time lmao
- the func **localtime()** converts **time_t** to a **struct tm**
- the func **gmtime()** does the same but in UTC
- func **mktime()** converts **struct tm** to **t_time**
- **strftime()** is like **printf()** but for dates
- **timespec_get()** lets you grab epoch time down to the nanosecond
- might not always be able to subtract times so better to use **difftime()**




06/10/2025
## Ch. 39 - Multithreading
- standard library is generally thread safe
- threads are identified with the opaque type **thrd_t**
  - when a thread is created it is given a **thrd_t** ID
- **thrd_create** takes a pointer to the function to run of type **thrd_start_t**
- none of this works you gotta do pthread instead because unix and stuff
  - okay so just make sure everything is a void pointer lol
- threads don't have their own memory beyond local variables
- **_Thread_local** before variable tells C every thread gets its own version of the variable
  - if the variable is in block scope it must be static (or extern)
- **Thread-Specific Storage (TSS)**
  - can specify a destructor for when the TSS variable is deleted ex free()
    - ex cleans up malloc data with free
  - **tss_t** type variable needs to exist
    - initializaed with **tss_create**
    - deleted with **tss_delete**
      - this doesn't do anything but release the memory created before
    - **tss_set** and **tss_get**
      - work as getters and setters
- **Mutexes** only allow a single thread into a section of code at a time
  - initialize the variable with **mtx_init()**
  - then threads can call with **mtx_lock()** and **mtx_unlock()**
  - when finished it can be destroyed with **mtx_destroy()**
  - when other threads try to access it, they are blocked and sleep until they can access
- **Conditional Variables**
  - allows thread to sleep until an event in another thread occurs
  - only holds the data C uses to track the thread condition
  - mutex can be passed between parent and child thread because **cnd_wait()** releases the mutex
- timed condition wait **cnd_timedwait** allows you to specify a timeout to stop waiting
- **cnd_Broadcast()** lets you wake up all waiting threads at once
- **call_once()** only allows one thread to run a function once even if many call the function
  - must declare flag once_flag of = ONCE_FLAG_INIT;




06/12/2025
## Ch. 40 - Atomics
- test for atomic support with __STDC_NO_ATOMICS__ 0 is supported 1 means not supported
- 

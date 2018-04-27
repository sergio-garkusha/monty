# 0x18. C - Stacks, Queues - LIFO, FIFO

### Requirements:

* Allowed editors: `vi`, `vim`, `emacs`
* Files will be compiled on `Ubuntu 14.04 LTS`
* Programs will be compiled with `gcc 4.8.4` using `-Wall` `-Werror` `-Wextra` and `-pedantic`
* Files should end with a new line
* A `README.md` file, at the root of the folder of the project
* A code should use the [Betty](https://github.com/holbertonschool/Betty) style. It will be checked using `betty-style.pl` and `betty-doc.pl`
* One global variable maximum
* No more than 5 functions per file
* C standard library
* The prototypes of all functions should be included in header file called monty.h
* All header files should be include guarded
* Do the tasks in the order shown in the project
* The repository `monty` should be added as a submodule to [holbertonschool-low_level_programming](https://github.com/Cu7ious/holbertonschool-low_level_programming) repository, under the name `0x17-stacks_queues_lifo_fifo`
* Use the following data structures for this project:
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```

```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

### Compilation
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


### Tasks

#### 0. push, pall

Implement the `push` and `pall` opcodes.

##### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$
```

##### The monty program

1. Usage: `monty file`
	* where file is the path to the file containing Monty byte code
2. If the user does not give any file or more than one argument to your program, print `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
3. If, for any reason, it’s not possible to use read the file, print Error: Can't open file <file>, followed by a new line, and exit with the status `EXIT_FAILURE`
4. If the file contains an invalid instruction, print `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
	* Line numbers always start at 1
5. The monty program runs the bytecodes line by line and stop if:
	* it executed properly every line of the file
	* or it finds an error in the file
	* or an error occured
6. If you can’t malloc anymore, print `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`. You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc`
7. All error messages must be printed on stdout


##### The push opcode

The opcode `push` pushes an element to the stack.

1. Usage: `push <int>``
        * where `<int>` is an integer
2. If `<int>` is not an integer or if there is no argument to push, print the message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
3. You don’t have to deal with overflows. Use the `atoi` function

##### The pall opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

1. Usage: `pall`
2. Format: see example
If the stack is empty, don’t print anything

```
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$
```

##### The pint opcode

The opcode `pint` prints the value at the top of the stack, followed by a new line.

1. Usage: `pint`
2. If the stack is empty, print `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ ./monty bytecodes/06.m
1
2
3
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$
```

##### The pop opcode

The opcode pop removes the top element of the stack.

1. Usage: `pop`
2. If the stack is empty, print `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ cat bytecodes/07.m
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ ./monty bytecodes/07.m
3
2
1
2
1
1
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$
```

##### The swap opcode

The opcode `swap` swaps the top two elements of the stack.

1. Usage: `swap`
2. If the stack is less than two element long, print `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ cat bytecodes/09.m
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$ ./monty bytecodes/09.m
3
2
1
2
3
1
julien@ubuntu:~/0x18. Stack (LIFO) & queue (FIFO)$
```

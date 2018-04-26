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

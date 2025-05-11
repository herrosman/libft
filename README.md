# My C Program

This project demonstrates a simple C program that outputs a string using the `write` function. It is structured with separate directories for source files, header files, and object files.

## Project Structure

```
my-c-program
├── src
│   ├── main.c          # Entry point of the program
│   ├── ft_putchar.c    # Implementation of the ft_putchar function
├── inc
│   └── libft.h        # Header file with function prototypes
├── obj                 # Directory for object files
├── Makefile            # Build instructions
└── README.md           # Project documentation
```

## Compilation Instructions

To compile the program, navigate to the project directory and run the following command:

```
make
```

This will compile the source files and create an executable.

## Running the Program

After compilation, you can run the program with the following command:

```
./my-c-program
```

## Functionality

- The `ft_putchar` function writes a single character to the standard output using the `write` system call.
- The `main` function calls `ft_putchar` to display the character 'H'.

## Dependencies

This project does not have any external dependencies and is written in standard C.
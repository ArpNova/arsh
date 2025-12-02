# Simple Shell in C

This is a custom implementation of a Unix shell, written from scratch in C. The project aims to understand the inner workings of a shell, including process creation, execution, and signal handling.

## Features

- **REPL (Read-Eval-Print Loop)**: The shell runs in a continuous loop, waiting for user input.
- **Input Parsing**: Reads commands from stdin and tokenizes them into arguments.
- **Command Execution**: (In Progress) Executes commands by forking processes and using `execvp`.

## Project Structure

- `src/main.c`: Contains the main logic for the shell, including the main loop, input reading, and parsing functions.

## How to Build and Run

To compile the shell, use a C compiler like `gcc`:

```bash
gcc src/main.c -o myshell
```

To run the shell:

```bash
./myshell
```

## Implementation Details

The shell follows a standard lifecycle:
1. **Read**: Reads a line of input from the user.
2. **Parse**: Splits the line into program names and arguments.
3. **Execute**: Runs the parsed command.

## Future Improvements

- Support for built-in commands (cd, help, exit).
- Input/Output redirection.
- Pipes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

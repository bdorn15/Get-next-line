# get_next_line (42)
`get_next_line` is a C function that reads from a file descriptor and returns one line per call. It keeps an internal buffer between calls (via a static variable), so you can read a file incrementally without loading the whole file into memory.

## Project overview
- Allowed functions: read, malloc, free
- Repeated calls return the file content line by line
- The returned line includes the trailing \n, except at EOF if the file does not end with \n
- Returns NULL when there is nothing left to read, or if an error occurs
- Buffer size is configurable with -D BUFFER_SIZE=n (default is 42)

## Files
- get_next_line.c — core logic (reading + stash handling)
- get_next_line_utils.c — helper string functions
- get_next_line.h — header and BUFFER_SIZE default
- main.c — minimal tester

## Build
Default buffer size (42):
cc -Wall -Wextra -Werror -g main.c get_next_line.c get_next_line_utils.c -o gnl

Custom BUFFER_SIZE (example: 1):
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o gnl

## Usage
1) Create a file named test.txt in the same directory.

2) Run:
./gnl

Expected behavior:
- Lines are printed one by one
- Empty lines ("\n") are returned correctly
- The final line is returned without "\n" if the file does not end with one

## Notes
- BUFFER_SIZE can be adjusted, so the implementation must work for small and large values.
- This project is typically tested on Linux/glibc. If you're on Windows, use WSL/Ubuntu for consistent behavior.

## License
Educational project (42).

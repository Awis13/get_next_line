Get Next Line - 42 École Project

Hey there! 👋 Welcome to my personal implementation of the get_next_line project from 42 École. This project is all about creating a convenient function to read lines from a file descriptor, making it super easy to process text files line by line.

Goals 🎯

This project has two main goals:

Create a function, get_next_line, that returns a line read from a file descriptor.
Learn about static variables in C programming.
Getting Started 🚀

Before diving into the code, make sure you have a C compiler installed on your machine. I recommend using gcc or clang.

Compile the Code
To compile the code, use the following command:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<your_buffer_size> get_next_line.c get_next_line_utils.c
```

Replace <your_buffer_size> with the desired buffer size. For example, you can use 42 as the buffer size:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

This command will generate an executable file called a.out. To run it, simply use:

```sh
./a.out
```

```c
int main()
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    return 0;
}
```
This code snippet will read the first three lines from a file called file.txt.

🙌 Happy coding! 💻

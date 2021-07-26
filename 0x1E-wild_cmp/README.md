# Interview Prep: Wild Compare

## Description of Problem

Write a function that compares two strings and returns 1 if the strings can be considered identical, otherwise return 0.

* Prototype: `int wildcmp(char *s1, char *s2);`
    * s2 can contain the special character `*`.
    * The special char `*` can replace any string (including an empty string)


## Proposed Solution 💡

See [0-wildcmp.c](./0-wildcmp.c) for my solution. To see an example of my solution in use, compile the test program available in the repository like this:
```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o ildcmp
```
Then you will have a file called `wildcmp` which you can run:
```bash
$ ./wildcmp
```

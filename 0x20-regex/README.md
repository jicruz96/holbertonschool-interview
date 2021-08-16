# Interview Prep: Regular Expression Basic

## Description of Problem

Write a function that checks whether a given pattern matches a given string.

* Prototype: `int regex_match(char const *str, char const *pattern);`, where:
    * `str` is the string to scan
        * `str` can be empty, and can contain any ASCII character in the exception of `.` and `*`
    * `pattern` is the regular expression
        * `pattern` can be empty, and can contain any ASCII character, including `.` and `*`
* Your function must return 1 if the pattern matches the string, or 0 if it doesn’t
    * The regular expression matching must support the characters `.` and `*`
        * `.` matches any single character
        * `*` matches zero or more of the preceding character


## Proposed Solution 💡

See [regex.c](regex.c) for my solution. To see an example of my solution in use, compile a sample program like so:
```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c
```
Then, execute the resulting `a.out` output file:
```bash
$ ./a.out
```

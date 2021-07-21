# Interview Prep: Is this an AVL Tree?

## Description of Problem

Write a function that checks if a binary tree is a valid AVL Tree

* Prototype: `int binary_tree_is_avl(const binary_tree_t *tree);`
    * Where `tree` is a pointer to the root node of the tree to check
* Your function must return 1 if tree is a valid AVL Tree, and 0 otherwise
* If tree is NULL, return 0


## Proposed Solution 💡

See [0-binary_tree_is_avl.c](./0-binary_tree_is_avl.c) for my solution. To see an example of my solution in use, compile the test program available in the repository like this:
```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o is_avl_test
```
Then you will have a file called `is_avl_test` which you can run:
```bash
$ ./is_avl_test
```

# Interview Prep: Linear Search In Skip List

## Description of Problem

Looking for a specific value in a singly linked list always leads to browse every element of the list. A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it. A linked list with an express lane is called a **skip list**.

Write a function that searches for a value in a sorted (ascending) skip list of integers, where the skip list express lanes exist in every node that is in a position equal to a multiple of the square root of the size of the list.

* Prototype: `skiplist_t *linear_skip(skiplist_t *list, int value);`, where:
    * `list` is a pointer to thehead of the skip list to search in.
    * `value` is the value to search for
    * the return value is a pointer to the node containing `value`
        * If `value` is not present in `list` or if `list` is NULL, return `NULL` 
* Every time you compare a value in the list to `value`, print:
    * `Value checked at index [<index>] = [<value>]`
* When you find the interval of indexes where `value` should be, print:
    * `Value found between indexes [<index of previous express lane node>] and [<index of next express lane node>]`


## Proposed Solution 💡

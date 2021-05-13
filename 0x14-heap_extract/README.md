# Interview Prep: Insert a Node into a Max Binary Heap

## Description of Problems, Constraints

**Write a function that extracts the root node of a Max Binary heap.**

* Prototype: `int heap_extract(heap_t **root);`
* `root` is a double pointer to the root node of the heap
* Your function must return the value stored in the root node
* The `root` node must be freed and replace with the last level-order node of the heap
* Once replaced, the heap must be rebuilt if necessary
* If your function fails, return 0

### What is a [max binary heap](https://en.wikipedia.org/wiki/Heap_(data_structure)), you ask?

In essence, it's a tree-like data structure where values are sorted from greatest to lowest.

Details in the [wiki page](https://en.wikipedia.org/wiki/Heap_(data_structure)).
<br>

## Proposed Solution 💡

Check the file [0-heap_extract.c](./0-heap_extract.c) for my solution.

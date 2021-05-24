# Interview Prep: Rotate a 2D Matric

## Description of Problems, Constraints

**Write a program in Python that rotates a `n` x `n` 2D matrix**

## Proposed Solution 💡

My algorithm rotates the 2d matrix in place by replacing four places
of the matrix at a time.

* Time complexity: **O(n^2)**, where **n** is the dimension size of the matrix.
* Space complexity: **O(1)** 

```python
def rotate_2d_matrix(matrix):
    for start in range(int(len(matrix) / 2)):
        end = len(matrix) - start - 1
        # Rotate four positions
        for i in range(end - start):
            # Save top left number
            tmp = matrix[start][start + i]
            # In top left position, place bottom left number
            matrix[start][start + i] = matrix[end - i][start]
            # In bottom left position, save bottom right number
            matrix[end - i][start] = matrix[end][end - i]
            # In bottom right position, save top right number 
            matrix[end][end - i] = matrix[start + i][end]
            # In top right position, save former top left number
            matrix[start + i][end] = tmp
```

#!/usr/bin/python3
""" See problem description in README.md """


def pascal_triangle(n):
    """Returns the first n rows of Pascal's Triangle

    Args:
        n (int): number of rows to return

    Return:
        List[List]: n rows of pascal's triangle
    """

    pascal = []
    for i in range(0, n):
        row = [1]
        if i:
            row += [prev_row[j] + prev_row[j - 1] for j in range(1, i)] + [1]
        pascal.append(row)
        prev_row = row
    return pascal

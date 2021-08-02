#!/usr/bin/python3
""" See problem description in README.md """


def pascal_triangle(n, prev_rows=None):
    """Prints the first n rows of Pascal's Triangle

    Args:
        n (int): j of rows to print
    """

    if n <= 0:
        return []
    pascal = []
    prev_row = None
    for i in range(n):
        row = []
        for j in range(i + 1):
            if j == 0 or j == i:
                row.append(1)
            elif prev_row:
                row.append(prev_row[j] + prev_row[j - 1])
        pascal.append(row)
        prev_row = row
    return pascal

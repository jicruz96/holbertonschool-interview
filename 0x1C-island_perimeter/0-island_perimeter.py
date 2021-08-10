#!/usr/bin/python3
"""
See problem description in README.md
"""


def cell_perimeter(grid, i, j):
    """
    Calculates the perimeter of a cell in a rectangular grid
    """
    # empty cell, no perimeter
    if grid[i][j] == 0:
        return 0

    perimeter = 0

    # top cell
    if i == 0 or grid[i - 1][j] == 0:
        perimeter += 1
    # bottom cell
    if i == len(grid) - 1 or grid[i + 1][j] == 0:
        perimeter += 1
    # left cell
    if j == 0 or grid[i][j - 1] == 0:
        perimeter += 1
    # right cell
    if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:
        perimeter += 1

    return perimeter


def solution1(grid):
    """O(n) solution (n = len(grid) * len(grid[0]))"""

    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            perimeter += cell_perimeter(grid, i, j)

    return perimeter


def island_perimeter(grid):
    """
    Calculates the perimeter of an "island" represented by 1's on a
    rectangular grid of zeroes
    """
    return solution1(grid)

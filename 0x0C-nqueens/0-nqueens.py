#!/usr/bin/python3

from sys import argv


def safe_position(queens, row, column):
    """checks if a new position is safe from attack from all other queens

    Args:
        queens    (list[list[2]]): positions of all other queens
        row       (int)          : row value of new position
        column    (int)          : column value of new position

    Returns:
        bool: True if position is safe | False otherwise
    """
    for queen in queens:
        # "If a queen exists in row or column..."
        if queen[0] == row or queen[1] == column:
            return False
        # "If a queen exists in a position diagonal to [row, column]..."
        if abs(queen[0] - row) == abs(queen[1] - column):
            return False

    return True


def nqueens(N, queens=[]):
    """prints all possible position combinations for N queens in an NxN
    chessboard, such that no queen can attack another queen

    Args:
        N      (int) : number of queens
        queens (list): list of queens valid positions.
    """
    if len(queens) == N:
        print(queens)
        return

    if len(queens):
        rows = range(queens[-1][0], N)
    else:
        rows = range(N)

    for i in rows:
        for j in range(N):
            if safe_position(queens, i, j):
                nqueens(N, queens + [[i, j]])


if __name__ == '__main__':

    if len(argv) != 2:
        print('Usage: nqueens N')
        exit(1)

    try:
        N = int(argv[1])
    except ValueError:
        print('N must be a number')
        exit(1)

    if N < 4:
        print('N must be at least 4')
        exit(1)

    nqueens(N)

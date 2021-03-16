# Interview Prep: N Queens

## Description of Problem

Write a program that solves the N Queens Problem for N >= 4.

## Proposed Solution 💡

### 16 march 2021

Without googling, I was able to come up with this solution that utilizes
a recursive backtracking approach. It has an exponential time complexity.

I timed it for inputs `4 <= N <= 11` and got:

| N | execution time (on M1 MacBook Pro)|
|-|-|
| 4  |  ~350 microseconds |
| 5  | ~2000 microseconds |
| 6  | ~0.01 seconds |
| 7  | ~0.08 seconds |
| 8  | ~0.62 seconds |
| 9  | ~6.00 seconds |
| 10 | ~1 minute |
| 11 | ~10 minutes |

```python

def safe_position(queens, row, column):
    """checks if a new position is safe from attack from all other queens"""
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
```

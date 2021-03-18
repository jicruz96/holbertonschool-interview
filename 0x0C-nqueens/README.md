# Interview Prep: N Queens

## Description of Problem

Write a program that solves the N Queens Problem for N >= 4.

## Proposed Solution 💡

### 17 march 2021 - Second (& Final) Attempt

Whereas my previous solution needed **_10 minutes_** to calculate the solutions for `N = 11`, this approach calculates it **_in a second_**. Wow. 

Nevertheless, this solution, and apparently most solutions out there, still have an exponential time complexity. Around `N = 15`, this function takes longer than what I am willing to wait for.


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


def nqueens(rows, queens=[], col=0):
    """prints all possible position combinations for N queens in an NxN
    chessboard, such that no queen can attack another queen
    """

    if len(queens) == N:
        print(queens)
        return

    for row in rows:
        if safe_position(queens, row, col):
            nqueens(rows.difference({row}), queens + [[row, col]], col + 1)

# Function is called like this:
N = # User input (must be at least 4)
nqueens(N, set(range(N)))
```


### **How this solution is better than the previous one:**

First, check out the previous solution [below](#16-march-2021). After consulting with a peer, I learned that I was shooting myself in the foot by having a recursion call within two nested loops. This-- plus a few other things-- was provoking redundant recursions.

This updated solution avoids those redundant recursions in three ways:

1. _The range of the loop now **always** includes valid rows **only**._ I achieve this by passing a _set of valid rows_ from one recursion call to another, always eliminating the row where I just added another queen. (That's what `rows.difference({row})` is doing).
2. _The recursive call is nested within one loop only._
    * Instead of checking the entire range of columns in each recursive call, _I check one column value at each recursion level._ The loop ensures we check all possible column values for all valid rows.

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
    # same as final solution up above

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

# Interview Prep: Making Change

## Description of Problem

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.

* Prototype: `def makeChange(coins, total)`
* Return: fewest number of coins needed to meet total
	* If total is 0 or less, return 0
	* If total cannot be met by any number of coins you have, return -1
* `coins` is a list of the values of the coins in your possession
	* The value of a coin will always be an integer greater than 0
	* You can assume you have an infinite number of each denomination of coin in the list

## Proposed Solution 💡

My solution is in the file [0-making_change.py](./0-making_change.py) and below.

This solution sorts the coins in descending order, then calculates how many of the largest coin can fit into the total. Then, we recurse to the next greatest coin using the remaining amount as the new total. If this recursion fails to find an answer, then we add one unit of the greatest coin and recurse again.

```python
def makeChange(coins, total):

    def makeChangeHelper(coins, total, count=0):
        if total <= 0:
            return count
        if len(coins) == 0:
            return -1

        count += total // coins[0]
		newTotal = total % coins[0]

        result = makeChangeHelper(coins[1:], newTotal, count)
        while result == -1 and newTotal != total:
            count -= 1
            newTotal += coins[0]
            result = makeChangeHelper(coins[1:], newTotal, count)
        return result
    
    coins.sort(reverse=True)
    return makeChangeHelper(coins, total)
```

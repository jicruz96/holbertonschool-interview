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

This solution uses a cache of all integer values less than or equal to the target and then calculates the amount of change needed for each one of these subtotals, leading up to the total, taking advantage of the cache of previous results to get the result for the current subtotal.

Time complexity: `O(total * len(coins))`
```python
def makeChange(coins, total):

    if total <= 0:
        return 0
    
    inf = float('inf')
    cache = [0] + [inf] * total

    for i in range(len(cache)):
        for coin in coins:
            if coin <= i:
                cache[coin] = min(cache[i - coin], cache[coin])
    
    if cache[total] != inf:
        return cache[total]
    
    return -1
```

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

This solution sorts the coins in descending order, then calculates how many of the largest coin can fit into the total. Then, we recurse to the next greatest coin using the remaining amount as the new total. If this recursion fails to find an answer, then we add one unit of the greatest coin and recurse again. We use a cache of previous answers to avoid re-calculating results during recursive calls.

```python
def makeChange(coins, total):

    cache = {coin: 1 for coin in coins}
    cache[0] = 0

    def helper(coins, total):
        """ recursive helper for makeChange """

        cache[total] = -1

        for coin in coins:

            coin_count = total // coin
            rest = total % coin

            while cache.get(rest) is None and helper(coins[1:], rest) == -1:
                rest += coin
                coin_count -= 1

            if cache.get(rest) != -1:
                coin_count += cache[rest]
                if cache[total] > coin_count or cache[total] == -1:
                    cache[total] = coin_count

        return cache[total]

    if total <= 0:
        return 0

    return helper(sorted(coins, reverse=True), total)
```

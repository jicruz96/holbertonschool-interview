#!/usr/bin/python3
""" See README.md for problem description """


def makeChange(coins, total):
    """Returns the smallest number of coins needed to add up to the toal

    Args:
        coins (list[int]): coin denominations
        total (int): target value
    """
    def makeChangeHelper(coins, total, count=0):
        """Helper function for makeChange"""
        if total <= 0:
            return count
        if len(coins) == 0:
            return -1

        count += total // coins[0]
        newTotal = total % coins[0]
        result = makeChangeHelper(coins[1:], newTotal, count)

        if result == -1:
            if len(coins) - 1 != 0 and coins[0] % sum(coins[1:]) == 0:
                return -1

            while result == -1 and newTotal != total:
                count -= 1
                newTotal += coins[0]
                result = makeChangeHelper(coins[1:], newTotal, count)

        return result

    return makeChangeHelper(sorted(coins, reverse=True), total)

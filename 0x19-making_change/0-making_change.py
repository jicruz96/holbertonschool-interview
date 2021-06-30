#!/usr/bin/python3
""" see README.md for problem description """


def makeChange(coins: list, total: int) -> int:
    """ makes change """
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

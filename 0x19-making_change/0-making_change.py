#!/usr/bin/python3
""" see README.md for problem description """


def makeChange(coins, total):
    """ makes Change """

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

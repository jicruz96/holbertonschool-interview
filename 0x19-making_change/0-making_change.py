#!/usr/bin/python3
""" see README.md for problem description """


def makeChange(coins, total):
    """ makes Change """

    cache = {coin: 1 for coin in coins}
    cache[0] = 0

    def helper(coins, total):
        """ recursive helper for makeChange """
        for coin in coins:
            if coin > total:
                continue

            coin_count = total // coin
            rest = total % coin

            while cache.get(rest) is None and rest != total:
                if helper(coins, rest) != -1:
                    break
                rest += coin
                coin_count -= 1

            if rest == total or cache.get(rest) == -1:
                continue

            coin_count += cache[rest]
            if cache.get(total) is None or cache[total] > coin_count:
                cache[total] = coin_count

        if cache.get(total) is None:
            cache[total] = -1

        return cache[total]

    if total <= 0:
        return 0

    return helper(sorted(coins, reverse=True), total)

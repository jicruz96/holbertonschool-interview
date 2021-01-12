#!/usr/bin/python3
"""
Solution to minimum operations interview practice question. See README.md
for question specifics.
"""


def minOperations(n):
    """
    Calculates the minimum number of operations to go from one 'H' to n 'H's
    if the only available operations are "Copy All" and "Paste"
    """
    
    if n < 1:
        return 0

    operations = 0, factor = 2, product = n
    while factor <= product:
        while product % factor == 0:
            operations += factor
            product /= factor
        factor += 1

    if operations == 0:
        return n

    return operations

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

    # If n is 1, 0 operations are needed.
    if n < 1:
        return 0

    # Find smallest prime factors
    for i in range(2, int((n/2)+1)):
        if n % i == 0:
            return minOperations(int(n / i)) + i

    return n


def minOperations_sumOfFactors(n):
    """
    Calculates the minimum number of operations to go from one 'H' to n 'H's
    if the only available operations are "Copy All" and "Paste"
    """

    if n == 1:
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


def minOperations_bruteForceRecursion(n):
    """
    calculates the minimum number of operations to go from one 'H' to n 'H's
    if the only available operations are "Copy All" and "Paste".

    This approach is a brute force recursion that checks all possibilities and
    was my first go at the problem
    """

    # If n is 1, then we need to do nothing. Return 0
    if n == 1:
        return 0

    # this helper function will do all the dirty work
    def simulate(numChars, clipboard, operations):
        if numChars == n:
            return operations
        if numChars > n:
            return 0

        # Simulate pasting only
        """
        pasting only does the following:
            * adds clipboard units to numChars
            * adds 1 to operations
        """
        pasteOnly = simulate(numChars + clipboard, clipboard, operations + 1)

        # Simulate copy/pasting
        """
        copy/pasting does the following:
            * sets clipboard equal to numChars
            * doubles numChars
            * adds 2 to operations
        """
        copyPaste = simulate(numChars * 2, numChars, operations + 2)

        if copyPaste == 0 or copyPaste > pasteOnly:
            return pasteOnly

        return copyPaste

    # initiate simulation (starting at case where n = 2)
    return simulate(2, 1, 2)

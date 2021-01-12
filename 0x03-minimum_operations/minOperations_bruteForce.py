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

    def simulate(numChars, clipboard, operations):
        if numChars == n:
            return operations
        if numChars > n:
            return 0

        pasteOnly = simulate(numChars + clipboard, clipboard, operations + 1)
        copyPaste = simulate(numChars * 2, numChars, operations + 2)

        if copyPaste == 0 or copyPaste > pasteOnly:
            return pasteOnly

        return copyPaste

    return simulate(2, 1, 2)

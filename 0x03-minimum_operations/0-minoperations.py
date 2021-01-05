#!/usr/bin/python3
"""
solution to minimum operations interview practice question. see README.md
for question specifics.
"""


def minOperations(n):
    """
    calculates the minimum number of operations my hypothetical test editor
    would need to write n characters if the only available operations are
    "Copy All" and "Paste" and I start with a file with a single character
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
        
        if copyPaste == 0 || copyPaste > pasteOnly:
            return pasteOnly
        
        return copyPaste

    # initiate simulation (starting at case where n = 2)
    return simulate(2, 1, 2)

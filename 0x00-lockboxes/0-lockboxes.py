#!/usr/bin/python3
""" Module with solutions to the Lockboxes problem, as described in the
    README.md file
"""


# Brute Force Solution from 8 dec 2020
def canUnlockAll(boxes):
    """ a function that verifies if its possible to open all lockboxes in a set
    of lockboxes where each box contains keys to other boxes. First box in set
    is always unlocked. See more info on this puzzle in the README.md file
    """

    numBoxes = len(boxes)
    unlockedBoxes = [0]
    numUnlocked = 1

    for box in unlockedBoxes:
        for key in boxes[box]:
            if key < numBoxes and key not in unlockedBoxes:
                unlockedBoxes.append(key)
                numUnlocked += 1
    return numBoxes == numUnlocked

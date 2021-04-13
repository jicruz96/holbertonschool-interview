#!/usr/bin/python3
""" Script for rain interview question """


def rain(walls):
    """ computes amount of rain caputred by a set of walls """

    i = 0
    water = 0

    # Skip the void
    while i < len(walls) and walls[i] == 0:
        i += 1

    while i < len(walls) - 1:

        # Find a right side wall (assume i is index of left side wall)
        for j in range(i + 1, len(walls)):
            # Right wall must be a wall larger or equal to wall[i]
            if walls[j] >= walls[i]:
                break

        # Base is distance between walls
        base = j - i - 1

        # Height is the smaller of the two walls
        height = min(walls[i], walls[j])

        # Any walls between these two are subtracted from the total
        not_water = sum(walls[i + 1:j - 1])

        # Bada-bing
        water += (base * height) - not_water

        # Restart algorithm at right wall (treat as a left wall now)
        i = j

    return water

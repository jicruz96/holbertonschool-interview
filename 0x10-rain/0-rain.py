#!/usr/bin/python3
""" Script for rain interview question """


def rain(walls):
    """ computes amount of rain caputred by a set of walls
    
    Args:
        * walls (List[int]): Heights of walls.
     """

    left = 0
    total_rain = 0
    while left < len(walls) - 1:

        # Find right side wall. Must be at least as tall as left wall
        tallest = right = left + 1
        while right < len(walls) and walls[right] < walls[left]:
            if walls[right] > walls[tallest]:
                tallest = right
            right += 1
        
        # If a right wall wasn't found, fall back to the tallest wall found
        if right == len(walls):
            right = tallest

        """
        Amount of rain that fits between left and right walls is same as
        area of rectangle formed by left and right walls, minus the heights of
        walls inside rectangle
        """
        inner_wall_heights = sum(walls[left + 1:right])
        base = right - left - 1
        height = min(walls[left], walls[right])
        total_rain += (base * height) - inner_wall_heights

        # Restart algorithm at right wall (treat as a left wall now)
        left = right

    return total_rain

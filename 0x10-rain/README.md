# Interview Prep: Rain

## Description of Problem

Given a list of non-negative integers representing the height of walls of width 1, calculate how much water will be retained after it rains.

* Prototype: `def rain(walls)`
* `walls` is a list of non-negative integers.
* Return: Integer indicating total amount of rainwater retained.
* Assume that the ends of the list (before `walls[0]` after `walls[-1]`) are not walls, meaning they will not retain water.
* If the list is empty return 0.

## My Solution 💡

### 4-13-2021 , First Attempt

This solution finds a left and right wall, then computes the area created by the walls, subtracting any inner walls between them.

This has a `O(n^2)` time complexity (Although it's really `O(0.5n^2 + 0.5n)` but I digress-- y'all don't like precision).

Here's the code:
```python
def rain(walls):

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
        total_rain += (base * height) - inner_wall_heights # Bada-bing

        # Restart algorithm at right wall (treat as a left wall now)
        left = right

    return total_rain
```

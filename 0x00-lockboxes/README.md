# The 'Lockboxes' Interview Question

## Description of Problem, Constraints

You have `n` number of locked boxes in front of you. Each box is numbered sequentially from `0` to `n - 1` and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.

* Prototype: `def canUnlockAll(boxes)`
* `boxes` is a list of lists
* A key with the same number as a box opens that box
    * There can be keys that do not have boxes
    * You can assume all keys will be positive integers
* The first box `boxes[0]` is unlocked
* Return `True` if all boxes can be opened, else return `False`

## My Proposed Solutions

All my proposed solutions are available in the `0x00-lockboxes` file as distinct methods. My best solution is at the top and retains the name `canUnlockAll(boxes)`. Below is a description of them:

### 8 december 2020 - Brute-Forcing It

```
def canUnlockAll(boxes):

    numBoxes = len(boxes)
    unlockedBoxes = [0]
    numUnlocked = 1

    for box in unlockedBoxes:
        for key in boxes[box]:
            if key < numBoxes and key not in unlockedBoxes:
                unlockedBoxes.append(key)
                numUnlocked += 1
    return numBoxes == numUnlocked
```

In this solution, we loop through a queue of known unlocked boxes. For each unlocked box, we check each key. If a key opens a locked box, the key is added to the queue of known unlocked boxes. When the queue is done, we check if the number of unlocked boxes equaled the amount of total boxes.

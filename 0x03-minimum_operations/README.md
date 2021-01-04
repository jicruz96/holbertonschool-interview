# Interview Prep: Minimum Operations Challenge

## Description of Problem

In a text file, there is a single character `H`. Your text editor can execute only two operations in this file: `Copy All` and `Paste`. Given a number `n`, write a method that calculates the _fewest number of operations needed_ to result in exactly `n` `H` characters in the file.

* Prototype: `def minOperations(n)`
* Returns an integer
* If `n` is impossible to achieve, return `0`

### Example:

```
n = 9

H => Copy All => Paste => HH => Paste =>HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH

Number of operations: 6
```

## Proposed Solution 💡

### 4 january 2021

My initial solution uses a recursive tactic to check the length of each
possible variation of operation sequences. I return the smallest of these.

```python
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
```

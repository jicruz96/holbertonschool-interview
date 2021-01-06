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

## Proposed Solutions 💡

### 5 january 2021 - Reverse-Engineering via Recursion

Say we need to reach `n = 90` How do we get 90 H's? We could copy/paste 45 H's, but then we'd need to know how to get 45 H's. Ergo:
```
numOperations(90) = 2 operations + numOperations(45)
```
Do all the math and you come to learn that in general:
```
numOperations(n) = p + numOperations(q)
```
where `p * q = n` and `p` is the smallest prime factor of n.

Moreover, if `n` is prime, `numOperations(n) = n` because there are no numbers other than 1 that multiply up to `n`, so we'd have to copy the singular H and paste it `n - 1` times, giving us `n` total operations.

Bring those two facts together and you get this solution:

```python
def minOperations(n):
    """
    Calculates the minimum number of operations to go from one 'H' to n 'H's
    if the only available operations are "Copy All" and "Paste"
    """

    # If n is 1, 0 operations are needed.
    if n == 1:
        return 0

    # Find smallest prime factors
    for i in range(2, int((n/2)+1)):
        if n % i == 0:
            return minOperations(int(n / i)) + i

    return n
```

### 5 january 2021 - Sum of Prime Factors Solution

The solution, mathematically speaking, is fundamentally equivalent to the
sum of all prime factors. This approach can be seen here.


```python3
def minOperations_sumOfPrimeFactors(n):
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
```


### 4 january 2021 - Brute Force Checking via Recursion

My initial solution used a recursive tactic to check the length of each
possible variation of operation sequences. I return the smallest of these.

```python
def minOperations_bruteForce(n):
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
	
        if copyPaste == 0 or copyPaste > pasteOnly:
            return pasteOnly
	    
        return copyPaste
	
    # initiate simulation (starting at case where n = 2)
    return simulate(2, 1, 2)
```

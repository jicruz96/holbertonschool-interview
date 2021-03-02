# Interview Prep: 2-D Menger Sponge

## Description of Problem

Write a function that draws a 2D Menger Sponge

* Prototype: `void menger(int level);`
* Where `level` is the level of the Menger Sponge to draw
* If `level` is lower than 0, your function must do nothing
* Will be compiled with the C `math` library.

## Proposed Solution 💡

### 1 march 2021

A level-N menger sponge is `3**level` units long. So, my solution prints a `3**level` x `3**level` grid.

For each cell in the grid, I check if the current row (`i`) and column (`j`) are both the middle unit of a sub-section of the grid-- assuming the rows/columns are divided into `k` sub-sections, where `k` is any power of 3 smaller than `3**level`.

I arrived at this result through some pattern matching and some trial and error.

In terms of the side length `size` of the grid, this function has a standard `O(n**2)` time complexity. Don't worry about the third inner loop-- this loop adds, at most, `level` number of operations to each run of the inner loop, but does not increase the time complexity.

```C++
void menger(int level)
{
	int i, j, k, symbol, size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			symbol = '#';
			for (k = 1; k < size; k *= 3)
				if ((i / k) % 3 == 1 && (j / k) % 3 == 1)
				{
					symbol = ' ';
					break;
				}
			putchar(symbol);
		}
		putchar('\n');
	}
}
```

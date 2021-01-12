# Interview Prep: Sandpiles

## Description of Problem

Write a function that computes the sum of two 3x3 sandpiles.

* Prototype: `void sandpiles_sum(int grid1[3][3], int grid2[3][3]);`
* You can assume that both grid1 and grid2 are **individually stable**
    * (*A sandpile is stable when no cells contain more than 3 grains*)
* grid1 must be printed before each toppling round, only if it is unstable (See example)
* You’re not allowed to allocate memory dynamically

### What is a sandpile?

[Check out this video to learn!](https://intranet.hbtn.io/rltoken/UVY3WFjMmCRlLcr-B2Krug)

## Proposed Solution 💡

### 11 january 2021

My solution is straightforward.
<ol>
	<li>
		I add the two grids together using a nested loop.
		<ul>
			<li>While I add them, I record whether or not the sum resulted in a number greater than 3 on grid2's cell. Therefore, after the sum is complete grid2 acts as a map that tells us which cells need to be stabilized.</li>
		</ul>
	</li>
	<li>I topple the unstable cells, using grid2 as a map to find the unstable cells.</li>
	<li>I recheck for unstable cells and repeat steps 2 and 3 until grid1is stable.</li>
</ol>

In reality, the mapping of unstable cells onto grid2 is unnecessary to complete the sum accurately. But the interview exercise asked that we print the intermediate sandpile of each round of stabilization, which meant we needed to maintain a stage-by-stage order of cells to be stabilized.

```C++
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable = 0;

	/* ADD SANDPILES */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];                         /* add cells */
			grid2[i][j] = (grid1[i][j] > 3);    /* map cell state onto grid2 */
			unstable += (grid1[i][j] > 3);         /* count cell if unstable */
		}

	/* STABILIZE SANDPILE */
	while (unstable)
	{
		print_grid(grid1);

		/* stabilize sandpile (using grid2 as map to find unstable cells) */
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid2[i][j])
				{
					grid1[i][j] -= 4;           /* remove 4 grains from cell */
					if (i + 1 < 3)                /* add grain to right cell */
						grid1[i + 1][j] += 1;
					if (i - 1 >= 0)                /* add grain to left cell */
						grid1[i - 1][j] += 1;
					if (j + 1 < 3)                  /* add grain to top cell */
						grid1[i][j + 1] += 1;
					if (j - 1 >= 0)              /* add grain to bottom cell */
						grid1[i][j - 1] += 1;
				}

		/* re-count and re-map unstable cells */
		for (unstable = 0, i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				grid2[i][j] = (grid1[i][j] > 3);     /* map state onto grid2 */
				unstable += (grid1[i][j] > 3);       /* count unstable cells */
			}
	}
}

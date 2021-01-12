#include "sandpiles.h"


/**
 * sandpiles_sum -  adds grid2 sandpile onto grid1. Prints intermediate,
 *					unstable sandpiles.
 * @grid1: first sandpile
 * @grid2: second sandpile
**/
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

/**
 * print_grid - prints a grid of numbers
 * @grid: grid
 **/
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

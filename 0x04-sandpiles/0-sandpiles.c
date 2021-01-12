#include "sandpiles.h"


/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
**/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable = 0;

	/* add sandpiles */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j]; /* add cells */
			grid2[i][j] = (grid1[i][j] > 3); /* map unstable cell onto grid2 */
			unstable += (grid1[i][j] > 3); /* count cell if unstable */
		}

	/* topple sanpile while unstable cells exist */
	while (unstable)
	{
		print_grid(grid1);

		/* topple sandpile, using grid2 as map for which cells need toppling */
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid2[i][j])
				{
					grid1[i][j] -= 4;
					if (i + 1 < 3)
						grid1[i + 1][j] += 1;
					if (i - 1 >= 0)
						grid1[i - 1][j] += 1;
					if (j + 1 < 3)
						grid1[i][j + 1] += 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] += 1;
				}

		/* recount and map unstable cells */
		for (unstable = 0, i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid2[i][j] = (grid1[i][j] > 3), unstable += (grid1[i][j] > 3);
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

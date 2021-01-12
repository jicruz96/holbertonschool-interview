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
* First, I add the two grids together using a nested loop.
    * While I add them, I record whether or not the sum resulted in a number greater than 3 on `grid2`'s cell. Therefore, after the sum is complete `grid2` acts as a map that tells us which cells need to be toppled.
* Second, I topple the unstable cells, using `grid2` as a map to find the unstable cells.
* Third, I recheck for unstable cells and repeat step 2 until `grid1`is stable.

```C++
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, unstable = 0;

    /* add sandpiles */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
            /* record if position is unstable onto grid2 */
            grid2[i][j] = (grid1[i][j] > 3);
            unstable += (grid1[i][j] > 3);
        }
    
    /* topple sanpile while unstable cells exist */
    while (unstable)
    {
        print_grid(grid1);

        /* topple sandpile, using grid2 as key for which cells to topple */
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

#include "menger.h"

/**
 * menger - draws a 2D Menger sponge
 * @level: level of Menger sponge to draw
 **/
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

#include "slide_line.h"

/**
 * slide_line - treats a 1D array as a game of 2048.
 * @line: pointer to array of integers (the line)
 * @size: line size
 * @direction: which way the line slides (either SLIDE_RIGHT or SLIDE_LEFT)
 * Return: 1 on success | 0 if unslideable
 **/
int slide_line(int *line, size_t size, int direction)
{
	int *target, *spot = line, *end = line + size, next = 1;

	if (direction == SLIDE_RIGHT)
		spot = line + size - 1, end = line - 1, next = -1;
	else if (direction != SLIDE_LEFT)
		return (0);

	for (target = spot; target != end; target += next)
		if (*target)
			break;

	if (target == end)
		return (1);

	for (line = target + next; line != end; line += next)
		if (*line)
		{
			if (*line == *target)
			{
				*line = 0, *spot = (*target) * 2;
				*target = (spot != target) ? 0 : *target;
				for (line += next; line != end; line += next)
					if (*line)
						break;
				if (line == end)
					return (1);
			}
			else if (spot != target)
			{
				*spot = *target, *target = 0;
			}
			target = line;
			while (spot != target && *spot)
				spot += next;
		}

	if (spot != target)
		*spot = *target, *target = 0;

	return (1);
}

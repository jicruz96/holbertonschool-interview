# Interview Prep: 2048 (single line)

## Description of Problem

### The goal of this task is to reproduce the mechanics of [the 2048 game](https://play2048.co) on a single horizontal line.

Given an array of integers, we want to be able to slide & merge its values to the left or to the right such that identical numbers, if they are contiguous or separated by zeros, are merged, and all empty positions in the direction of movement are filled. Write a function that slides and merges an array of integers in this way.

* Prototype: `int slide_line(int *line, size_t size, int direction);`
* `line` points to an array of integers containing `size` elements, that must be slided & merged to the direction represented by `direction`. direction can be either: `SLIDE_LEFT` or `SLIDE_RIGHT`. If it is something else, return 0.
* I am not allowed to allocate memory dynamically (`malloc`, `calloc`, …)


## Proposed Solution 💡

### 23 february 2021


This algorithm scans the list twice. One pointer, `target`, scans the list looking for a target (i.e. a number to slide and merge) while another pointer, `spot`, keeps track of the next available spot that `target` can slide over to. In the worst case scenario, this algorithm has a time complexity of **O(2 * size)** .

To keep the solution **DRY**[^1], I use the pointers `next` and `end` to denote the direction of movement and the end of the scan. Their values depend on the value of `direction`.

I am not certain this is the best way to code it out, nor am I certain that this is necessarily the fastest approach, but it's fast _enough_. I also am not a huge fan of the coding style here, but I wanted to stay under my school's 40 line limit.

[^1]: Don't Repeat Yourself

```C++
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
```

#ifndef _SUBSTRING_H_
#define _SUBSTRING_H_

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int _strlen(char const *s);
int _strncmp(char const *s1, char const *s2, int n);
int append(int **arr, int *arr_size, int n);
int is_substring(char const *s, char const **words,
	int nb_words, int len, int *seen);

#endif /* _SUBSTRING_H_ */

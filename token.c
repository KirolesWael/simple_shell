#include "main.h"

/**
 * split_words - Split a line into words
 *
 * @line: Line to spli
 * @sep: Delimiters for split the words
 *
 * Return: Set of words
 **/
char **split_words(char *line, const char *sep)
{
	char **wds, **tmp, *token;
	size_t n_size, o_size;

	o_size = sizeof(char *);
	wds = malloc(o_size);
	if (wds != NULL)
	{
		n_size = 1;
		token = strtok(line, sep);
		while (token)
		{
			if (token[0] == '#')
				break;
			tmp = _realloc(wds, o_size, (n_size + 1) * sizeof(char *));
			o_size = (n_size + 1) * sizeof(char *);
			if (tmp == NULL)
				break;

			wds = tmp;
			++n_size;

			wds[n_size - 2] = malloc(_strlen(token) + 1);
			if (wds == NULL)
			{
				free(wds);
				free(tmp);
			}

			if (wds[n_size - 2] != NULL)
				_strcpy(wds[n_size - 2], token);

			token = strtok(NULL, sep);

			tmp = NULL;
		}

		wds[n_size - 1] = NULL;
	}

	return (wds);
}

/**
 * join_words - Join 3 words with a separator
 * Description: Result -> w1.sep.w2.sep.nl
 * @word1: Word1 to join
 * @word2: Word2 to join
 * @word3: Word3 to join
 * @sep: Separator between the words
 *
 * Return: Line composed by 3 parts followed by a separator and
 * end by a new line
 **/
char *join_words(char *word1, char *word2, char *word3, const char *sep)
{
	char *aux;
	int size_str1, size_str2, size_str3, size_sep;

	size_str1 = size_str2 = size_sep = 0;

	if (word1 != NULL)
		size_str1 = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		size_str2 = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		size_str3 = _strlen(word3);
	else
		word3 = "";

	if (sep != NULL)
		size_sep = _strlen((char *)sep);
	else
		sep = "";

	aux = malloc(size_str1 + size_str2 + size_sep + size_str3 + size_sep + 2);
	if (aux == NULL)
		return (NULL);

	aux = _strcpy(aux, word1);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word2);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word3);
	aux = _strcat(aux, "\n");

	return (aux);
}

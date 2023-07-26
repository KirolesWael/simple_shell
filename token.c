#include "main.h"

/**
 * split_words - Split a line into words
 *
 * @line: Line to spli
 * @sep: Delimiters for split the words
 *
 * Return: Set of words
 **/
char **breakingWords(char *line, const char *separted)
{
	char **sentence, **tempo, *token;
	size_t new, old;

	old = sizeof(char *);
	sentence = malloc(old);
	if (sentence != NULL)
	{
		new = 1;
		token = strtok(line, separted);
		while (token)
		{
			if (token[0] == '#')
				break;
			tempo = _realloc(sentence, old, (new + 1) * sizeof(char *));
			old = (new + 1) * sizeof(char *);
			if (tempo == NULL)
				break;

			sentence = tempo;
			++new;

			sentence[new - 2] = malloc(_strlen(token) + 1);
			if (sentence == NULL)
			{
				free(sentence);
				free(tempo);
			}

			if (sentence[new - 2] != NULL)
				_strcpy(sentence[new - 2], token);

			token = strtok(NULL, separted);

			tempo = NULL;
		}

		sentence[new - 1] = NULL;
	}

	return (sentence);
}

/**
 * join_words - Join 3 words with a separator
 * Description: Result -> w1.sep.w2.sep.nl
 * @word1: Word1 to join
 * @word2: Word2 to join
 * @word3: Word3 to join
 * @separted: Separator between the words
 *
 * Return: Line composed by 3 parts followed by a separator and
 * end by a new line
 **/
char *jointOfWords(char *word1, char *word2, char *word3, const char *separted)
{
	char *aux;
	int size1, size2, size3, sepatationSizearted;

	size1 = size2 = sepatationSizearted = 0;

	if (word1 != NULL)
		size1 = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		size2 = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		size3 = _strlen(word3);
	else
		word3 = "";

	if (separted != NULL)
		sepatationSizearted = _strlen((char *)separted);
	else
		separted = "";

	aux = malloc(size1 + size2 + sepatationSizearted + size3 + sepatationSizearted + 2);
	if (aux == NULL)
		return (NULL);

	aux = _strcpy(aux, word1);
	aux = _strcat(aux, (char *)separted);
	aux = _strcat(aux, word2);
	aux = _strcat(aux, (char *)separted);
	aux = _strcat(aux, word3);
	aux = _strcat(aux, "\n");

	return (aux);
}

#include "shell.h"
/**
 * split_str - a function taht splits a string and returns array of words
 * for the splitted string
 * @str: the string to split
 * @delim: the delimiter to split string with
 * Return: an array of words for the split string
 */
/* str = "I am a string" */
char **split_str(char *str, const char *delim)
{
	/*create a pointer to the strings*/
	char *str_ptr = str;
	/*make a copy of the input string*/
	char *str_cpy = strdup(str_ptr);
	/*creat a pointer to the splitted word*/
	char *splitted;
	char **array_strs;
	int n_words = 0;
	int i;

	splitted = strtok(str_ptr, delim);
	/*get other fragments*/
	while (splitted)
	{
		splitted = strtok(NULL, delim);
		n_words++;
	}
	/*allocated size for array of strings*/
	array_strs = malloc(sizeof(char *) * (n_words + 1));
	/*MALLOC FAILURE*/
	if (array_strs == NULL)
	{
		free(str_cpy);
		return (NULL);
	}

	/*now break the words again, based on copy and then save to the array*/
	splitted = strtok(str_cpy, delim);
	/*get othe rparths of the string and save into array*/
	n_words = 0;
	while (splitted)
	{
		/*save previous split into array*/
		array_strs[n_words] = strdup(splitted);
		/*HANDLE MALLOC RETURN*/
		if (array_strs[n_words] == NULL)
		{
			/*FREE EACH ROW AND COLUMN*/
			for (i = 0; i < n_words; i++)
				free(array_strs[i]);
			free(array_strs);
			free(str_cpy);
			return (NULL);
		}
		/*split the rest*/
		splitted = strtok(NULL, delim);
		n_words++;
	}
	/*set last array value to NULL*/
	array_strs[n_words] = NULL;
	/*free allocs*/
	free(str_cpy);

	return (array_strs);
}

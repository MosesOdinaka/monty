#include "monty.h"
/**
 * my_getline - reads an entire line from a stream.
 * @lineptr: pointer to the address of the buffer.
 * @n: a pointer to the size_t.
 * @stream: a file pointer.
 * @buffer_size: allocated size`
 * Return: -1 if any of them a NULL.
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream,
				size_t buffer_size)
{
	char *buffer;
	size_t total = 0;
	size_t len;
	char *new_line;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	buffer = malloc(buffer_size);
	if (buffer == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = buffer_size;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			free(buffer);
			return (-1);
		}
	}
	while (fgets(buffer, buffer_size, stream) != NULL)
	{
		len = strlen(buffer);
		if (total + len + 1 > *n)
		{
			*n = total + len + 1;
			new_line = malloc(*n);
			if (new_line == NULL)
			{
				free(buffer);
				return (-1);
			}
			memcpy(new_line, *lineptr, total);
			free(*lineptr);
			*lineptr = new_line;
		}
		strcpy(*lineptr + total, buffer);
		total += len;
		if ((*lineptr)[total - 1] == '\n')
			break;
	}
	free(buffer);
	if (total == 0)
		return (-1);
	(*lineptr)[total] = '\0';
	return (total);
}

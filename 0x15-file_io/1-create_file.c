#include "holberton.h"

/**
 * _strlen - get the length of a string
 * @s: a string
 *
 * Return: length of the string
 */
size_t _strlen(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
		;

	return (i);
}

/**
 * create_file - create a file
 * @filename: name of file to create
 * @text_content: content to include in the new file
 *
 * Return: error code (1 for success, -1 for failure)
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		bytes_written = write(fd, text_content, _strlen(text_content));
	}

	close(fd);

	if (bytes_written == -1)
		return (-1);

	return (1);
}

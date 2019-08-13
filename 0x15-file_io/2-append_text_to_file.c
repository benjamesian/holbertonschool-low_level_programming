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
 * append_text_to_file - append text at the end of a file
 * @filename: name of file to append text to
 * @text_content: text to append to the end of the file
 *
 * Return: error code (1 for success, -1 for failure)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}

	bytes_written =  write(fd, text_content, _strlen(text_content));

	close(fd);

	if (bytes_written == -1)
		return (-1);

	return (1);
}

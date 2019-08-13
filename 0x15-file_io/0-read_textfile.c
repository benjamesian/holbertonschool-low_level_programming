#include "holberton.h"

/**
 * read_textfile - read text from a file and print it to stdout
 * @filename: name of file to read
 * @letters: number of characters to read from the file
 *
 * Return: number of characters written to stdout
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_written, bytes_read;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(*buf) * letters);
	if (!buf)
		return (0);

	bytes_read = read(fd, buf, letters);
	bytes_written = write(STDOUT_FILENO, buf, bytes_read);

	close(fd);

	return (bytes_written);
}

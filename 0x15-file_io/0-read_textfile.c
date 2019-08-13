#include "holberton.h"

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
	bytes_written = write(1, buf, bytes_read);

	close(fd);

	return (bytes_written);
}

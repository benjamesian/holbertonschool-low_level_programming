#include "holberton.h"
#include <stdio.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_written;
	char buf[letters];

	if (!filename)
		return (0);

	puts("a");
	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	puts("b");
	read(fd, buf, letters);
	puts(buf);
	bytes_written = write(fd, buf, letters);

	close(fd);

	return (bytes_written);
}

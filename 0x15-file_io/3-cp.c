#include <stdio.h>
#include "holberton.h"

#define BUFSIZE 1024

/**
 * close_file - close a file and return an error message on failure
 * @fd: file descriptor of file to close
 */
void close_file(int fd)
{

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - entry point
 * @argc: number of args provided to program
 * @argv: arguments provided to the program
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fdf, fdt, bytes_read = BUFSIZE;
	char buf[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fdf = open(argv[1], O_RDONLY);
	if (fdf == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fdt = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fdt == -1)
	{
		close_file(fdf);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while (bytes_read == BUFSIZE)
	{
		bytes_read = read(fdf, buf, BUFSIZE);
		if (bytes_read && write(fdt, buf, bytes_read) == -1)
		{
			close_file(fdf);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	close_file(fdf);
	close_file(fdt);

	return (0);
}

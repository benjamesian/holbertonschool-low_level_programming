#include <stdio.h>
#include "holberton.h"

#define BUFSIZE 1024

/**
 * main - entry point
 * @argc: number of args provided to program
 * @argv: arguments provided to the program
 */
int main(int argc, char *argv[])
{
	int fdf, fdt, closed, bytes_read = BUFSIZE, bytes_written;
	char *ft, *ff;
	char buf[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	ff = argv[1];
	ft = argv[2];

	fdf = open(ff, O_RDONLY);
	if (fdf == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", ff);
		exit(98);
	}

	fdt = open(ft, O_WRONLY | O_TRUNC | O_CREAT, 0664);

	if (fdt == -1)
	{
		closed = close(fdf);
		if (closed == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (int) fdf);
			exit(100);
		}
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", ft);
		exit(99);
	}

	while (bytes_read == BUFSIZE)
	{
		bytes_read = read(fdf, buf, BUFSIZE);
		printf("Writing... %s", buf);
		bytes_written = write(fdt, buf, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", ft);
			exit(99);
		}
	}

	closed = close(fdf);
	if (closed == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (int) fdf);
		exit(100);
	}

	closed = close(fdt);
	if (closed == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (int) fdt);
		exit(100);
	}

	return (0);
}

#include <stdio.h>

void print_10_hex(char *b, int size);
void print_10_char(char *b, int size);

/**
 * print_buffer - Print a buffer
 * @b: buffer to print
 * @size: size of the buffer
 */
void print_buffer(char *b, int size)
{
	int i = 0;

	while (size > 0)
	{
		printf("%08x: ", i);
		i += 10;
		print_10_hex(b, size);
		putchar(' ');
		print_10_char(b, size);
		b += 10;
		putchar('\n');
		size -= 10;
	}
}

/**
 * print_10_hex - print 10 hexadecimal values of chars
 * @b: buffer containing chars to print
 * @size: number of chars to print (max 10)
 */
void print_10_hex(char *b, int size)
{
	int i;

	if (size > 10)
		size = 10;
	i = size;
	while (i--)
	{
		printf("%02x", *(b + size - i));
		if (!((size - i) % 2))
			putchar(' ');
	}

	while (size < 10)
	{
		size += 2;
		printf("     ");
	}
}

/**
 * print_10_char - Print chars
 * @b: buffer containing chars
 * @size: number of chars to print (max 10)
 */
void print_10_char(char *b, int size)
{
	if (size > 10)
		size = 10;
	while (size--)
	{
		if (*b >= ' ' && *b <= '~')
			putchar(*b);
		else
			putchar('.');
		b++;
	}

}

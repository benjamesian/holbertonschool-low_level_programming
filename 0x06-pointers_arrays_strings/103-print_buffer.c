#include <stdio.h>

void print_10_hex(char *b, int size);
void print_10_char(char *b, int size);

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

	while (10 > size)
	{
		size += 2;
		printf("     ");
	}
}

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

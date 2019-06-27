/**
 * print_most_numbers - Print the characters from '0' to '9', except '2' & '4'
 */
void print_most_numbers(void)
{
	char n;

	for (n = '0'; n <= '9'; n++)
		if (n != '2' && n != '4')
			_putchar(n);
	_putchar('\n');
}

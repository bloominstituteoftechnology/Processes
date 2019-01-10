#include <stdio.h>
#include <unistd.h>

void putchar_ls(char c)
{
	write(1, &c, 1);
}

void print_str(char *s)
{
	while (*s != '\0') {
		putchar_ls(*(s++));
	}
}

int main(void)
{
	print_str("Hello, world!\n");

	return 0;
}
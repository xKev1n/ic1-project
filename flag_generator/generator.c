#include <stdio.h>
#include <stdlib.h>

static char *rand_flag(char *str, size_t size)
{
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	if (size)
	{
		--size;
		for (size_t i = 0; i < size; i++)
		{
			int key = rand() % (int) (sizeof charset - 1);
			str[i] = charset[key];
		}
		str[size] = '\0';
	}
	return str;
}

int main(int argc, char const *argv[])
{
	time_t t;

	srand((unsigned) time(&t));

	char flag1[17];
	rand_flag(flag1, 17);

	for(int i = 0; i < sizeof flag1; i++)
	{
		printf("%c", flag1[i]);
	}

	return 0;
}
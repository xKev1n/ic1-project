#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int end = 300;
	int mins = end / 60;

	for (end; end > 0; end--)
	{
		int secs = end % 60;

		if (secs < 10)
		{
			printf("%i:0%i\n", mins, secs);
		}
		else
		{
			printf("%i:%i\n", mins, secs);
		}
		
		if (end % 60 == 0)
		{
			mins --;
		}
		
		sleep(1);
	}

	return 0;
}